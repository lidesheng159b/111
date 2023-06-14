#pragma once
#include <qstandarditemmodel.h>
#include <QtWidgets/QMainWindow>
#include "ui_IMGPro.h"
#include "Drawing.h"
//#pragma execution_character_set("utf-8")    // 解决汉字乱码问题，注意！！！
class IMGPro : public QMainWindow
{
    Q_OBJECT

public:
    IMGPro(QWidget *parent = nullptr);
    ~IMGPro();
    void InitSource();//用于初始化左侧图层
private:
    Ui::IMGProClass ui;//这里把ui和IMGPro.ui联系起来了
    QTreeView* treeView; // 添加一个QTreeView成员
    //DrawingContext drawingContext;//添加一个图形上下文对象

private slots:  //qt的特殊语法，写槽函数要先声明
    //void slot_try1();//尝试槽函数
    void on_treeView_customContextMenuRequested(const QPoint& pos);
    

public slots:
    void showErrorDialog(const QString& errorMessage);
    void setStateInMain1();

signals:
    //void try1(int b);     // 尝试信号
private: 
    QMenu* menu;//菜单对象指针，用于显示图层操作的上下文菜单
    QStandardItemModel* model;//数据模型对象指针，用于管理图层数据
    QStandardItem* rootItem1;//图层文件夹1
    QStandardItem* rootItem2;//图层文件夹2


};
