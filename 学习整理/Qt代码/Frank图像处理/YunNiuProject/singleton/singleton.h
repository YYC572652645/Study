#ifndef SINGLETON_H
#define SINGLETON_H
#include <QMutex>
#include <QScopedPointer>
#include <QDebug>

/***************************************************************
   功能:自封装线程安全的单例模式模板类

   创建人:殷宇辰

   创建时间:2017-7-12
**************************************************************/

template <class T>
class Singleton
{
public:
    static T* getInstance()
    {
        static QMutex mutex;               //互斥量
        static QScopedPointer<T> instance; //智能指针QT封装的

        if(Q_UNLIKELY(!instance))
        {
            mutex.lock();

            if(!instance)
            {
                instance.reset(new T);
            }

            mutex.unlock();
        }

        return instance.data();
    }
};

#endif // SINGLETON_H
