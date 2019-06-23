#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
 
using namespace std;

class Sheep
{
    private:
        int pos;
        int model;
        bool life;

    public:
        Sheep()
        {
        }
        Sheep(int m, int p)
        {
            srand(time(NULL));
            model = m;
            pos = p;
            life = true;
            printf("creating sheep %d \n",model);
        }

        int getPos()
        {
            return pos;
        }

        void setPos(int P)
        {
            pos = P;
        }

        int getModel()
        {
            return model;
        }
        
        int setModel(int m)
        {
            model = m;
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