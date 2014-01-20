#ifndef MYPAGE_H
#define MYPAGE_H

#include <QWebPage>

class MyPage : public QWebPage
{
    Q_OBJECT

public:
    MyPage(QObject *parent = 0);
protected:
    void javaScriptConsoleMessage(const QString& message, int lineNumber, const QString& sourceID);
};

#endif // MYPAGE_H
