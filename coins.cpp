#include "coins.h"
#include "minion.h"

Coins::Coins()
{
    QPixmap coinsimage(":/new/prefix1/pink_bubbles.png");
    coinsimage = coinsimage.scaledToWidth(30);
    coinsimage = coinsimage.scaledToHeight(30);
    setPixmap(coinsimage);
}
