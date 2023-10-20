#include "DesenareGrafuri.h"

DesenareGrafuri::DesenareGrafuri(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

DesenareGrafuri::~DesenareGrafuri()
{}

void DesenareGrafuri::mouseReleaseEvent(QMouseEvent * e)
{
    Node n;
    m_graph.addNode(e->pos());
    update();

}

void DesenareGrafuri::paintEvent(QPaintEvent* e)
{
    QPainter p(this);
    std::vector<Node> noduri = m_graph.getNodes();
    for (Node nod : noduri)
    {
        QRect r(nod.getX(), nod.getY(), 20, 20);
        p.drawEllipse(r);
    }
}
