#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

const int N = 54;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

char s[N][N];
int h, w;

bool bio[N][N];
int bfs() {
    queue<pair<pair<int, int>, int>> q;
    q.emplace(make_pair(0, 0), 1);
    bio[0][0] = 1;
    while (!q.empty()) {
        const auto u = q.front(); q.pop();
        int x = u.first.first, y = u.first.second, d = u.second;
        for (int i = 0; i < 4; ++i) {
            int xx = x+dx[i], yy = y+dy[i];
            if (xx < 0 || xx >= w || yy < 0 || yy >= h) continue;
            if (s[yy][xx] == '#') continue;
            if (bio[yy][xx]) continue;
            if (yy == h-1 && xx == w-1) return h*w-d-1;
            q.emplace(make_pair(xx, yy), d+1);
            bio[yy][xx] = 1;
        }
    }
    return -1;
}

void solve() {
    scanf("%d%d", &h, &w);
    int c = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            scanf(" %c", s[i]+j);
            c += s[i][j] == '#';
        }
    }
    int ans = bfs();
    if (ans == -1) printf("-1");
    else printf("%d", ans-c);
}

int main() {
    init();
    int t = 1; //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}