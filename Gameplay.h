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
    lifeBarA = 100;
    lifeBarB = 100;
    srand(time(0));
    sheepPosA = new int[100];
    sheepModelA = new int[100];
    sheepMoveA = new float[100];
    sheepFrontA = new float[100];
    sheepBackA = new float[100];
    sheepLifeA = new bool[100];
    sheepMacetA = new bool[100];

    sheepPosB = new int[100];
    sheepModelB = new int[100];
    sheepMoveB = new float[100];
    sheepFrontB = new float[100];
    sheepBackB = new float[100];
    sheepLifeB = new bool[100];
    sheepMacetB = new bool[100];
    
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
        poin = 80;
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
            
            if (sheepFrontB[i] != 0 && sheepPos == sheepPosB[i] && sheepLifeB[i] == true)
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
            if (sheepFrontA[i] != 0  && sheepPos == sheepPosA[i] && sheepLifeA[i] == true)
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
            
            if (sheepBackA[i] != 0 && sheepPos == sheepPosA[i] && sheepFront != sheepFrontA[i]  && sheepLifeA[i] == true)
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
            
            if (sheepBackA[i] != 0 && sheepPos == sheepPosB[i] && sheepFront != sheepFrontB[i] && sheepLifeB[i] == true)
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

bool checkScore(bool sheepCol, int sheepPos)
{
    float sA = 0, sB = 0;
    for (int i = 0; i < countSheepA; i++)
    {
        if (sheepPosA[i] == sheepPos && sheepLifeA[i] == true)
        {
            if (sheepModelA[i] == 1)
            {
                sA += 2;
            }
            else if (sheepModelA[i] == 2)
            {
                sA += 5;
            }
            else if (sheepModelA[i] == 3)
            {
                sA += 8;
            }
            else if (sheepModelA[i] == 4)
            {
                sA += 12;
            }
        }
    }

    for (int i = 0; i < countSheepB; i++)
    {
        if (sheepPosB[i] == sheepPos && sheepLifeB[i] == true)
        {
            if (sheepModelB[i] == 1)
            {
                sB += 2;
            }
            else if (sheepModelB[i] == 2)
            {
                sB += 5;
            }
            else if (sheepModelB[i] == 3)
            {
                sB += 8;
            }
            else if (sheepModelB[i] == 4)
            {
                sB += 12;
            }
        }
    }
    if (sA > sB)
    {
        if (sheepCol == white)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    else
    {
        if (sheepCol == white)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    return NULL;
}