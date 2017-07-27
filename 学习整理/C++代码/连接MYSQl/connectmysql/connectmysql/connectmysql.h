#ifndef __CONNECT_MYSQL_H__
#define __CONNECT_MYSQL_H__
#include<iostream>
#include <WinSock2.h>
#include<stdio.h>
#include "mysql.h"
#include<string.h>
#pragma comment(lib,"libmysql.lib")
#define   CONNECTMYSQL   ConnectMysql::GetInstance()

class ConnectMysql
{
public:
	static ConnectMysql *GetInstance();
	~ConnectMysql();
	
	bool DataConn();
	int  DataSelect();
	void DataDelete();
	void DataUpdate();
	bool DataInsert();
	bool DataClose();
	void SetConfig(std::string db_name, std::string ip, int port, std::string username, std::string password);
private:
	ConnectMysql();
	MYSQL mysql;
	static ConnectMysql *instance;
	std::string m_db_name;
	std::string m_ip;
	int m_port;
	std::string m_username;
	std::string m_password;
};

#endif