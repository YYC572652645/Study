#ifndef __FACTORY_METHOD_BASE_H__
#define __FACTORY_METHOD_BASE_H__
#include<stdio.h>
class  FactoryMethodPoduct;
class FactoryMethodBase
{
public:
	virtual ~FactoryMethodBase(){}
	virtual FactoryMethodPoduct* creatProduct(){return NULL;}
};



#endif