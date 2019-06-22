
void cube(float p=0, float l=0, float t=0)
{
    float x = p/2;
    float y = t/2;
    float z = l/2;
    for (int i=0; i< 2; i++){
        glPushMatrix();
            glTranslated(0, 0, l*i);
            //depan belakang
            glBegin(GL_POLYGON);
            glNormal3f(0.0,0.0, -1+2*i);
            glVertex3f(-x, -y, -z);
            glVertex3f(-x,  y, -z);
            glVertex3f( x,  y, -z);
            glVertex3f( x, -y, -z);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslated(p*i, 0, 0);
            //kiri kanan
            glBegin(GL_POLYGON);
            glNormal3f(-1+2*i, 0, 0);
            glVertex3f(-x, -y, -z);
            glVertex3f(-x,  y, -z);
            glVertex3f(-x,  y, z);
            glVertex3f(-x, -y, z);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslated(0, -t*i, 0);
            // atas bawah
            glBegin(GL_POLYGON);
            glNormal3f(0.0, 1-2*i, 0.0);
            glVertex3f(-x, y, -z);
            glVertex3f(-x, y,  z);
            glVertex3f( x, y,  z);
            glVertex3f( x, y, -z);
            glEnd();
        glPopMatrix();
    }

}

void elips(float p, float l, float t)
{
    glPushMatrix();
    glScalef(p, t, l);
    glutSolidSphere(1, 36, 36);
    glPopMatrix();
}

void cone(float p, float l, float t)
{
    glPushMatrix();
    glRotated(-90, 1, 0, 0);
    glScalef(p, l, t);
    glutSolidCone(1, 1, 36, 36);
    glPopMatrix();
}

void makeBox(float x, float y, float z, float p, float l, float t, float colR, float colG, float colB, float colA)
{
    glPushMatrix();
        glTranslated(x, y, z);
        setMaterialColor(colR, colG, colB, colA);
        cube(p, l, t);
    glPopMatrix();
}

void cylinder(float x, float y, float z, float alas, float tinggi, float colR, float colG, float colB, float colA)
{
    glPushMatrix();
        glTranslated(x, y, z+2.5);
        setMaterialColor(colR, colG, colB, colA);
        glutSolidCone(alas, 0, 50, 1);
        GLUquadricObj *obj = gluNewQuadric();
        gluCylinder(obj, alas, alas, tinggi, 50, 50);
        glTranslated(0, 0, tinggi);
        glutSolidCone(alas, 0, 50, 1);
    glPopMatrix();
}

void createLoadingSheep(float x, float y, float z, float r, float loadTime, float colR, float colG, float colB, float colA)
{
    glPushMatrix();
    glTranslated(x, y, z);
    glRotated(90,0,0,1);
    setMaterialColor(colR, colG, colB, colA);
    for (float i = 0; i < 360*(loadTime/10); i++)
    {
        glPushMatrix();

        glRotated(-i,0,0,1);
        glTranslated(r, 0, 0);
        glutSolidSphere(1.5, 36, 36);

        glPopMatrix();
    }

    glPopMatrix();
}


