#include "mainWindow.h"
#include"layerStandardItem.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QtGui>
#include <QtWidgets>
#include <QtWidgets/QApplication>
#include <QtCore/qbytearray.h>
#pragma execution_character_set("utf-8")    // 解决汉字乱码问题，注意！！！
IMGPro::IMGPro(QWidget *parent): QMainWindow(parent)
{
    //setupUi(this) 函数接受当前窗口对象的指针作为参数，以便将 UI 定义中的控件和部件与窗口对象关联起来。
    ui.setupUi(this);
    //初始化资源
    InitSource();
    //this->resize(400, 400);
    helloworld();

    // 标题大小
    setWindowTitle("图像");

    // 软件图标
    setWindowIcon(QIcon("E:/嘉然表情包/试图把我激怒（修复版）/1.PNG"));

    // 界面大小
    resize(QApplication::desktop()->width() * 0.9, QApplication::desktop()->height() * 0.9);
    move(QApplication::desktop()->width() * 0.05, QApplication::desktop()->height() * 0.01);

    // 第一个菜单
    QMenu* menu1 = menuBar()->addMenu(tr("读取文件"));
    // 创建子菜单，第一个参数QIcon为添加图标，注意路径是否正确，第二个参数是子菜单的显示文本
    QAction* act1_1 = new QAction(QIcon("E:/嘉然表情包/试图把我激怒（修复版）/1.PNG"), tr("读取shp文件"), this);
    QAction* act1_2 = new QAction(QIcon("E:/嘉然表情包/试图把我激怒（修复版）/1.PNG"), tr("读取自定义文件"), this);
    // 创建快捷方式：Ctrl+N，如果想自定义快捷键，可以设置为act->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
    //act1->setShortcuts(QKeySequence::New);//默认ctrl+n
    // 子菜单触发时执行槽函数
    connect(act1_1, SIGNAL(triggered()), this, SLOT(pSlot1()));
    // 菜单栏添加子菜单
    menu1->addAction(act1_1);
    menu1->addAction(act1_2);

    // 第二个菜单：添加二级菜单
    QMenu* menu2 = menuBar()->addMenu(tr("图元绘制"));
    QAction* act2 = new QAction(QIcon("E:/嘉然表情包/试图把我激怒（修复版）/2.PNG"), tr("图形绘制"), this);//设置图标
    menu2->addAction(act2); //给菜单赋予这个动作，即给menu2增加一个新的动作，可以理解为子菜单+1

    QMenu* submenu = new QMenu();
    QAction* subact1_1_1 = new QAction(QIcon("E:/嘉然表情包/试图把我激怒（修复版）/3.PNG"), tr("线段(line)"), this);
    submenu->addAction(subact1_1_1);//给submenu增加一个新的动作，可以理解为子菜单+1
    QAction* subact1_1_2 = new QAction(QIcon("E:/嘉然表情包/试图把我激怒（修复版）/3.PNG"), tr("点(point)"), this);
    submenu->addAction(subact1_1_2);//给submenu增加一个新的动作，可以理解为子菜单+1
    QAction* subact1_1_3 = new QAction(QIcon("E:/嘉然表情包/试图把我激怒（修复版）/3.PNG"), tr("多边形(polygon)"), this);
    submenu->addAction(subact1_1_3);//给submenu增加一个新的动作，可以理解为子菜单+1
    QAction* subact1_1_4 = new QAction(QIcon("E:/嘉然表情包/试图把我激怒（修复版）/3.PNG"), tr("矩形(rectangle)"), this);
    submenu->addAction(subact1_1_4);//给submenu增加一个新的动作，可以理解为子菜单+1
    QAction* subact1_1_5 = new QAction(QIcon("E:/嘉然表情包/试图把我激怒（修复版）/3.PNG"), tr("圆(circle)"), this);
    submenu->addAction(subact1_1_5);//给submenu增加一个新的动作，可以理解为子菜单+1
    QAction* subact1_1_6 = new QAction(QIcon("E:/嘉然表情包/试图把我激怒（修复版）/3.PNG"), tr("扇形(sector)"), this);
    submenu->addAction(subact1_1_6);//给submenu增加一个新的动作，可以理解为子菜单+1

    //什么时候位于菜单末尾了就不用创建QMenu，直接QAction
    //connect(subact, SIGNAL(triggered()), this, SLOT(subSlot()));

    act2->setMenu(submenu); // 在act2这个子菜单引出这个menu

    //********************************************
    // 窗口自带的工具栏
    ui.mainToolBar->addAction(act1_1);    //添加动作

    // 自定义工具栏
    QToolBar* toolBar = new QToolBar();
    toolBar->setMovable(false);     // 设置工具栏不可移动,默认是可移动
    addToolBar(toolBar);                // 把工具栏添加到窗口

    QPushButton* button = new QPushButton();    // 这里用按钮控件进行测试
    button->setText(tr("控件"));

    //toolBar->addAction(subact1_1_1);         // 添加动作
    //toolBar->addWidget(button);         // 添加控件
 
    // 任务栏
    act1_1->setStatusTip(tr("子菜单"));//给这个动作添加提示文本（在左下角）
    

    //************************************************************************

}

