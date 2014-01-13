#include <QApplication>
#include "html5applicationviewer.h"
#include <QWebInspector>
#include <QGraphicsWebView>
#include <QCoreApplication>
#include <QRegularExpression>

#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Html5ApplicationViewer viewer;
    viewer.setOrientation(Html5ApplicationViewer::ScreenOrientationAuto);
    viewer.showExpanded();
    viewer.showMaximized();

    std::cout << qWebKitVersion().toStdString() << std::endl;

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

    viewer.loadFile(QLatin1String("html/index.html"));

    return app.exec();
}
