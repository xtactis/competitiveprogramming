#include <bits/stdc++.h>

using namespace std;

bool flush(const vector<string> &p) {
    char suit = p[0][1];
    for (const auto &s: p) {
        if (s[1] != suit) return false;
    }
    return true;
}

char straight(const vector<string> &p) {
    for (int i = 1; i < p.size(); ++i) {
        if (p[i][0]-p[i-1][0] != 1) return 0;
    }
    return p[0][0];
}

char straight_flush(const vector<string> &p) {
    char s = straight(p);
    if (flush(p) && s) {
        return s;
    }
    return 0;
}

bool royal_flush(const vector<string> &p) {
    return straight_flush(p) == 10;
}

char four_of_a_kind(const vector<string> &p) {
    for (int i = 3; i < p.size(); ++i) {
        if (p[i][0] == p[i-1][0] && p[i][0] == p[i-2][0] && p[i][0] == p[i-3][0]) return p[i][0];
    }
    return 0;
}

char three_of_a_kind(const vector<string> &p) {
    for (int i = 2; i < p.size(); ++i) {
        if (p[i][0] == p[i-1][0] && p[i][0] == p[i-2][0]) return p[i][0];
    }
    return 0;
}

char two_of_a_kind(const vector<string> &p, char omit=0) {
    char highest = 0;
    for (int i = 1; i < p.size(); ++i) {
        if (p[i][0] == omit) continue;
        if (p[i][0] == p[i-1][0]) highest = max(highest, p[i][0]);
    }
    return highest;
}

vector<char> full_house(const vector<string> &p) {
    char tris = three_of_a_kind(p);
    if (!tris) return {0,0};
    char par = two_of_a_kind(p, tris);
    if (!par) return {0,0};
    return {tris, par};
}

vector<char> two_pairs(const vector<string> &p) {
    char f = two_of_a_kind(p);
    if (!f) return {0,0};
    char s = two_of_a_kind(p, f);
    if (!s) return {0,0};
    if (f < s) swap(f, s);
    return {f, s};
}

char highest_card(const vector<string> &p, const set<char> &omit = {}) {
    char ret = 0;
    for (const auto &str: p) {
        if (omit.count(str[0])) continue;
        ret = max(ret, str[0]);
    }
    return ret;
}

void conv_values(vector<string> &p) {
    for (auto &s: p) {
        if (s[0] >= '0' && s[0] <= '9') {
            s[0] -= '0';
        } else if (s[0] == 'T') {
            s[0] = 10;
        } else if (s[0] == 'J') {
            s[0] = 11;
        } else if (s[0] == 'Q') {
            s[0] = 12;
        } else if (s[0] == 'K') {
            s[0] = 13;
        } else {
            s[0] = 14;
        }
    }
}

bool kicker(const vector<string> &p1, const vector<string> &p2, set<char> omit1 = {}, set<char> omit2 = {}) {
    if (omit1.size() == 5 || omit2.size() == 5) return false;
    char hc1 = highest_card(p1, omit1), hc2 = highest_card(p2, omit2);
    if (hc1 > hc2) {
        return true;
    } else if (hc1 < hc2) {
        return false;
    }
    omit1.insert(hc1);
    omit2.insert(hc2);
    return kicker(p1, p2, omit1, omit2);
}

int main() {
    int ans = 0;
    for (string line; getline(cin, line);) {
        vector<string> p1, p2;
        string cur = "";
        int n = 0;
        for (int i = 0; i < line.size(); ++i) {
            if (line[i] == ' ') {
                if (n < 5) {
                    p1.emplace_back(cur);
                } else { 
                    p2.emplace_back(cur);
                }
                ++n;
                cur = "";
            } else {
                cur += line[i];
            }
        }
        p2.emplace_back(cur);
        conv_values(p1); conv_values(p2);
        sort(p1.begin(), p1.end());
        sort(p2.begin(), p2.end());
        if (royal_flush(p1) && !royal_flush(p2)) {
            ++ans;
            continue;
        } else if (royal_flush(p2)) {
            continue;
        }
        char sf1 = straight_flush(p1), sf2 = straight_flush(p2);
        if (sf1 > sf2) {
            ++ans;
            continue;
        } else if (sf2 && sf1 <= sf2) {
            continue;
        }
        char fok1 = four_of_a_kind(p1), fok2 = four_of_a_kind(p2);
        if (fok1 > fok2) {
            ++ans;
            continue;
        } else if (fok1 < fok2) {
            continue;
        } else if (fok1 && fok1 == fok2) {
            if (kicker(p1, p2, {fok1}, {fok2})) {
                ++ans;
            }
            continue;
        }
        auto fh1 = full_house(p1), fh2 = full_house(p2);
        if (fh1[0] && !fh2[0]) {
            ++ans;
            continue;
        } else if (!fh1[0] && fh2[0]) {
            continue;
        } else if (fh1[0] && fh2[0]) {
            char tok1 = three_of_a_kind(p1), tok2 = three_of_a_kind(p2);
            if (tok1 > tok2) {
                ++ans;
            } else if (tok1 == tok2) {
                char par1 = two_of_a_kind(p1, {tok1}), par2 = two_of_a_kind(p2, {tok2});
                if (par1 > par2) {
                    ++ans;
                } else if (par1 == par2) {
                    if (kicker(p1, p2, {tok1, par1}, {tok2, par2})) {
                        ++ans;
                    }
                }
            }
            continue;
        }
        bool fl1 = flush(p1), fl2 = flush(p2);
        if (fl1 && !fl2) {
            ++ans;
            continue;
        } else if (!fl1 && fl2) {
            continue;
        } else if (fl1 && fl2) {
            if (kicker(p1, p2)) {
                ++ans;
            }
            continue;
        }
        char st1 = straight(p1), st2 = straight(p2);
        if (st1 > st2) {
            ++ans;
            continue;
        } else if (st1 < st2 || st1) {
            continue;
        } 
        char tok1 = three_of_a_kind(p1), tok2 = three_of_a_kind(p2);
        if (tok1 > tok2) {
            ++ans;
            continue;
        } else if (tok1 < tok2) {
            continue;
        } else if (tok1 && tok2) {
            if (kicker(p1, p2, {tok1}, {tok2})) {
                ++ans;
            }
            continue;
        }
        auto tp1 = two_pairs(p1), tp2 = two_pairs(p2);
        if (tp1[0] && !tp2[0]) {
            ++ans;
            continue;
        } else if (!tp1[0] && tp2[0]) {
            continue;
        } else if (tp1[0] && tp2[0]) {
            if (tp1[0] > tp2[0]) {
                ++ans;
            } else if (tp1[0] < tp2[0]) {
            } else if (tp1[1] > tp2[1]) {
                ++ans;
            } else if (tp1[1] < tp2[1]) {
            } else {
                if (kicker(p1, p2, {tp1[0], tp1[1]}, {tp2[0], tp2[1]})) {
                    ++ans;
                }
            }
            continue;
        }
        char op1 = two_of_a_kind(p1), op2 = two_of_a_kind(p2);
        if (op1 > op2) {
            ++ans;
            continue;
        } else if (op1 < op2) {
            continue;
        } else if (op1 && op2) {
            if (kicker(p1, p2, {op1}, {op2})) {
                ++ans;
            }
            continue;
        }
        if (kicker(p1, p2)) {
            ++ans;
        }
    }
    printf("%d\n", ans);

    return 0;
}
