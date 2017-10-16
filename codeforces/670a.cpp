#include <stdio.h>

int main(){
  int n;
  while (scanf("%d",&n)!=EOF){
    int a = int(n/7);
    int b = n % 7;
    if (b==0) printf("%d %d\n",a*2, a*2);
    else if (b==1) printf("%d %d\n", a*2, a*2+1);
    else if (b>=2 && b <=5) printf("%d %d\n", a*2, a*2+2);
    else printf("%d %d\n", a*2+1, a*2+2);
  }
  return 0;
}

