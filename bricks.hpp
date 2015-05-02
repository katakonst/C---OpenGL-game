using namespace std;
class MovBricks{

public:
    GLfloat brx;
    GLfloat bry;
    int d;
    GLfloat brx1;
    GLfloat bry1;
     int ok2;

    MovBricks()
    {
        d=1;
        ok2=1;
    }
    void setCoord(int x,int y)
    {   brx=x;
        bry=y;
        brx1=x+100;
        bry1=y-10;
    }

    void desenare()
    {
       glRectf(brx, bry, brx1,bry1);
    }
    void coliziune(int px,int py,int px1,int py1,int &dir,int &v,int vit)
    {

      if(dir==1&&(((px>=brx+10&&px<=brx1)|| (px1>=brx&&px1<=brx1))&&((py>=bry1&&py<=bry))))

       {
           dir=rand()%2+1;
          if(dir==1)
              dir=3;
          else
            dir=2;
            v=vit;

       }
       else if(dir==4&&(((px>=brx&&px<=brx1)|| (px1>=brx&&px1<=brx1))&&((py>=bry1&&py<=bry))))
       {
           dir=rand()%2+1;
          if(dir==1)
              dir=3;
          else
            dir=2;
            v=vit;

       }
       else if(dir==2&&(((px>=brx&&px<=brx1)|| (px1>=brx&&px1<=brx1))&&((py>=bry1&&py<=bry))))
       {

             dir=rand()%2+1;
          if(dir==1)
              dir=1;
          else
            dir=4;
            v=vit;
       }
       else if(dir==3&&(((px>=brx&&px<=brx1)|| (px1>=brx&&px1<=brx1))&&((py>=bry1&&py<=bry))))
       {

             dir=rand()%2+1;
          if(dir==1)
              dir=1;
          else
            dir=4;
            v=vit;
       }
       }
    };



    class bricks
    {
        public:
        GLfloat brx;
        GLfloat bry;
        int d;
        GLfloat brx1;
        GLfloat bry1;
         float c1;

    float c2;
    float c3;
    bricks()
    {
        d=1;
    }
     void setCoord(int x,int y)
    {   brx=x;
        bry=y;
        brx1=x+70;
        bry1=y-30;
    }
     void setCol(float x,float y,float z)
    {

       c1=x;
       c2=y;
       c3=z;
    }
    void desenare()
    {
                glColor3f(c1,c2,c3);

       glRectf(brx, bry, brx1,bry1);
    }
          void coliziune(int px,int py,int px1,int py1,int &dir,int &v,int vit){
         if(dir==1&&(((px>=brx&&px<=brx1)|| (px1>=brx&&px1<=brx1))&&((py>=bry1&&py<=bry)||py1>=bry1&&py1<=bry))&&d==1)

       {
           dir=rand()%2+1;
          if(dir==1)
              dir=3;
          else
            dir=2;
            v=vit;
            d=0;
       }
       else if(dir==4&&(((px>=brx&&px<=brx1)|| (px1>=brx&&px1<=brx1))&&((py>=bry1&&py<=bry)||py1>=bry1&&py1<=bry))&&d==1)
       {
           dir=rand()%2+1;
          if(dir==1)
              dir=3;
          else
            dir=2;
            v=vit;
d=0;
       }
       else if(dir==2&&(((px>=brx&&px<=brx1)|| (px1>=brx&&px1<=brx1))&&((py>=bry1&&py<=bry)||py1>=bry1&&py1<=bry))&&d==1)
       {


              d=0;
       }
       else if(dir==3&&(((px>=brx&&px<=brx1)|| (px1>=brx&&px1<=brx1))&&((py>=bry1&&py<=bry)||py1>=bry1&&py1<=bry))&&d==1)
       {

d=0;
       }
          }
    };


