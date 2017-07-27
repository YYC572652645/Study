#ifndef GLOBALDEF_H
#define GLOBALDEF_H

/***************************************************************
   功能:定义变量

   创建人:殷宇辰

   创建时间:2017-6-20
**************************************************************/

#include <QString>
#include <QPoint>
#include <QColor>

#define INITEVENT(event)   (event)                                                    //去除event未使用的警告
#define REDCOLOR           QColor(255, 0, 0)                                          //红色
#define CHENGCOLOR         QColor(255, 156, 0)                                        //橙色
#define YELLOWCOLOR        QColor(255, 255, 0)                                        //黄色
#define GREENCOLOR         QColor(0, 255, 0)                                          //绿色
#define CYANCOLOR          QColor(0, 255, 255)                                        //青色
#define BLUECOLOR          QColor(0, 0, 255)                                          //蓝色
#define PURPLECOLOR        QColor(255, 0, 255)                                        //紫色#CD96CD
#define DARKREDCOLOR       QColor(128, 0, 0)                                          //深红色
#define NOCOLOR            QColor(0, 0, 0, 0)                                         //透明色

const static int     WHITEPIXEL = 4294967295;                                         //白色像素
const static int     BLACKPIXEL = 4278190080;                                         //黑色像素
const static int     WHEELMOVETIME = 30;                                              //滚轮每次移动
const static int     COLORCOUNT = 4;                                                  //点的个数
const static int     POINTCOUNT = 40;                                                 //连续点的个数
const static QColor  BLANKPIXEL = QColor(0, 0, 0);                                    //空白区域像素
const static int     PENWIDTH = 2;                                                    //画笔宽度
const static int     DRAWTIME = 2;                                                    //目的为了求画图起始点
const static int     TIMEINTERNAL = 600;                                              //0.6秒切换一次图片
const static float   INITZOOMFACTOR = 0.2f;                                           //初始放大倍数
const static float   PDFZOOMFACTOR = 5.894f;                                          //PDF放大倍数
const static float   NORMALINITZOOMFACTOR = 0.6f;                                     //图片正常初始放大倍数
const static float   ZOOMINMAX = 2.0f;                                                //图片最大放大倍数
const static float   ZOOMOUTMIN = 0.2f;                                               //图片最小缩小倍数
const static float   ZOOMINFACTOR = 0.1f;                                             //图片每次放大10%
const static float   ZOOMOUTCUTRSOR = 0.4f;                                           //鼠标样式缩小40%
const static float   MOVEFACTOR = 0.5f;                                               //图片移动系数
const static int     ROTATEANGEL270 = 270;                                            //旋转270度
const static int     ROTATEANGEL90 = 90;                                              //旋转90度
const static int     MAXPOINTVALUE = 5;                                               //在点的周围一个范围
const static int     MINPOINTVALUE = -5;                                              //在点的周围一个范围
const static int     WIDTHVALUE = 100;                                                //结果图补偿值
const static int     HEIGHTVALUE = 500;                                               //结果图补偿值
const static int     OUTPUTVALUE = 40;                                                //输出结果图补偿值
const static int     MAXPDFPAGE = 10;                                                 //pdf最大页数
const static float   TWOTIME = 1.5f;                                                  //两倍
const static QPoint  INVALIDPOINT = QPoint(0, 0);                                     //初始化值
const static QPoint  ADDXPOINT = QPoint(10, 0);                                       //加x坐标，用来移动图片
const static QPoint  ADDYPOINT = QPoint(0, 10);                                       //加y坐标，用来移动图片
const static QPoint  COMPENSATEPOINT = QPoint(10, 65);                                //补偿点
const static QPoint  CURSORMOVEPOINT = QPoint(18, 101);                               //鼠标移动补偿点
const static QString ZOOMINIMAGEPATH = ":/image/res/zoom_in.png";                     //放大图标
const static QString ZOOMOUTIMAGEPATH = ":/image/res/zoom_out.png";                   //缩小图标
const static QString OKIMAGEPATH = ":/image/res/ok.png";                              //成功笑脸图片
const static QString FAILIMAGEPATH = ":/image/res/fail.png";                          //失败哭脸图片
const static QString ICONPATH = ":/image/res/LOGO.png";                               //软件LOGO
const static QString STARTSHOWIMAGE = "STARTSHOWIMAGE";                               //给出一个任意路径
const static QString SPLITTERSTYLESHEET = "QSplitter::handle{background-color:gray}"; //分割条样式表
const static QString STYLESHEETBLUE ="background-color:rgb(39, 72 ,98);";             //主题风格蓝
const static QString STYLESHEETLIGHT ="background-color:rgb(222, 222 ,222);";         //主题风格亮
const static QString STYLESHEETGRAY ="background-color:rgb(0, 0 ,0);";                //主题风格暗
const static QString CHINESEQMPATH =":/languag/language/chinese.qm";                  //中文国际化文件
const static QString ENGLISHQMPATH =":/languag/language/english.qm";                  //英文国际化文件
const static char    SPLITSTRING = '|' ;                                              //图片转字符串分隔符

