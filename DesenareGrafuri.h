#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_DesenareGrafuri.h"

#include "Graph.h"
#include <QMouseEvent>
#include <qpainter.h>

class DesenareGrafuri : public QMainWindow
{
    Q_OBJECT

public:
    DesenareGrafuri(QWidget *parent = nullptr);
    ~DesenareGrafuri();
    
    virtual void mouseReleaseEvent(QMouseEvent* e);
    virtual void paintEvent(QPaintEvent* e);



private:
    Ui::DesenareGrafuriClass ui;
    Graph m_graph;
};
