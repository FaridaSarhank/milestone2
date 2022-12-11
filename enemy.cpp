 #include "enemy.h"
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include "minion.h"
#include "lose.h"
#include <QVector>


enemy::enemy(int boardData[15][15], int r, int c,lose *l[1],Graph *g)
{
    //sets enemy image
    QPixmap vectorimage(":/new/prefix1/vector.png");
    vectorimage = vectorimage.scaledToWidth(50);
    vectorimage = vectorimage.scaledToHeight(50);
    setPixmap(vectorimage);

    row = r;
    column = c;
    this->l=l ;
    this-> g = g ;

    // Set data Array
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            data[i][j] = boardData[i][j];
}

QVector<QVector<int>> enemy :: Dijkstra(Graph *g, int startVertex)
{
int N = 225;
bool done[N];
int previous[N];
double cost[N];

double temp[N][N];
for (int i = 0; i < N; i++)
  for (int j = 0; j < N; j++)
if (g->adj_Matrix[i][j] == 0)
temp[i][j] = INF;
else
temp[i][j] = g->adj_Matrix[i][j];

 //1st Row:
for (int i = 0; i < N; i++)
{
if (i == startVertex)
{
done[i] = true;
previous[i] = -1;
cost[i] = 0;
}
else
{
done[i] = false;
previous[i] = startVertex;
cost[i] = temp[startVertex][i];
}
}
int count = 1;
while (count < N)
{
double minimum = INF;
int currentVertex;
for (int i = 0; i < N; i++)
{
if (done[i] == false && cost[i] < minimum)
{
minimum = cost[i];
currentVertex = i;
}
}
done[currentVertex] = true;

for (int i = 0; i < N; i++)
{
if (done[i] == false)
{
double value = cost[currentVertex] + temp[currentVertex][i];
if (value < cost[i])
{
cost[i] = value;
previous[i] = currentVertex;
}
}
}
count++;
}
QVector<QVector<int>> paths;
paths.resize(N);
int j;
for (int i = 0; i < N; i++)
{
paths[i].push_back(i);
j = i;
while (j != startVertex)
{
paths[i].insert(paths[i].begin(), previous[j]);
j = previous[j];
}
}
return paths;
}

// Movement code for enemy works with a rand that generates a number and based on that the enemy moves up , down , right , left
void enemy::move()
{
    int u=row*15+column;
    int v = px*15+py;
    qDebug() << row<<column<<u ;
    if(u==v)
        return;
    QVector<QVector<int>> results = Dijkstra(g, u);
    row = results[v][1]/15;
    column = results[v][1]-(row*15);
     qDebug() << results [v] ;


    setPos(50 + column * 50, 50 + row * 50);

// handles the colliosion of when the enemy collides into player and accordingly decreases lives and resets both the variable and function are passed through dynamic casting


    QList<QGraphicsItem*> items2 = collidingItems();
    for (int i = 0; i < items2.size(); i++)
    {
        if (typeid(*items2[i]) == typeid(minion))
        {
            minion * m = dynamic_cast<minion*>(items2[i]);
            if(m->very_cool)
            {
                continue;
            }
             else
            {
              qDebug("hiii") ;
              m->lives -- ;
              m-> hearts();
              m->reset();
             }
            if (m->lives<= 0)
            {
                scene()->addItem(l[0]);
                l[0]->setPos(50 + -2 * 50, 50 + -2 * 50);
                QFont *f = new QFont;
                f->setPointSize(35);
                f->setBold(true);
                QGraphicsTextItem*text5 = scene()->addText("CLICK R TO PLAY AGAIN or E TO EXIT ");
                text5->setPos(50,-50);
                text5->setFont(*f);
                text5->setDefaultTextColor(QColor(QColorConstants::Svg::lightpink));
            }
        }
    }
}