void createBackground()
{
    // make ground
    makeBox(0, 0, -5, 165, 5, 250, 0, 0.5, 0, 1);
    makeBox(0, 135, 9, 165, 33, 20, 0, 0.8, 1, 1);
    makeBox(0, -135, 9, 165, 33, 20, 0, 0.8, 1, 1);

    
    // make board
    glPushMatrix();
    glTranslated(-62.5, 0, 0);
    makeBox(0, 0, 0, 40, 5, 250, 0, 1, 0, 1);

    // make wall wood
    makeBox(-2.5, 0, 12.5, 35, 20, 7.5, 0.5, 0.5, 0, 1);

    // make board sheep cooming
    // top
    cylinder(0, 40, 2, 11, 5, 0.2, 0.2, 0, 1);
    cylinder(0, 70, 2, 14, 5, 0.2, 0.2, 0, 1);
    cylinder(0, 40, 0, 13, 5, 0.8, 0.6, 0, 1);
    cylinder(0, 70, 0, 16, 5, 0.8, 0.6, 0, 1);
    
    // bottom
    cylinder(0, -40, 2, 11, 5, 0.2, 0.2, 0, 1);
    cylinder(0, -70, 2, 14, 5, 0.2, 0.2, 0, 1);
    cylinder(0, -40, 0, 13, 5, 0.8, 0.6, 0, 1);
    cylinder(0, -70, 0, 16, 5, 0.8, 0.6, 0, 1);

    // make sheep loading
    // top
    createLoadingSheep(0, 70, 9, 14.5, loadTime, 0, 1, 1, 0.7);
    //bottom
    createLoadingSheep(0, -70, 9, 14.5, loadTime, 0, 1, 1, 0.7);

    // make profile player
    cylinder(0, 117.5, -9.9, 22, 35, 0.8, 0.6, 0, 1);
    cylinder(0, -117.5, -9.9, 22, 35, 0.8, 0.6, 0, 1);

    // make ex-foto profile
    //top
    cylinder(0, 117.5, 14.9, 20, 13, 1, 1, 1, 1);
    cylinder(0, 117.5, 16.9, 18, 13, 1, 0, 0, 1);
    // bottom
    cylinder(0, -117.5, 14.9, 20, 13, 1, 1, 1, 1);
    cylinder(0, -117.5, 16.9, 18, 13, 0, 0, 1, 1);

    glPopMatrix();
    
    // make border top
    glPushMatrix();
    glTranslated(20, 0, 0);
    makeBox(0, 122.5, 0, 125, 5, 5, 0, 1, 0, 1);
    // border bottom
    makeBox(0, -122.5, 0, 125, 5, 5, 0, 1, 0, 1);
    // make border right
    makeBox(60, 0, 0, 5, 5, 250, 0, 1, 0, 1);

    // make col
    makeBox(-37.5, 0, 0, 5, 5, 250, 0, 1, 0, 1);
    makeBox(-12.5, 0, 0, 5, 5, 250, 0, 1, 0, 1);
    makeBox(12.5, 0, 0, 5, 5, 250, 0, 1, 0, 1);
    makeBox(37.5, 0, 0, 5, 5, 250, 0, 1, 0, 1);
    
    // make midle line
    makeBox(0, 0, -1, 124.9, 5, 3, 1, 0, 0, 0.5);

    // make bar life player
    makeBox(-7.5, 117.5, 14, 140, 23, 15, 0.8, 0.6, 0, 1);
    makeBox(-7.5, -117.5, 14, 140, 23, 15, 0.8, 0.6, 0, 1);
    makeBox(-7.5, 117.5, 15, 136, 23, 13, 0.5, 0.2, 0, 1);
    makeBox(-7.5, -117.5, 15, 136, 23, 13, 0.5, 0.2, 0, 1);

    // make bar life player loading
    makeBox(-1-((119-(119*(lifeBarA/100)))/2), 117.5, 16, 119*(lifeBarA/100), 22, 10, 0, 0.6, 0, 1);
    makeBox(-1-((119-(119*(lifeBarB/100)))/2), -117.5, 16, 119*(lifeBarB/100), 22, 10, 0, 0.6, 0, 1);

    glPopMatrix();

}


void bulu(float p, float l, float t, float x, float y, float z)
{
    glPushMatrix();
        if (model == 1 || model == 2 || model == 3 || model == 4 || model == 9)
        {
            setMaterialColor(p/0.75,p/0.75,p/0.75, alphaTrans);
        }
        else
        {
            setMaterialColor(1,1,1, alphaTrans);
        }
        glTranslated(x,y,z);
        elips(p,l,t);
    glPopMatrix();
}

void tubuhHitam(float p, float l, float t, float x, float y, float z)
{
    glPushMatrix();
    setMaterialColor(0,0,0, alphaTrans);
        glTranslated(x,y,z);
        elips(p,l,t);
    glPopMatrix();
}

void tandukCone(float p, float l, float t, float x, float y, float z, float r=-35)
{
    glPushMatrix();
        glRotated(r,0,0,1);
        glTranslated(x,y,z);
        cone(p,l,t);
    glPopMatrix();
}

void tandukBall(float p, float l, float t, float x, float y, float z)
{
    glPushMatrix();
        glTranslated(x,y,z);
        elips(p,l,t);
    glPopMatrix();
}

