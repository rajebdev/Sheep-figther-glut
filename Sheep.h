#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
 
using namespace std;

class Sheep
{
    private:
        int x, y;
        int model;
        bool life;

    public:
        Sheep(int m)
        {
            srand(time(NULL));
            model = m;
            printf("creating sheep %d \n",model);
            life = true;
        }

        void setX(int X)
        {
            x = X;
        }
        int getX()
        {
            return x;
        }

        void setY(int Y)
        {
            y = Y;
        }
        int getY()
        {
            return y;
        }
        
        int getModel()
        {
            return model;
        }

        void setLife(bool lv)
        {
            life = lv;
        }

        bool getLife()
        {
            return life;
        }

        void  setDead()
        {
            life = false;
        }

};