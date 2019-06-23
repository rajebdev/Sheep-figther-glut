#include <time.h>
#include <stdio.h> 
#include <stdlib.h>

int getRandomSheep()
{
    int sheepMod = 1 + rand()%4;
    return sheepMod;
}


void startingGame()
{
    srand(time(NULL));
    sheepPosA = new int[100];
    sheepModelA = new int[100];
    sheepMoveA = new float[100];
    sheepLifeA = new bool[100];
    sheepPosB = new int[100];
    sheepModelB = new int[100];
    sheepMoveB = new float[100];
    sheepLifeB = new bool[100];
    
    sheepA1 = getRandomSheep();
    sheepA2 = getRandomSheep();
    sheepB1 = getRandomSheep();
    sheepB2 = getRandomSheep();
}


void laodingSheep()
{
    if (loadTimeA <= 10 && loadTimeA > 0)
    {
        loadTimeA -= 1;
    }
    if (loadTimeB <= 10 && loadTimeB > 0)
    {
        loadTimeB -= 1;
    }
}

void showingIconSheep()
{
    createIconSheep(sheepA1, white);
    createIconSheepComing(sheepA2, white);
    createIconSheep(sheepB1, black);
    createIconSheepComing(sheepB2, black);
}

void collisonChecker();

bool lifeChecker(bool sheepCol, int sheepMod, float sheepMove)
{
    int poin;
    if (sheepMod == 1)
    {
        poin = 2;
    }
    else if (sheepMod == 2)
    {
        poin = 5;
    }
    else if (sheepMod == 3)
    {
        poin = 8;
    }
    else if (sheepMod == 4)
    {
        poin = 12;
    }

    if (sheepCol == true)
    {
        if (sheepMove > 285)
        {
            lifeBarB -= poin;
            return true;
        }
        
    }else{
        if (sheepMove < -285)
        {
            lifeBarA -= poin;
            return true;
        }
    }
    return false;
}