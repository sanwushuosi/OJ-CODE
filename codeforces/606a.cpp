#include <stdio.h>
#include <string.h>

int main(){
  int in[4];
  int out[4];
  while (scanf("%d %d %d", &in[0], &in[1], &in[2])!=EOF){
    scanf("%d %d %d", &out[0], &out[1], &out[2]);
    int sz[4];
    memset(sz, 0, sizeof(sz));
    for (int i = 0; i < 3; i ++) sz[i] = in[i] - out[i];
    for (int i = 0; i < 3; i++){
      for (int j = i + 1; j < 3; j++){
        if (sz[i] < sz[j]){
          int te = sz[i];sz[i] = sz[j];sz[j] = te;
          te = in[i]; in[i] = in[j];in[j]=te;
          te = out[i];out[i]=out[j];out[j]=te;
        }
      }
    }
    //for (int i = 0; i < 3; i++) printf("%d\t",sz[i]);
    //printf("\n");
    int final = 0;
    for (int i=2;i>=0;i--){
      if (sz[i]<=0) final += sz[i];
      else final += int(sz[i]/2);
    }
    if (final >= 0) printf("Yes\n");
    else printf("No\n");
    /*
    if (sz[2] >= 0){
      if (in[0]>1) printf("Yes\n");
      else if (sz[0]>0) printf("No\n");
    }
    else if (sz[0] < 0) printf("No\n");
    else{
      int tota, totb;
      if (sz[1]>=0) {
        tota = sz[0] + sz[1];
        totb = sz[2];
      }else{
        tota = sz[0];
        totb = sz[1] + sz[2];
      }
      //printf("%d\t%d\n",tota,totb);
      if (tota > - totb * 2) printf("Yes\n");
      else if (tota == - totb * 2){
        if (sz[1] <= 0) printf("Yes\n");
        else if (int(sz[0]/2) + int(sz[1]/2) >= -sz[2]) printf("Yes\n");
        else printf("No\n");
      }else printf("No\n");
    }
    */
  }
  return 0;
}

