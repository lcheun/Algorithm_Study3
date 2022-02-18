#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#define MAX 51


using namespace std;

int n, m;
long long ans;
int arr[MAX][MAX];


long long sum(int x, int y, int xx, int yy) {
	long long s = 0;
	for (int i = y; i <= yy; i++) {
		for (int j = x; j <= xx; j++) {
			s += arr[i][j];
		}
	}
	return s;
}

void case1() {//6
	/*
	a	|
		|	c
	b	|
	*/
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < m - 1; j++) {
			long long a = sum(0, i, m - 1, n - 1);
			long long b = sum(0, 0, j, i - 1);
			long long c = sum(j + 1, 0, m - 1, i - 1);
			if (ans < a * b * c) ans = a * b * c;
		}
	}
}

void case2() {//5
	/*
		|	b
	a	|	
		|	c
	*/
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			long long a = sum(0, 0, m - 1, i);
			long long b = sum(0, i + 1, j, n - 1);
			long long c = sum(j + 1, i + 1, m - 1, n - 1);
			if (ans < a * b * c) ans = a * b * c;
		}
	}
}

void case3() {//1
	/*
		a
		b
		c
	*/
	for (int i = 0; i < m - 2; i++) {
		for (int j = i + 1; j < m - 1; j++) {
			long long a = sum(0, 0, i, n - 1);
			long long b = sum(i + 1, 0, j, n - 1);
			long long c = sum(j + 1, 0, m - 1, n - 1);
			if (ans < a * b * c) ans = a * b * c;
		}
	}
}

void case4() {//2
	/*
		a	b	c
	*/
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			long long a = sum(0, 0, m - 1, i);
			long long b = sum(0, i + 1, m - 1, j);
			long long c = sum(0, j + 1, m - 1, n - 1);
			if (ans < a * b * c) ans = a * b * c;
		}
	}
}

void case5() {//4
	/*
			a	
		b	|	c
	*/
	for (int i = m - 1; i > 0; i--) {
		for (int j = 0; j < n - 1; j++) {
			long long a = sum(i, 0, m - 1, n - 1);
			long long b = sum(0, 0, i - 1, j);
			long long c = sum(0, j + 1, i - 1, n - 1);
			if (ans < a * b * c) ans = a * b * c;
		}
	}
}

void case6() {//3
	/*
		a	|	b
			c
	*/
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			long long a = sum(0, 0, i, n - 1);
			long long b = sum(i + 1, 0, m - 1, j);
			long long c = sum(i + 1, j + 1, m - 1, n - 1);
			if (ans < a * b * c) ans = a * b * c;
		}
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	case1();
	case2();
	case3();
	case4();
	case5();
	case6();

	cout << ans << '\n';
}


/*
1451. 직사각형으로 나누기
https://www.acmicpc.net/problem/1451

문제
세준이는 N*M크기로 직사각형에 수를 N*M개 써놓았다.

세준이는 이 직사각형을 겹치지 않는 3개의 작은 직사각형으로 나누려고 한다. 각각의 칸은 단 하나의 작은 직사각형에 포함되어야 하고, 각각의 작은 직사각형은 적어도 하나의 숫자를 포함해야 한다.

어떤 작은 직사각형의 합은 그 속에 있는 수의 합이다. 입력으로 주어진 직사각형을 3개의 작은 직사각형으로 나누었을 때, 각각의 작은 직사각형의 합의 곱을 최대로 하는 프로그램을 작성하시오.

입력
첫째 줄에 직사각형의 세로 크기 N과 가로 크기 M이 주어진다. 둘째 줄부터 직사각형에 들어가는 수가 가장 윗 줄부터 한 줄에 하나씩 M개의 수가 주어진다. N과 M은 50보다 작거나 같은 자연수이고, 직사각형엔 적어도 3개의 수가 있다. 또, 직사각형에 들어가는 수는 한 자리의 숫자이다.

출력
세 개의 작은 직사각형의 합의 곱의 최댓값을 출력한다.

6가지 case
*/