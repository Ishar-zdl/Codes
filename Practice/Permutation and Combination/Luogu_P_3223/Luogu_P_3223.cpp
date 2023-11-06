/*
 * @Author: Ishar-zdl 
 * @Date: 2023-11-02 06:59:27 
 * @Last Modified by: Ishar-zdl
 * @Last Modified time: 2023-11-05 11:12:40
 */
#include<bits/stdc++.h>
#define get_int(a) scanf("%d",&a)
#define put_int(a) printf("%d",a)
using namespace std;
struct bignum{
	#define base 10000
	int a[20000];
	bignum(){memset(a,0,sizeof(a));}
    inline void init(){memset(a,0,sizeof(a));a[0]=1;a[1]=1;}
    inline bignum trans(int b){
        bignum ans;
        while(b){ans.a[++ans.a[0]]=b%base;b/=base;}
        return ans;
    }
    bignum operator+(const bignum &b){
		bignum ans;
		for(int i=1,x=0,tmp=0;x||i<=a[0]||i<=b.a[0];++i){
			tmp=a[i]+b.a[i]+x;
			ans.a[++ans.a[0]]=tmp%base;
			x=tmp/base;
		}
		return ans;
	}
    bignum operator-(const bignum &b){
		bignum ans;
		for(int i=1,x=0,tmp=0;i<=a[0];++i){
			tmp=a[i]-b.a[i]-x;
			if(tmp>=0) x=0;
			else tmp+=base,x=1;
			ans.a[++ans.a[0]]=tmp;
		}
		while(ans.a[0]>1&&ans.a[ans.a[0]]==0) ans.a[0]--;
		return ans;
	}
    bignum operator*(const bignum &b){
        bignum ans;ans.a[0]=a[0]+b.a[0];
        for(int i=1;i<=a[0];++i){
            for(int j=1,x=0;x||j<=b.a[0];++j){
                ans.a[i+j-1]+=x+a[i]*b.a[j];
                x=ans.a[i+j-1]/base;
                ans.a[i+j-1]%=base;
            }
        }
        while(ans.a[0]>1&&ans.a[ans.a[0]]==0) ans.a[0]--;
        return ans;
    }
    bignum operator*(const int &b){
    	bignum ans;
    	for(int i=1,x=0,tmp=0;x||i<=a[0];++i){
    		tmp=a[i]*b+x;
    		ans.a[++ans.a[0]]=tmp%base;
    		x=tmp/base;
		}
		return ans;
	}
	friend bool operator<(const bignum &x,const bignum &y){
		if(x.a[0]^y.a[0]) return x.a[0]<y.a[0];
		for(int i=x.a[0];i>=1;--i) if(x.a[i]^y.a[i]) return x.a[i]<y.a[i];
		return false;
	}
    friend bool operator>(const bignum &x,const bignum &y){return y<x;}
    friend bool operator==(const bignum &x,const bignum &y){return !(x>y)&&!(x<y);}
	inline void print(){put_int(a[a[0]]);for(int i=a[0]-1;i>=1;i--)printf("%04d",a[i]);}
	#undef base
}c;
inline bignum A(int n,int m){bignum ans;ans.init();for(int i=n-m+1;i<=n;++i)ans=ans*i;return ans;}
// inline int C(int n,int m){return A(n,m)/A(m,m);}
int n,m;
int main(){
    get_int(n);get_int(m);
    // c.a[0]=c.a1
    // c=A(n+1,n+1)*2;
    (A(n,n)*A(n+1,2)*A(n+3,m)+A(n,n)*2*m*(n+1)*A(n+2,m-1)).print();
    // ((c*A(n+2,m-1)*m)+(A(n+3,m)*(A(n+2,n+2)-c))).print();
}