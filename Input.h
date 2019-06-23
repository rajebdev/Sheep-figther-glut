
void kunci(unsigned char key, int x, int y)
{
    tempRotX=rotX;
    tempRotY=rotY;
    tempRotZ=rotZ;

    if (key == 'w' || key == 'W')
    {
        rotY += 5;
    }
    if (key == 's' || key == 'S')
    {
        rotY -= 5;
    }
    if (key == 'a' || key == 'A')
    {
        rotX += 5;
    }
    if (key == 'd' || key == 'D')
    {
        rotX -= 5;
    }
    if (key == 'z' || key == 'Z')
    {
        rotZ += 5;
    }
    if (key == 'x' || key == 'X')
    {
        rotZ -= 5;
    }
    if (key == 'v' || key == 'V')
    {
        viewMode < 2 ? viewMode += 1 : viewMode = 0;
    }
    if (key==48){
        rotX = 0;
        rotY = 0;
        rotZ = 0;
        
        angle = 0.0f;
        lx=0.0f,lz=-1.0f;
        x=0.0f, z=5.0f;
        deltaAngle = 0.0f;
        xOrigin = -1;
    }
    
    if (key > 48 && key < 54)
    {
        srand(time(NULL));
        if (loadTimeA == 0)
        {
            sheepModelA[countSheepA] = sheepA1;
            sheepPosA[countSheepA] = key-49;
            sheepMoveA[countSheepA] = 0;
            sheepLifeA[countSheepA] = true;
            loadTimeA = 10;
            sheepA1 = sheepA2;
            sheepA2 = getRandomSheep();
            countSheepA++;
        }
    }
    if ((key > 53 && key < 58) || key == 48)
    {
        srand(time(NULL));
        if (loadTimeB == 0)
        {
            sheepModelB[countSheepB] = sheepB1;
            key == 48 ? sheepPosB[countSheepB] = 0 : sheepPosB[countSheepB] = key-54;
            sheepMoveB[countSheepB] = 0;
            sheepLifeB[countSheepB] = true;
            loadTimeB = 10;
            sheepB1 = sheepB2;
            sheepB2 = getRandomSheep();
            countSheepB++;
        }
    }

    display();
}

void specKey(int key, int x, int y)
{
    if (viewMode == 2) {
            if(key == GLUT_KEY_RIGHT ) {
                    alpha-=0.1;
                    viewDir[0] = cos(alpha);
                    viewDir[1] = sin(alpha);
            }else if(key == GLUT_KEY_LEFT) {
                    alpha+=0.1;
                    viewDir[0] = cos(alpha);
                    viewDir[1] = sin(alpha);
            }else if(key == GLUT_KEY_UP) {
                    pos[0]+=1*viewDir[0];
                    pos[1]+=1*viewDir[1];
                    pos[2]+=1*viewDir[2];
            }else if(key == GLUT_KEY_DOWN) {
                    pos[0]-=1*viewDir[0];
                    pos[1]-=1*viewDir[1];
                    pos[2]-=1*viewDir[2];
            }
            display();
            // cout << pos[0] << " " << pos[1] << " " << pos[2] << endl;
    }
}

void mouseButton(int button, int state, int x, int y)
{

	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON) {

		// when the button is released
		if (state == GLUT_UP) {
			angle += deltaAngle;
			xOrigin = -1;
		}
		else  {// state = GLUT_DOWN
			xOrigin = x;
		}
	}
}

void mouseMove(int x, int y)
{

	// this will only be true when the left button is down
	if (xOrigin >= 0) {

		// update deltaAngle
		deltaAngle = (x - xOrigin) * 0.01f;

		// update camera's direction
		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle);
	}
}