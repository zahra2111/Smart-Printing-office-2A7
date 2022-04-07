#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDateEdit>
#include <QPlainTextEdit>
//#include <QPrinter>
//#include <QPrinterInfo>
//#include <QPrintDialog>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <strstream>
#include <QSystemTrayIcon>
#include <QRegExpValidator>
#include <QDesktopServices>
#include <QUrl>
#include <QGuiApplication>
//#include <QQmlApplicationEngine>
#include <QTcpSocket>
//#include <QQuickItem>
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

    void on_tri_asc_clicked();

    void on_tri_desc_clicked();

    void on_lineEditAff_textChanged(const QString &arg1);

    void on_lineEditAff_textEdited(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_CHAT_clicked();

    void on_pushButton_2_clicked();

    void on_notifi_clicked();

private:
    Ui::MainWindow *ui;
    Employee emp;
    int mref;
    QTcpSocket*mSocket;
};
#endif // MAINWINDOW_H
