#include <GL/glut.h>
#include <stdlib.h>
#include<windows.h>
#include<time.h>
#include<iostream>
#include <math.h>
#include "bricks.hpp"
using namespace std;
GLfloat x=300,y=20,bx=300,by=300,x2=300,y2=600,x3=300,y3=400,ok2=1;
int dir=1,v=3,vit=4,maxx=600,maxy=600,c=1;
struct br
{
    GLfloat x;
    GLfloat y;
    int d=1;
};
bricks bricksVec[100][100];
MovBricks brc[2];
void display(void)
{
glColor3f(1.0f,1.0f,1.0f);
glClear(GL_COLOR_BUFFER_BIT);
glPushMatrix();
glRectf(x2, y2, x2+100, y2-10);
glColor3f(0.0f,0.0f,1.0f);
glRectf(bx, by, bx+20, by+20);
glColor3f(0.0f,1.0f,0.0f);
 for(int i=0;i<=5;i++)
{

      for(int j=0;j<=5;j++)
      {

          if(bricksVec[i][j].d)
           bricksVec[i][j].desenare();

      }

}
     glColor3f(1,1,0);
for(int i=0;i<2;i++)
     brc[i].desenare();
glPopMatrix();
glutSwapBuffers();


}


void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
   GLfloat tempx,tempy=0,distx,disty;
   for(int i=0;i<=5;i++)
{

       tempx=70;
      for(int j=0;j<=5;j++)
{

       bricksVec[i][j].setCoord(tempx,tempy);
           float r=rand()/9.0;
           float c1=r-(int)r;
            r=rand()/9.0;
           float c2=r-(int)r;
           r=rand()/9.0;
           float c3=r-(int)r;
            bricksVec[i][j].setCol(c1,c2,c3);
                      tempx+=80;




      }
      tempy+=50;

}
 brc[0].setCoord(50,350);
      brc[1].setCoord(500,450);

}

void reshape(int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, 600.0, 600.0, 0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}



void miscare(int x)
{

 glutTimerFunc(25,miscare,0);
 glutPostRedisplay();


 for(int i=0;i<=5;i++)
      for( int j=0;j<=5;j++)
 {

    bricksVec[i][j].coliziune(bx,by,bx+20,by+26,dir,v,vit);

 }
 for(int i=0;i<2;i++)
  if(brc[i].brx>=-3&&brc[i].brx1<=604)
    {
        if(brc[i].brx<=0)
             brc[i].ok2=0;
        else if(brc[i].brx1>=600)
               brc[i].ok2=1;
        if( brc[i].ok2==1)
        {
            brc[i].brx1-=3;
            brc[i].brx-=3;

            }
           else if( brc[i].ok2==0)
        {
            brc[i].brx1+=3;
            brc[i].brx+=3;
            }
    }
for(int i=0;i<2;i++)
     brc[i].coliziune(bx,by,bx+20,by+16,dir,v,vit);
 if(dir==2&&bx>=x2&&bx<=x2+100&&by>=y2-20){

 dir=rand()%2+1;
          if(dir==1)
              dir=1;
          else
            dir=4;
              v=vit;
 }
 else if(dir==3&&bx>=x2&&bx<=x2+100&&by>=y2-20){
        dir=rand()%2+1;
          if(dir==1)
              dir=1;
          else
            dir=4;
            v=vit;

 }
 if(dir==2 && bx>maxx)
          {
              dir=3;
          }
          else if(dir==4 && bx<0)
          {
              dir=1;
          }
           else if(dir==3 && bx<0)
          {
              dir=2;
          }

         else if(dir==1 && bx>maxx-20)
          {
              dir=4;
         }
          else if(dir==1 && by<0)
          {
              dir=3;
         }
         else if(dir==4 && by<0)
          {
              dir=2;
         }

         if(dir==1)
        {
           bx+=v;
           by-=v;
        }
       else if(dir==2)
       {
           bx+=v;
           by+=v;
       }
       else if(dir==3)
       {
           bx-=v;
           by+=v;
       }
       else if(dir==4)
       {
           bx-=v;
           by-=v;
       }

       if(by>600)
{
    for(int i=0;i<=5;i++)
         for(int j=0;j<=5;j++){
            bricksVec[i][j].d=1;
             float r=rand()/9.0;
           float c1=r-(int)r;
            r=rand()/9.0;
           float c2=r-(int)r;
           r=rand()/9.0;
           float c3=r-(int)r;
            bricksVec[i][j].setCol(c1,c2,c3);

            }
    bx=300;
    by=300;
}
if(GetAsyncKeyState(VK_RIGHT))
if(x2<500)
x2+=8;
if(GetAsyncKeyState(VK_LEFT))
    if(x2>0)
x2-=8;


     }

int main(int argc, char** argv)
{


   srand(time(0));
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (600, 600);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init();

   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutTimerFunc(25,miscare,0);
   glutMainLoop();
   return 0;
}
