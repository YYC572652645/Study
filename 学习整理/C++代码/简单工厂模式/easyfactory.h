#ifndef __EASY_FACTORY_H__
#define __EASY_FACTORY_H__
#include<map>
class EasyProduct;
namespace TYPE
{
	enum FRUITS
	{
		BANANA,
		ORANGE,
		APPLE,
	};
}

class EasyFactory
{
public:
	static EasyFactory & instance();
	EasyProduct* createProduct(TYPE::FRUITS type);
};

#endif