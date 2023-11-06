/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-30 10:32:35 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-30 22:04:05
 */
#include<bits/stdc++.h>
inline int read(){
    char ch=getchar();int x=0,f=1;
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x*f;
}
const int N=5e5+10;
int n,k,s,b[N],a[N],rnk1[N],rnk2[N],bit[N],next[N],ans[N],tot;
// std::pair<int,int>a[N],zc[N];
// inline int lb(int x){return x&(-x);}
#define lowbit(x) x&(-x)


inline void add(int x,int val){for(;x<=s;x+=lowbit(x))bit[x]+=val;}
inline int query(int x){
    int res=0;
    for(;x;x-=lowbit(x))res+=bit[x];
    return res;
}
inline void input(){
    n=read(),k=read(),s=read();
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=1;i<=k;++i){
        b[i]=read();
        add(b[i],1);
        rnk1[i]=query(b[i]);rnk2[i]=query(b[i]-1);
    }
    for(int i=0;i<=s;++i)bit[i]=0;
}
inline void get_next(){
    for(int i=2,j=0;i<=k;++i){
        while(j&&(rnk1[j+1]!=rnk1[i]||rnk2[j+1]!=rnk2[i]))j=next[j];
        next[i]=++j;
    }
}
inline void match(){
    for(int i=1,j=0;i<=n;++i){
        add(a[i],1);
        while(j&&(rnk1[j+1]!=query(a[i])||rnk2[j+1]!=query(a[i]-1))){
            for(int q=i-j;q<i-next[j];++q)add(a[q],-1);
            j=next[j];
        }
        j++;
        if(j==k)ans[++tot]=i-k+1;
    }
}
int main(){
    input();
    get_next();
    match();
    printf("%d\n",tot);
    for(int i=1;i<=tot;++i)printf("%d\n",ans[i]);   
}