#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n, c;
float m, p; 
vector<pair<int, int>> candy; //사탕 가게에 있는 사탕 칼로리 c와 가격 p
int dp[10001]; // dp 테이블

int calcMaxCal(int money) {
    if (dp[money] != -1) return dp[money];
    int sum = 0;
    for (auto x:candy) {
        if (money - x.second >= 0) {
            sum = max(sum, x.first + calcMaxCal(money - x.second));
            dp[money] = sum;
        }
    }
    return sum;
}
int main() {
    while (1) {
        memset(dp, -1, sizeof(dp));
        candy.clear();
        scanf("%d %f", &n, &m);

        if (n == 0 && m == 0.00) return 0; //종료 조건
        for (int i = 0; i < n; i++) {
            scanf("%d %f", &c, &p);
            candy.push_back({ c, (int)(p * 100 + 0.5 ) }); //0.5를 더해줘야함
        }
        printf("%d\n", calcMaxCal((int)(m * 100 + 0.5 )));
    }
}
