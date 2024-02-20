#include "mylistwidget.h"


MyListWidget::MyListWidget(QWidget *parent) : QListWidget(parent) {
    setDragEnabled(true);
    setAcceptDrops(true);
    setDropIndicatorShown(true);
    addIconsWithLabels();
}

void MyListWidget::addIconsWithLabels()
{
    QListWidgetItem *item1 = new QListWidgetItem(QIcon(":/img/img/green.jpg"), "Зеленый");
    this->addItem(item1);

    QListWidgetItem *item2 = new QListWidgetItem(QIcon(":/img/img/red.jpg"), "Красный");
    this->addItem(item2);

    QListWidgetItem *item3 = new QListWidgetItem(QIcon(":/img/img/orange.jpg"), "Оранжевый");
    this->addItem(item3);

    QListWidgetItem *item4 = new QListWidgetItem(QIcon(":/img/img/blue.png"), "Синий");
    this->addItem(item4);

    QListWidgetItem *item5 = new QListWidgetItem(QIcon(":/img/img/yellow.png"), "Желтый");
    this->addItem(item5);
}


void MyListWidget::mousePressEvent(QMouseEvent *event) {
    QListWidget::mousePressEvent(event);

    if (event->button() != Qt::LeftButton) return;

    QListWidgetItem *item = itemAt(event->pos());
    if (!item) return;

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    QPixmap pixmap = item->icon().pixmap(32, 32);
    QString text = item->text();
    dataStream << pixmap << text;

    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/vnd.text.listwidgetitem", itemData);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(QPoint(0, 0));
    drag->exec(Qt::CopyAction | Qt::MoveAction);
}


