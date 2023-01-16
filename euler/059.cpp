#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int cur = 0;
    vector<int> code;
    for (auto c: s) {
        if (c == ',') {
            code.push_back(cur);
            cur = 0;
        } else {
            cur *= 10;
            cur += c - '0';
        }
    }
    code.push_back(cur);

    for (int i = 'a'; i <= 'z'; ++i) {
        for (int j = 'a'; j <= 'z'; ++j) {
            for (int k = 'a'; k <= 'z'; ++k) {
                string text;
                for (int l = 0; l < code.size(); ++l) {
                    switch (l % 3) {
                        case 0: {
                            text.push_back(code[l] ^ i);
                            break;
                        }
                        case 1: {
                            text.push_back(code[l] ^ j);
                            break;
                        }
                        case 2: {
                            text.push_back(code[l] ^ k);
                            break;
                        }
                    }

                }
                if (text.find(" and ") != string::npos) {
                    int ans = 0;
                    for (auto c: text) {
                        ans += c;
                    }
                    cout << ans << "\n";
                    return 0;
                }
            }
        }
    }

    return 0;
}
