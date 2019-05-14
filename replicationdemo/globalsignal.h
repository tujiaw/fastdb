#pragma once

#include <QObject>

class GlobalSignal : public QObject
{
    Q_OBJECT

public:
    static GlobalSignal* instance();
    
signals:
    void sigFastdbLog(const QString &);
};
