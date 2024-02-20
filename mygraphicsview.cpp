#include <QGraphicsPixmapItem>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QStringListModel>
#include <QDataStream>
#include <QTableView>
#include <QHeaderView>
#include <QGraphicsView>
#include <QItemSelectionModel>
#include "mygraphicsview.h"

QListView *globalListView;

MyGraphicsView::MyGraphicsView(QListView *listView, QWidget *parent)
    : QGraphicsView(parent), globalListView(listView) {
}

void MyGraphicsView::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/vnd.text.listwidgetitem")) {
        event->acceptProposedAction();
    }
}

void MyGraphicsView::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/vnd.text.listwidgetitem")) {
        event->acceptProposedAction();
    }
}

void MyGraphicsView::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/vnd.text.listwidgetitem")) {
        QByteArray itemData = event->mimeData()->data("application/vnd.text.listwidgetitem");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QString text;
        dataStream >> pixmap >> text;
        //scene()->setSceneRect(0, 0, this->width()-5, this->height()-5);

        const int itemWidth = 64;
        const int itemHeight = 64;
        //const int itemsPerRow = this->width() / itemWidth;

        QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pixmap);
        item->setFlag(QGraphicsItem::ItemIsSelectable, true);
        item->setData(0, text);
        item->setPos(0,0);
        scene()->addItem(item);

        event->acceptProposedAction();
        QStringListModel* model = qobject_cast<QStringListModel*>(globalListView->model());
            if (!model) {
                model = new QStringListModel(this);
                globalListView->setModel(model);
            }
            QStringList list = model->stringList();
            list << text;
            model->setStringList(list);
}
}



void MyGraphicsView::mousePressEvent(QMouseEvent *event) {}
