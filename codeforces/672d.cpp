#include <cstdio>
#include <iostream>
using namespace std;

const int maxn=5e+5+5;
int n,k;
int c[maxn];

long long cal_min(int x){
  long long tot=0;
  for (int i=0;i<n;i++){
    if (c[i]<x) tot=tot+(long long)x - (long long)c[i];
  }
  return tot;
}

int min_search(int h,int t){
  //printf("debug_min, h = %d, t = %d\n",h,t);
  if (h>t) return 0;
  if (h==t-1||h==t){
    long long tot1=cal_min(h);
    long long tot2=cal_min(t);
    //cout<<tot1<<tot2<<k<<endl;
    if (tot2<=k) return t;
    else if (tot1<=k) return h;
    else return 0;
  }
  else{
    int mid=(h+t)/2;
    long long tot3=cal_min(mid);
    if (tot3<=k) return min_search(mid,t);
    else return min_search(h,mid-1);
  }
}

long long cal_max(int x){
  long long tot=0;
  for (int i=0;i<n;i++){
    if (c[i]>x) tot=tot + (long long)c[i] - (long long)x;
  }
  return tot;
}

int max_search(int h,int t){
  //printf("debug_max, h = %d, t = %d\n",h,t);
  if (h>t) return 1e9+1;
  if (h==t-1||h==t){
    long long tot1=cal_max(h);
    long long tot2=cal_max(t);
    //cout<<tot1<<tot2<<k<<endl;
    if (tot1<=k) return h;
    else if (tot2<=k) return t;
    else return 1e9+1;
  }
  else{
    int mid=(h+t)/2;
    long long tot3=cal_max(mid);
    if (tot3<=k) return max_search(h,mid);
    else return max_search(mid+1,t);
  }
}



int main(){
  cin>>n>>k;
  for (int i=0;i<n;i++) cin>>c[i];
  int lower=min_search(0,1e9);
  int upper=max_search(0,1e9);
  //printf("lower = %d, upper = %d\n",lower, upper);
  if (upper>lower) printf("%d\n",upper-lower);
  else{
    int last=0;
    for (int i=0;i<n;i++) last=(last+c[i])%n;
    if (last==0) printf("0\n");
    else printf("1\n");
  }
  return 0;
}

