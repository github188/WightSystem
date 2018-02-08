// SQLite3_Test.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"
#include "sqlite3.h"
#include <iostream>
using namespace std;

sqlite3 * pDB = NULL;

//�����û�  
bool CreateTable();

//�����û�  
bool AddUser(const string& sName, const string& sAge);
//ɾ���û�  
bool DeleteUser(const string& sName);
//�޸��û�  
bool ModifyUser(const string& sName, const string& sAge);
//�����û�  
bool SelectUser();

int _tmain(int argc, _TCHAR* argv[])
{
	//��·������utf-8����
	//���·���а������ģ���Ҫ���б���ת��
	int nRes = sqlite3_open("test.db", &pDB);
	if (nRes != SQLITE_OK)
	{
		cout << "Open database fail: " << sqlite3_errmsg(pDB);
		goto QUIT;
	}
	if (!CreateTable())
	{
		goto QUIT;
	}

	//��ӡ���Ǯ���
	if (!AddUser("zhao", "18")
		|| !AddUser("qian", "19")
		|| !AddUser("sun", "20")
		|| !AddUser("li", "21"))
	{
		goto QUIT;
	}

	//ɾ�����ԡ�
	if (!DeleteUser("zhao"))
	{
		goto QUIT;
	}

	//�޸ġ��
	if (!ModifyUser("sun", "15"))
	{
		goto QUIT;
	}

	//�����û�
	if (!SelectUser())
	{
		goto QUIT;
	}

QUIT:
	sqlite3_close(pDB);
	cin.get();
	return 0;
}

bool CreateTable()
{
	string strSql = "create table user(name varchar(20) PRIMARY KEY, age int);";
	char* cErrMsg;
	int nRes = sqlite3_exec(pDB, strSql.c_str(), 0, 0, &cErrMsg);
	if (nRes != SQLITE_OK)
	{
		cout << "create table fail: " << cErrMsg << endl;
		return false;
	}
	else
	{
		cout << "create table success!" << endl;
	}

	return true;
}

bool AddUser(const string& sName, const string& sAge)
{
	string strSql = "";
	strSql += "insert into user(name,age)";
	strSql += "values('";
	strSql += sName;
	strSql += "',";
	strSql += sAge;
	strSql += ");";

	char* cErrMsg;
	int nRes = sqlite3_exec(pDB, strSql.c_str(), 0, 0, &cErrMsg);
	if (nRes != SQLITE_OK)
	{
		cout << "add user fail: " << cErrMsg << endl;
		return false;
	}
	else
	{
		cout << "add user success: " << sName.c_str() << "\t" << sAge.c_str() << endl;
	}

	return true;
}

bool DeleteUser(const string& sName)
{
	string strSql = "";
	strSql += "delete from user where name='";
	strSql += sName;
	strSql += "';";

	char* cErrMsg;
	int nRes = sqlite3_exec(pDB, strSql.c_str(), 0, 0, &cErrMsg);
	if (nRes != SQLITE_OK)
	{
		cout << "delete user fail: " << cErrMsg << endl;
		return false;
	}
	else
	{
		cout << "delete user success: " << sName.c_str() << endl;
	}

	return true;
}

bool ModifyUser(const string& sName, const string& sAge)
{
	string strSql = "";
	strSql += "update user set age =";
	strSql += sAge;
	strSql += " where name='";
	strSql += sName;
	strSql += "';";

	char* cErrMsg;
	int nRes = sqlite3_exec(pDB, strSql.c_str(), 0, 0, &cErrMsg);
	if (nRes != SQLITE_OK)
	{
		cout << "modify user fail: " << cErrMsg << endl;
		return false;
	}
	else
	{
		cout << "modify user success: " << sName.c_str() << "\t" << sAge.c_str() << endl;
	}

	return true;
}

static int UserResult(void *NotUsed, int argc, char **argv, char **azColName)
{
	for (int i = 0; i < argc; i++)
	{
		cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << ", ";
	}
	cout << endl;

	return 0;
}

bool SelectUser()
{
	char* cErrMsg;
	int res = sqlite3_exec(pDB, "select * from user;", UserResult, 0, &cErrMsg);

	if (res != SQLITE_OK)
	{
		cout << "select fail: " << cErrMsg << endl;
		return false;
	}

	return true;
}

