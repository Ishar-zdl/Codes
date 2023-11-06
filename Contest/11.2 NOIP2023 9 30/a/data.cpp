#include<bits/stdc++.h>
using namespace std;
#define reg register
inline int random(int x) { return (rand()%x)*(rand()%x)%x; }
#define maxn 25
int main(){
    srand(time(0));
    freopen("a.in","w",stdout);
    cout<<random(10000000);
    return 0;
}
