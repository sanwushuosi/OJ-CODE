#include <stdio.h>
#include <string.h>

const int maxn=5e+5;
char str[maxn];

int main(){
  memset(str,0,sizeof(str));
  int l=0;
  int n=0;
  for (int i=1;i<1000;i++){
    int te[10];
    int tel=0;
    int tei=i;
    memset(te,0,sizeof(te));
    while (tei>0){
      te[tel++]=tei%10;
      tei/=10;
    }
    //printf("i=%d,te=%d\n",i,te);
    for (int j=0;j<tel;j++){
      str[l++]=te[tel-j-1];
    }
    if (l>1000) break;
  }
  scanf("%d",&n);
  printf("%d\n",str[n-1]);
  return 0;
}


