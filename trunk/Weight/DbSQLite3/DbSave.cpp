#include "stdafx.h"
#include "DbSave.h"


CDbSave::CDbSave()
{
}

CDbSave::~CDbSave()
{
}

bool CDbSave::CreateDBSave()
{
	db.open("data.db");

	return true;
}
bool CDbSave::CreateTable()
{
	string sqlLine = "CREATE TABLE store ( sn varchar(50), weight1 float, time1 datetime, weight2 float, time2 datetime ) ";
	int iRet = db.execDML(sqlLine.c_str());
	if (iRet == 0)
	{
		return false;
	}
	return true;
}
bool CDbSave::AddBeforDb(string _sn, float weight)
{
	if (ExitSN(_sn))
	{
		return false;
	}
	string _cWeight = "";
	_cWeight = weight;

	string sqlLine = "insert into store (weight1,time1) values (" + _sn + "," + _cWeight + ")";
	int iRet = db.execDML(sqlLine.c_str());
	if (iRet == 0)
	{
		return false;
	}
	return true;
}
bool CDbSave::AddAfterDb(string _sn, float weight)
{
	if (!ExitSN(_sn))
	{
		return false;
	}
	string _cWeight = "";
	_cWeight = weight;

	string sqlLine = "update store set weight2 = " + _cWeight + ", time2 = getdate() where sn = '" + _sn + "'";
	int iRet = db.execDML(sqlLine.c_str());
	if (iRet == 0)
	{
		return false;
	}

	return true;
}
CppSQLite3Query CDbSave::Search(string _sPreTime, string _sEndTime, string _sBatchNo, string _sSn)
{
	string sqlLine = "select * from store where (time1 > '" + _sPreTime + "' and time2 < '" + _sEndTime + "' ";
	if (_sSn != "")
	{
		sqlLine += "and _sSn = '" + _sSn + "' ";
	}
	sqlLine += " )";

	CppSQLite3Query query = db.execQuery(sqlLine.c_str());

	return query;
}
bool CDbSave::ExitSN(string _sn)
{
	string sqlLine = "select 1 from store where sn = '" + _sn +"'";
	CppSQLite3Query query = db.execQuery(sqlLine.c_str());
	if (!query.eof())
	{
		return true;
	}
	return false;
}