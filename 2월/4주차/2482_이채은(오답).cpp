#include <stdio.h>

int N, K;
long long comb[1001][1001];

long long combination(int n, int r) {
    if (comb[n][r] != 0) return comb[n][r];
    if (n == r || r == 1) return 1;
    else {
        comb[n][r] = combination(n - 1, r - 1) + (n - 1, r);
        return comb[n][r];
    }
}

int main() {
    scanf("%d %d", &N, &K);
    long long ans = combination(N, K);
    for (int i = 1; i < K; i++)
        ans -= combination(N, i);
    if (ans < 0) ans = 0;
    printf("%d", ans % 1000000003);
}
