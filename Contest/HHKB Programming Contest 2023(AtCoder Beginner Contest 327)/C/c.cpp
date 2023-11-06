/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-04 20:11:06 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-04 20:30:28
 */
#include<bits/stdc++.h>
#define clear memset(map,0,sizeof(map))
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
int s[15][15];
int map[10];
int main(){
    for(int i=1;i<=9;++i){
        for(int j=1;j<=9;++j){
            s[i][j]=read();
        }
    }
    // for(int i=1;i<=)
    for(int i=1;i<=9;++i){
        int tot=0;
        for(int j=1;j<=9;++j){
            if(!map[s[i][j]])map[s[i][j]]=1,tot++;
        }
        if(tot!=9){std::cout<<"No\n";return 0;}
        clear;
    }
    for(int j=1;j<=9;++j){
        int tot=0;
        for(int i=1;i<=9;++i){
            int zc=s[i][j];
            // std::cout<<zc<<'\n';
            if(!map[zc])map[zc]=1,tot++;
        }
        if(tot!=9){std::cout<<"No\n";return 0;}
        clear;
    }
    for(int i=1;i<=9;++i){
        int tot=0;
        int w=i;while(w>3)w-=3;
        for(int x=ceil(1.0*i/3)*3-2;x<=ceil(1.0*i/3)*3;++x){
            for(int y=w*3-2;y<=w*3;++y){
                int zc=s[x][y];
                if(!map[zc])map[zc]=1,tot++;
            }
        }
        if(tot!=9){std::cout<<"No\n";return 0;}
        clear;
    }
    std::cout<<"Yes\n";
    return 0;
}