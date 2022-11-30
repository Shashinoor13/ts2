#ifndef BOOKNOW_H
#define BOOKNOW_H

#include <QDialog>
#include<QSqlTableModel>
#include<QSql>
#include<QSqlDatabase>

namespace Ui {
class BookNow;
}

class BookNow : public QDialog
{
    Q_OBJECT

public:
    explicit BookNow(QWidget *parent = nullptr);
    ~BookNow();



private slots:

    void on_ContactUs_PushButton_clicked();

    void on_home_clicked();



    void on_see_Companies_clicked();

    void on_book_button_clicked();

private:
    Ui::BookNow *ui;
};

#endif // BOOKNOW_H
