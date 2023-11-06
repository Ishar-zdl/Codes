/*
 * @Author: Ishar-zdl 
 * @Date: 2023-09-27 07:31:24 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-09-27 14:20:00
 */
#include<bits/stdc++.h>
#define N (int)(1e4+5)

using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x*f;
}
inline void write(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+48);
}
// map<int,int>
int a[N],ans,pre[N],vis[N],tot;
map<int,bool>s;
inline void get_prime(int n){
    for(int i=2;i<=n;i++){
        if(!vis[i])pre[++tot]=i;
        for(int j=1,m;j<=tot;j++){
            m=pre[j]*i;if(m<=n)vis[m]=pre[j];
            if(i%pre[j]==0)break;
        }
    }
}

int main(){
    freopen("color.in","r",stdin);freopen("color.out","w",stdout);
    int n=read();
    if(n<8){
            get_prime(n);
        for(int i=1;i<=n;i++)a[i]++;
        for(int i=1;i<=n;i++){
            if(!s[a[i]])s[a[i]]=1,ans++;
            for(int j=1,m;j<=tot&&pre[j]+i<=n;j++){
                m=pre[j];if(a[i]==a[i+m])a[i+m]++;
            }
        }
        write(ans);putchar('\n');
        for(int i=1;i<=n;i++)write(a[i]),putchar(' ');
    }
    else{
        printf("4\n");
        for(int i=1;i<=n/4*4;i+=4){
            printf("1 2 3 4 ");
        }
        for(int i=1;i<=n%4;i++)printf("%d ",i);
    }
    return 0;
}