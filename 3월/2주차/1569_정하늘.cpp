#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int n, ans = 1234567890;
vector<pair<int, int>> points;

bool chk(int x, int y, int l) {
	int size = points.size();
	for (int i = 0; i < size; i++) {
		int xx = points[i].first;
		int yy = points[i].second;
		if (xx < x || xx > x + l || yy < y || yy > y + l) return false; //정사각형 밖
		else if (x < xx && xx < x + l && y < yy && yy < y + l) return false;//정사각형 안
	}

	return true;
}


int main() {
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	scanf("%d", &n);
	int x_max = -1234567890, x_min = 1234567890, y_max = -1234567890, y_min = 1234567890;
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x_max = max(x_max, x), x_min = min(x_min, x);
		y_max = max(y_max, y), y_min = min(y_min, y);
		points.push_back({ x,y });
	}
	int line = max(x_max - x_min, y_max - y_min);
	bool flag = false;
	for (int i = 0; i < n; i++) {
		int x = points[i].first, y = points[i].second;
		for (int j = 1; j <= line; j++) {
			if (chk(x, y, line) || chk(x - j, y, line) || chk(x, y - j, line) || chk(x - j, y - j, line)) {
				ans = min(ans, line);
				flag = true;
				break;
			}//각 점에 대해 1, 2, 3, 4분면 사각형을 그려봄
		}
		if (flag) break;

	}

	if (flag) printf("%d\n", line);
	else printf("-1\n");
}


/*
1569. 정사각형으로 가리기
https://www.acmicpc.net/problem/1569

문제
정사각형으로 가려지는 점이란, 어떤 점이 그 정사각형의 한 변 위에 놓여져 있을 때, 정사각형으로 가려진다고 한다.

점이 N개가 주어진다. N개의 점 모두를 가릴 수 있는 정사각형을 구하는 프로그램을 작성하시오. 정사각형의 변은 x축과 y축에 평행해야 한다.

입력
첫째 줄에 N이 주어진다. 둘째 줄부터 N개의 줄에 점이 X좌표 Y좌표 순으로 주어지고, 이 값의 절댓값은 1000보다 작거나 같다. 모든 좌표는 정수이다. 같은 점이 여러 번 주어지는 경우는 없다.

출력
모든 점을 가릴 수 있는 정사각형이 존재할 경우, 그 변의 길이를 첫째 줄에 출력한다. 정사각형으로 가릴 수 없는 경우에는 -1을 출력한다.


조건 1. (x 최대 - x 최소) or (y 최대 - y 최소) -> 가능하다면 이 길이가 정답
조건 2. 모든 점에 대해 1, 2, 3, 4 사분면으로 확인
*/