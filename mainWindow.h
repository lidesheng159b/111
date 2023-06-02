#pragma once
#include <qstandarditemmodel.h>
#include <QtWidgets/QMainWindow>
#include "ui_IMGPro.h"

class IMGPro : public QMainWindow
{
    Q_OBJECT

public:
    IMGPro(QWidget *parent = nullptr);
    ~IMGPro();
    void helloworld();//声明函数
    void InitSource();//用于初始化列表资源
private:
    Ui::IMGProClass ui;//这里把ui和IMGPro.ui联系起来了

    QTreeView* treeView; // 添加一个QTreeView成员

private slots:  //qt的特殊语法，写槽函数要先声明
    void iSlot();//槽函数

    void on_treeView_customContextMenuRequested(const QPoint& pos);
private:
    
    QMenu* menu;
    QStandardItemModel* model;
    QStandardItem* rootItem1;
    QStandardItem* rootItem2;


};
