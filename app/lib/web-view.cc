//
// Created by dingjing on 2/14/25.
//

#include "web-view.h"

class WebViewPrivate
{
    Q_DECLARE_PUBLIC(WebView);
public:
    explicit WebViewPrivate(WebView* q);
    ~WebViewPrivate();

private:
    WebView*                q_ptr = nullptr;
    QWebEnginePage*         mPage = nullptr;

    QString                 mUrl;
    QString                 mName;
};

WebViewPrivate::WebViewPrivate(WebView * q)
    : q_ptr(q), mPage(new QWebEnginePage(q)), mUrl("")
{
}

WebViewPrivate::~WebViewPrivate()
{
    delete mPage;
}

WebView::WebView(const WebView & other)
{
    Q_D(WebView);
    d->mName = other.name();
    d->mUrl = other.baseUrl();
    d->mPage->setUrl(d->mUrl);
}

WebView::WebView(const QString& name, const QString& baseUrl, QWidget * parent)
    : QWebEngineView(parent), d_ptr(new WebViewPrivate(this))
{
    Q_D(WebView);
    d->mUrl = baseUrl;
    d->mName = name;
    setPage(d->mPage);
    d->mPage->setUrl(d->mUrl);

    connect(d->mPage, &QWebEnginePage::loadFinished, this, [&] (bool res) {
        if (res) {Q_EMIT pageLoadSucceed(QPrivateSignal());} else {Q_EMIT pageLoadFailed(QPrivateSignal());}
    });
}

WebView::~WebView()
{
    delete d_ptr;
}

bool WebView::operator==(const WebView& other) const
{
    Q_D(const WebView);

    return d->mName == other.name();
}

const QString & WebView::name() const
{
    Q_D(const WebView);

    return d->mName;
}

const QString & WebView::baseUrl() const
{
    Q_D(const WebView);

    return d->mUrl;
}

QWebEnginePage * WebView::page() const
{
    Q_D(const WebView);

    return d->mPage;
}
