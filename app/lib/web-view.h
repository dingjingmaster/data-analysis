//
// Created by dingjing on 2/14/25.
//

#ifndef data_analysis_WEB_VIEW_H
#define data_analysis_WEB_VIEW_H
#include <QDomDocument>
#include <QWebEngineView>


class WebViewPrivate;
class WebView : public QWebEngineView
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(WebView);
public:
    WebView(const WebView &other);
    explicit WebView(const QString& name, const QString& baseUrl, QWidget *parent=nullptr);
    ~WebView() override;
    bool operator==(const WebView& other) const;

    const QString& name() const;
    const QString& baseUrl() const;
    const QString& getHTMLLocalFile() const;

    // 开始获取页面内容
    void run();

    // 获取成功后，首先执行这个解析方法
    virtual void rootParser(const QDomDocument& doc);

    // 临时保存解析到的内容
    void insertKeyValue(const QString& key, const QVariant& value);

    const QMap<QString, QVariant>& getKeyValue() const;

private Q_SLOTS:
    void onHtmlDownloaded();

Q_SIGNALS:

private:
    WebViewPrivate*             d_ptr = nullptr;
};

inline uint qHash(const WebView& w, const uint seed=0)
{
    return qHash(w.name(), seed);
}


#endif // data_analysis_WEB_VIEW_H