IMGPro::~IMGPro()
{}

// 打印日志函数，接受一个 std::string 类型的参数 str
void PrintLog(const std::string& str)
{
    // 弹出一个信息框，展示参数 str 的值，并将其转换为 const char* 类型
    QMessageBox::information(nullptr, "", str.c_str());
}

// 打印日志函数，接受一个 QString 类型的参数 str
void PrintLog(QString str)
{
    // 弹出一个信息框，展示参数 str 的值
    QMessageBox::information(nullptr, "", str);
}

void IMGPro::helloworld() {
    QPushButton* button = new QPushButton(this);    // QPushButton是QT的按钮类  
    button->setText(tr("你好，QT !"));               // 按钮显示的文本
    button->move(100, 100);                          // 重设按钮位置
    connect(button, SIGNAL(clicked()), this, SLOT(iSlot()));  // 连接信号与槽
}

void IMGPro::iSlot()                       // 槽函数
{
    QMessageBox::information(this, tr("hello"), tr("Hello World!"));//跳出来的提示
}

void IMGPro::InitSource()
{

    ui.treeView->setContextMenuPolicy(Qt::CustomContextMenu);
    //添加右键菜单...
    QString qss = " QMenu{color:#E8E8E8;background:#4D4D4D;margin:2px;}\
                    QMenu::item{padding:3px 20px 3px 20px;}\
                    QMenu::indicator{width:13px;height:13px;}\
                    QMenu::item:selected{color:#E8E8E8;border:0px solid #575757;background:#1E90FF;}\
                    QMenu::separator{height:1px;background:#757575;}";      //设置样式表
    menu = new QMenu(ui.treeView);
    menu->setStyleSheet(qss);                                         //给菜单设置样式
    QAction* a1 = new QAction(QStringLiteral("增加"));
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
                    parentItem->appendRow(new QStandardItem(QStringLiteral("城市_%1").arg(model->rowCount())));
                }
            }
            else
            {
                //model
                model->appendRow(new QStandardItem(QStringLiteral("城市_%1").arg(model->rowCount())));
            }

#else

            auto curItem = model->itemFromIndex(curIndex);
            if (curItem != nullptr)
            {
                auto item = new layerStandardItem(QStringLiteral("城市_%1").arg(model->rowCount()));
                item->setCheckable(true);
                item->setCheckState(Qt::Checked);
                curItem->appendRow(item);
            }


