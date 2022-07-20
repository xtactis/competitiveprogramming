#include <bits/stdc++.h>
using namespace std;
int main() {
  	int n; cin >> n;
	set<char> s;
	for (int i = 0; i < n; ++i) {
		char t; cin >> t;
		s.insert(t);
	}
	cout << (s.size() == 3?"Three":"Four");
}