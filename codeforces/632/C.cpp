#include <bits/stdc++.h>
using namespace std;

vector<string> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		v.emplace_back(s);
	}
	sort(v.begin(), v.end(), [](const string &a, const string &b) {
		return a+b < b+a;
	});
	for (const auto &e: v) {
		cout << e;
	}
	return 0;
}
