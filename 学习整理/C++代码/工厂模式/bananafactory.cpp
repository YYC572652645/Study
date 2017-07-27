#include "bananafactory.h"
#include "banana.h"

BananaFactory&BananaFactory::instance()
{
	static BananaFactory banana;
	return banana;
}

FactoryMethodPoduct*BananaFactory::creatProduct()
{
	return new Banana();
}