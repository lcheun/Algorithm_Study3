#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
long long map[35][35][4];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%lld", &map[i][j][0]);

    map[0][1][1] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j][0] == 0) {
                if (j >= 1) map[i][j][1] += map[i][j - 1][1] + map[i][j - 1][3];
                if (i >= 1) map[i][j][2] += map[i - 1][j][2] + map[i - 1][j][3];
                if (i >= 1 && j >= 1 && map[i][j - 1][0] == 0 && map[i - 1][j][0] == 0)
                    map[i][j][3] += map[i - 1][j - 1][1] + map[i - 1][j - 1][2] + map[i - 1][j - 1][3];
            }
        }
    }

    printf("%lld", map[N - 1][N - 1][1] + map[N - 1][N - 1][2] + map[N - 1][N - 1][3]);
}
