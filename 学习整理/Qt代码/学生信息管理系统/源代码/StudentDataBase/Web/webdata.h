#ifndef WEBDATA_H
#define WEBDATA_H

#include <QWidget>

namespace Ui {
class WebData;
}

class WebData : public QWidget
{
    Q_OBJECT

public:
    explicit WebData(QWidget *parent = 0);
    ~WebData();

private:
    Ui::WebData *ui;

public :
    void showWeb(QString webUrl);
};

#endif // WEBDATA_H
