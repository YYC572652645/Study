#ifndef MAINOBJECT_H
#define MAINOBJECT_H

#include <QObject>

class RadarWindow;


class MainObject : public QObject
{
    Q_OBJECT
public:
    explicit MainObject(QObject *parent = 0);
    ~MainObject();

public :
    void setInit();//初始化

private:
    RadarWindow *m_mainWindow;

};

#endif // MAINOBJECT_H
