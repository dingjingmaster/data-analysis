//
// Created by dingjing on 2/14/25.
//

#include "daemon.h"

#include "spider/east-money.h"
#include "spider/spider-manager.h"


class DaemonPrivate
{
    Q_DECLARE_PUBLIC(Daemon);
public:
    explicit DaemonPrivate(Daemon* daemon);

private:
    Daemon*                 q_ptr;
};

DaemonPrivate::DaemonPrivate(Daemon * daemon)
    : q_ptr(daemon)
{
}

Daemon::Daemon(QObject* parent)
    : QObject(parent), d_ptr(new DaemonPrivate(this))
{
}

Daemon::~Daemon()
{
    delete d_ptr;
}

bool Daemon::init()
{
    auto eastMoney = new EastMoney;
    SpiderManager::getInstance().addSpider(eastMoney);

    return true;
}

void Daemon::run()
{
    SpiderManager::getInstance().runAllSpiders();
}