void tubuh(float p, float l, float t, float x, float y, float z)
{
    glPushMatrix();
        glTranslated(x,y,z);
        elips(p,l,t);
    glPopMatrix();
}

void jengger(float p, float l, float t, float x, float y, float z)
{
    glPushMatrix();
        setMaterialColor(10,0,0, alphaTrans);
        glTranslated(x,y,z);
        elips(p,l,t);
    glPopMatrix();
}

void paruh(float p, float l, float t, float x, float y, float z)
{
    glPushMatrix();
        setMaterialColor(5,2,0, alphaTrans);
        glTranslated(x,y,z);
        cone(p,l,t);
    glPopMatrix();
}

void tulangAyam(float p, float l, float t, float x, float y, float z)
{
    glPushMatrix();
        setMaterialColor(1,1,0, alphaTrans);
        glTranslated(x,y,z);
        elips(p,l,t);
    glPopMatrix();
}

void sheep1()
{
    glPushMatrix();
        glTranslated(0, -10, 0);
        glRotated(-10,1,0,0);
        glPushMatrix();
        // badan
        if (model == 1 || model == 2 || model == 3 || model == 4 )
        {
            setMaterialColor(7,7,7, alphaTrans);
        }
        else
        {
            setMaterialColor(1,1,1, alphaTrans);
        }
        elips(6,6,5);
        glTranslated(4,0,0);
        elips(5,5,5);
        glTranslated(-8,0,0);
        elips(5,5,5);
        glTranslated(4,4,0);
        elips(5,5,5);
        glPushMatrix();
        glTranslated(3,0,-1);
        elips(4,4,4);
        glTranslated(-6,0,0);
        elips(4,4,4);
        glTranslated(3,0.2,-3);
        elips(5,5,5);
        glPopMatrix();
        glTranslated(3,-3,-4);
        elips(5,5,5);
        glTranslated(-6,0,0);
        elips(5,5,5);
        glPushMatrix();
        glTranslated(3,0,-2);
        elips(4,4,4);
        glTranslated(0,0,-2);
        elips(2,3,2);
        glPopMatrix();
        // kepala
        setMaterialColor(6,3,2, alphaTrans);
        glTranslated(3,-1, 8);
        elips(5,4,4);

        bulu(5,3,3,0,4,0);

        // tanduk
        setMaterialColor(0.5, 0.2, 0, alphaTrans);
        glTranslated(2.5, 2.5, 1);
        glRotated(-35,0,0,1);
    //    cone(1,1,4);
        glRotated(35,0,0,1);
        glTranslated(-5, 0, 0);
        glRotated(35,0,0,1);
    //    cone(1,1,4);
        glRotated(-35,0,0,1);
        // mata
        setMaterialColor(0,0,0, alphaTrans);
        glTranslated(4, -2.5, 2.4);
        elips(1, 0.7, 1);
        glTranslated(-3, 0, 0);
        elips(1, 0.7, 1);
        setMaterialColor(1,1,1, alphaTrans);
        glTranslated(0,0,0.43);
        elips(0.5, 0.3, 0.5);
        glTranslated(3,0,0);
        elips(0.5, 0.3, 0.5);
        // mulut
        setMaterialColor(0,0,0, alphaTrans);
        glTranslated(-1.5, -2, -1);
        elips(1.5, 0.7, 1);
        glPopMatrix();

        //kaki
        glPushMatrix();
        setMaterialColor(0,0,0, alphaTrans);
        glTranslated(4,-5,0);
        elips(1,1,2);
        glTranslated(-8,0,0);
        elips(1,1,2);
        glTranslated(0,1,-5);
        elips(1,1,2);
        glTranslated(8,0,0);
        elips(1,1,2);
        glPopMatrix();

        //telinga

        setMaterialColor(2,1,1, alphaTrans);
        glPushMatrix();
            glRotated(-25,0,0,1);
            tubuh(4,1.5,1.5,3,2,4);
        glPopMatrix();
        glPushMatrix();
            glScaled(-1,1,1);
            glRotated(-25,0,0,1);
            tubuh(4,1.5,1.5,3,2,4);
        glPopMatrix();


    glPopMatrix();
}

