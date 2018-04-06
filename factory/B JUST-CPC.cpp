#include <bits/stdc++.h>
 
using namespace std;
//B
int const N = 10000 + 100;
int n, a, b, match[N], m[N], f[N], bt[N];

bool vis[N];

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

bool findMatch(int ma) {
  vis[ma] = true;
  
  for(int fe = 0; fe < b; ++fe) {

    int d = gcd(m[ma], f[fe]);
    if(d > 1 && (match[fe] == -1 || (!vis[match[fe]] && findMatch(match[fe])) ) ) {
      match[fe] = ma;
      return true;
    }
  }
  
  return false;
}

void solve(){

    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &bt[i]);
    }

    a = 0; b = 0;
    for(int i = 0; i < n; ++i){
        char ch;
        scanf(" %c", &ch);

        if(ch == 'M')
            m[a++] = bt[i];
        else
            f[b++] = bt[i];
    }

    memset(match, -1, sizeof match);

    int res = 0;
    for(int i = 0; i < a; ++i){
        memset(vis, 0, sizeof vis);
        if(findMatch(i))
            ++res;
    }

    int tmp = 0;
    for(int i = 0; i < b; ++i){
        if(match[i] == -1) ++res;
        else ++tmp;
    }

    res += (a-tmp);

    printf("%d\n", res);
}

int main() {
  
    freopen("in.txt", "r", stdin);    

    int t;
    scanf("%d", &t);
    while(t-- > 0)
        solve();
    

    return 0;
} 
