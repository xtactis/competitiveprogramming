#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t; cin >> s >> t;
  t.pop_back();
  if (s == t) cout << "Yes";
  else cout << "No";
  return 0;
}
