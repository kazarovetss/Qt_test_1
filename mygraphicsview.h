#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QListWidget>
#include <QMimeData>
#include <QDrag>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QGraphicsView>
#include <QTableView>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include "mylistwidget.h"
class MyGraphicsView : public QGraphicsView {
 Q_OBJECT
public:
explicit MyGraphicsView(QListView *listView, QWidget *parent = nullptr);

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent(QMouseEvent *event);
private:
    QListView *globalListView;
    QTableView *tableView;
    QStandardItemModel *tableModel;
};

#endif
