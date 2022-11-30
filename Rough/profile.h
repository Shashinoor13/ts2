#ifndef PROFILE_H
#define PROFILE_H

#include <QDialog>

namespace Ui {
class profile;
}

class profile : public QDialog
{
    Q_OBJECT

public:
    explicit profile(QWidget *parent = nullptr);
    ~profile();

private slots:
    void on_ChangePassword_clicked();

    void on_UpdateInfo_clicked();

    void on_PwdChange_clicked();

private:
    Ui::profile *ui;
};

#endif // PROFILE_H
