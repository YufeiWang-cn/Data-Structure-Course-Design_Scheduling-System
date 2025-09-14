#ifndef COURSEMAP_H
#define COURSEMAP_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGridLayout>
#include <QtGui>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include <QScrollArea>
#include <QScrollBar>
#include "node.h"
#include "edge.h"
#include "Graphl.h"

namespace Ui {
class courseMap;
}

class courseMap : public QGraphicsView
{
    Q_OBJECT

public:
    explicit courseMap(QWidget *parent = nullptr, QString name = "");
    ~courseMap();

private:
    Ui::courseMap *ui;
};

#endif // COURSEMAP_H
