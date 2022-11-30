#ifndef LOGIN2_H
#define LOGIN2_H

#include <QDialog>

namespace Ui {
class login2;
}

class login2 : public QDialog
{
    Q_OBJECT

public:
    explicit login2(QWidget *parent = nullptr);
    ~login2();

private slots:
    void on_Login_clicked();

    void on_Register_clicked();

private:
    Ui::login2 *ui;
};

#endif // LOGIN2_H
