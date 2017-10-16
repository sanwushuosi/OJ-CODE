#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int max_num=1000000;
int tower[max_num+5];
int normal[max_num+5];
int cut[max_num+5];

int max(int x,int y){
  if (x>y) return x;
  return y;
}

int main(){
  int n;
  int a,b;
  while (scanf("%d",&n)!=EOF){
    int maxm=0;
    memset(tower,0,sizeof(tower));
    for (int i=0;i<n;i++){
      scanf("%d %d",&a,&b);
      if (b>a&&a!=0) b=a;
      tower[a]=b;
      maxm=max(maxm,a);
    }
    memset(normal,0,sizeof(normal));
    memset(cut,0,sizeof(cut));
    if (tower[0]!=0) normal[0]=1;
    for (int i=1;i<=maxm;i++){
      if (tower[i]==0){
        normal[i]=normal[i-1];
        cut[i]=normal[i-1];
      }else{
        normal[i]=normal[i-tower[i]-1]+1;
        cut[i]=normal[i-1];
      }
    }
    /*    
    for (int i=0;i<=maxm;i++) printf("%d ",tower[i]);printf("\n");
    for (int i=0;i<=maxm;i++) printf("%d ",normal[i]);printf("\n");
    for (int i=0;i<=maxm;i++) printf("%d ",cut[i]);printf("\n");
    printf("=========================\n");
    */
    int rest=normal[maxm];
    for (int i=maxm;i>=0;i--){
      if (cut[i]>rest) rest=cut[i];
    }
    printf("%d\n",n-rest);
  }
  return 0;
}


