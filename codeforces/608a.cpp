#include<stdio.h>

int max(int x,int y){
  if (x>y) return x;
  return y;
}

int main(){
  int n,s,f,t;
  while (scanf("%d %d",&n,&s)!=EOF){
    int out=0;
    for (int i=0;i<n;i++){
      scanf("%d%d",&f,&t);
      out=max(max(s-f,t)+f,out);
    }
    printf("%d\n",out);
  }
  return 0;
}
