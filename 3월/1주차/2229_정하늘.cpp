#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#define MAX 1010

using namespace std;


int main() {
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	int score[MAX] = { 0, };
	int dp[MAX] = { 0, };
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &score[i]);	
		int max_ = 0, min_ = 1234567890;
		for (int j = i; j > 0; j--) {
			if (max_ < score[j]) max_ = score[j];
			if (min_ > score[j]) min_ = score[j];
			if (dp[i] < dp[j - 1] + max_ - min_) dp[i] = dp[j - 1] + max_ - min_;
		}
	}
	printf("%d\n", dp[n]);
	
}


/*
2229. 조 짜기
https://www.acmicpc.net/problem/2229

문제
알고스팟 캠프에 N(1 ≤ N ≤ 1,000)명의 학생들이 참여하였다. 학생들은 열심히 공부를 하고 있었는데, 어느 날 조별 수업을 진행하기로 하였다. 조별 수업의 목적은 잘 하는 학생들과 덜 잘 하는 학생들을 같은 조로 묶어서 서로 자극을 받으며 공부하도록 만들기 위함이다. 따라서 가급적이면 실력 차이가 많이 나도록 조를 편성하는 것이 유리하다.

하지만 조를 편성할 때 같은 조에 속하게 된 학생들의 나이 차이가 많이 날 경우에는 오히려 부정적인 효과가 나타날 수도 있다. 따라서 선생님들은 우선 학생들을 나이 순서대로 정렬한 다음에, 적당히 학생들을 나누는 방식으로 조를 짜기로 하였다. 조의 개수는 상관이 없다.

각각의 조가 잘 짜여진 정도는 그 조에 속해있는 가장 점수가 높은 학생의 점수와 가장 점수가 낮은 학생의 점수의 차이가 된다. 또한 전체적으로 조가 잘 짜여진 정도는, 각각의 조가 잘 짜여진 정도의 합으로 나타난다. 한 명으로 조가 구성되는 경우에는 그 조의 잘 짜여진 정도가 0이 된다(가장 높은 점수와 가장 낮은 점수가 같으므로).

학생들의 점수가 주어졌을 때, 조가 잘 짜여진 정도의 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. 다음 줄에는 N명의 학생들의 점수가 나이 순서대로 주어진다. 각 학생의 점수는 0 이상 10,000 이하의 정수이다.

출력
첫째 줄에 답을 출력한다.
*/