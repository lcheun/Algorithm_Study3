#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int T, N;
bool visit[61];
int time[] = { 0, 60, 10, -10, 1, -1 };

void bfs() {
    queue<vector<int>> q;
    q.push({ 0, 0, 0, 0, 0, 0 });
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            vector<int> val = q.front(); q.pop();
            if (val[0] == N % 60) {
                val[1] += N / 60;
                for (int j = 1; j <= 5; j++) {
                    printf("%d ", val[j]);
                }
                printf("\n");
                return;
            }
            for (int j = 5; j >= 1; j--) {
                int tmp = max(0, val[0] + time[j]);
                if (!visit[tmp] && tmp <= 60) {
                    if (j == 1 && val[1] == 1) continue;
                    visit[tmp] = true;
                    val[j]++;
                    q.push({ tmp, val[1], val[2], val[3], val[4], val[5] });
                    val[j]--;
                }
            }
        }
    }
}

int main() {
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &N);
        bfs();
        memset(visit, false, sizeof(visit));
    }
}
