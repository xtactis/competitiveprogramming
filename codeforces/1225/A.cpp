#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
	scanf("%d %d", &a, &b);
	if (a == b) {
		printf("%d0 %d1", a, b);
	} else if (a+1 == b) {
		printf("%d %d", a, b);
	} else if (a-8 == b) {
		printf("%d %d0", a, b);
	} else {
		printf("-1");
	}
	
	return 0;
}
