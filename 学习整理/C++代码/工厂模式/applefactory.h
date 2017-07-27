#ifndef __APPLE_FACTORY_H__
#define __APPLE_FACTORY_H__
#include"factorymethodbase.h"
class  FactoryMethodPoduct;
class AppleFactory:public FactoryMethodBase
{
public:
	static AppleFactory & instance();
	 FactoryMethodPoduct* creatProduct();
};



#endif