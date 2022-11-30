#ifndef POKHARA_H
#define POKHARA_H

#include <QDialog>

namespace Ui {
class Pokhara;
}

class Pokhara : public QDialog
{
    Q_OBJECT

public:
    explicit Pokhara(QWidget *parent = nullptr);
    ~Pokhara();

private:
    Ui::Pokhara *ui;
};

#endif // POKHARA_H
