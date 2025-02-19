//
// Created by dingjing on 2/14/25.
//

#include "web-view.h"

#include <QTimer>
#include <QDomDocument>
#include <QTemporaryDir>
#include <macros/macros.h>

#include "html-parser/cxx/document.h"


class WebViewPrivate
{
    Q_DECLARE_PUBLIC(WebView);
public:
    explicit WebViewPrivate(WebView* q);
    ~WebViewPrivate();
    void downloadHTML() const;

private:
    WebView*                q_ptr = nullptr;
    QWebEnginePage*         mPage = nullptr;

    QString                 mUrl;
    QString                 mName;
    html::Document          mParser;
    QTemporaryDir           mTempDir;
    QString                 mCurHtmlFile;
    QTimer*                 mCurHtmlFileTimer;
    QMap<QString, QVariant> mKV;
};

WebViewPrivate::WebViewPrivate(WebView * q)
    : q_ptr(q), mPage(new QWebEnginePage(q)), mUrl(""), mCurHtmlFileTimer(new QTimer)
{
    mTempDir.setAutoRemove(true);
    mCurHtmlFile = mTempDir.path() + "/index.html";
    mCurHtmlFileTimer->setInterval(100);
}

WebViewPrivate::~WebViewPrivate()
{
    delete mPage;
    mTempDir.remove();
}

void WebViewPrivate::downloadHTML() const
{
    mPage->save(mCurHtmlFile, QWebEngineDownloadItem::SingleHtmlSaveFormat);
    mCurHtmlFileTimer->start();
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
    setContextMenuPolicy(Qt::NoContextMenu);

    connect(d->mCurHtmlFileTimer, &QTimer::timeout, this, &WebView::onHtmlDownloaded);

    connect(d->mPage, &QWebEnginePage::loadFinished, this, [d, this] (const bool res) ->void {
        if (res) {
            d->downloadHTML();
        }
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

void WebView::run()
{
    Q_D(WebView);

    d->mPage->setUrl(d->mUrl);
}

void WebView::rootParser(html::Document& doc)
{
    qWarning() << "WebView::rootParser";
}

void WebView::insertKeyValue(const QString& key, const QVariant& value)
{
    Q_D(WebView);
    C_RETURN_IF_OK(key.isNull() || key.isEmpty());

    d->mKV[key] = value;
}

const QMap<QString, QVariant> & WebView::getKeyValue() const
{
    Q_D(const WebView);

    return d->mKV;
}

void WebView::onHtmlDownloaded()
{
    Q_D(WebView);

    if (!QFile::exists(d->mCurHtmlFile)) { return; }
    d->mCurHtmlFileTimer->stop();

    QFile f(d->mCurHtmlFile);
    if (!f.open(QIODevice::ReadOnly)) {
        qInfo() << "Failed to open file" << d->mCurHtmlFile << " error: " << f.errorString();
        return;
    }
    d->mParser.parse(f.readAll().toStdString());
    f.close();

    rootParser(d->mParser);

    qInfo() << "Done!";
}

const QString& WebView::getHTMLLocalFile() const
{
    Q_D(const WebView);

    return d->mCurHtmlFile;
}
