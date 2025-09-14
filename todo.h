#ifndef TODO_H
#define TODO_H

#include <QWidget>

namespace Ui {
class todo;
}

class todo : public QWidget
{
    Q_OBJECT

public:
    explicit todo(QWidget *parent = nullptr);
    ~todo();
    Ui::todo *ui;

private:
};

#endif // TODO_H