void sheep2()
{
    glPushMatrix();
    glTranslated(0,-5,11);
    glScaled(0.9, 0.9, 0.9);
    glRotated(-10,1,0,0);
        //kepala
        glPushMatrix();
            setMaterialColor(8,4,3, alphaTrans);
            elips(7,6,6);
            setMaterialColor(0,0,0, alphaTrans);
            glTranslated(3,0,5);
            elips(1,1,1);
            setMaterialColor(1,1,1, alphaTrans);
            glTranslated(0,0,0.8);
            elips(0.4, 0.4, 0.4);
            setMaterialColor(0,0,0, alphaTrans);
            glTranslated(-6,0,-0.8);
            elips(1,1,1);
            setMaterialColor(1,1,1, alphaTrans);
            glTranslated(0,0,0.8);
            elips(0.4, 0.4, 0.4);
            //mulut
            setMaterialColor(0,0,0, alphaTrans);
            glTranslated(3,-2,-1);
            elips(2,1,1.5);
        glPopMatrix();

        // tanduk
        setMaterialColor(1, 0.15, 0, alphaTrans);
        glPushMatrix();
            glRotated(-35,0,0,1);
                glPushMatrix();
                    glTranslated(3,5,0);
                    cone(3,3,8);
                glPopMatrix();
            glRotated(70,0,0,1);
                glPushMatrix();
                    glTranslated(-3,5,0);
                    cone(3,3,8);
                glPopMatrix();
        glPopMatrix();

        //telinga
        setMaterialColor(2,1,1, alphaTrans);
        glPushMatrix();
            glRotated(-25,0,0,1);
            tubuh(5,2,2,6,4,1);
        glPopMatrix();
        glPushMatrix();
            glScaled(-1,1,1);
            glRotated(-25,0,0,1);
            tubuh(5,2,2,6,4,1);
        glPopMatrix();

        // badan
        glPushMatrix();
            setMaterialColor(9,9,9, alphaTrans);
            glTranslated(0,0,-10);
            glRotated(10,1,0,0);
            elips(8,12,5);
        glPopMatrix();

        // bulu

        bulu(4,4,4,0,8,-5);
        bulu(4,4,4,3,5,1);
        bulu(4,4,4,-3,5,1);
        bulu(4,4,4,0,6,2);
        bulu(5,5,5,5,0,-1);
        bulu(5,5,5,-5,0,-1);

        bulu(6,6,6,4,6,-5);
        bulu(6,6,6,6,2.5,-5);
        bulu(6,6,6,-4,6,-5);
        bulu(6,6,6,-6,2.5,-5);
        bulu(6,6,6,0,9,-9);
        bulu(6,6,6,4,6,-9);
        bulu(6,6,6,-4,6,-9);
        bulu(6,6,6,6,3,-9);
        bulu(6,6,6,-6,3,-9);
        bulu(6,6,6,0,9,-15);
        bulu(6,6,6,4,6,-15);
        bulu(6,6,6,-4,6,-15);
        bulu(6,6,6,6,3,-15);
        bulu(6,6,6,-6,3,-15);
        bulu(6,6,6,0,7,-20);
        bulu(6,6,6,4,5,-20);
        bulu(6,6,6,-4,5,-20);
        bulu(4,4,4,0,5,-24);

        bulu(7,5,5,0,-1,-5);

        bulu(5,5,5,0,-2,-8);
        bulu(5,5,5,6,0,-8);
        bulu(5,5,5,-6,0,-8);
        bulu(5,5,5,4,-1,-8);
        bulu(5,5,5,-4,-1,-8);

        bulu(5,5,5,0,-2,-13);
        bulu(5,5,5,6,0,-13);
        bulu(5,5,5,-6,0,-13);
        bulu(5,5,5,4,-1,-13);
        bulu(5,5,5,-4,-1,-13);

        bulu(5,5,5,0,0,-17);
        bulu(5,5,5,6,2,-17);
        bulu(5,5,5,-6,2,-17);
        bulu(5,5,5,4,1,-17);
        bulu(5,5,5,-4,1,-17);

        bulu(5,5,5,0,2,-21);

        //kaki
        tubuhHitam(1.7, 1.7, 4, 5, -6, -8);
        tubuhHitam(1.7, 1.7, 4, -5, -6, -8);
        tubuhHitam(1.7, 1.7, 4, 5, -4, -20);
        tubuhHitam(1.7, 1.7, 4, -5, -4, -20);

    glPopMatrix();
}

