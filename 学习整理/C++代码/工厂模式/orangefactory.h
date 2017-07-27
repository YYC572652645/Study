#ifndef __ORANGE_FACTORY_H__
#define __ORANGE_FACTORY_H__
#include"factorymethodbase.h"
class  FactoryMethodPoduct;
class OrangeFactory:public FactoryMethodBase
{
public:
	static OrangeFactory & instance();
	 FactoryMethodPoduct* creatProduct();
};


#endif