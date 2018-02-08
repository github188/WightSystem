#ifndef __DB_SAVE_H__
#define __DB_SAVE_H__
#include "CppSQLite3.h"
#include <iostream>
using namespace std;

class CDbSave
{
public:
	CDbSave();
	~CDbSave();
	
	bool CreateDBSave();
	bool CreateTable();
	bool AddBeforDb(string _sn, float weight);
	bool AddAfterDb(string _sn, float weight);
	bool ExitSN(string _sn);
	CppSQLite3Query Search(string _sPreTime, string _sEndTime, string _sBatchNo = "All", string _sSn = "");

private:
	CppSQLite3DB db;
};
#endif