#include<bits/stdc++.h>
using namespace std;
int T,q,n,t[3000005][130],cnt[3000005],idx;
char s[3000005];
void insert(char str[]){
    int p=0,len=strlen(str);
    for(int i=0;i<len;i++){
        int c=str[i]-'0';
        // int c=getnum(str[i]);
        if(!t[p][c])
            t[p][c]=++idx;
        p=t[p][c];
        cnt[p]++;
    }
}
int find(char str[]){
    int p=0,len=strlen(str);
    for(int i=0;i<len;i++){
        int c=str[i]-'0';
        // int c=getnum(str[i]);
        if(!t[p][c])
            return 0;
        p=t[p][c];
    }
    return cnt[p];
}
int main(){
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<=idx;i++)
            for(int j=0;j<=122;j++)
                t[i][j]=0;
        for(int i=0;i<=idx;i++)
            cnt[i]=0;
        idx=0;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++){
            scanf("%s",s);
            insert(s);
        }
        for(int i=1;i<=q;i++){
            scanf("%s",s);
            printf("%d\n",find(s));
        }
    }
    return 0;
}
