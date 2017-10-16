#include <stdio.h>
#include <string.h>

int main(){
  int n,m,sz[200005];
  int tot[15];
  int cnt[15];
  while (scanf("%d %d",&n,&m)!=EOF){
    for (int i=0;i<n;i++) scanf("%d",&sz[i]);
    memset(tot,0,sizeof(tot));
    for (int i=0;i<n;i++) tot[sz[i]]++;
    //for (int i=1;i<=m;i++) printf("%d ",tot[i]);printf("\n");
    memset(cnt,0,sizeof(cnt));
    for (int i=m;i>=1;i--){
      cnt[i]=cnt[i+1]+tot[i];
    }
    //for (int i=1;i<=m;i++) printf("%d ",cnt[i]);printf("\n");
    int out=0;
    for (int i=1;i<=m;i++){
      out+=tot[i]*cnt[i+1];
    }
    printf("%d\n",out);
  }
  return 0;
}
