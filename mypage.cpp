#include "mypage.h"
#include <iostream>

MyPage::MyPage(QObject *parent) : QWebPage(parent) {}

void MyPage::javaScriptConsoleMessage (const QString& message, int lineNumber, const QString& sourceID) {
   QString logEntry = message + "\t\t" + sourceID + ":" + QString::number(lineNumber);
   std::cout << logEntry.toStdString() << std::endl;
}
