#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>

using namespace std;

int t, n;

int main() {
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long dp[65][10] = { 0, };

	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= 64; i++) {
		//i 자릿수
		for (int j = 0; j <= 9; j++) {
			//해당 자리에 오는 수
			for (int k = j; k <= 9; k++) {
				//j보다 작지 않은 경우의 수
				dp[i][j] += dp[i - 1][k];

				//n=2일 때, 0: 10, 1: 9, 2: 8 ... 
				//dp[2][1] = dp[1][1] + dp[2][2] + dp[2][3] + ... + dp[2][9]
				//dp[2][3] = dp[1][3] + dp[1][4] + dp[1][5] + ... + dp[1][9]
			}
		}
	}

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		long long ans = 0;
		for (int i = 0; i <= 9; i++) {
			ans += dp[n][i];
		}

		printf("%lld\n", ans);
	}
}


/*
2688. 줄어들지 않아
https://www.acmicpc.net/problem/2688

문제
어떤 숫자가 줄어들지 않는다는 것은 그 숫자의 각 자리 수보다 그 왼쪽 자리 수가 작거나 같을 때 이다.

예를 들어, 1234는 줄어들지 않는다.

줄어들지 않는 4자리 수를 예를 들어 보면 0011, 1111, 1112, 1122, 2223이 있다. 줄어들지 않는 4자리수는 총 715개가 있다.

이 문제에서는 숫자의 앞에 0(leading zero)이 있어도 된다. 0000, 0001, 0002는 올바른 줄어들지 않는 4자리수이다.

n이 주어졌을 때, 줄어들지 않는 n자리 수의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T(1 <= T <= 1,000)이 주어진다. 각 테스트 케이스는 숫자 하나 n으로 이루어져 있다. (1 <= n <= 64)

출력
각 테스트 케이스에 대해 한 줄에 하나씩 줄어들지 않는 n자리 수의 개수를 출력한다.
*/