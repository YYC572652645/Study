#ifndef __BANANA_FACTORY_H__
#define __BANANA_FACTORY_H__
#include"factorymethodbase.h"
class  FactoryMethodPoduct;
class BananaFactory: public FactoryMethodBase
{
public:
	static BananaFactory & instance();
	 FactoryMethodPoduct* creatProduct();
};



#endif