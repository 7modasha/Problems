#include <bits/stdc++.h>
#define N 1000100
#define M 1000000007
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, c;
ll seg[4 * N], lazy[4 * N];

void update(int p, int l, int r, int a, int b, ll v){

	if(lazy[p] != 0){
		seg[p] += 1LL*lazy[p]*(r-l+1);
		if(l != r){
			lazy[p*2] += lazy[p];
			lazy[p*2+1] += lazy[p];
		}
		lazy[p] = 0;
	}

	if(r < a or l > b) return;

	if(a <= l and r <= b){
		seg[p] += 1LL*(r-l+1)*v;
		if(l != r){
			lazy[p*2] += v;
			lazy[p*2+1] += v;
		}
		return;
	}

	int md = (l+r)/2;
	update(p*2, l, md, a, b, v);
	update(p*2+1, md+1, r, a, b, v);
	seg[p] = seg[p*2] + seg[p*2+1];
}

ll get(int p, int l, int r, int a, int b){

	if(a > b or r < a or l > b) return 0;

	if(lazy[p] != 0){
		seg[p] += 1LL*lazy[p]*(r-l+1);
		if(l != r){
			lazy[p*2] += lazy[p];
			lazy[p*2+1] += lazy[p];
		}
		lazy[p] = 0;
	}
	if(a <= l and r <= b) return seg[p];

	int md = (l+r)/2;
	return get(p*2, l, md, a, b) + get(p*2+1, md+1, r, a, b);
}

void solve(){

	memset(seg, 0, sizeof seg);
	memset(lazy, 0, sizeof lazy);

	ll v;
	int op, l, r;
	scanf("%d%d", &n, &c);
	while(c-- > 0){
		scanf("%d", &op);

		if(op == 0){
			scanf("%d%d%lld", &l, &r, &v);
			update(1, 1, n, l, r, v);
		} else {
			scanf("%d%d", &l, &r);
			printf("%lld\n", get(1, 1, n, l, r));
		}
	}
}

int main(){
 
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	//ios_base::sync_with_stdio(false);

	int t;
	scanf("%d", &t);
	while(t-- > 0){
		solve();
	}

	return 0;
}