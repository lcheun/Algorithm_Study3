#include <stdio.h>
#include <algorithm>

using namespace std;

int N, score[10001], dp[10001];

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &score[i]);
        int high = 0, low = 100000;
        for (int j = i; j > 0; j--) {
            high = max(score[j], high);
            low = min(score[j], low);
            if (dp[i] < dp[j - 1] + high - low) dp[i] = dp[j - 1] + high - low;
        }
    }
    printf("%d", dp[N]);
}
