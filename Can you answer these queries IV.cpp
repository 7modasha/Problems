#include <bits/stdc++.h>
#define N 100100
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, m;
ll arr[N], seg[4 * N];

void build(int p, int l, int r){
	if(l == r){
		seg[p] = arr[l];
		return;
	}

	int md = (l+r)/2;
	build(p*2, l, md);
	build(p*2+1, md+1, r);

	seg[p] = seg[p*2] + seg[p*2+1];
}

ll get(int p, int l, int r, int a, int b){
	if(a <= l and r <= b)
		return seg[p];

	if(r < a or l > b)
		return 0;

	int md = (l+r)/2;
	return get(p*2, l, md, a, b) 
		 + get(p*2+1, md+1, r, a, b);
}

void update(int p, int l, int r, int a, int b){

	if(seg[p] == r-l+1) return;

	if(r < a or l > b) return;

	if(l == r){
		seg[p] = arr[l] = sqrt(arr[l]);
		return;
	}

	int md = (l+r)/2;
	update(p*2, l, md, a, b);
	update(p*2+1, md+1, r, a, b);

	seg[p] = seg[p*2] + seg[p*2+1];
}

void solve(){
	for(int i = 0; i < n; ++i)
		scanf("%lld", arr+i);

	build(1, 0, n-1);

	int t, x, y;
	scanf("%d", &m);
	while(m-- > 0){
		scanf("%d%d%d", &t, &x, &y);
		if(x > y) swap(x, y); 
		--x; --y;

		if(!t){
			update(1, 0, n-1, x, y);
		} else {
			printf("%lld\n", get(1, 0, n-1, x, y));
		}
	}
}

int main(){
 
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);

	for(int i = 1; scanf("%d", &n) != EOF; ++i){
		printf("%sCase #%d:\n", i-1 ? "\n" : "", i);
		solve();
	}

	return 0;
}