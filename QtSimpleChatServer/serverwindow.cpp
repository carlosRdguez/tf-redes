#include "serverwindow.h"
#include "ui_serverwindow.h"
#include "chatserver.h"
#include <QMessageBox>
ServerWindow::ServerWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServerWindow)
    , m_chatServer(new ChatServer(this))
{
    ui->setupUi(this);
    connect(ui->startStopButton, &QPushButton::clicked, this, &ServerWindow::toggleStartServer);
    connect(m_chatServer, &ChatServer::logMessage, this, &ServerWindow::logMessage);
}

ServerWindow::~ServerWindow()
{
    delete ui;
}

void ServerWindow::toggleStartServer()
{
    if (m_chatServer->isListening()) {
        m_chatServer->stopServer();
        ui->startStopButton->setText(tr("Iniciar Servidor"));
        logMessage(QStringLiteral("Servidor detenido"));
    } else {
        if (!m_chatServer->listen(QHostAddress::Any, 1967)) {
            QMessageBox::critical(this, tr("Error"), tr("No fue posible iniciar el servidor"));
            return;
        }
        logMessage(QStringLiteral("Servidor iniciado"));
        ui->startStopButton->setText(tr("Detener Servidor"));
    }
}

void ServerWindow::logMessage(const QString &msg)
{
    ui->logEditor->appendPlainText(msg + QLatin1Char('\n'));
}
