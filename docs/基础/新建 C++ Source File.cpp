#include<cstdio>
const int mod=998244353;
inline int add(int a,int b) {
	if((a+=b)>=mod)
		a-=mod;
	return a;
}
inline int sub(int a,int b) {
	if((a-=b)<0)
		a+=mod;
	return a;
}
inline int mul(int a,int b) {
	return (long long)a*b%mod;
}
inline int qpow(int a,int p) {
	int res=1;
	for(; p; a=mul(a,a),p>>=1)
		if(p&1)
			res=mul(res,a);
	return res;
}
int inv2=qpow(2,mod-2);
inline void or_fmt(int *f,int n,int p) { //p=-1?????
	register int i,j;
	for(i=0; i<n; i++)
		for(j=0; j<1<<n; j++)
			if(j>>i&1)
				f[j]=add(f[j],p^1?mod-f[j^1<<i]:f[j^1<<i]);
	return;
}
inline void and_fmt(int *f,int n,int p) {
	register int i,j;
	for(i=0; i<n; i++)
		for(j=(1<<n)-1; ~j; j--)
			if(~j>>i&1)
				f[j]=add(f[j],p^1?mod-f[j|1<<i]:f[j|1<<i]);
	return;
}
inline void fwt(int *f,int n,int p) {
	int u,t;
	register int i,j,k;
	for(i=1; i<<1<=1<<n; i<<=1)
		for(j=0; j<1<<n; j+=i<<1)
			for(k=0; k<i; k++) {
				u=f[j+k];
				t=f[j+k+i];
				f[j+k]=mul(p^1?inv2:1,add(u,t));
				f[j+k+i]=mul(p^1?inv2:1,sub(u,t));
			}
	return;
}
const int N=1e6+5;
int n;
int f[N],g[N],h[N];
signed main() {
	register int i;
	scanf("%d",&n);
	for(i=0; i<1<<n; i++)
		scanf("%d",&f[i]);
	for(i=0; i<1<<n; i++)
		scanf("%d",&g[i]);
	//or
	or_fmt(f,n,1);
	or_fmt(g,n,1);
	for(i=0; i<1<<n; i++)
		h[i]=mul(f[i],g[i]);
	or_fmt(f,n,-1);
	or_fmt(g,n,-1);

	or_fmt(h,n,-1);
	for(i=0; i<1<<n; i++)
		printf("%d ",h[i]);
	putchar('\n');
	//and
	and_fmt(f,n,1);
	and_fmt(g,n,1);
	for(i=0; i<1<<n; i++)
		h[i]=mul(f[i],g[i]);
	and_fmt(f,n,-1);
	and_fmt(g,n,-1);
	and_fmt(h,n,-1);
	for(i=0; i<1<<n; i++)
		printf("%d ",h[i]);
	putchar('\n');
	//xor
	fwt(f,n,1);
	fwt(g,n,1);
	for(i=0; i<1<<n; i++)
		h[i]=mul(f[i],g[i]);
	fwt(f,n,-1);
	fwt(g,n,-1);
	fwt(h,n,-1);
	for(i=0; i<1<<n; i++)
		printf("%d ",h[i]);
	putchar('\n');
	return 0;
}
