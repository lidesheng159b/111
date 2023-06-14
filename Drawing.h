#pragma once
#include "ui_IMGPro.h"
#include"mainWindow.h"
#include "Useui.h"
#include <QtGui>
#include <QtWidgets>
#include <QMainWindow>
#include <QMessageBox>

//
//Ui::IMGProClass* Dui = nullptr;
//void ui_init(Ui::IMGProClass* ui_ptr)
//{
//    Dui = ui_ptr;
//}

// 抽象状态类
class DrawingState :public QLabel{
	Q_OBJECT
public:
    virtual void draw() = 0;
    explicit DrawingState(QWidget* parent = 0);//只允许显式调用来创建对象
    //IMGPro* mainWindow; // 添加主窗口对象的指针或引用
    
    
protected://用于图像展现
    QPixmap m_Pixmap;
    QPoint m_StartPoint;
    QPoint m_EndPoint;
    //virtual void SetPixmap() = 0;
};

// 具体状态类
class DrawingLINESTRING : public DrawingState {
public:
    void draw() override {
        //IMGPro* mainWindow = dynamic_cast<IMGPro*>(ui->centralWidget);
        //if (mainWindow)
        //{
        //    // 使用信号与槽机制，调用主窗口的槽函数来弹出错误窗口
        //    mainWindow->showErrorDialog("An error occurred!");
        //};
        
    }

//signals:
//    void mySignal(); // 定义自定义信号
//
//public slots:
//    void emitSignal() {
//        emit mySignal(); // 发出自定义信号
//    }; 
};//线

class DrawingPOLYGON : public DrawingState {
public:
    void draw() override;
};//多边形

class DrawingPOINT:public DrawingState {
public:
    void draw() override;
};//点

class DrawingSector:public DrawingState {
public:
    void draw() override;
};//扇形

class DrawingCIRCLE :public DrawingState {
public:
    void draw() override {
        m_Pixmap.fill(Qt::white);
        QPainter painter(&m_Pixmap);
        QRect rect(m_StartPoint, m_EndPoint);
        painter.setPen(Qt::green);
        painter.drawEllipse(rect);
    };
};//圆形

class DrawingTEXT :public DrawingState {
public:
    void draw() override;
};//文本

class DrawingBITMAP :public DrawingState {
public:
    void draw() override;
};//位图




// 上下文类
class DrawingContext {
private:
    DrawingState* currentState;//当前状态
    //IMGPro* mainWindow; // 添加主窗口对象的指针或引用
   
public:
    //Ui::IMGProClass* ui;
    DrawingContext() : currentState(nullptr) {}//初始化
    

    // 设置当前状态
    void setCurrentState(DrawingState* state) {
        currentState = state;
    }

    // 执行绘制操作
    void draw()
    {
        if (currentState)
        {
            currentState->draw();
        }
        else 
        {
            /*IMGPro* mainWindow = dynamic_cast<IMGPro*>(ui->centralWidget);
            if (mainWindow) 
            {
                mainWindow->showErrorDialog("An error occurred!");
            }*/
        }
    }
    
};


class Useui {

};
