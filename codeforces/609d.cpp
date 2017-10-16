//#include<stdio.h>
//#include<string.h>

//#include <bits/stdc++.h>
//using namespace std;
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=200000;
int a[maxn+5],b[maxn+5];
int totd[maxn+5],totp[maxn+5];
int k,s;

long long cal_min(int x){
  long long ret=(long long)totd[0]*(long long)a[x]+(long long)totp[0]*(long long)b[x];
  for (int i=1;i<=k;i++){
    long long tmp=(long long)totd[i]*(long long)a[x]+(long long)totp[i]*(long long)b[x];
    if (tmp<ret) ret=tmp;
  }
  return ret;
}

int find_min(int x){
  long long tot=(long long)totd[0]*(long long)a[x]+(long long)totp[0]*(long long)b[x];
  int ret=0;
  for (int i=1;i<=k;i++){
    long long tmp=(long long)totd[i]*(long long)a[x]+(long long)totp[i]*(long long)b[x];
    if (tmp<tot) {tot=tmp;ret=i;}
  }
  return ret;
}


int b_search(int x,int y){
  if (y-x<0) return -1;
  if (y-x==0){
    long long tot=cal_min(x);
    if (tot<=s) return x;
    else return -1;
  }else if (y-x==1){
    long long tot1=cal_min(x);
    long long tot2=cal_min(y);
    if (tot1<=s) return x;
    else if (tot2<=s) return y;
    else return -1;
  }else{
    int mid=int((x+y)/2);
    long long tot=cal_min(mid);
    if (tot<=s) return b_search(x,mid);
    else return b_search(mid+1,y);
  }
  return -1;
}



int main(){
  int n,m;
  int dollar[maxn+5];
  int pound[maxn+5];
  int dp_bk[maxn+5][2];
  int t,c;
  while(scanf("%d",&n)!=EOF){
    scanf("%d%d%d",&m,&k,&s);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++) scanf("%d",&b[i]);
    for (int i=1;i<n;i++) if (a[i]>a[i-1]) a[i]=a[i-1];
    for (int i=1;i<n;i++) if (b[i]>b[i-1]) b[i]=b[i-1];
    int l_d=0;
    int l_p=0;
    memset(dollar,0,sizeof(dollar));
    memset(pound,0,sizeof(pound));
    memset(dp_bk,0,sizeof(dp_bk));
    for (int i=0;i<m;i++){
      scanf("%d%d",&t,&c);
      dp_bk[i][0]=t;dp_bk[i][1]=c;
      if (t==1){
        dollar[l_d++]=c;
      }else pound[l_p++]=c;
    }
    sort(dollar,dollar+l_d);
    //reverse(dollar,dollar+l_d);
    sort(pound,pound+l_p);
    //reverse(pound,pound+l_p);
    memset(totd,0,sizeof(totd));
    totd[0]=0;
    for (int i=1;i<=k;i++){
      if (dollar[i-1]>0) totd[i]=totd[i-1]+dollar[i-1];
      else totd[i]=1000000001;
    }
    memset(totp,0,sizeof(totp));
    totp[0]=0;
    for (int i=1;i<=k;i++){
      if (pound[i-1]>0) totp[i]=totp[i-1]+pound[i-1];
      else totp[i]=1000000001;
    }
    reverse(totp,totp+k+1);
    for (int i=l_d;i<k;i++) dollar[i]=1000001;
    for (int i=l_p;i<k;i++) pound[i]=1000001;
    /*
    for (int i=0;i<n;i++) printf("%d\t",a[i]);printf("\n");
    for (int i=0;i<n;i++) printf("%d\t",b[i]);printf("\n");
    for (int i=0;i<k;i++) printf("%d\t",dollar[i]);printf("\n");
    for (int i=0;i<k;i++) printf("%d\t",pound[i]);printf("\n");
    for (int i=0;i<=k;i++) printf("%d\t",totd[i]);printf("\n");
    for (int i=0;i<=k;i++) printf("%d\t",totp[i]);printf("\n");
    */
    int ret=b_search(0,n-1);
    if (ret == -1) printf("-1\n");
    else{
      printf("%d\n",ret+1);
      int buy_dollar_day=0;
      while (a[buy_dollar_day]>a[ret]&&buy_dollar_day<ret) buy_dollar_day++;
      int buy_pound_day=0;
      while (b[buy_pound_day]>b[ret]&&buy_pound_day<ret) buy_pound_day++;
      int pos=find_min(ret);
      //printf("pos=%d\n",pos);
      for (int i=0;i<m&&k>0;i++){
        if (dp_bk[i][0]==1){
          if (dp_bk[i][1]<=dollar[pos]&&k>0) {printf("%d %d\n",i+1,buy_dollar_day+1);k--;}
        }else{
          if (dp_bk[i][1]<=pound[pos]&&k>0) {printf("%d %d\n",i+1,buy_pound_day+1);k--;}
        }
      }
    }
  }
  return 0;
}

