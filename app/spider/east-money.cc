//
// Created by dingjing on 2/14/25.
//

#include "east-money.h"

#include <unistd.h>

EastMoney::EastMoney(QWidget * parent)
    : WebView("EastMoney", "https://fund.eastmoney.com/", parent)
{

}

EastMoney::~EastMoney()
{
}

void EastMoney::rootParser(html::Document& doc)
{
    qDebug() << "EastMoney::rootParser";

    auto select = doc.find("aa");
}

#if 0
void EastMoney::rootParser(const QDomDocument& doc)
{
    qDebug() << "EastMoney::rootParser: ";

    const auto rootDOM = doc.documentElement();
    qInfo() << rootDOM.tagName();
    const auto table = rootDOM.elementsByTagName("body").at(0);
    qInfo() << table.toElement().tagName();
        qInfo() << "0";
    qInfo() << "root DOM: " << table.text();
    if (!table.isNull()) {
        qInfo() << "1";
        const auto tBody1 = table.elementsByTagName("div");
        if (tBody1.length() > 10) {
        qInfo() << "2";
            const auto tBody2 = tBody1.at(9);
            if (!tBody2.isNull()) {
        qInfo() << "3";
                const auto tBody3 = tBody2.toElement().elementsByTagName("div");
                if (tBody3.length() > 2) {
        qInfo() << "4";
                    const auto tBody4 = tBody3.at(1);
                    if (!tBody4.isNull()) {
        qInfo() << "5";
                        const auto tBody5 = tBody4.toElement().elementsByTagName("table");
                        if (!tBody5.isEmpty()) {
                            const auto tBody6 = tBody5.at(0);
                            if (!tBody6.isNull()) {
                                const auto tbody7 = tBody6.toElement().elementsByTagName("tbody");
                                if (!tbody7.isEmpty()) {
                                    const auto trs = tbody7.at(0).childNodes();
                                    for (int i = 0; i < trs.size(); i++) {
                                        auto tr = trs.at(i);
                                        auto tds = tr.childNodes();
                                        if (tds.length() < 14) {
                                            continue;
                                        }
                                        const auto code = tds.at(3).nodeValue();
                                        const auto name = tds.at(4).nodeValue();
                                        const auto newWorth1 = tds.at(5).nodeValue().toFloat();
                                        const auto newWorth2 = tds.at(6).nodeValue().toFloat();
                                        const auto hisWorth1 = tds.at(7).nodeValue().toFloat();
                                        const auto hisWorth2 = tds.at(8).nodeValue().toFloat();
                                        const auto dayGrowValue = tds.at(9).nodeValue().toFloat();
                                        const auto dayGrowRate = tds.at(10).nodeValue().toFloat();
                                        const auto buyStatus = tds.at(11).nodeValue();
                                        const auto sellStatus = tds.at(12).nodeValue().toFloat();
                                        const auto handingCharge = tds.at(13).nodeValue().toFloat();

                                        qInfo() << code << "  " << name << "  " << newWorth1 << "  " << newWorth2 << "  " << hisWorth1 << "  " << hisWorth2 << "  " << dayGrowValue << "  " << dayGrowRate << "  " << buyStatus << "  " << sellStatus << "  " << handingCharge;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
#endif

