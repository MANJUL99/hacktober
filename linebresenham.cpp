//LINE-BRESENHAM GENERALIZED
#include<graphics.h>
#include<iostream>
using namespace std;
#define abs(x) (x>0?x:x*-1)//but()can be ignored in this case
void bresenham(int x1,int y1,int x2,int y2)
{
  int dx,dy,p,x,y,temp,swap=0,xend;
  dx=abs(x2-x1); dy=abs(y2-y1);
  if(x1>x2){    x=x2; y=y2; xend=x1;  }
  else { x=x1;y=y1;xend=x2;}
  if(dy>dx)
  {
    temp=dx; dx=dy; dy=temp;
    swap=1;
  }
  p=2*dy-dx;
  while(x<=xend)
  {
    putpixel(x,y,WHITE); delay(1);
    if(swap==0) x++;
    else y++;
    if(p>0)
    {
      p=p+2*dy-2*dx;
      if(swap==0) y++;
      else x++;
    }
    else p=p+2*dy;
  }
}
int main()
{
  int gd=DETECT,gm,x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  initgraph(&gd,&gm,NULL);
  bresenham(x1,y1,x2,y2);
  getch();
  closegraph();
  return 0;
}