void sheep3()
{
    glPushMatrix();
    glTranslated(0,0,18);
    glRotated(-10,1,0,0);
        //kepala
        glPushMatrix();
            setMaterialColor(10,5,4, alphaTrans);
            elips(9,8,8);
        glPopMatrix();

        //atribut wajah
        glPushMatrix();
            glRotated(45,0,0,1);
            tubuhHitam(4,4,1.5, 1,-3,4);
        glPopMatrix();
        glPushMatrix();
            glRotated(-45,0,0,1);
            tubuhHitam(4,4,1.5, -1,-3,4);
        glPopMatrix();
        //mulut
        glPushMatrix();
            tubuhHitam(4,2,3, 0,-3,5);
        glPopMatrix();

        //telinga
        setMaterialColor(2,1,1, alphaTrans);
        glPushMatrix();
            glRotated(-25,0,0,1);
            tubuh(5,2,2,8,4,0);
        glPopMatrix();
        glPushMatrix();
            glScaled(-1,1,1);
            glRotated(-25,0,0,1);
            tubuh(5,2,2,8,4,0);
        glPopMatrix();

        //tanduk
        setMaterialColor(1,0.15,0, alphaTrans);
        glPushMatrix();
            glTranslated(-1,0,-3);
            glPushMatrix();
                glRotated(150,0,1,1);
                tandukCone(2.5,2.5,10,0,10,4);
            glPopMatrix();
            glPushMatrix();
                tandukBall(2.5,2.5,2.5, -6,6,5.5);
                tandukBall(2.5,2.5,2.5, -5,5,5);
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glScaled(-1,1,1);
            glTranslated(-1,0,-3);
            glPushMatrix();
                glRotated(150,0,1,1);
                tandukCone(2.5,2.5,10,0,10,4);
            glPopMatrix();
            glPushMatrix();
                tandukBall(2.5,2.5,2.5, -6,6,5.5);
                tandukBall(2.5,2.5,2.5, -5,5,5);
            glPopMatrix();
        glPopMatrix();

        //bulu kepala
        bulu(4,4,4,0,5,6);
        bulu(4,4,4,-4,5,6);
        bulu(4,4,4,4,5,6);
        bulu(4,4,4,2.5,9,4);
        bulu(4,4,4,-2.5,9,4);
        bulu(5,5,5,0,9,3);

        //badan
        glPushMatrix();
            setMaterialColor(2,1,1, alphaTrans);
            glRotated(10,1,0,0);
            tubuh(10,17,10,0,0,-15);
        glPopMatrix();

        //bulu badan
        bulu(6,6,6,0,10,-5);
        bulu(6,6,6,6,8,-5);
        bulu(6,6,6,8,3,-5);
        bulu(6,6,6,-6,8,-5);
        bulu(6,6,6,-8,3,-5);
        bulu(5,5,5,0,-5,-6);
        bulu(5,5,5,6,-5,-6);
        bulu(5,5,5,9,-2,-6);
        bulu(5,5,5,-6,-5,-6);
        bulu(5,5,5,-9,-2,-6);

        bulu(6,6,6,0,12,-11);
        bulu(6,6,6,7,9,-11);
        bulu(6,6,6,9,4,-11);
        bulu(6,6,6,-7,9,-11);
        bulu(6,6,6,-9,4,-11);
        bulu(5,5,5,0,-6,-11);
        bulu(5,5,5,7,-5,-11);
        bulu(5,5,5,10,-2,-11);
        bulu(5,5,5,-7,-5,-11);
        bulu(5,5,5,-10,-2,-11);

        bulu(6,6,6,0,12,-16);
        bulu(6,6,6,7,9,-16);
        bulu(6,6,6,10,3,-16);
        bulu(6,6,6,-7,9,-16);
        bulu(6,6,6,-10,3,-16);
        bulu(5,5,5,0,-6,-16);
        bulu(5,5,5,7,-4,-16);
        bulu(5,5,5,10,-1,-16);
        bulu(5,5,5,-7,-4,-16);
        bulu(5,5,5,-10,-1,-16);


        bulu(6,6,6,0,10,-21);
        bulu(6,6,6,6,8,-21);
        bulu(6,6,6,8,3,-21);
        bulu(6,6,6,-6,8,-21);
        bulu(6,6,6,-8,3,-21);
        bulu(5,5,5,0,-5,-21);
        bulu(5,5,5,6,-4,-21);
        bulu(5,5,5,9,-1,-21);
        bulu(5,5,5,-6,-4,-21);
        bulu(5,5,5,-9,-1,-21);

        bulu(6,6,6,0,9,-25);
        bulu(6,6,6,4,7,-25);
        bulu(6,6,6,-4,7,-25);
        bulu(6,6,6,5,2,-25);
        bulu(6,6,6,-5,2,-25);
        bulu(6,6,6,4,-1,-25);
        bulu(6,6,6,-4,-1,-25);
        bulu(6,6,6,0,-2,-25);

        bulu(5,5,5,0,0,-30);
        bulu(5,5,5,3,2,-30);
        bulu(5,5,5,-3,2,-30);
        bulu(5,5,5,0,6,-30);
        bulu(5,5,5,3,4,-30);
        bulu(5,5,5,-3,4,-30);

        bulu(3,4,3,0,3,-35);

        //kaki
        tubuhHitam(1.7, 1.7, 4, 6, -10, -10);
        tubuhHitam(1.7, 1.7, 4, -6, -10, -10);
        tubuhHitam(1.7, 1.7, 4, 6, -9, -22);
        tubuhHitam(1.7, 1.7, 4, -6, -9, -22);

    glPopMatrix();
}

