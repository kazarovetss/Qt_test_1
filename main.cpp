#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QListView>
#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>
#include "MyListWidget.h"
#include "mygraphicsview.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Комплексное расположение виджетов");

    QHBoxLayout *mainLayout = new QHBoxLayout;

    QListView *listView = new QListView;

    QListWidget *listWidget = new QListWidget();
    QVBoxLayout *leftLayout = new QVBoxLayout;
    QGraphicsScene *graphicsScene = new QGraphicsScene();
    MyGraphicsView *graphicsView = new MyGraphicsView(listView);
    graphicsScene->setSceneRect(0, 0, graphicsView->width()-2, graphicsView->height()-2);
    graphicsView->setScene(graphicsScene);
    window.resize(800, 600);
    graphicsView->setAcceptDrops(true);
    leftLayout->addWidget(graphicsView, 1);

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    QTableView *tableView = new QTableView;
    bottomLayout->addWidget(listView);
    bottomLayout->addWidget(tableView);
    QStandardItemModel *model = new QStandardItemModel(2, 2); // 2 строки и 2 столбца

    tableView->horizontalHeader()->setVisible(false);
    tableView->verticalHeader()->setVisible(false);
    model->setItem(0, 0, new QStandardItem("x"));
    model->setItem(1, 0, new QStandardItem("y"));
    model->setItem(0, 1, new QStandardItem(QString::number(0)));
    model->setItem(1, 1, new QStandardItem(QString::number(0)));

    tableView->setModel(model);

    leftLayout->addLayout(bottomLayout);

    QGroupBox *groupBox = new QGroupBox("Элементы управления");
    groupBox->setFixedWidth(200);
    QVBoxLayout *groupBoxLayout = new QVBoxLayout(groupBox);
    MyListWidget *myListWidget = new MyListWidget;
    groupBoxLayout->addWidget(myListWidget, 0);


    mainLayout->addLayout(leftLayout, 2);
    mainLayout->addWidget(groupBox, 1);

    window.setLayout(mainLayout);
    window.resize(800, 600);
    window.show();

    return app.exec();
}
