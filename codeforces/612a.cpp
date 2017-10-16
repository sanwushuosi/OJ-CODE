#include <stdio.h>

int main(){
  int n,p,q;
  char s[105];
  while (scanf("%d%d%d",&n,&p,&q)!=EOF){
    scanf("%s",s);
    int i;
    int find=0;
    for (i=0;i<=int(n/p)&&find==0;i++){
      int te=n-p*i;
      int div=int(te/q);
      if (div*q==te){
        printf("%d\n",i+div);
        for (int j=0;j<i;j++){
          for (int k=0;k<p;k++) printf("%c",s[j*p+k]);
          printf("\n");
        }
        for (int j=0;j<div;j++){
          for (int k=0;k<q;k++) printf("%c",s[i*p+j*q+k]);
          printf("\n");
        }
        find=1;
      }
    }
    if (find==0) printf("-1\n");
  }
  return 0;
}
