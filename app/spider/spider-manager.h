//
// Created by dingjing on 2/14/25.
//

#ifndef data_analysis_SPIDER_MANAGER_H
#define data_analysis_SPIDER_MANAGER_H
#include <QObject>

#include "lib/web-view.h"


class SpiderManagerPrivate;
class SpiderManager final : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(SpiderManager)
public:
    SpiderManager& operator=(const SpiderManager&)=delete;
    SpiderManager(const SpiderManager&)=delete;
    static SpiderManager& getInstance();

    void addSpider(WebView* spider);
    void runAllSpiders();

private:
    explicit SpiderManager(QObject* parent=nullptr);
    ~SpiderManager() override;

private:
    static SpiderManager                gInstance;
    SpiderManagerPrivate*               d_ptr;
};



#endif // data_analysis_SPIDER_MANAGER_H
