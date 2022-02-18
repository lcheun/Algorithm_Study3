#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#define MAX 20

using namespace std;

int N, L, R, X, ans;
vector<int> problems, selected;
bool visit[MAX];

void backtracking(int index, int levelSum, int cnt) {
	if (cnt >= 2 && levelSum >= L && levelSum <= R) {
		int len = selected.size();
		int maxValue = -1234567890, minValue = 1234567890;
		for (int i = 0; i < len; i++) {
			maxValue = max(maxValue, problems[selected[i]]);
			minValue = min(minValue, problems[selected[i]]);
		}
		if (maxValue - minValue >= X) ans++;
	}

	for (int i = index; i < N; i++) {
		if (visit[i]) continue;
		if (levelSum + problems[i] <= R) {
			visit[i] = true;
			selected.push_back(i);
			backtracking(i, levelSum + problems[i], cnt + 1);
			selected.pop_back();
			visit[i] = false;
		}
	}
}


int main() {
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	scanf("%d%d%d%d", &N, &L, &R, &X);

	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		problems.push_back(x);
	}

	backtracking(0, 0, 0);
	printf("%d\n", ans);
}


/*
16938. 캠프 준비
https://www.acmicpc.net/problem/16938

문제
알고리즘 캠프를 열려면 많은 준비가 필요하다. 그 중 가장 중요한 것은 문제이다. 오늘은 백준이를 도와 알고리즘 캠프에 사용할 문제를 고르려고 한다.

백준이는 문제를 N개 가지고 있고, 모든 문제의 난이도를 정수로 수치화했다. i번째 문제의 난이도는 Ai이다.

캠프에 사용할 문제는 두 문제 이상이어야 한다. 문제가 너무 어려우면 학생들이 멘붕에 빠지고, 문제가 너무 쉬우면 학생들이 실망에 빠지게 된다. 따라서, 문제 난이도의 합은 L보다 크거나 같고, R보다 작거나 같아야 한다. 또, 다양한 문제를 경험해보기 위해 가장 어려운 문제와 가장 쉬운 문제의 난이도 차이는 X보다 크거나 같아야 한다.

캠프에 사용할 문제를 고르는 방법의 수를 구해보자.

입력
첫째 줄에 N, L, R, X가 주어진다.

둘째 줄에는 문제의 난이도 A1, A2, ..., AN이 주어진다.

출력
캠프에 사용할 문제를 고르는 방법의 수를 출력한다.


조건

1. 가장 어렵고 쉬운 문제의 차 >= X
2. L <= 문제 난이도의 합 <= R
3. 둘 이상
*/