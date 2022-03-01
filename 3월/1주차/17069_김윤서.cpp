#include <iostream> 
using namespace std;

int n, p[34][34];
long long d[3][34][34];

/*
D[M][X][Y] : M번 파이프가 (X, Y)에 도착하는 방법의 수 (M은 파이프의 상태 0~2)
D[0][X][Y] : 가로 파이프가 (X, Y)에 도착하는 방법의 수
D[1][X][Y] : 세로 파이프가 (X, Y)에 도착하는 방법의 수
D[2][X][Y] : 대각선 파이프가 (X, Y)에 도착하는 방법의 수
D[0][1][2] = 1 : 가로 파이프 시작 위치 (1, 2)

*/

void solve() {
    d[0][1][2] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (!p[i][j+1]) d[0][i][j+1] += d[0][i][j] + d[2][i][j];
            if (!p[i+1][j]) d[1][i+1][j] += d[1][i][j] + d[2][i][j];
            if (!p[i+1][j+1] && !p[i+1][j] && !p[i][j+1]) {
                d[2][i+1][j+1] += d[0][i][j] + d[1][i][j] + d[2][i][j];
            }
        }
    }
    printf("%lld\n", d[0][n][n]+d[1][n][n]+d[2][n][n]);
}

int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            scanf("%d", &p[i][j]);
        }
    }
    solve();
    return 0;
}

// https://www.acmicpc.net/problem/17069
