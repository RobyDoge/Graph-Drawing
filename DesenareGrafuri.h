#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_DesenareGrafuri.h"

#include "Graph.h"
#include <QMouseEvent>
#include <qpainter.h>
#include <qradiobutton.h>
#include <QVBoxLayout>


class DesenareGrafuri : public QMainWindow
{
    Q_OBJECT

public:
    DesenareGrafuri(QWidget *parent = nullptr);
    ~DesenareGrafuri();
    
    virtual void mouseReleaseEvent(QMouseEvent* e);
    virtual void paintEvent(QPaintEvent* e);

    void setTypeOfGraph(bool TypeOfGraph);

private:
    bool ValidatePosition(QMouseEvent* e);


    Ui::DesenareGrafuriClass ui;
    Graph m_graph;
    Node m_firstNode;
    bool m_TypeOfGraph=1; //1 - directed graph, 0 - non-directed graph
    QRadioButton* m_ButtonDirectedGraph = findChild<QRadioButton*>("DirectedGraph");
};
