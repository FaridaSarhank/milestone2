#ifndef GRAPH_H
#define GRAPH_H
#include <QVector>
#include <QDebug>

class Graph
{
public:
    Graph(int boardData[15][15]);
    int v;
     QVector<QVector<int>> adj = QVector<QVector<int>>(225);
     QVector<QVector<int>> adj_Matrix = QVector<QVector<int>>(225);
     bool *visited;
     QVector <int> queue;
    void addEdge(int i, int j);
};

#endif // GRAPH_H

