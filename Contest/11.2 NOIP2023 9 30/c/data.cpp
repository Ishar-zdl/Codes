#include<bits/stdc++.h>
using namespace std;
#define reg register
inline int random(int x) { return (rand()%x)*(rand()%x)%x+1; }
#define maxn 25
int main(){
    srand(time(0));
    freopen("c.in","w",stdout);
    cout<<10<<' '<<random(10)<<' '<<random(10)<<'\n';
    for(int i=1;i<=10;++i){cout<<random(10)<<' ';}
    return 0;
}
