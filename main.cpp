#include <QApplication>
#include "html5applicationviewer.h"
#include <QWebInspector>
#include <QGraphicsWebView>
#include <QCoreApplication>
#include <QRegularExpression>
#include <QUrl>
#include <QDebug>
#include <iostream>
#include <QWebFrame>

#include "mypage.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString baseDir = QCoreApplication::applicationDirPath();
#ifdef Q_OS_MAC
    QString indexLocation = QString("html/index.html");
#endif
#ifdef Q_OS_LINUX
    QString indexLocation = baseDir + QString("/html/index.html");
#endif
#ifdef Q_OS_WIN
    QString indexLocation = baseDir + QString("/html/index.html");
#endif
    QString libsLocation = baseDir + QString("/libs");
    QCoreApplication::addLibraryPath(QLatin1String(libsLocation.toStdString().c_str()));

    Html5ApplicationViewer viewer;

    viewer.setOrientation(Html5ApplicationViewer::ScreenOrientationAuto);
    viewer.showExpanded();
    viewer.showMaximized();

    int remoteInspectorPort = 0;
    QRegularExpression re("--inspect=(\\d+)");
    QStringList args = QCoreApplication::arguments();
    QStringList::Iterator it;
    for(it = args.begin(); it != args.end(); it++) {
        QRegularExpressionMatch match = re.match(*it);
        if(match.hasMatch()) {
            remoteInspectorPort = match.captured(1).toInt();
        }
    }

    if (remoteInspectorPort)
            viewer.webView()->page()->setProperty("_q_webInspectorServerPort", remoteInspectorPort);

    viewer.webView()->page()->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);

    QWebInspector *inspector = new QWebInspector();
    inspector->setPage(viewer.webView()->page());
    inspector->setVisible(false);

    viewer.loadFile(QLatin1String(indexLocation.toStdString().c_str()));

    return app.exec();
}
