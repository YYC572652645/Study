#ifndef __MYSQL_DEF_H__
#define __MYSQL_DEF_H__
#include<iostream>
#include <string>
namespace FieldNumber
{
	enum Number
	{
		NAME,
		SEX,
		NUMBER,
		AGE,
		HIGHT,
		MAX,
	};



	typedef struct SelectData
	{
		std::string name;
		std::string sex;
		std::string number;
		std::string age;
		std::string hight;
	}SelectData;
}


#endif