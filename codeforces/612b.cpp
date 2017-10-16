#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int abs(int x){
  if (x<0) return -x;
  return x;
}

int main(){
  int n;
  int sz[200005];
  int f;
  while (scanf("%d",&n)!=EOF){
    for (int i=0;i<n;i++){
      scanf("%d",&f);
      sz[f-1]=i;
    }
    long long tot=0;
    for (int i=1;i<n;i++) tot=tot+abs(sz[i]-sz[i-1]);
    cout<<tot<<endl;
  }
  return 0;
}
