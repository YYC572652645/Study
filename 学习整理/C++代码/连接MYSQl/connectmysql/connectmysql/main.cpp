#include "connectmysql.h"
#include "connectmysql.h"
int main()
{
	CONNECTMYSQL->SetConfig("test", "127.0.0.1", 3306, "root", "root");
	if(CONNECTMYSQL->DataConn())
	{
		CONNECTMYSQL->DataSelect();
	}
	else
	{
		std::cout<<"连接数据库失败"<< std::endl;
	}
	int a = 0;
	std::cin>>a;
	CONNECTMYSQL->DataDelete();

	system("pause");
	return 0;
}