#ifndef HAZARSIDI_H
#define HAZARSIDI_H

#include <QDialog>

namespace Ui {
class hazarsidi;
}

class hazarsidi : public QDialog
{
    Q_OBJECT

public:
    explicit hazarsidi(QWidget *parent = nullptr);
    ~hazarsidi();

private:
    Ui::hazarsidi *ui;
};

#endif // HAZARSIDI_H
