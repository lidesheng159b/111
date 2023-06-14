#pragma once
#include <qstandarditemmodel.h>
#include <QtWidgets/QMainWindow>
#include "ui_IMGPro.h"
#include "Drawing.h"
//#pragma execution_character_set("utf-8")    // ��������������⣬ע�⣡����
class IMGPro : public QMainWindow
{
    Q_OBJECT

public:
    IMGPro(QWidget *parent = nullptr);
    ~IMGPro();
    void InitSource();//���ڳ�ʼ�����ͼ��
private:
    Ui::IMGProClass ui;//�����ui��IMGPro.ui��ϵ������
    QTreeView* treeView; // ���һ��QTreeView��Ա
    //DrawingContext drawingContext;//���һ��ͼ�������Ķ���

private slots:  //qt�������﷨��д�ۺ���Ҫ������
    //void slot_try1();//���Բۺ���
    void on_treeView_customContextMenuRequested(const QPoint& pos);
    

public slots:
    void showErrorDialog(const QString& errorMessage);
    void setStateInMain1();

signals:
    //void try1(int b);     // �����ź�
private: 
    QMenu* menu;//�˵�����ָ�룬������ʾͼ������������Ĳ˵�
    QStandardItemModel* model;//����ģ�Ͷ���ָ�룬���ڹ���ͼ������
    QStandardItem* rootItem1;//ͼ���ļ���1
    QStandardItem* rootItem2;//ͼ���ļ���2


};
