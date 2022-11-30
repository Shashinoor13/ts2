#ifndef REGISTEROPTION_H
#define REGISTEROPTION_H

#include <QDialog>

namespace Ui {
class RegisterOption;
}

class RegisterOption : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterOption(QWidget *parent = nullptr);
    ~RegisterOption();

private slots:


    void on_as_a_Company_clicked();

    void on_as_a_User_clicked();

    void on_Home_Icon_clicked();

private:
    Ui::RegisterOption *ui;
};

#endif // REGISTEROPTION_H
