//
// Created by dingjing on 2/14/25.
//

#ifndef data_analysis_WEB_VIEW_H
#define data_analysis_WEB_VIEW_H
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

    QWebEnginePage* page() const;

    virtual void run() {};

Q_SIGNALS:
    void pageLoadFailed(QPrivateSignal);
    void pageLoadSucceed(QPrivateSignal);

private:
    WebViewPrivate*             d_ptr = nullptr;
};

inline uint qHash(const WebView& w, uint seed=0)
{
    return qHash(w.name(), seed);
}


#endif // data_analysis_WEB_VIEW_H
