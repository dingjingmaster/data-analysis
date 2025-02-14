//
// Created by dingjing on 2/14/25.
//

#ifndef data_analysis_EAST_MONEY_H
#define data_analysis_EAST_MONEY_H
#include "lib/web-view.h"


class EastMoney final : public WebView
{
    Q_OBJECT
public:
    explicit EastMoney(QWidget *parent = nullptr);
    ~EastMoney() override;

    void rootParser(const QDomDocument& doc) override;
};



#endif // data-analysis_EAST_MONEY_H
