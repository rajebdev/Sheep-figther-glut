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
    sheepMoveA = new int[100];
    sheepPosB = new int[100];
    sheepModelB = new int[100];
    sheepMoveB = new int[100];
    
    // for (int i = 0; i < 100; i++)
    // {
    //     cout << sheepModel[i] << " " << sheepPos[i] << endl;
    // }
    
    sheepA1 = getRandomSheep();
    sheepA2 = getRandomSheep();
    sheepB1 = getRandomSheep();
    sheepB2 = getRandomSheep();
}


void laodingSheep()
{
    int model = getRandomSheep();
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