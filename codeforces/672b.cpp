#include <stdio.h>
#include <string.h>

const int maxn=1e+5+5;
int l;
char str[maxn];
int mark[100];

int main(){
  scanf("%d",&l);
  scanf("%s",str);
  int ret=0;
  memset(mark,0,sizeof(mark));
  for (int i=0;i<l;i++){
    if (mark[str[i]-'a']==1) ret++;
    mark[str[i]-'a']=1;
  }
  if (l>26) printf("-1\n");
  else printf("%d\n",ret);
}