/******************************************************************************
    CONTOURTYPE 轮廓类型
    0 不指定坐标 模板图像区域为图像区域 检测图像为图像区域（一对多，一对一）
    1 模板图像指定多边形（矩形用4个角点表示） 检测图像为图像区域（一对多，一对一）
    2 双矩形，前2点表示模板检测图像感兴趣区域，后2点表示检测图像感兴趣区域
******************************************************************************/
enum CONTOURTYPE
{
    NOPOINTTYPE,      //不指定坐标
    RECTPOINTTYPE,    //多边形检测
    DOUBLERECTTYPE,   //双矩形检测
};


//图的类型
enum IMAGETYPE
{
    SOURCEIMAGE,     //源图
    RESULTIMAGE,     //结果图
    IMAGEMAX,        //最大值
};

//一对多画图的类型
enum DRAWTYPE
{
    WIDTHTYPE,     //横向画图
    HEIGHTTYPE,    //纵向画图
    ALLTYPE,       //横纵向
};

//颜色组合
enum COLORGROUP
{
    ZERO = 0,
    ONE = 1,
    TWO = 2,
    THREE = 5,
    FOUR = 10,
    FIVE = 3,
    SIX = 6,
    SEVEN = 11,
    EIGHT = 7,
    NINE = 12,
    TEN = 15,
    ELEVEN = 8,
    TWELVE = 13,
    THIRTEEN = 16,
    FOURTEEN = 17,
    FIFTEEN =18,
};

//颜色值
enum COLORVALUE
{
    INVALID = 0,
    CYAN = 1,
    MAGANT = 2,
    YELLOW = 5,
    BLACK = 10,
};

//语言
enum LANGUAGE
{
    CHINESE,
    ENGLISH,
};


//窗口
enum WIDGETTYPE
{
    SOURCEWIDGET,    //源窗口
    TARGETWIDGET,    //目标窗口
    RESULTWIDGET,    //结果窗口
    ALLWIDGET,       //所有窗口
    MAXWIDGET,       //最大值
};

//主题
enum THEMESTYLE
{
    THEMEBLUE,       //蓝色主题
    THEMELIGHT,      //亮色主题
    THEMEGRAY,       //灰色主题
};

//进度
enum RATE
{
    RATE20 = 20,     //进度20
    RATE80 = 80,     //进度80
    RATE100 = 100,   //进度100
};

//画笔颜色
enum PENCOLOR
{
    REDPENCOLOR,
    CHENGPENCOLOR,
    YELLOWPENCOLOR,
    GREENPENCOLOR,
    CYANPENCOLOR,
    BLUEPENCOLOR,
    PURPLEPENCOLOR,
};

//工具栏选中情况
enum OPERTOOL
{
    RECTOPER,
    POLYGONOPER,
    MOVEOPER,
    ZOOMINOPER,
    ZOOMOUTOPER,
};

//图片像素
enum PIXELTYPE
{
    BLACKPIXELCOLOR, //黑色像素
    WHITEPIXELCOLOR, //白色像素
};

//图片路径
typedef struct FileName
{
    QString sourceImageFileName;
    QString targetImageFileName;
}FileName;

//CMYK数据
typedef struct DataCmyk
{
    DataCmyk():cyanState(CYAN), magantState(MAGANT), yellowState(YELLOW), blackState(BLACK){}

    int cyanState;
    int magantState;
    int yellowState;
    int blackState;
}DataCmyk;

//CMYK数据
typedef struct ColorCmyk
{
    ColorCmyk():doubleCyan(0), doubleMagenta(0), doubleYellow(0), doubleBlack(0){}

    double doubleCyan;
    double doubleMagenta;
    double doubleYellow;
    double doubleBlack;
}ColorCmyk;

#endif // GLOBALDEF_H
