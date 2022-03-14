/*
#include <QApplication>
#include "chatwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChatWindow chatWin;
    chatWin.show();
    return a.exec();
}
*/

#include <qrsaencryption.h>
#include <QDebug>

bool testEncryptAndDecryptExample() {

    QByteArray pub, priv;
    QRSAEncryption e(QRSAEncryption::Rsa::RSA_2048);
    e.generatePairKey(pub, priv); // or other rsa size

    QByteArray msg = "test message";

    auto encryptMessage = e.encode(msg, pub);

    if (encryptMessage == msg)
        return false;

    auto decodeMessage = e.decode(encryptMessage, priv);

    return decodeMessage == msg;
}

int main() {
    if (testEncryptAndDecryptExample()) {
        qInfo() << "Success!";
    }
    return 0;
}
