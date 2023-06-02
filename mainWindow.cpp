#include "mainWindow.h"
#include"layerStandardItem.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QtGui>
#include <QtWidgets>
#include <QtWidgets/QApplication>
#include <QtCore/qbytearray.h>
#pragma execution_character_set("utf-8")    // ��������������⣬ע�⣡����
IMGPro::IMGPro(QWidget *parent): QMainWindow(parent)
{
    //setupUi(this) �������ܵ�ǰ���ڶ����ָ����Ϊ�������Ա㽫 UI �����еĿؼ��Ͳ����봰�ڶ������������
    ui.setupUi(this);
    //��ʼ����Դ
    InitSource();
    //this->resize(400, 400);
    helloworld();

    // �����С
    setWindowTitle("ͼ��");

    // ���ͼ��
    setWindowIcon(QIcon("E:/��Ȼ�����/��ͼ���Ҽ�ŭ���޸��棩/1.PNG"));

    // �����С
    resize(QApplication::desktop()->width() * 0.9, QApplication::desktop()->height() * 0.9);
    move(QApplication::desktop()->width() * 0.05, QApplication::desktop()->height() * 0.01);

    // ��һ���˵�
    QMenu* menu1 = menuBar()->addMenu(tr("��ȡ�ļ�"));
    // �����Ӳ˵�����һ������QIconΪ���ͼ�꣬ע��·���Ƿ���ȷ���ڶ����������Ӳ˵�����ʾ�ı�
    QAction* act1_1 = new QAction(QIcon("E:/��Ȼ�����/��ͼ���Ҽ�ŭ���޸��棩/1.PNG"), tr("��ȡshp�ļ�"), this);
    QAction* act1_2 = new QAction(QIcon("E:/��Ȼ�����/��ͼ���Ҽ�ŭ���޸��棩/1.PNG"), tr("��ȡ�Զ����ļ�"), this);
    // ������ݷ�ʽ��Ctrl+N��������Զ����ݼ�����������Ϊact->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
    //act1->setShortcuts(QKeySequence::New);//Ĭ��ctrl+n
    // �Ӳ˵�����ʱִ�вۺ���
    connect(act1_1, SIGNAL(triggered()), this, SLOT(pSlot1()));
    // �˵�������Ӳ˵�
    menu1->addAction(act1_1);
    menu1->addAction(act1_2);

    // �ڶ����˵�����Ӷ����˵�
    QMenu* menu2 = menuBar()->addMenu(tr("ͼԪ����"));
    QAction* act2 = new QAction(QIcon("E:/��Ȼ�����/��ͼ���Ҽ�ŭ���޸��棩/2.PNG"), tr("ͼ�λ���"), this);//����ͼ��
    menu2->addAction(act2); //���˵������������������menu2����һ���µĶ������������Ϊ�Ӳ˵�+1

    QMenu* submenu = new QMenu();
    QAction* subact1_1_1 = new QAction(QIcon("E:/��Ȼ�����/��ͼ���Ҽ�ŭ���޸��棩/3.PNG"), tr("�߶�(line)"), this);
    submenu->addAction(subact1_1_1);//��submenu����һ���µĶ������������Ϊ�Ӳ˵�+1
    QAction* subact1_1_2 = new QAction(QIcon("E:/��Ȼ�����/��ͼ���Ҽ�ŭ���޸��棩/3.PNG"), tr("��(point)"), this);
    submenu->addAction(subact1_1_2);//��submenu����һ���µĶ������������Ϊ�Ӳ˵�+1
    QAction* subact1_1_3 = new QAction(QIcon("E:/��Ȼ�����/��ͼ���Ҽ�ŭ���޸��棩/3.PNG"), tr("�����(polygon)"), this);
    submenu->addAction(subact1_1_3);//��submenu����һ���µĶ������������Ϊ�Ӳ˵�+1
    QAction* subact1_1_4 = new QAction(QIcon("E:/��Ȼ�����/��ͼ���Ҽ�ŭ���޸��棩/3.PNG"), tr("����(rectangle)"), this);
    submenu->addAction(subact1_1_4);//��submenu����һ���µĶ������������Ϊ�Ӳ˵�+1
    QAction* subact1_1_5 = new QAction(QIcon("E:/��Ȼ�����/��ͼ���Ҽ�ŭ���޸��棩/3.PNG"), tr("Բ(circle)"), this);
    submenu->addAction(subact1_1_5);//��submenu����һ���µĶ������������Ϊ�Ӳ˵�+1
    QAction* subact1_1_6 = new QAction(QIcon("E:/��Ȼ�����/��ͼ���Ҽ�ŭ���޸��棩/3.PNG"), tr("����(sector)"), this);
    submenu->addAction(subact1_1_6);//��submenu����һ���µĶ������������Ϊ�Ӳ˵�+1

    //ʲôʱ��λ�ڲ˵�ĩβ�˾Ͳ��ô���QMenu��ֱ��QAction
    //connect(subact, SIGNAL(triggered()), this, SLOT(subSlot()));

    act2->setMenu(submenu); // ��act2����Ӳ˵��������menu

    //********************************************
    // �����Դ��Ĺ�����
    ui.mainToolBar->addAction(act1_1);    //��Ӷ���

    // �Զ��幤����
    QToolBar* toolBar = new QToolBar();
    toolBar->setMovable(false);     // ���ù����������ƶ�,Ĭ���ǿ��ƶ�
    addToolBar(toolBar);                // �ѹ�������ӵ�����

    QPushButton* button = new QPushButton();    // �����ð�ť�ؼ����в���
    button->setText(tr("�ؼ�"));

    //toolBar->addAction(subact1_1_1);         // ��Ӷ���
    //toolBar->addWidget(button);         // ��ӿؼ�
 
    // ������
    act1_1->setStatusTip(tr("�Ӳ˵�"));//��������������ʾ�ı��������½ǣ�
    

    //************************************************************************

}