void sheep4()
{
    glPushMatrix();
    glScaled(1,1,0.9);
    glTranslated(0,0,18);
    glRotated(-10,1,0,0);
        //kepala
        glPushMatrix();
            setMaterialColor(10,5,4, alphaTrans);
            elips(9,8,8);
        glPopMatrix();

        //mata
        tubuhHitam(2.2,2.2,2.2, 3.5, -2, 6);
        tubuhHitam(2.2,2.2,2.2, -3.5, -2, 6);

        //mulut
        tubuhHitam(2,2,0.5, 0, -6, 4);

        // tanduk
        setMaterialColor(0.5,0.15,0, alphaTrans);
        glPushMatrix();
            glTranslated(-1,0,-3);
            glPushMatrix();
                glRotated(210,1,0,1);
                tandukCone(3,3,12,5,0,14);
            glPopMatrix();
            glPushMatrix();
                tandukBall(3,3,3, 12.2,6,5.5);
                tandukBall(3,3,3, 11.2,7,5);
                tandukBall(3,3,3, 10.2,7,5);
                tandukBall(3,3,3, 9,6,5);
                tandukBall(3,3,3, 7.2,5,4);
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glScaled(-1,1,1);
            glTranslated(-1,0,-3);
            glPushMatrix();
                glRotated(210,1,0,1);
                tandukCone(3,3,12,5,0,14);
            glPopMatrix();
            glPushMatrix();
                tandukBall(3,3,3, 12.2,6,5.5);
                tandukBall(3,3,3, 11.2,7,5);
                tandukBall(3,3,3, 10.2,7,5);
                tandukBall(3,3,3, 9,6,5);
                tandukBall(3,3,3, 7.2,5,4);
            glPopMatrix();
        glPopMatrix();

        //bulu kepala
        bulu(5,5,5, 0, 5, 7);
        bulu(4,4,4, 4, 5.5, 7);
        bulu(4,4,4, -4, 5.5, 7);
        bulu(4,4,4, 5, 9, 7);
        bulu(4,4,4, -5, 9, 7);
        bulu(4,4,4, 4, 11, 6);
        bulu(4,4,4, -4, 11, 6);
        bulu(5,5,5, 0, 12, 5);
        bulu(5,5,5, 0, 9, 7);

        bulu(8,5,5, 0, 6, 2);

        bulu(5,5,5, 0, 5, -1);
        bulu(4,4,4, 4, 5.5, -1);
        bulu(4,4,4, -4, 5.5, -1);
        bulu(4,4,4, 5, 9, 0);
        bulu(4,4,4, -5, 9, 0);
        bulu(4,4,4, 4, 11, 1);
        bulu(4,4,4, -4, 11, 1);
        bulu(5,5,5, 0, 12, 2);
        bulu(5,5,5, 0, 9, -1);

        //badan
        glPushMatrix();
            setMaterialColor(12,6,6, alphaTrans);
            glRotated(10,1,0,0);
            tubuh(12,17,12,0,0,-15);
        glPopMatrix();

        //bulu badan
        bulu(7,7,7, 0, 11, -5);
        bulu(7,7,7, 6, 9, -5);
        bulu(7,7,7, -6, 9, -5);
        bulu(7,7,7, 10, 6, -5);
        bulu(7,7,7, -10, 6, -5);
        bulu(6,6,6, 8, 0, -5);
        bulu(6,6,6, -8, 0, -5);
        bulu(6,6,6, 5, -2, -5);
        bulu(6,6,6, -5, -2, -5);
        bulu(7,7,7, 0, -4, -5);

        bulu(8,8,8, 0, 13, -11);
        bulu(7,7,7, 8, 11, -11);
        bulu(7,7,7, -8, 11, -11);
        bulu(7,7,7, 11, 8, -11);
        bulu(7,7,7, -11, 8, -11);
        bulu(7,7,7, 12, 4, -11);
        bulu(7,7,7, -12, 4, -11);
        bulu(6,6,6, 10, 0, -11);
        bulu(6,6,6, -10, 0, -11);
        bulu(6,6,6, 7, -3, -11);
        bulu(6,6,6, -7, -3, -11);
        bulu(6,6,6, 3, -5, -11);
        bulu(6,6,6, -3, -5, -11);


        bulu(8,8,8, 0, 14, -18);
        bulu(8,8,8, 6, 12, -18);
        bulu(7,7,7, -6, 12, -18);
        bulu(7,7,7, 10, 10, -18);
        bulu(7,7,7, -10, 10, -18);
        bulu(7,7,7, 11, 6, -18);
        bulu(7,7,7, -11, 6, -18);
        bulu(6,6,6, 11, 0, -18);
        bulu(6,6,6, -11, 0, -18);
        bulu(6,6,6, 7, -3, -18);
        bulu(6,6,6, -7, -3, -18);
        bulu(6,6,6, 2, -5, -18);
        bulu(6,6,6, -2, -5, -18);


        bulu(7,7,7, 0, 12, -25);
        bulu(7,7,7, 6, 10, -25);
        bulu(7,7,7, -6, 10, -25);
        bulu(7,7,7, 8, 6, -25);
        bulu(7,7,7, -8, 6, -25);
        bulu(7,7,7, 7, 2, -25);
        bulu(7,7,7, -7, 2, -25);
        bulu(6,6,6, 2, -2, -25);
        bulu(6,6,6, -2, -2, -25);


        bulu(6,6,6, 0, 10, -32);
        bulu(6,6,6, 5, 7, -32);
        bulu(6,6,6, -5, 7, -32);
        bulu(6,6,6, 4, 3, -32);
        bulu(6,6,6, -4, 3, -32);
        bulu(6,6,6, 0, 1, -32);


        bulu(4,6,4, 0, 5, -36);


        //kaki
        tubuhHitam(1.7, 1.7, 4, 6, -10, -10);
        tubuhHitam(1.7, 1.7, 4, -6, -10, -10);
        tubuhHitam(1.7, 1.7, 4, 6, -9, -22);
        tubuhHitam(1.7, 1.7, 4, -6, -9, -22);


    glPopMatrix();
}

