#include <bits/stdc++.h>
using namespace std;

void init() {

}

int h[30];

void solve() {
	string w; cin >> w;
	for (char c: w) {
		++h[c-'a'];
	}
	for (int i = 'a'; i <= 'z'; ++i) {
		if (h[i-'a']&1) {
			puts("No");
			return;
		}
	}
	puts("Yes");
}

int main() {
	init();
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
