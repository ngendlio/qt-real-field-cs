#ifndef CLIENT_H
#define CLIENT_H

//#include <QDialog>
#include <QTcpSocket>
#include <QtCore>

//class QDialogButtonBox;
//class QLabel;
//class QLineEdit;
//class QPushButton;
class QTcpSocket;
class QNetworkSession;

class Client : public QObject
{
    Q_OBJECT

public:
    Client();
    Q_INVOKABLE void sendMessage(const QString &msg);
    Q_INVOKABLE void sendImage(const QByteArray &image);
    Q_INVOKABLE QByteArray loadPhoto(const QString &uName);
    Q_INVOKABLE QByteArray loadImage();


public slots:
    void readMessage();
    void sendMessageSlot();

signals:
    void login(QString errorMessage);
    void loginSuccess();
    void loginFailed();

    void gameList(QStringList list, int size);
    void gameCreateSuccess(QString gameId, int gameTime, int noOfTeamA, int noOfTeamB);
    void gameCreateFailed(QString error);
    void joinGameInfo(QString gameId, int gameTime, int noOfTeamA, int noOfTeamB, QString joinUserName);
    void leaveGameInfo(QString gameId, int gameTime, int noOfTeamA, int noOfTeamB, QString leaveUserName);
    void teamJoined(QString gameId);
    void startGame();
    void leaveGame();
    void gameAbort();

    void gameEnd(QString winner);
    void gameUpdate(QString gameId, int gameTime, int noOfTeamALeft, int noOfTeamBLeft,
                    QString killer, QString beKilledOne, bool isSelfKilled);
    void onTarget(bool isShot, QString uName);




private slots:
    //void connectto();
    void displayError(QAbstractSocket::SocketError socketError);
    void enablereadLineButton();
    void enablesendLineButton();
    void enableconnectButton();
    void sessionOpened();
    void connected();

private:
    /*QLabel *hostLabel;
    QLabel *portLabel;
    QLineEdit *hostLineEdit;
    QLineEdit *portLineEdit;
    QLabel *statusLabel;
    QPushButton *connectButton;
    QPushButton *readLineButton;
    QPushButton *sendLineButton;
    QPushButton *quitButton;
    QDialogButtonBox *buttonBox;*/

    QTcpSocket *tcpSocket;
    QString currentMessage;
    quint16 blockSize;
    QByteArray photo;
    void connectto();
    QNetworkSession *networkSession;
    QString userName;

    QString gameId;
    int noOfTeamA;
    int noOfTeamB;
    int gameTime;
};

#endif
