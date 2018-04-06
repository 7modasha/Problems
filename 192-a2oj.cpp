#include <bits/stdc++.h>
using namespace std;

int main(){

#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif

	int t, y1, y2, y3, m1, m2, m3;

	scanf("%d", &t);

	while (t--){

		scanf("%d%d", &y1, &m1);
		scanf("%d%d", &y2, &m2);
		
		int tmp = (m1 + m2) / 12;

		y3 = (y1 + y2) + tmp;
		m3 = (m1 + m2) - tmp * 12;

		if (m3 == 0){
			m3 = 12; y3 -= 1;
		}

		printf("%d %d\n", y3, m3);

	}

	return 0;
}
