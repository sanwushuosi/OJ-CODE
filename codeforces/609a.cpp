#include <stdio.h>

int main(){
  int n,m,sz[200];
  while(scanf("%d",&n)!=EOF){
    scanf("%d",&m);
    for (int i=0;i<n;i++) scanf("%d",&sz[i]);
    for (int i=0;i<n;i++){
      for (int j=i+1;j<n;j++){
        if (sz[i]<sz[j]){
          int te=sz[i];sz[i]=sz[j];sz[j]=te;
        }
      }
    }
    int tot=sz[0];
    int i=1;
    while (tot<m&&i<n){
      tot+=sz[i];i++;
    }
    printf("%d\n",i);
  }
  return 0;
}
