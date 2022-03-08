#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

char arr[3][3];
int x, o, point;
bool flag = true;

int check(char c) {
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) {		//가로 3개 확인
			if (arr[i][0] == c) 	cnt++;
		}
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]) {		//세로 3개 확인
			if (arr[0][i] == c) 	cnt++;
		}
	}
	//대각선 2개 확인
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) {
		if (arr[1][1] == c)		cnt++;
	}
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) {
		if (arr[1][1] == c) 	cnt++;
	}
	return cnt;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string line;
	cin >> line;

	while (line != "end") {
		flag = true;//이미 연속으로 3개가 나온 적 있는 지
		point = 0;	x = 0;	o = 0;
		int cnt = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				arr[i][j] = line[cnt++];
				if (arr[i][j] == '.') point++;
				else if (arr[i][j] == 'X') x++;
				else if (arr[i][j] == 'O') o++;
			}
		}
		if (point == 0) {//맨 마지막수까지 둔 경우, 'O'3개가 연속되면 안된다
			if (x - 1 != o)	flag = false;//개수 비교
			int result = check('O');
			if (result > 0) flag = false;
		}
		else if (point % 2 == 0 && point != 0) {//X가 O보다 1개 더 많아야 하며 X가 이겨야 한다
			if (x - 1 != o)	flag = false;//개수 비교
			int result = check('O');
			if (result > 0) flag = false;
			result = check('X');
			if (result == 0) flag = false;
		}
		else {//X와 O의 개수가 같아야 하며 O가 이겨야 한다
			if (x != o)	flag = false;//개수 비교
			int result = check('X');
			if (result > 0) flag = false;
			result = check('O');
			if (result == 0) flag = false;
		}
		if (flag) cout << "valid\n";
		else cout << "invalid\n";

		cin >> line;
	}

}


/*
7682. 틱택토
https://www.acmicpc.net/problem/7682

문제
틱택토 게임은 두 명의 사람이 번갈아가며 말을 놓는 게임이다. 게임판은 3×3 격자판이며, 처음에는 비어 있다. 두 사람은 각각 X 또는 O 말을 번갈아가며 놓는데, 반드시 첫 번째 사람이 X를 놓고 두 번째 사람이 O를 놓는다. 어느 때든지 한 사람의 말이 가로, 세로, 대각선 방향으로 3칸을 잇는 데 성공하면 게임은 즉시 끝난다. 게임판이 가득 차도 게임은 끝난다.

게임판의 상태가 주어지면, 그 상태가 틱택토 게임에서 발생할 수 있는 최종 상태인지를 판별하시오.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 줄은 9개의 문자를 포함하며, 'X', 'O', '.' 중 하나이다. '.'은 빈칸을 의미하며, 9개의 문자는 게임판에서 제일 윗 줄 왼쪽부터의 순서이다. 입력의 마지막에는 문자열 "end"가 주어진다.

출력
각 테스트 케이스마다 한 줄에 정답을 출력한다. 가능할 경우 "valid", 불가능할 경우 "invalid"를 출력한다.
*/