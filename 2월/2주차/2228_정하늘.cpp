#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#define MAX 110
#define MIN -3276800

using namespace std;

int dp[MAX][MAX / 2];
int nums[MAX];

int solve(int n, int m) {
	if (m == 0) return 0;
	if (n <= 0) return MIN;
	if (dp[n][m] != -1) return dp[n][m];

	int sum = 0;
	dp[n][m] = solve(n - 1, m);
	for (int i = n; i > 0; i--) {
		sum += nums[i];
		int tmp = solve(i - 2, m - 1) + sum;
		if (tmp > dp[n][m]) dp[n][m] = tmp;
	}

	return dp[n][m];
}


int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX / 2; j++) {
			dp[i][j] = -1;
		}
	}

	for (int i = 1; i <= n; i++) {
		scanf("%d", &nums[i]);
	}

	printf("%d\n", solve(n, m));
}


/*
2228. 구간 나누기
https://www.acmicpc.net/problem/2228

문제
N(1 ≤ N ≤ 100)개의 수로 이루어진 1차원 배열이 있다. 이 배열에서 M(1 ≤ M ≤ ⌈(N/2)⌉)개의 구간을 선택해서, 구간에 속한 수들의 총 합이 최대가 되도록 하려 한다. 단, 다음의 조건들이 만족되어야 한다.

각 구간은 한 개 이상의 연속된 수들로 이루어진다.
서로 다른 두 구간끼리 겹쳐있거나 인접해 있어서는 안 된다.
정확히 M개의 구간이 있어야 한다. M개 미만이어서는 안 된다.
N개의 수들이 주어졌을 때, 답을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 두 정수 N, M이 주어진다. 다음 N개의 줄에는 배열을 이루는 수들이 차례로 주어진다. 배열을 이루는 수들은 -32768 이상 32767 이하의 정수이다.

출력
첫째 줄에 답을 출력한다.

dp[MAX][MAX] 일 때 틀렸습니다 떴음
*/