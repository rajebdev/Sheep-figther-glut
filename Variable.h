#include <time.h>
// Rotation
float rotX=0, rotY=0, rotZ=0;
float tempRotX=0, tempRotY=0, tempRotZ=0;

// Mouse Gerak
float angle = 0.0f;
float lx=0.0f,lz=-1.0f;
float x=0.0f, z=5.0f;
float deltaAngle = 0.0f;
int xOrigin = -1;

int model = 0;

// Cameras
int viewMode = 1;
float pos[] = {2,10.5,1.5};
float viewDir[] = {0,-1,0};
float alpha = 5;

// Transparant Objek
float alphaTrans = 1;

// Game play

// loading life
float lifeBarA = 100;
float lifeBarB = 100;

// loading sheep
float loadTimeA = 0;
float loadTimeB = 0;

// sheep color
bool black = false;
bool white = true;

// animasi

bool maju = true;
float animasiMove = 0;

// Icon sheep

int sheepA1 = 0;
int sheepA2 = 0;
int sheepB1 = 0;
int sheepB2 = 0;

// time
time_t timeStart, timeDisplay = time(NULL), timeSec;
int mod = 0, count = 0;
time_t timeSecTemp;

// sheep array
int *sheepPosA, *sheepModelA; 
float *sheepMoveA;
bool *sheepLifeA;
int *sheepPosB, *sheepModelB;
float *sheepMoveB;
bool *sheepLifeB;

// count sheep A B
int countSheepA = 0;
int countSheepB = 0;

// index awal sheep A B
int startSheepA = 0;
int startSheepB = 0;
