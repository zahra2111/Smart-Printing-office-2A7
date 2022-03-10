#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "commande.h"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_tabcommande_activated(const QModelIndex &index);

    void on_com_selec_clicked();

    void on_com_retour_clicked();

    void on_com_sup_clicked();

    void on_sup_tt_clicked();

    void on_com_retour_3_clicked();

    void on_com_retour_2_clicked();

private:
    Ui::MainWindow *ui;
    commande c;

};
#endif // MAINWINDOW_H
