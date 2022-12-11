#include "graph.h"


Graph::Graph(int boardData[15][15])
{
for (int i=0 ; i<15 ; i++)
{

    for (int j = 0 ; j<15 ; j++)
    {
 int u=i*15+j;


 if (boardData[i][j]<0)
      {


          if (boardData[i+1][j]<0)
          {
              int v = ((i+1)*15)+j ;
              adj[u].push_back(v) ;
          }
          if (boardData[i-1][j]<0)
          {
               int v = ((i-1)*15)+j ;
               adj[u].push_back(v) ;
          }
          if (boardData[i][j+1]<0)
          {
               int v = ((i)*15)+(j+1) ;
               adj[u].push_back(v) ;
          }
          if (boardData[i][j-1]<0)
          {
              int v = ((i)*15)+(j-1) ;
              adj[u].push_back(v) ;
          }
      }
    }

}


for (int i=0;i<225;i++)
{
   QVector<int> CurrentNeigh= adj[i];

   for (int j=0; j<225;j++)
   {
       int n = CurrentNeigh.indexOf(j);
       if (n!=-1)
       {
           adj_Matrix[i].push_back(1);
       }
       else
       {
           adj_Matrix[i].push_back(0);
       }
   }
}

}
