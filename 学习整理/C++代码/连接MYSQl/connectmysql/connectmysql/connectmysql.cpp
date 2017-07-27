#include "connectmysql.h"

ConnectMysql*ConnectMysql::instance = NULL;

ConnectMysql::ConnectMysql()
{
}


ConnectMysql::~ConnectMysql()
{

}


ConnectMysql *ConnectMysql::GetInstance()
{
	if(NULL == instance)
	{
		instance = new ConnectMysql();
	}
	return instance;
}


void ConnectMysql::SetConfig(std::string db_name, std::string ip, int port, std::string username, std::string password)
{
	m_ip = ip;
	m_port = port;
	m_db_name = db_name;
	m_username = username;
	m_password = password;
}


bool ConnectMysql::DataConn()
{
	mysql_library_init(NULL, 0, 0);   
	mysql_init(&mysql);
	bool open_flage = mysql_real_connect(&mysql, m_ip.c_str(), m_username.c_str(), m_password.c_str(), m_db_name.c_str(), m_port, NULL,CLIENT_MULTI_STATEMENTS);
	return open_flage;
}


int ConnectMysql::DataSelect()
{
	mysql_query(&mysql, "select * from people;");        
	MYSQL_RES *result = mysql_store_result(&mysql);  

	if(NULL != result)
	{
		int rowcount = mysql_num_rows(result);                
		int fieldcount = mysql_num_fields(result);   

		MYSQL_FIELD *field = NULL;                    
		MYSQL_ROW row = NULL;                       

		while(row = mysql_fetch_row(result))
		{
			for(int i = 0; i < fieldcount; i ++)
			{
				field = mysql_fetch_field_direct(result, i);
				std::cout<<field->name<<": "<<row[i]<<std::ends<<std::ends<<std::ends;
			}
			std::cout<<std::endl; 
		}   
		mysql_free_result(result);
		return rowcount;
	}
	else
	{
		return 0;
	}
	
}


void ConnectMysql::DataDelete()
{
	mysql_query(&mysql, "delete  from people where name = 'YYC';");  
	mysql_close(&mysql);
}
void ConnectMysql::DataUpdate()
{
	mysql_query(&mysql, "update  people set name = 'YYX' where name = 'YYC';");  
	mysql_close(&mysql);
}