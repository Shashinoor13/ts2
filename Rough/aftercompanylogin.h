#ifndef AFTERCOMPANYLOGIN_H
#define AFTERCOMPANYLOGIN_H

#include <QMainWindow>

namespace Ui {
class AfterCompanyLogin;
}

class AfterCompanyLogin : public QMainWindow
{
    Q_OBJECT

public:
    explicit AfterCompanyLogin(QWidget *parent = nullptr);
    ~AfterCompanyLogin();

private slots:



    void on_signout_clicked();

    void on_customers_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::AfterCompanyLogin *ui;
};

#endif // AFTERCOMPANYLOGIN_H
