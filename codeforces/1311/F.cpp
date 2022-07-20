#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    vector<long long> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(const vector<long long> &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    long long sum(int r) {
        long long ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    long long sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, long long delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

vector<long long> x, v, vece;
vector<pair<int, int>> p;
map<int, int> revX;

void solve() {
	int n; scanf("%d", &n);
	x.resize(n); v.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &x[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &v[i]);
		p.emplace_back(v[i], x[i]);
	}
	sort(x.begin(), x.end());
	for (int i = 0; i < n; ++i) {
		revX[x[i]] = i;
		vece.push_back(1);
	}
	sort(p.begin(), p.end(), greater<pair<int, int>>());
	FenwickTree ft(x), ft2(vece);
	long long ans = 0;
	for (int i = 0; i < (int)p.size(); ++i) {
		const int &x = p[i].second;
		const int &v = p[i].first;
		if (v < 0) break;
		ft.add(revX[x], -x);
		ft2.add(revX[x], -1);
		ans += abs(ft2.sum(revX[x])*x-ft.sum(revX[x]));
	}
	for (int i = (int)p.size()-1; i >= 0; --i) {
		const int &x = p[i].second;
		const int &v = p[i].first;
		if (v >= 0) break;
		ft.add(revX[x], -x);
		ft2.add(revX[x], -1);
		ans += abs(ft2.sum(revX[x], n-1)*x-ft.sum(revX[x], n-1));
	}
	printf("%lld", ans);
}

int main() {
	int t = 1; //scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
