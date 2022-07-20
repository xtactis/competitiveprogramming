#include <bits/stdc++.h>
using namespace std;
int main() {
  	int n; cin >> n;
	int A[123];
	int a = 0, b = 0;
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	sort(A, A+n, greater<int>());
	for (int i = 0; i < n; ++i) {
		if (i%2) b += A[i];
		else a += A[i];
	}
	cout << a-b;
}