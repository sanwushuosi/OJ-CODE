#include <stdio.h>
#include <math.h>

double sqr(double _x){
  return _x*_x;
}

double dis(double x1,double y1,double x2,double y2){
  return sqrt(sqr(x1-x2)+sqr(y1-y2));
}

void swap(int &_x,int &_y){
  int te=_x;
  _x=_y;
  _y=te;
}

double min(double _x,double _y){
  if (_x<_y) return _x;
  return _y;
}

const int maxn=1e5+5+5;
double x[maxn];
double y[maxn];
int n;

int main(){
  double ax,ay,bx,by,tx,ty;
  scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&tx,&ty);
  scanf("%d",&n);
  for (int i=0;i<n;i++) scanf("%lf%lf",&x[i],&y[i]);
  int mina1=0;
  int mina2=1;
  if (dis(x[mina1],y[mina1],tx,ty)-dis(ax,ay,x[mina1],y[mina1])<dis(x[mina2],y[mina2],tx,ty)-dis(ax,ay,x[mina2],y[mina2])) swap(mina1,mina2);
  for (int i=2;i<n;i++){
    if (dis(x[i],y[i],tx,ty)-dis(ax,ay,x[i],y[i])>dis(x[mina2],y[mina2],tx,ty)-dis(ax,ay,x[mina2],y[mina2])) mina2=i;
    if (dis(x[mina1],y[mina1],tx,ty)-dis(ax,ay,x[mina1],y[mina1])<dis(x[mina2],y[mina2],tx,ty)-dis(ax,ay,x[mina2],y[mina2])) swap(mina1,mina2);
  }

  int minb1=0;
  int minb2=1;
  if (dis(x[minb1],y[minb1],tx,ty)-dis(bx,by,x[minb1],y[minb1])<dis(x[minb2],y[minb2],tx,ty)-dis(bx,by,x[minb2],y[minb2])) swap(minb1,minb2);
  for (int i=2;i<n;i++){
    if (dis(x[i],y[i],tx,ty)-dis(bx,by,x[i],y[i])>dis(x[minb2],y[minb2],tx,ty)-dis(bx,by,x[minb2],y[minb2])) minb2=i;
    if (dis(x[minb1],y[minb1],tx,ty)-dis(bx,by,x[minb1],y[minb1])<dis(x[minb2],y[minb2],tx,ty)-dis(bx,by,x[minb2],y[minb2])) swap(minb1,minb2);
  }

  double ret=0.0;
  if (n==1){
    ret=min(dis(ax,ay,x[0],y[0])+dis(x[0],y[0],tx,ty),dis(bx,by,x[0],y[0])+dis(x[0],y[0],tx,ty));
  }else{
    for (int i=0;i<n;i++) ret+=dis(x[i],y[i],tx,ty)*2;
    int choicea=mina1;
    int choiceb=minb1;
    if (choicea != choiceb){
      ret-=dis(x[mina1],y[mina1],tx,ty)-dis(ax,ay,x[mina1],y[mina1]);
      ret-=dis(x[minb1],y[minb1],tx,ty)-dis(bx,by,x[minb1],y[minb1]);
    }else{
      double ret1=ret;
      double ret2=ret;
      ret1-=dis(x[mina1],y[mina1],tx,ty)-dis(ax,ay,x[mina1],y[mina1]);
      ret1-=dis(x[minb2],y[minb2],tx,ty)-dis(bx,by,x[minb2],y[minb2]);
      ret2-=dis(x[mina2],y[mina2],tx,ty)-dis(ax,ay,x[mina2],y[mina2]);
      ret2-=dis(x[minb1],y[minb1],tx,ty)-dis(bx,by,x[minb1],y[minb1]);
      ret=min(ret1,ret2);
    }
  }
  printf("%.12lf\n",ret);
  return 0;
}
