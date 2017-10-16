#include <stdio.h>

int main(){
  int n;
  int sz[100005];
  while (scanf("%d",&n)!=EOF){
    int sum=0;
    for (int i=0;i<n;i++) {scanf("%d",&sz[i]);sum+=sz[i];}
    int div=int(sum*1.0/n);
    int out=0;
    if (sum == div * n){
      for (int i=0;i<n;i++){
        if (sz[i]<div) out+=div-sz[i];
      }
    }else{
      int out1=0;
      int out2=0;
      for (int i=0;i<n;i++){
        if (sz[i]<div) out1+=div-sz[i];
        else if (sz[i]>div+1) out2+=sz[i]-div-1;
      }
      if (out1>out2) out=out1;
      else out=out2;
      //out=out1?out2:out1>out2;
    }
    printf("%d\n",out);
  }
  return 0;
}
