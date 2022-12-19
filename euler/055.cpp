#include <bits/stdc++.h>

using namespace std;

string add(string x, string y) {
    string ret = "";
    int carry = 0;
    for (int i = x.size()-1; i >= 0; --i) {
        int a = x[i]-'0';
        int b = y[i]-'0';
        a += b+carry;
        ret.push_back((a%10)+'0');
        carry = a / 10;
    }
    if (carry) {
        ret.push_back(carry+'0');
    }
    return ret;
}

bool is_lychrel(string x, int n = 50) {
    string y = x;
    reverse(y.begin(), y.end());
    if (n != 50 && x == y) return false;
    if (n == 0) return true;
    
    return is_lychrel(add(x, y), n-1);
}

int main() {
    int ans = 0;
    for (int i = 1; i < 10000; ++i) {
        ans += is_lychrel(to_string(i));
    }
    printf("%d\n", ans);
    return 0;
}
