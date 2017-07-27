#include"easyfactory.h"
#include"banana.h"
#include"orange.h"
#include"apple.h"
#include<stdio.h>

EasyFactory &EasyFactory::instance()
{
	static EasyFactory factory;
	return factory;
}
EasyProduct*EasyFactory::createProduct(TYPE::FRUITS type)
{
	switch(type)
	{
	case TYPE::BANANA:return new Banana();break;
	case TYPE::ORANGE:return new Orange();break;
	case TYPE::APPLE:return new Apple();break;
	default:return NULL;
	}
}