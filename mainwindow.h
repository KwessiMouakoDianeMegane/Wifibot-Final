#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QWebEngineView>
#include <QKeyEvent>
#include "myrobot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots :


    //Connexion
    void connexion();

    //Lancement du mouvement
    void avancer();
    void gauche();
    void droite();
    void reculer();
    void stop();
    void hgauche();
    void bgauche();
    void hdroite();
    void bdroite();

    //Clavier
    void keyPressEvent(QKeyEvent* key_robot);
    void keyReleaseEvent(QKeyEvent* key_robot);




    //Données du robot
    void maj_batterie();
    void on_slide_vitesse_valueChanged(int value);
    void maj_infrarougeAvG();
    void maj_infrarougeAvD();
    void maj_infrarougeArG();
    void maj_infrarougeArD();
    void maj_odometrieD();
    void maj_odometrieG();

    //Collision
    void maj_collision();

    //Boutons connexion et mouvement
    void on_Gauche_pressed();
    void on_avancer_pressed();
    void on_droite_pressed();
    void on_reculer_pressed();
    void on_hgauche_pressed();
    void on_hdroite_pressed();
    void on_bgauche_pressed();
    void on_bdroite_pressed();
    void on_connexion_clicked();
    void on_avancer_released();
    void on_hdroite_released();
    void on_droite_released();
    void on_bdroite_released();
    void on_reculer_released();
    void on_bgauche_released();
    void on_Gauche_released();
    void on_hgauche_released();

    //Mouvements cameras et filtres
    void on_haut_camera_pressed();
    void on_gauche_camera_pressed();
    void on_droite_camera_pressed();
    void on_bas_camera_pressed();

    void cam_haut();
    void cam_bas();
    void cam_gauche();
    void cam_droite();
    void cam_stop();
    void cam_filtre(int valeur);
    void cam_reset();



private:

    //Affichage camera
    QWebEngineView *view;
    //Mouvement camera
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    //Robot
    MyRobot* robot;


    //Pour le calcul de la vitesse
    int m_odo_droite;
    int m_odo_gauche;
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
