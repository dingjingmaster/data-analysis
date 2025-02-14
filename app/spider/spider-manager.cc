//
// Created by dingjing on 2/14/25.
//

#include "spider-manager.h"

#include "macros/macros.h"


class SpiderManagerPrivate
{
    Q_DECLARE_PUBLIC(SpiderManager)
public:
    explicit SpiderManagerPrivate(SpiderManager* q);

private:
    SpiderManager*              q_ptr;
    QSet<WebView*>              mSpiders;
};

SpiderManagerPrivate::SpiderManagerPrivate(SpiderManager * q)
    : q_ptr(q)
{
}

SpiderManager SpiderManager::gInstance;

SpiderManager & SpiderManager::getInstance()
{
    return gInstance;
}

void SpiderManager::addSpider(WebView* spider)
{
    Q_D(SpiderManager);

    C_RETURN_IF_FAIL(spider);

    d->mSpiders.insert(spider);
}

void SpiderManager::runAllSpiders()
{
    Q_D(SpiderManager);
    for (auto& s : d->mSpiders) {
        s->run();
    }
}

SpiderManager::SpiderManager(QObject* parent)
    : QObject(parent), d_ptr(new SpiderManagerPrivate(this))
{
}

SpiderManager::~SpiderManager()
{
    delete d_ptr;
}
