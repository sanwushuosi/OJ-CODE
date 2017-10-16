#include <stdio.h>
#include <string.h>
#include <math.h>

const int maxn = 1000000;
int sz[maxn+5];

int tot(int x){
  return int(x/2.0*(x+1));
}

int main(){
  int n,k;
  scanf("%d %d",&n,&k);
  memset(sz,0,sizeof(sz));
  for (int i=0;i<n;i++) scanf("%d",&sz[i]);
  int find_i = int(sqrt(k)*sqrt(2))-1;
  while(tot(find_i+1)<k) find_i++;
  //printf("debug2 : find_i = %d\n",find_i);
  //printf("debug3 : tot(find_i) = %d\n",tot(find_i));
  //printf("debug4 : k-tot(find_i) = %d\n",k-tot(find_i));
  if (k==1) printf("%d\n",sz[0]);
  else printf("%d\n",sz[k-tot(find_i)-1]);
  return 0;
}



