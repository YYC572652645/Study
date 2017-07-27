#pragma once
#ifndef DetectAlgorithm_API
#define DetectAlgorithm_API  extern "C" __declspec(dllexport)
#endif

typedef void (*CallBackFun)(int step);

#ifndef UNICODE                    // UNICODE 2 need  define this
typedef  char     DATACHAR; 
#else
typedef  wchar_t  DATACHAR;
#endif

//封装QImage数据
struct DAMat
{
	int height;
	int width;
	void* bits;
	int bytesPerLine;
};

//点位坐标数据
struct DAPoint 
{
	float x;
	float y;
};

//返回值，如果为0则出现异常，请检查相关参数
//0.比对图像返回异常位置
//contourType 轮廓类型 
//0 不指定坐标 模板图像区域为图像区域 检测图像为图像区域
//1 模板图像指定多边形（矩形用4个角点表示） 检测图像为图像区域
//2 双矩形，前2点表示模板检测图像感兴趣区域，后2点表示检测图像感兴趣区域
DetectAlgorithm_API int DetectFlaw(
	DAMat imgTemplate,//模板图像
	DAMat imgDetect,//待检测图像
	char** pData,int& dataCount,//缺陷结果 第一层为检测到的匹配数量 第二层一副图像中缺陷个数及在检测图像中的位置
	float densityDiffThr,//亮度差值阈值 如果为-1 则采用自动模式
	float noiseAreaDiffThr,//污点面积阈值 如果为-1 则采用自动模式
	char* pointStr,int pointStrCount,//坐标数据及数据长度 格式为x1,y1;x2,y2......
	int roiType,//感兴趣区域类型
	//检测模板图像 检测图像对应点 格式为x1,y1;x2,y2;x3,y3|xx1,yy1;...... 第一组三个点位为模板图像坐标 第二组往后为检测到的目标图像坐标
	char** pTranformPts,int pTranformPtsCount,
	const CallBackFun opch=NULL,//回调函数地址
	char** pErrMsg=NULL);//错误信息提示字符串