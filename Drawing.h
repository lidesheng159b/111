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

// ����״̬��
class DrawingState :public QLabel{
	Q_OBJECT
public:
    virtual void draw() = 0;
    explicit DrawingState(QWidget* parent = 0);//ֻ������ʽ��������������
    //IMGPro* mainWindow; // ��������ڶ����ָ�������
    
    
protected://����ͼ��չ��
    QPixmap m_Pixmap;
    QPoint m_StartPoint;
    QPoint m_EndPoint;
    //virtual void SetPixmap() = 0;
};

// ����״̬��
class DrawingLINESTRING : public DrawingState {
public:
    void draw() override {
        //IMGPro* mainWindow = dynamic_cast<IMGPro*>(ui->centralWidget);
        //if (mainWindow)
        //{
        //    // ʹ���ź���ۻ��ƣ����������ڵĲۺ������������󴰿�
        //    mainWindow->showErrorDialog("An error occurred!");
        //};
        
    }

//signals:
//    void mySignal(); // �����Զ����ź�
//
//public slots:
//    void emitSignal() {
//        emit mySignal(); // �����Զ����ź�
//    }; 
};//��

class DrawingPOLYGON : public DrawingState {
public:
    void draw() override;
};//�����

class DrawingPOINT:public DrawingState {
public:
    void draw() override;
};//��

class DrawingSector:public DrawingState {
public:
    void draw() override;
};//����

class DrawingCIRCLE :public DrawingState {
public:
    void draw() override {
        m_Pixmap.fill(Qt::white);
        QPainter painter(&m_Pixmap);
        QRect rect(m_StartPoint, m_EndPoint);
        painter.setPen(Qt::green);
        painter.drawEllipse(rect);
    };
};//Բ��

class DrawingTEXT :public DrawingState {
public:
    void draw() override;
};//�ı�

class DrawingBITMAP :public DrawingState {
public:
    void draw() override;
};//λͼ




// ��������
class DrawingContext {
private:
    DrawingState* currentState;//��ǰ״̬
    //IMGPro* mainWindow; // ��������ڶ����ָ�������
   
public:
    //Ui::IMGProClass* ui;
    DrawingContext() : currentState(nullptr) {}//��ʼ��
    

    // ���õ�ǰ״̬
    void setCurrentState(DrawingState* state) {
        currentState = state;
    }

    // ִ�л��Ʋ���
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
