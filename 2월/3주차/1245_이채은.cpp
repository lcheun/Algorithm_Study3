#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>

using namespace std;

bool isAns = true;
int N, M, ans, farm[100][70], visit[100][70];
int dy[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dx[] = { 1, 0, -1, 1, -1, 1, 0, -1 };

void solve(int y, int x) {
    queue<pair<int, int>> q;
    q.push({ y, x });
    visit[y][x] = true;
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        for (int i = 0; i < 8; i++) {
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];
            if (ny >= 0 && nx >= 0 && ny < N && nx < M) {
                if (!visit[ny][nx] && farm[ny][nx] == farm[p.first][p.second]) {
                    q.push({ ny, nx });
                    visit[ny][nx] = true;
                }
                else if (farm[ny][nx] > farm[p.first][p.second]) {
                    isAns = false;
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &farm[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visit[i][j] && farm[i][j] > 0) {
                solve(i, j);
                if (isAns) ans++;
                isAns = true;
            }
        }
    }
    printf("%d", ans);
}
