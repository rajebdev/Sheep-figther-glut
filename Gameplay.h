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
    sheepPosA = new int[100];
    sheepModelA = new int[100];
    sheepMoveA = new float[100];
    sheepFrontA = new float[100];
    sheepBackA = new float[100];
    sheepLifeA = new bool[100];
    sheepPosB = new int[100];
    sheepModelB = new int[100];
    sheepMoveB = new float[100];
    sheepFrontB = new float[100];
    sheepBackB = new float[100];
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

bool collisonChecker(bool sheepCol, int sheepMod, float sheepFront, int sheepPos)
{
    bool coll = false;
    int i = 0;
    if (sheepCol == true && countSheepB > 0)
    {
        while (!coll && i < countSheepB)
        {
            
            if (sheepFrontB[i] != 0 && sheepPos == sheepPosB[i])
            {
                // if (timeSecTemp != timeSec)
                // {
                //     printf("white check betwen %f and %f \n", sheepFront, sheepFrontB[i]);
                // }
                if (sheepFront > sheepFrontB[i])
                {
                    // printf("Tabrakan Woy \n", NULL);
                    return true;
                }
            }
            i++;
        }
        
    }else if (sheepCol == false && countSheepA > 0)
    {
        while (!coll && i < countSheepA && countSheepA > 0)
        {
            // if (timeSecTemp != timeSec)
            // {
            //     printf("black check betwen %f and %f \n", sheepFront, sheepFrontA[i]);
            // }
            if (sheepFrontA[i] != 0  && sheepPos == sheepPosA[i])
            {
                if (sheepFront < sheepFrontA[i])
                {
                    // printf("Tabrakan Woy \n", NULL);
                    return true;
                }
            }
            i++;
        }
        
    }
    return false;
}

bool checkCollisionSelf(bool sheepCol, int index, int sheepMod, float sheepFront, int sheepPos)
{
    bool coll = false;
    int i = 0;
    if (sheepCol == white && countSheepA > 1)
    {
        while (!coll && i < index)
        {
            
            if (sheepBackA[i] != 0 && sheepPos == sheepPosA[i] && sheepFront != sheepFrontA[i])
            {
                // if (timeSecTemp != timeSec)
                // {
                //     printf("white check betwen %f and %f \n", sheepFront, sheepBackA[i]);
                // }
                if (sheepFront > sheepBackA[i])
                {
                    // printf("Tabrakan Woy \n", NULL);
                    return true;
                }
            }
            i++;
        }
    }else if (sheepCol == black && countSheepB > 1)
    {
        while (!coll && i < index)
        {
            
            if (sheepBackA[i] != 0 && sheepPos == sheepPosB[i] && sheepFront != sheepFrontB[i])
            {
                // if (timeSecTemp != timeSec)
                // {
                //     printf("white check betwen %f and %f \n", sheepFront, sheepBackB[i]);
                // }
                if (sheepFront > sheepBackB[i])
                {
                    // printf("Tabrakan Woy \n", NULL);
                    return true;
                }
            }
            i++;
        }
    }
    return false;
}