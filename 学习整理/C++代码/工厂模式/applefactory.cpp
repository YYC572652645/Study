#include "applefactory.h"
#include "apple.h"

AppleFactory&AppleFactory::instance()
{
	static AppleFactory apple;
	return apple;
}


FactoryMethodPoduct*AppleFactory::creatProduct()
{
	return new Apple();
}