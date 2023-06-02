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
    void helloworld();//��������
    void InitSource();//���ڳ�ʼ���б���Դ
private:
    Ui::IMGProClass ui;//�����ui��IMGPro.ui��ϵ������

    QTreeView* treeView; // ���һ��QTreeView��Ա

private slots:  //qt�������﷨��д�ۺ���Ҫ������
    void iSlot();//�ۺ���

    void on_treeView_customContextMenuRequested(const QPoint& pos);
private:
    
    QMenu* menu;
    QStandardItemModel* model;
    QStandardItem* rootItem1;
    QStandardItem* rootItem2;


};
