/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-06 08:21:35 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-06 15:10:13
 */
#include<bits/stdc++.h>
inline int read(){
    char ch=getchar();int x=0,f=1;
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x*f;
}
inline void CIN_sync(){
    #ifdef ONLINE_JUDGE
        std::ios::sync_with_stdio(false);
        std::cin.tie(0),std::cout.tie(0);
    #endif
}
char ans1[5]={'1','r','y','x','y'};
char cn[45][45];
int n,m;
int main(){
    freopen("ryx.in","r",stdin);freopen("ryx.out","w",stdout);
    n=read();
    int ans=2223;
    printf("40 40\n");
    for(int i=1;i<=40;i++)
        for(int j=1;j<=39;++j)
            cn[i][j]=ans1[((j%4)?(j%4):4)];
    for(int j=1;j<=40;++j)cn[j][40]=ans1[((j%4)?(j%4):4)];
    ans=ans-n;
    int w=ans/3;
    int duo=std::max(w-722,0);
    int q=0;
    if(w){
        for(int i=2;i<=39;++i){
            for(int j=2;j<=39;j+=2){
                cn[i][j]='x';w--;
                if(!w)break;
            }
            if(!w)break;
        }
    }
    ans=ans%3+duo*3;
    if(ans){
        for(int i=2;i<=39;i+=2){
        cn[1][i]='x';ans--;
        if(!ans)break;
        cn[40][i]='x';ans--;
        if(!ans)break;
    }
    }
    if(ans){
        for(int i=2;i<=40;i+=2){
        cn[i][40]='x';ans--;
        if(!ans)break;
    }
    }
    for(int i=1;i<=40;++i){
        for(int j=1;j<=40;++j){
            std::cout<<cn[i][j];
        }
        std::cout<<'\n';
    }
}