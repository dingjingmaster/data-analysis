//
// Created by dingjing on 2/14/25.
//

#include "east-money.h"

EastMoney::EastMoney(QWidget * parent)
    : WebView("EastMoney", "https://fund.eastmoney.com/", parent)
{
    connect(this, &EastMoney::pageLoadSucceed, this, [&] () {
        qInfo() << "EastMoney::pageLoadSucceed";
    });

    connect(this, &EastMoney::pageLoadFailed, this, [&] () {
        qInfo() << "EastMoney::pageLoadFailed";
    });
}

EastMoney::~EastMoney()
{
}

void EastMoney::run()
{
    // show();
    qInfo() << "EastMoney::run";
}