void ayam()
{
    glPushMatrix();

    // badan
    bulu(6,9,6, 0, 0, 0);

    // leher
    glPushMatrix();
    glRotated(15,1,0,0);
    bulu(2.5,2.5,11, 0, 8, 6);
    glPopMatrix();

    // kepala
    glPushMatrix();
    glRotated(5,1,0,0);
    bulu(2.5,4,2.5, 0, 16, 10);
    glPopMatrix();

    // mata
    bulu(2,2,2, 2, 15, 14);
    bulu(2,2,2, -2, 15, 14);
    tubuhHitam(0.7,0.7,0.7, 2.2, 15, 15.5);
    tubuhHitam(0.7,0.7,0.7, -2.2, 15, 15.5);

    //ekor
    glPushMatrix();
    glTranslated(0,0,-6);
    glRotated(30,1,0,0);
    bulu(1.5,5,1.5, 0, 3, -6);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0,0,-6);
    glRotated(10,1,0,0);
    bulu(1.5,5,1.5, 0, 3, -5);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0,0,-6);
    glRotated(-10,1,0,0);
    bulu(1.5,5,1.5, 0, 3, -4);
    glPopMatrix();

    // jengger
    glPushMatrix();
    glRotated(60,1,0,0);
    jengger(1.5,4,1.5, 0, 21, -7);
    glPopMatrix();
    glPushMatrix();
    glRotated(-20,1,0,0);
    jengger(1.5,1.5,4, 0, 15, 14);
    glPopMatrix();
    glPushMatrix();
    jengger(1.5,1.5,4, 0, 20, 11);
    glPopMatrix();
    glPushMatrix();
    glRotated(20,1,0,0);
    jengger(1.5,1.5,4, 0, 23, 6);
    glPopMatrix();
    glPushMatrix();
    glRotated(70,1,0,0);
    jengger(1.5,4,1.5, 0, 15, -7);
    glPopMatrix();

    // paruh
    glPushMatrix();
    glRotated(125,1,0,0);
    paruh(2, 2, 7, 0, 3, -20);
    glPopMatrix();

    // sayap
    glPushMatrix();
        glRotated(-10,1,0,0);
        bulu(1,6,3, 5, 0, 0);
        bulu(1,6,3, -5, 0, 0);
    glPopMatrix();

    // paha
    bulu(2,2,3, 2, -5, 0);
    bulu(2,2,3, -2, -5, 0);

    // kaki
    tulangAyam(0.7,0.7,5, 2.5, -7, 0);
    tulangAyam(0.7,0.7,5, -2.5, -7, 0);
    tulangAyam(1,1,1, 2.5, -11, 0);
    tulangAyam(1,1,1, -2.5, -11, 0);

    // jari
    glPushMatrix();
        tulangAyam(0.7,3,0.7, 2.5, -11, 1.7);
        glPushMatrix();
        glRotated(35,0,1,0);
        tulangAyam(0.7,2.5,0.7, 2.5, -11, 3);
        glPopMatrix();
        glPushMatrix();
        glRotated(-35,0,1,0);
        tulangAyam(0.7,2.5,0.7, 1.75, -11, 0);
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        tulangAyam(0.7,3,0.7, -2.5, -11, 1.7);
        glPushMatrix();
        glRotated(35,0,1,0);
        tulangAyam(0.7,2.5,0.7, -2, -11, 0);
        glPopMatrix();
        glPushMatrix();
        glRotated(-35,0,1,0);
        tulangAyam(0.7,2.5,0.7, -2, -11, 3);
        glPopMatrix();
    glPopMatrix();


    glPopMatrix();
}

