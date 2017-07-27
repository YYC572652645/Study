#include"study.h"

Study::Study()
{
}

Study::~Study()
{
}

Study & Study::StudyInstance()
{
	static Study study;
	return study;
}


bool Study::studyHistory(int &hour, int &minute, int &second)
{
	std::cout<<"study history"<<std::endl<<"time:"<<hour<<":"<<minute<<":"<<second<<std::endl<<std::endl;
	return true;
}

bool Study::studyMath(int &hour, int &minute, int &second)
{
	std::cout<<"study math"<<std::endl<<"time:"<<hour<<":"<<minute<<":"<<second<<std::endl<<std::endl;
	return true;
}

bool Study::studyEnglish(int &hour, int &minute, int &second)
{
	std::cout<<"study english"<<std::endl<<"time:"<<hour<<":"<<minute<<":"<<second<<std::endl<<std::endl;
	return true;
}

bool Study::studyBiology(int &hour, int &minute, int &second)
{
	std::cout<<"study biology"<<std::endl<<"time:"<<hour<<":"<<minute<<":"<<second<<std::endl<<std::endl;
	return true;
}

bool Study::studyComputure(int &hour, int &minute, int &second)
{
	std::cout<<"study computure"<<std::endl<<"time:"<<hour<<":"<<minute<<":"<<second<<std::endl<<std::endl;
	return true;
}

bool Study::studyDataBase(int &hour, int &minute, int &second)
{
	std::cout<<"study database"<<std::endl<<"time:"<<hour<<":"<<minute<<":"<<second<<std::endl<<std::endl;
	return true;
}

bool Study::studyCPlusPlus(int &hour, int &minute, int &second)
{
	std::cout<<"study cplusplus"<<std::endl<<"time:"<<hour<<":"<<minute<<":"<<second<<std::endl<<std::endl;
	return true;
}

bool Study::onCommand(int &hour, int &minute, int &second)
{
	DataStudy *mystudyList = this->getCommandStudy();
	
	if(NULL != mystudyList)
	{
		for(int i = 0; i < STUDYMAX; i ++)
		{
			(this->*mystudyList[i].commandhandler)(hour, minute, second);
		}
	}
	return true;
}

Study::DataStudy* Study::getCommandStudy()
{
	static DataStudy setDataStudy[] =
	{
		{"history"   , &Study::studyHistory   },
		{"math"      , &Study::studyMath      },
		{"english"   , &Study::studyEnglish   },
		{"biology"   , &Study::studyBiology   },
		{"computure" , &Study::studyComputure },
		{"database"  , &Study::studyDataBase  },
		{"cplusplus" , &Study::studyCPlusPlus },
	};

	return &setDataStudy[0];
}

int main()
{
	int hour = 0, minute = 0, second = 0;
	std::cin >> hour >> minute >> second;

	Study::StudyInstance().onCommand(hour, minute, second);


	system("pause");
	return 0;
}