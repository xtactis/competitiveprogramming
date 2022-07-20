#include <bits/stdc++.h>
using namespace std;

inline int ones(int x) {
    switch(x) {
        case 0: return 0;
        case 1: case 2: case 6: return 3;
        case 4: case 5: case 9: return 4;
        default: return 5;
    }
}

inline int teens(int x) {
    switch(x) {
        case 10: return 3;
        case 11: case 12: return 6;
        case 13: case 14: case 18: case 19: return 8;
        case 15: case 16: return 7;
        default: return 9;
    }
}

inline int tens(int x) {
    switch(x) {
        case 20: case 30: case 80: case 90: return 6;
        case 40: case 50: case 60: return 5;
        default: return 7;
    }
}

inline int hundreds(int x) {
    return ones(x/100) + 7;
}

inline int thousands(int x) {
    return ones(x/1000) + 8;
}

int letters(int x) {
    int ret = 0;
    if (x == 1000) {
        ret = thousands(x);
    } else if (x >= 100) {
        ret = hundreds(x/100*100);
        if (x %= 100) {
            ret += 3;
            if (x/10 > 1) {
                ret += tens(x/10*10);
                ret += ones(x%10);
            } else if (x/10 == 1) {
                ret += teens(x);
            } else {
                ret += ones(x%10);
            }
        }
        
    } else if (x >= 20) {
        ret = tens(x/10*10);
        if (x%10) ret += ones(x%10);
    } else if (x >= 10) {
        ret = teens(x);
    } else {
        ret = ones(x);
    }
    return ret;
}

int main() {
    int ans = 0;
    for (int i = 1; i <= 1000; ++i) {
        ans += letters(i);
    }
    printf("%d %d %d %d", ans, letters(301), letters(512), letters(69));
    return 0;
}