#include "orangefactory.h"
#include "orange.h"

OrangeFactory&OrangeFactory::instance()
{
	static OrangeFactory orange;
	return orange;
}

FactoryMethodPoduct*OrangeFactory::creatProduct()
{
	return new Orange();
}