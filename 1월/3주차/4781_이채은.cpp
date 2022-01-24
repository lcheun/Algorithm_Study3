#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, c;
float m, p; 
vector<pair<int, int>> candy;
int dp[10001];

int calc(int cash) {
    
    if (dp[cash] != -1) return dp[cash];

    int res = 0;
    for (auto x:candy) {
        if (cash - x.second >= 0) {
            res = max(res, x.first + calc(cash - x.second));
            dp[cash] = res;
        }
    }

    return res;
}



int main() {
    while (true) {
        memset(dp, -1, sizeof(dp));
        candy.clear();
        scanf("%d %f", &n, &m);

        if (n == 0 && m == 0.00) return 0;

        for (int i = 0; i < n; i++) {
            scanf("%d %f", &c, &p);
            candy.push_back({ c, (int)(p * 100 + 0.5 ) });
        }

        printf("%d\n", calc((int)(m * 100 + 0.5 )));
    }
}
