#ifndef MINION_H
#define MINION_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QTimer>
#include "dislife.h"
#include "enemy.h"
#include "bullet.h"
#include "teddy.h"
#include "door.h"
#include "win.h"
#include "lose.h"
#include <QImage>
#include "dislife.h"
#include "coins.h"
#include <QMediaPlayer>
#include<QAudioOutput>
#include "menu.h"


class minion : public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
private:
    int row, column;
    int data[15][15];
    int enemeis_remain=2;

public:
    minion(int boardData[15][15], Bullet *b[4], enemy *e[2], Teddy *t[2], door *d[1], dislife *h[4], win *w[1], lose *l[1], QGraphicsTextItem *text,QGraphicsTextItem *text2, Coins*c[10],QGraphicsTextItem *text3,QGraphicsTextItem *text4, QTimer * timer );
    QPixmap minionimage();
    QPixmap strongimage();
    QPixmap gunminion();
    QPixmap winimage ();
    enemy **e;
    Bullet **b;
    Teddy **t;
    door **d;
    dislife **h ;
    win **w;
    lose **l;
    Coins**c ;
    QGraphicsTextItem *text;
    QGraphicsTextItem *text2;
    QGraphicsTextItem *text3;
    QGraphicsTextItem *text4 ;
    bool very_cool = false;
    int lives = 3;
    int count = 0;
    bool winner = false;
    QTimer timer0;
    QTimer timer1;
    QTimer *timer2;
    QGraphicsPixmapItem* image1;
    QImage image2;
    bool timerr;
    int coin = 0;
    QMediaPlayer *music ;
    QAudioOutput *output;
    QMediaPlayer *music1 ;
    QAudioOutput *output1;
    QMediaPlayer *music2 ;
    QAudioOutput *output2;
    QTimer *e_timer ;

public slots:
    void keyPressEvent(QKeyEvent* event); // handels player movemement and all colliding items within it upon key press
    void minionreturn(); // returns minion to intial picture
    void minionreturn1 () ;
    void minionreturn2 () ;
    void killenemy(); // decreases enemy health and kills the enemy that is closer
    void reset_all(); //resets whole game (not used)
    void reset(); // resets all position after player loses a life
    void hearts (); // removes hearts as the player loses lives
    float getdistance(enemy*e); // gets the distance of a point to another
    void updateCountdown(); // timer starts a counter so we're able to output a string on the screen
    void  coinBalance () ;
};

#endif // MINION_H
