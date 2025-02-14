//
// Created by dingjing on 2/14/25.
//

#ifndef data_analysis_DAEMON_H
#define data_analysis_DAEMON_H
#include <QObject>

class DaemonPrivate;
class Daemon final : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Daemon)
public:
    explicit Daemon(QObject *parent = nullptr);
    ~Daemon() override;

    bool init();
    void run();

private:
    DaemonPrivate*              d_ptr;
};



#endif // data_analysis_DAEMON_H