IMGPro::~IMGPro()
{}

// ��ӡ��־����������һ�� std::string ���͵Ĳ��� str
void PrintLog(const std::string& str)
{
    // ����һ����Ϣ��չʾ���� str ��ֵ��������ת��Ϊ const char* ����
    QMessageBox::information(nullptr, "", str.c_str());
}

// ��ӡ��־����������һ�� QString ���͵Ĳ��� str
void PrintLog(QString str)
{
    // ����һ����Ϣ��չʾ���� str ��ֵ
    QMessageBox::information(nullptr, "", str);
}

void IMGPro::helloworld() {
    QPushButton* button = new QPushButton(this);    // QPushButton��QT�İ�ť��  
    button->setText(tr("��ã�QT !"));               // ��ť��ʾ���ı�
    button->move(100, 100);                          // ���谴ťλ��
    connect(button, SIGNAL(clicked()), this, SLOT(iSlot()));  // �����ź����
}

void IMGPro::iSlot()                       // �ۺ���
{
    QMessageBox::information(this, tr("hello"), tr("Hello World!"));//����������ʾ
}

void IMGPro::InitSource()
{

    ui.treeView->setContextMenuPolicy(Qt::CustomContextMenu);
    //����Ҽ��˵�...
    QString qss = " QMenu{color:#E8E8E8;background:#4D4D4D;margin:2px;}\
                    QMenu::item{padding:3px 20px 3px 20px;}\
                    QMenu::indicator{width:13px;height:13px;}\
                    QMenu::item:selected{color:#E8E8E8;border:0px solid #575757;background:#1E90FF;}\
                    QMenu::separator{height:1px;background:#757575;}";      //������ʽ��
    menu = new QMenu(ui.treeView);
    menu->setStyleSheet(qss);                                         //���˵�������ʽ
    QAction* a1 = new QAction(QStringLiteral("����"));
    menu->addAction(a1);
    connect(a1, &QAction::triggered, this, [&]() {

        QModelIndex curIndex = ui.treeView->currentIndex();
        if (curIndex.isValid())
        {
#if 0
            auto parentIndex = curIndex.parent();
            if (parentIndex.isValid())
            {
                auto parentItem = model->itemFromIndex(parentIndex);
                if (parentItem != nullptr)
                {
                    parentItem->appendRow(new QStandardItem(QStringLiteral("����_%1").arg(model->rowCount())));
                }
            }
            else
            {
                //model
                model->appendRow(new QStandardItem(QStringLiteral("����_%1").arg(model->rowCount())));
            }

#else

            auto curItem = model->itemFromIndex(curIndex);
            if (curItem != nullptr)
            {
                auto item = new layerStandardItem(QStringLiteral("����_%1").arg(model->rowCount()));
                item->setCheckable(true);
                item->setCheckState(Qt::Checked);
                curItem->appendRow(item);
            }


#endif // 0


        }


        });


    QAction* a2 = new QAction(QStringLiteral("�鿴"));
    menu->addAction(a2);
    connect(a2, &QAction::triggered, this, [&]() {

        QModelIndex curIndex = ui.treeView->currentIndex();
        if (curIndex.isValid())
        {

            auto curItem = static_cast<layerStandardItem*>((model->itemFromIndex(curIndex)));
            if (curItem != nullptr)
            {
                QString info;
                info.append(curItem->text());//��ȡ��ǰ�ı�.
                info.append(QStringLiteral("\r\n״̬: %1\r\n").arg(curItem->checkState()));
                info.append(QStringLiteral("�Լ�������(IlayerTreeItem): %1").arg(curItem->gTreeData->toString().c_str()));
                PrintLog(info);
            }

        }

        });

    QAction* a5 = new QAction(QStringLiteral("չ��"));
    menu->addAction(a5);
    connect(a5, &QAction::triggered, this, [&]() {

        QModelIndex curIndex = ui.treeView->currentIndex();
        if (curIndex.isValid())
        {
            ui.treeView->expand(curIndex);
        }

        });

    QAction* a6 = new QAction(QStringLiteral("����"));
    menu->addAction(a6);
    connect(a6, &QAction::triggered, this, [&]() {

        QModelIndex curIndex = ui.treeView->currentIndex();
        if (curIndex.isValid())
        {
            ui.treeView->collapse(curIndex);
        }

        });

    QAction* a3 = new QAction(QStringLiteral("�޸�"));
    menu->addAction(a3);
    connect(a3, &QAction::triggered, this, [&]() {

        QModelIndex curIndex = ui.treeView->currentIndex();
        if (curIndex.isValid())
        {

            auto curItem = static_cast<layerStandardItem*>((model->itemFromIndex(curIndex)));
            if (curItem != nullptr)
            {
                QString str = QStringLiteral("�쳯");
                curItem->gTreeData->gName = str.toStdString();
                curItem->setText(str);
                PrintLog(QStringLiteral("�޸����"));
            }

        }

        });

    QAction* a4 = new QAction(QStringLiteral("ɾ��"));
    menu->addAction(a4);
    connect(a4, &QAction::triggered, this, [&]() {

        QModelIndex curIndex = ui.treeView->currentIndex();
        if (curIndex.isValid())
        {
            auto parentIndex = curIndex.parent();
            if (parentIndex.isValid())
            {
                auto parentItem = model->itemFromIndex(parentIndex);
                parentItem->removeRow(curIndex.row());
            }
            else
            {
                model->removeRow(curIndex.row());
            }

        }

        });
    //���˵������


    //���һЩTree����.
    {
        model = new QStandardItemModel(ui.treeView); //ָ�������󣬱����ڴ����
        model->setHorizontalHeaderLabels(QStringList() << QStringLiteral("����") << QStringLiteral("˵��"));
        ui.treeView->setModel(model);//��������Model,�ؼ�.

        rootItem1 = new layerStandardItem(QStringLiteral("����"));
        model->appendRow(rootItem1);

        layerStandardItem* childItem1_1 = new layerStandardItem(QStringLiteral("�ʹ�"));
        rootItem1->appendRow(childItem1_1);
        layerStandardItem* childItem1_2 = new layerStandardItem(QStringLiteral("������"));
        rootItem1->appendRow(childItem1_2);
        rootItem1->appendRow(new layerStandardItem(QStringLiteral("����̶")));
        rootItem1->appendRow(new layerStandardItem(QStringLiteral("���Ϻ�")));

        rootItem2 = new layerStandardItem(QStringLiteral("����"));
        model->appendRow(rootItem2);
        //model->setItem(model->indexFromItem(rootItem2).row(), 1, new layerStandardItem(QStringLiteral("�ƺ�¥")));//���õڶ�������.

        layerStandardItem* childItem2_1 = new layerStandardItem(QStringLiteral("�人"));
        rootItem2->appendRow(childItem2_1);
        //rootItem2->setChild(childItem2_1->index().row(), 1, new layerStandardItem(QStringLiteral("���н�")));//�ڵڶ����������.

        layerStandardItem* childItem2_2 = new layerStandardItem(QStringLiteral("԰��԰")); //ע������->rootItem2,ͨ���������������ڵ���.
        rootItem2->appendRow(childItem2_2);
        //rootItem2->setChild(childItem2_2->index().row(),1,new layerStandardItem(QStringLiteral("����¥")));

        rootItem2->appendRow(new layerStandardItem(QStringLiteral("������")));
    }

}
/// <summary>
/// �Ҽ��˵�...
/// </summary>
/// <param name="pos"></param>
void IMGPro::on_treeView_customContextMenuRequested(const QPoint& pos)
{
    if (ui.treeView->hasFocus()) {

        menu->exec(this->mapToGlobal(pos));
    }
}


