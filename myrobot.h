#ifndef MYROBOT_H
#define MYROBOT_H

#include <QObject>
//On inclut le module network dans le fichier .pro
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QTimer>
#include <QMutex>

class MyRobot : public QObject {
    Q_OBJECT
public:
    explicit MyRobot(QObject *parent = 0);  //MyTcpClient (ancien nom sur le fichier original)
    void doConnect();
    void disConnect();
    void move(int cas);
    void move_xbox();
    void set_vitesse(int valeur);
    void set_etat(int valeur);
    void set_manette(bool valeur);
    void set_xbox_x(double valeur);
    void set_xbox_y(double valeur);
    int get_vitesse();


    //short Crc16(unsigned char *Adresse_tab , unsigned char Taille_max);
    qint64 Crc16(QByteArray Adresse_tab , int Taille_max);
    QByteArray DataToSend;
    QByteArray DataReceived;
    QMutex Mutex;

signals:
    void updateUI(const QByteArray Data);
public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
    void MyTimerSlot();

private:
    QTcpSocket *socket;
    QTimer *TimerEnvoi;
    int m_vitesse;  //vitesse actuelle
    int m_etat; //etats : avancer/aller à gauche...
    //Pour la manette
    bool m_manette;    //Si true : L'utilisateur utilise la manette
    double m_xbox_x;
    double m_xbox_y;
};

#endif // MYROBOT_H
