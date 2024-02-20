#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H

#include <QListWidget>
#include <QMimeData>
#include <QDrag>
#include <QMouseEvent>

class MyListWidget : public QListWidget {
    Q_OBJECT
public:
    explicit MyListWidget(QWidget *parent = nullptr);

protected:
    void addIconsWithLabels();
    void mousePressEvent(QMouseEvent *event) override;
    void updateListView(const QString &text);

};

#endif
