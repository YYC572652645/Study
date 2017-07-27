#include<iostream>

#define DATASIZE 100

enum StudySubject
{
	STUDYHISTORY,
	STUDYMATH,
	STUDYENGLISH,
	STUDYBIOLOGY,
	STUDYCOMPUTURE,
	STUDYDATABASE,
	STUDYCPLUSPLUS,


	STUDYMAX,
};

class Study
{
public:
		static Study  & StudyInstance();

		bool onCommand(int &hour, int &minute, int &second);
private:
	Study();

	~Study();

	bool studyHistory(int &hour, int &minute, int &second);

	bool studyMath(int &hour, int &minute, int &second);

	bool studyEnglish(int &hour, int &minute, int &second);

	bool studyBiology(int &hour, int &minute, int &second);

	bool studyComputure(int &hour, int &minute, int &second);

	bool studyDataBase(int &hour, int &minute, int &second);

	bool studyCPlusPlus(int &hour, int &minute, int &second);


	/*************************************************************************************************/

	typedef bool (Study::*CommandFunc)(int &hour, int &minute, int &second);

	typedef struct DataStudy
	{
		char studyName[DATASIZE];
		CommandFunc commandhandler;
	}DataStudy;

	DataStudy *getCommandStudy();
};