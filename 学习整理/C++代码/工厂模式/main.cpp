#include<iostream>
#include"factorymethodproduct.h"
#include"applefactory.h"
#include"bananafactory.h"
#include"orangefactory.h"

int main()
{
	FactoryMethodPoduct *product = AppleFactory::instance().creatProduct();
	product->show();

	product = BananaFactory::instance().creatProduct();
	product->show();


	product = OrangeFactory::instance().creatProduct();
	product->show();

	system("pause");
	return 0;
}