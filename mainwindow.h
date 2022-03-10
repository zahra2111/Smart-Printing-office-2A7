#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employee.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_annulerajout_clicked();

    void on_Ajouteraff_clicked();

    void on_confirmerajout_clicked();

    void on_quittermodif_clicked();

    void on_Quitteraff_clicked();

    void on_quitterajout_clicked();

    void on_annulermodif_clicked();

    void on_Ajouteraff_2_clicked();

    void on_confirmermodif_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_stackedWidget_currentChanged(int arg1);

    void on_quitterajout_2_clicked();

    void on_confirsupp_clicked();

    void on_Suppaff_2_clicked();

private:
    Ui::MainWindow *ui;
    Employee emp;
    int mref;
};
#endif // MAINWINDOW_H
