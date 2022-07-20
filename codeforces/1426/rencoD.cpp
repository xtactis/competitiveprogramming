#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
ll mod = 1e9 + 7;
 
int main(){
  ll n; cin >> n;
  ll arr[n];
  set<ll> s;
  for(ll i = 0; i < n; ++i){
    cin >> arr[i];
  }
  s.insert(0);
  ll sum = 0, ans = 0;
  for(ll i = 0; i < n; ++i){
    sum += arr[i];
    if(s.find(sum) != s.end()){
      sum -= arr[i];
      sum += 10000004873;
      s.insert(sum);
      sum += arr[i];
      s.insert(sum);
      ans++;
    }
    s.insert(sum);
  }
  cout << ans;
  return 0;
}
