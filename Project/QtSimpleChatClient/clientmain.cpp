#include <QApplication>
#include "chatwindow.h"
#include <qrsaencryption.h>
#include <QDebug>
#include <QTextCodec>
#include <QString>


int main(int argc, char** argv) {
    QApplication a(argc, argv);
    ChatWindow chatWin;
    chatWin.show();


    return a.exec();
}