#endif // 0


        }


        });


    QAction* a2 = new QAction(QStringLiteral("查看"));
    menu->addAction(a2);
    connect(a2, &QAction::triggered, this, [&]() {

        QModelIndex curIndex = ui.treeView->currentIndex();
        if (curIndex.isValid())
        {

            auto curItem = static_cast<layerStandardItem*>((model->itemFromIndex(curIndex)));
            if (curItem != nullptr)
            {
                QString info;
                info.append(curItem->text());//获取当前文本.
                info.append(QStringLiteral("\r\n状态: %1\r\n").arg(curItem->checkState()));
                info.append(QStringLiteral("自己的数据(IlayerTreeItem): %1").arg(curItem->gTreeData->toString().c_str()));
                PrintLog(info);
            }

        }

        });

    QAction* a5 = new QAction(QStringLiteral("展开"));
    menu->addAction(a5);
    connect(a5, &QAction::triggered, this, [&]() {

        QModelIndex curIndex = ui.treeView->currentIndex();
        if (curIndex.isValid())
        {
            ui.treeView->expand(curIndex);
        }

        });

    QAction* a6 = new QAction(QStringLiteral("收起"));
    menu->addAction(a6);
    connect(a6, &QAction::triggered, this, [&]() {

        QModelIndex curIndex = ui.treeView->currentIndex();
        if (curIndex.isValid())
        {
            ui.treeView->collapse(curIndex);
        }

        });

    QAction* a3 = new QAction(QStringLiteral("修改"));
    menu->addAction(a3);
    connect(a3, &QAction::triggered, this, [&]() {

        QModelIndex curIndex = ui.treeView->currentIndex();
        if (curIndex.isValid())
        {

            auto curItem = static_cast<layerStandardItem*>((model->itemFromIndex(curIndex)));
            if (curItem != nullptr)
            {
                QString str = QStringLiteral("天朝");
                curItem->gTreeData->gName = str.toStdString();
                curItem->setText(str);
                PrintLog(QStringLiteral("修改完成"));
            }

        }

        });

    QAction* a4 = new QAction(QStringLiteral("删除"));
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
    //给菜单添加项


    //添加一些Tree数据.
    {
        model = new QStandardItemModel(ui.treeView); //指定父对象，便于内存管理
        model->setHorizontalHeaderLabels(QStringList() << QStringLiteral("名称") << QStringLiteral("说明"));
        ui.treeView->setModel(model);//设置数据Model,关键.

        rootItem1 = new layerStandardItem(QStringLiteral("北京"));
        model->appendRow(rootItem1);

        layerStandardItem* childItem1_1 = new layerStandardItem(QStringLiteral("故宫"));
        rootItem1->appendRow(childItem1_1);
        layerStandardItem* childItem1_2 = new layerStandardItem(QStringLiteral("子午庙"));
        rootItem1->appendRow(childItem1_2);
        rootItem1->appendRow(new layerStandardItem(QStringLiteral("日月潭")));
        rootItem1->appendRow(new layerStandardItem(QStringLiteral("中南海")));

        rootItem2 = new layerStandardItem(QStringLiteral("湖北"));
        model->appendRow(rootItem2);
        //model->setItem(model->indexFromItem(rootItem2).row(), 1, new layerStandardItem(QStringLiteral("黄鹤楼")));//设置第二列内容.

        layerStandardItem* childItem2_1 = new layerStandardItem(QStringLiteral("武汉"));
        rootItem2->appendRow(childItem2_1);
        //rootItem2->setChild(childItem2_1->index().row(), 1, new layerStandardItem(QStringLiteral("步行街")));//在第二列添加数据.

        layerStandardItem* childItem2_2 = new layerStandardItem(QStringLiteral("园博园")); //注意这里->rootItem2,通过父类设置其所在的行.
        rootItem2->appendRow(childItem2_2);
        //rootItem2->setChild(childItem2_2->index().row(),1,new layerStandardItem(QStringLiteral("揽月楼")));

        rootItem2->appendRow(new layerStandardItem(QStringLiteral("白云寺")));
    }

}
/// <summary>
/// 右键菜单...
/// </summary>
/// <param name="pos"></param>
void IMGPro::on_treeView_customContextMenuRequested(const QPoint& pos)
{
    if (ui.treeView->hasFocus()) {

        menu->exec(this->mapToGlobal(pos));
    }
}


