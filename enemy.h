#ifndef ENEMY_H
#define ENEMY_H

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QDir>
#include <QDebug>
#include <QPainter>
#include "lose.h"
#include "graph.h"

class enemy : public QObject,  public QGraphicsPixmapItem
{
  Q_OBJECT
private :

    int data[15][15];

public:
    int health=2 ;
    bool dead = false;
    QPixmap vectorimage ;
    enemy(int boardData[15][15],int r , int c,lose *l[1], Graph *g);
    int row, column;

    lose **l ;
    Graph *g ;
    int px=7;
    int py=7;

    const int INF = 99999;

public slots :
   void move() ; // handles enemy moving fuctionaility (through rand)
QVector<QVector<int>> Dijkstra(Graph *g, int startVertex);
};

#endif // ENEMY_H
