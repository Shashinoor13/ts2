#ifndef NAMOBUDDHA_H
#define NAMOBUDDHA_H

#include <QDialog>

namespace Ui {
class Namobuddha;
}

class Namobuddha : public QDialog
{
    Q_OBJECT

public:
    explicit Namobuddha(QWidget *parent = nullptr);
    ~Namobuddha();

private:
    Ui::Namobuddha *ui;
};

#endif // NAMOBUDDHA_H
