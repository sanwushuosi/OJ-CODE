#include<stdio.h>
#include<string.h>

int ll(char ch){
  if (ch=='[' || ch=='<' || ch=='(' || ch=='{') return 1;
  return 0;
}

int rr(char ch){
  if (ll(ch)) return 0;
  return 1;
}

int match(char x,char y){
  if (x=='['&&y==']') return 1;
  if (x=='{'&&y=='}') return 1;
  if (x=='('&&y==')') return 1;
  if (x=='<'&&y=='>') return 1;
  return 0;
}

int main(){
  char s[1000005];
  char stack[1000005];
  while (scanf("%s",s)!=EOF){
    int l=strlen(s);
    memset(stack,0,sizeof(stack));
    int lstack=0;
    int fail=0;
    int tot=0;
    for (int i=0;i<l&&fail==0;i++){
      //for (int j=0;j<lstack;j++) printf("%c",stack[j]);printf("\n");
      if (rr(s[i])){
        if (lstack==0){
          fail=1;
          continue;
        }else{
          if (!match(stack[lstack-1],s[i])) tot++;
          lstack--;
        }
      }else stack[lstack++]=s[i];
      //for (int j=0;j<lstack;j++) printf("%c",stack[j]);printf("\n");
      //printf("i=%d,tot=%d\n",i,tot);
    }
    if (fail==1) printf("Impossible\n");
    else if (lstack==0) printf("%d\n",tot);
    else printf("Impossible\n");
  }
  return 0;
}

