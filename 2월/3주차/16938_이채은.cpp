#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N, L, R, X, ans;
int level[15];
bool visit[15];

void DFS(int idx, int cnt, int sum) {
    if (cnt >= 2 && L <= sum && sum <= R) {
        int Min = 987654321, Max = -987654321;

        for (int i = 0; i < N; i++) {
            if (visit[i]) {
                Min = min(Min, level[i]);
                Max = max(Max, level[i]);
            }
        }

        if (Max - Min >= X) ans++;
    }

    for (int i = idx; i < N; i++) {
        if (visit[i]) continue;

        if (sum + level[i] <= R) {
            visit[i] = true;
            DFS(i, cnt + 1, sum + level[i]);
            visit[i] = false;
        }
    }
}

int main() {
    scanf("%d %d %d %d", &N, &L, &R, &X);
    for (int i = 0; i < N; i++) {
        scanf("%d", &level[i]);
    }
    DFS(0, 0, 0);
    printf("%d", ans);
}
