#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100; 
const int mod = 2009; 

int n, m, T; 

struct mat
{
	int r, c; 
	int a[MaxN + 1][MaxN + 1]; 
	
	mat(){}
	mat(const int &_r, const int &_c):
		r(_r), c(_c) 
	{
		memset(a, 0, sizeof(a)); 
	}
	
	inline void clear()
	{
		memset(a, 0, sizeof(a)); 
		for (int i = 1; i <= r; ++i)
			a[i][i] = 1; 
	}
	
	inline mat operator * (const mat &rhs) const
	{
		mat res(r, rhs.c); 
		for (int i = 1; i <= r; ++i)
			for (int j = 1; j <= rhs.c; ++j)
			{
				for (int k = 1; k <= c; ++k)
					res.a[i][j] += a[i][k] * rhs.a[k][j]; 
				res.a[i][j] %= mod; 
			}
		return res; 
	}
	
	inline mat operator ^ (int p) const
	{
		mat res(r, c), x = *this; 
		res.clear(); 
		for (; p; p >>= 1, x = x * x)
			if (p & 1)
				res = res * x; 
		return res; 
	}
}f; 

inline int pos(const int &u, const int &i)
{
	return u + i * n; 
}

int main()
{
    // freopen("in.in","r",stdin);
    // freopen("outright.out","w",stdout);
	scanf("%d%d", &n, &T); 
	m = n * 9; 
	f = mat(m, m); 
	int x; 
	for (int i = 1; i <= n; ++i){
		for(int zc=i*9-7;zc<=i*9;zc++)
			f.a[zc][zc-1]=1;
		for (int j = 1; j <= n; ++j){
			scanf("%1d", &x); 
			if (x)
 				f.a[i*9-8][j*9-9+x] = 1; 
		}
	}
	f = f ^ T; 
	printf("%d\n", f.a[1][n*9-8]); 
	return 0; 
}