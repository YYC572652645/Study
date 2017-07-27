#-------------------------------------------------
#
# Project created by QtCreator 2017-06-24T15:47:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = YunNiuProject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    screen/mainobject.cpp \
    screen/splashscreen.cpp \
    MessageBox/messagedialog.cpp \
    version/versiondialog.cpp \
    qreadwrite/qreadwriteini.cpp \
    systemtray/systemtray.cpp \
    setuplanguage/setuplangue.cpp \
    singleton/singleton.cpp \
    mythread/cmykthread.cpp \
    mythread/comparethread.cpp

HEADERS  += mainwindow.h \
    screen/mainobject.h \
    screen/splashscreen.h \
    globaldef.h \
    DetectAlgorithm.h \
    MessageBox/messagedialog.h \
    version/versiondialog.h \
    qreadwrite/qreadwriteini.h \
    systemtray/systemtray.h \
    setuplanguage/setuplangue.h \
    singleton/singleton.h \
    include/libmupdf_global.h \
    include/mupdf-document.h \
    include/mupdf-link.h \
    include/mupdf-outline.h \
    include/mupdf-page.h \
    include/mupdf-qt.h \
    include/mupdf-textbox.h \
    mythread/cmykthread.h \
    mythread/comparethread.h \
    include/opencv/cv.h \
    include/opencv/cv.hpp \
    include/opencv/cvaux.h \
    include/opencv/cvaux.hpp \
    include/opencv/cvwimage.h \
    include/opencv/cxcore.h \
    include/opencv/cxcore.hpp \
    include/opencv/cxeigen.hpp \
    include/opencv/cxmisc.h \
    include/opencv/highgui.h \
    include/opencv/ml.h \
    include/opencv2/aruco.hpp \
    include/opencv2/bgsegm.hpp \
    include/opencv2/bioinspired.hpp \
    include/opencv2/calib3d.hpp \
    include/opencv2/ccalib.hpp \
    include/opencv2/core.hpp \
    include/opencv2/cvconfig.h \
    include/opencv2/dnn.hpp \
    include/opencv2/dpm.hpp \
    include/opencv2/face.hpp \
    include/opencv2/features2d.hpp \
    include/opencv2/flann.hpp \
    include/opencv2/fuzzy.hpp \
    include/opencv2/highgui.hpp \
    include/opencv2/imgcodecs.hpp \
    include/opencv2/imgproc.hpp \
    include/opencv2/line_descriptor.hpp \
    include/opencv2/ml.hpp \
    include/opencv2/objdetect.hpp \
    include/opencv2/opencv.hpp \
    include/opencv2/opencv_modules.hpp \
    include/opencv2/optflow.hpp \
    include/opencv2/phase_unwrapping.hpp \
    include/opencv2/photo.hpp \
    include/opencv2/plot.hpp \
    include/opencv2/rgbd.hpp \
    include/opencv2/saliency.hpp \
    include/opencv2/shape.hpp \
    include/opencv2/stereo.hpp \
    include/opencv2/stitching.hpp \
    include/opencv2/structured_light.hpp \
    include/opencv2/superres.hpp \
    include/opencv2/surface_matching.hpp \
    include/opencv2/text.hpp \
    include/opencv2/tracking.hpp \
    include/opencv2/video.hpp \
    include/opencv2/videoio.hpp \
    include/opencv2/videostab.hpp \
    include/opencv2/xfeatures2d.hpp \
    include/opencv2/ximgproc.hpp \
    include/opencv2/xobjdetect.hpp \
    include/opencv2/xphoto.hpp

FORMS    += mainwindow.ui \
    MessageBox/messagedialog.ui \
    version/versiondialog.ui \
    setuplanguage/setuplangue.ui

RESOURCES += \
    res.qrc

RC_FILE = myapp.rc

LIBS += D:/Program/YunNiuProject/DetectAlgorithm.lib\
        D:/Program/YunNiuProject/lib/x64/libmupdf.lib\
        C:/opencv/x64/vc12/lib\
        C:/opencv/x64/vc12/lib/opencv_aruco320.lib\
        C:/opencv/x64/vc12/lib/opencv_bgsegm320.lib\
        C:/opencv/x64/vc12/lib/opencv_bioinspired320.lib\
        C:/opencv/x64/vc12/lib/opencv_calib3d320.lib\
        C:/opencv/x64/vc12/lib/opencv_ccalib320.lib\
        C:/opencv/x64/vc12/lib/opencv_core320.lib\
        C:/opencv/x64/vc12/lib/opencv_datasets320.lib\
        C:/opencv/x64/vc12/lib/opencv_dnn320.lib\
        C:/opencv/x64/vc12/lib/opencv_dpm320.lib\
        C:/opencv/x64/vc12/lib/opencv_face320.lib\
        C:/opencv/x64/vc12/lib/opencv_features2d320.lib\
        C:/opencv/x64/vc12/lib/opencv_flann320.lib\
        C:/opencv/x64/vc12/lib/opencv_fuzzy320.lib\
        C:/opencv/x64/vc12/lib/opencv_highgui320.lib\
        C:/opencv/x64/vc12/lib/opencv_imgcodecs320.lib\
        C:/opencv/x64/vc12/lib/opencv_imgproc320.lib\
        C:/opencv/x64/vc12/lib/opencv_line_descriptor320.lib\
        C:/opencv/x64/vc12/lib/opencv_ml320.lib\
        C:/opencv/x64/vc12/lib/opencv_objdetect320.lib\
        C:/opencv/x64/vc12/lib/opencv_optflow320.lib\
        C:/opencv/x64/vc12/lib/opencv_phase_unwrapping320.lib\
        C:/opencv/x64/vc12/lib/opencv_photo320.lib\
        C:/opencv/x64/vc12/lib/opencv_plot320.lib\
        C:/opencv/x64/vc12/lib/opencv_reg320.lib\
        C:/opencv/x64/vc12/lib/opencv_rgbd320.lib\
        C:/opencv/x64/vc12/lib/opencv_saliency320.lib\
        C:/opencv/x64/vc12/lib/opencv_shape320.lib\
        C:/opencv/x64/vc12/lib/opencv_stereo320.lib\
        C:/opencv/x64/vc12/lib/opencv_stitching320.lib\
        C:/opencv/x64/vc12/lib/opencv_structured_light320.lib\
        C:/opencv/x64/vc12/lib/opencv_superres320.lib\
        C:/opencv/x64/vc12/lib/opencv_surface_matching320.lib\
        C:/opencv/x64/vc12/lib/opencv_text320.lib\
        C:/opencv/x64/vc12/lib/opencv_tracking320.lib\
        C:/opencv/x64/vc12/lib/opencv_video320.lib\
        C:/opencv/x64/vc12/lib/opencv_videoio320.lib\
        C:/opencv/x64/vc12/lib/opencv_videostab320.lib\
        C:/opencv/x64/vc12/lib/opencv_xfeatures2d320.lib\
        C:/opencv/x64/vc12/lib/opencv_ximgproc320.lib\
        C:/opencv/x64/vc12/lib/opencv_xobjdetect320.lib\
        C:/opencv/x64/vc12/lib/opencv_xphoto320.lib



TRANSLATIONS += english.ts\
                chinese.ts
