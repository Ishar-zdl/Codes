/*
 * @Author: Ishar-zdl 
 * @Date: 2023-10-10 17:01:20 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-10-10 17:14:57
 */
#include<bits/stdc++.h>
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
int in[200];
vector<int>node[200];
int main(){
    int n=read();
    for(int i=1,a;i<=n;++i){
        while(1){
            a=read();
            if(!a)break;
            node[i].push_back(a);
            in[a]++;
        }
    }
    queue<int>q;
    for(int i=1;i<=n;++i)
        if(!in[i])q.push(i);
    while(!q.empty()){
        int w=q.front();q.pop();
        cout<<w<<' ';
        for(int i:node[w]){
            in[i]--;if(!in[i])q.push(i);
        }
    }
    return 0;
}