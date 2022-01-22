#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, ans, arr[300000];
vector<int> diff;

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < N - 1; i++)
        diff.push_back(arr[i + 1] - arr[i]);

    sort(diff.begin(), diff.end());

    for (int i = 0; i < N - K; i++)
        ans += diff[i];

    printf("%d", ans);
}
