#include <bits/stdc++.h>

using namespace std;
string add(string x, string y) {
    if (x.size() < y.size()) {
        swap(x, y);
    }
    string ret = "";
    int carry = 0;
    for (int i = 0; i < x.size(); ++i) {
        int a = x[x.size()-i-1]-'0';
        int b = i < y.size() ? y[y.size()-i-1]-'0' : 0;
        a += b+carry;
        ret.push_back((a%10)+'0');
        carry = a / 10;
    }
    if (carry) {
        ret.push_back(carry+'0');
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string mul(const string &x, const string &y) {
    string ret = "";
    for (int i = x.size()-1; i >= 0; --i) {
        string cur = "";
        for (int k = x.size()-1; k > i; --k) {
            cur.push_back('0');
        }
        int carry = 0;
        for (int j = y.size()-1; j >= 0; --j) {
            int a = y[j]-'0';
            int b = x[i]-'0';
            a *= b;
            a += carry;
            cur.push_back((a % 10) + '0');
            carry = a / 10;
        }
        if (carry) {
            cur.push_back(carry + '0');
        }
        reverse(cur.begin(), cur.end());
        ret = add(ret, cur);
    }
    return ret;
}

string binpow(const string &b, int e) {
    if (!e) return "1";
    if (e&1) return mul(b, binpow(b, e-1));
    return binpow(mul(b, b), e/2);
}

int main() {
    int ans = 0;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            string res = binpow(to_string(i), j);
            int sum = 0;
            for (char c: res) {
                sum += c-'0';
            }
            ans = max(ans, sum);
        }
    }
    printf("%d\n", ans);

    return 0;
}
