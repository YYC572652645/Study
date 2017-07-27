#include<iostream>
#include"easyfactory.h"
#include"easyproduct.h"

int main()
{
	EasyProduct *product=EasyFactory::instance().createProduct(TYPE::BANANA);
	product->show();
	product=EasyFactory::instance().createProduct(TYPE::ORANGE);
	product->show();
	product=EasyFactory::instance().createProduct(TYPE::APPLE);
	product->show();
	system("pause");
	return 0;
}