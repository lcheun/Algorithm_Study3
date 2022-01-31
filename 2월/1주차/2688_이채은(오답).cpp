#include <stdio.h>

int T, n;
long long dp[65][11];

void set() {
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;

    for (int i = 1; i < 65; i++)
        dp[i][0] = 1;

    for (int i = 2; i < 65; i++) {
        for (int j = 1; j < 10; j++) {
            for (int k = j; k < 10; k++) {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }

    for (int i = 1; i < 65; i++) {
        long long sum = 0;
        for (int j = 0; j < 10; j++)
            sum += dp[i][j];
        dp[i][11] = sum;
    }
}

int main() {
    scanf("%d", &T);
    set();
    for (int i = 0; i < T; i++) {
        scanf("%d", &n);
        printf("%lld\n", dp[n][11]);
    }
}
