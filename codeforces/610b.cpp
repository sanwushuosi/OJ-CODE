#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
  int n;
  int sz[200005];
  while (scanf("%d",&n)!=EOF){
    for (int i=0;i<n;i++) scanf("%d",&sz[i]);
    int min=sz[0];
    for (int i=1;i<n;i++) if (sz[i]<min) min=sz[i];
    for (int i=0;i<n;i++) if (sz[i]>min) sz[i]=min+1;
    int htot=0;
    for (int i=0;i<n;i++){
      if (sz[i]==min+1) htot++;
      else break;
    }
    int ttot=0;
    for (int i=n-1;i>=0;i--){
      if (sz[i]==min+1) ttot++;
      else break;
    }
    int tot=0;
    int maxtot=0;
    for (int i=0;i<n;i++){
      if (sz[i]==min+1) tot++;
      else{
        if (tot>maxtot) maxtot=tot;
        tot=0;
      }
    }
    if (tot>maxtot) maxtot=tot;
    if (htot+ttot>maxtot) maxtot=htot+ttot;
    //for (int i=0;i<n;i++) printf("%d ",sz[i]);printf("\n");
    //printf("htot=%d,ttot=%d,maxtot=%d\n",htot,ttot,maxtot);
    long long out=(long long)n*(long long)min;
    out=out+maxtot;
    cout<<out<<endl;
  }
  return 0;
}
