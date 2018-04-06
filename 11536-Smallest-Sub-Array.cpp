#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <memory.h>

using namespace std;

const int N = 1e6 + 2, K = 104;
int t, n, m, k;

int a[N], fk[K];

bool isAllThere() {
  
  for (int i = 1; i <= k; ++i)
    if(fk[i] <= 0) return false;
    
  return true;
}

void buildSeq() {
  
  a[0] = 1, a[1] = 2, a[2] = 3;
  for (int i = 3; i < n; ++i) {
    a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % m + 1;
  }
}

int calc() {
  
  int l = 0, r = 0, ans = 1e7 + 1;
  
  while(r < n) {
    
    if (a[r] <= k) ++fk[a[r]];
    ++r;
    
    while (isAllThere()) {
      ans = min(ans, r - l);
      
      if(a[l] <= k) --fk[a[l]];
      ++l;
    }
  }
  
  return ans;
}

int main() {

  int c = 1;
  scanf("%d", &t);
  
  while (t-- > 0) {
    
    scanf("%d%d%d", &n, &m, &k);
    
    buildSeq();
    memset(fk, 0, sizeof fk);
    
    int ans = calc();
    
    if (ans != 1e7 + 1)
      printf("Case %d: %d\n", c++, ans);
    else
      printf("Case %d: sequence nai\n", c++);
  }

  return 0;  
}
