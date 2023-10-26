#include "DesenareGrafuri.h"

DesenareGrafuri::DesenareGrafuri(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.DirectedGraph->setCheckable(true);
    ui.NonDirectedGraph->setCheckable(true);
    
    m_firstNode.setValue(-1);
}

DesenareGrafuri::~DesenareGrafuri()
{
}

void DesenareGrafuri::mouseReleaseEvent(QMouseEvent * e)
{
    

    if (e->button() == Qt::RightButton)
    {
        if (!ui.DirectedGraph->isChecked() && !ui.NonDirectedGraph->isChecked())
        {
            return;
        }
        else if (ui.NonDirectedGraph->isChecked())
        {
            m_TypeOfGraph = 0;
            ui.NonDirectedGraph->setEnabled(false);
            ui.DirectedGraph->setEnabled(false);

        }
        else
        {
            m_TypeOfGraph = 1;
            ui.NonDirectedGraph->setEnabled(false);
            ui.DirectedGraph->setEnabled(false);
        }
        if(ValidatePosition(e))
        {
            m_graph.addNode(e->pos());
            update();
        }
    }
    else if (e->button() == Qt::LeftButton)
    {
        std::vector<Node> nodes = m_graph.getNodes();
        for (Node& n : nodes)
        {
            if (fabs(e->pos().x() - n.getX()) < 10 &&
                fabs(e->pos().y() - n.getY()) < 10)
            {
                if (m_firstNode.getValue() == -1)
                    m_firstNode = n;
                else
                {
                    m_graph.addArch(Arch(m_firstNode, n),m_TypeOfGraph);
                    m_firstNode.setValue(-1);

                }
                update();
                break;
            }
        }
    }
}


void DesenareGrafuri::paintEvent(QPaintEvent* e)
{
    QPainter p(this);
    std::vector<Node> noduri = m_graph.getNodes();
    for (Node& n : noduri)
    {
        QRect r(n.getX() - 10, n.getY() - 10, 20, 20);
        p.drawEllipse(r);
        QString s;
        s.setNum(n.getValue());
        p.drawText(r, Qt::AlignCenter, s);
    }

    std::vector<Arch> arches = m_graph.getArches();
    for (Arch& a : arches)
    {
        p.drawLine(a.getFirstNode().getX(), a.getFirstNode().getY(),
            a.getSecondNode().getX(), a.getSecondNode().getY());

        //if(m_TypeOfGraph==1)
        //{
        //    double angle = std::atan2(a.getSecondNode().getY() - a.getFirstNode().getY(),
        //        a.getSecondNode().getX() - a.getFirstNode().getX());
        //    double arrowLength = 10.0;

        //    double arrowX1 = a.getSecondNode().getX() - arrowLength * std::cos(angle - M_PI / 6);
        //    double arrowY1 = a.getSecondNode().getY() - arrowLength * std::sin(angle - M_PI / 6);
        //    double arrowX2 = a.getSecondNode().getX() - arrowLength * std::cos(angle + M_PI / 6);
        //    double arrowY2 = a.getSecondNode().getY() - arrowLength * std::sin(angle + M_PI / 6);


        //    QPolygonF arrowhead;
        //    arrowhead.append(QPointF(a.getSecondNode().getX(), a.getSecondNode().getY()));
        //    arrowhead.append(QPointF(arrowX1, arrowY1));
        //    arrowhead.append(QPointF(arrowX2, arrowY2));

        //    p.setBrush(Qt::black);
        //    p.setPen(Qt::black);
        //    p.drawPolygon(arrowhead);
        //    /*m_graph.createNewDirectedArch(a);
        //    continue;*/
        //}
        //m_graph.createNewNonDirectedArch(a);
    }

    if (m_firstNode.getValue() >= 0)
    {
        QRect r(m_firstNode.getX() - 10, m_firstNode.getY() - 10, 20, 20);
        QPen pen;
        pen.setColor(Qt::red);
        pen.setWidth(2);
        p.setPen(pen);
        p.drawEllipse(r);
        QString s;
        s.setNum(m_firstNode.getValue());
        p.drawText(r, Qt::AlignCenter, s);
    }
}
     

bool DesenareGrafuri::ValidatePosition(QMouseEvent* e)
{
    int minDistance = 20; 
    std::vector<Node> nodes = m_graph.getNodes();
    for (auto node : nodes)
    {
        int dx = e->pos().x() - node.getX();
        int dy = e->pos().y() - node.getY();
        int distance = std::sqrt(dx * dx + dy * dy); 

        if (distance < minDistance)
        {
            
            return false;
        }
    }

    return true;
}
