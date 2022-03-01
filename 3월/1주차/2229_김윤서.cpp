#include <iostream>
#include <algorithm>

using namespace std;

int N;
int value[10001] = {0, };
int dp[10001] = {0, };

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &value[i]);
        int high = 0, low = 100000;
      
        //맨 처음 ~ 현재 입력받은 점수 구간을 묶었을 때의 최댓값을 매번 계산한다.
        for (int j = i; j > 0; j--) {
            high = max(value[j], high);
            low = min(value[j], low);
		//더 큰 값으로 dp 갱신
            if (dp[i] < dp[j - 1] + high - low) dp[i] = dp[j - 1] + high - low; 
        }
    }
    printf("%d", dp[N]);
    
    return 0;
}