void setObjek(int m)
{
    if (model == 1)
    {
        sheep1();
    }
    else if (model == 2)
    {
        sheep2();
    }
    else if (model == 3)
    {
        sheep3();
    }
    else if (model == 4)
    {
        sheep4();
    }
    else if (model == 5)
    {
        sheep1();
    }
    else if (model == 6)
    {
        sheep2();
    }
    else if (model == 7)
    {
        sheep3();
    }
    else if (model == 8)
    {
        sheep4();
    }
    else if (model == 9)
    {
        ayam();
    }
}

void walkSheep(int m)
{
    glPushMatrix();
    
        glTranslated(0, -0, 0);

        glPushMatrix();
        
            glRotated(-10, 1, 0, 0);
            glRotated(-90, 1, 0, 0);
            glRotated(180, 0, 0, 1);
            glScaled(0.75, 0.75, 0.75);
            glTranslated(7.5, 15, 0);

            setObjek(m);
        
        glPopMatrix();

    glPopMatrix();
}

void iconSheep(int m)
{
    glPushMatrix();

    glRotated(-10, 1, 0, 0);
    glRotated(-90, 1, 0, 0);
    glRotated(180, 0, 0, 1);
    glScaled(0.75, 0.75, 0.75);
    glTranslated(7.5, 15, 0);

    setObjek(m);

    glPopMatrix();
}