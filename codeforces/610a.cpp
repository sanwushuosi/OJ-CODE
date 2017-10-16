#include<stdio.h>
int main(){
  int n;
  while(scanf("%d",&n)!=EOF){
    if (n%2==1) printf("0\n");
    else{
      int tot=n/2;
      if (tot%2==1) printf("%d\n",tot/2);
      else printf("%d\n",tot/2-1);
    }
  }
  return 0;
}

