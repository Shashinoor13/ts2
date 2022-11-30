#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_NamoBuddha_PushButton_clicked();

    void on_Pokhara_PushButton_clicked();

    void on_ThousandStep_PushButton_clicked();

    void on_Chandragiri_PushButton_clicked();







   void on_bookNow_clicked();

    void on_Profile_clicked();



    void on_ContactUs_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
