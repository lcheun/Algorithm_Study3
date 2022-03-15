#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#define INF 2e9

using namespace std;

struct INFO { //버튼 종류를 구조체로 저장 
	int ADDH, ADDT, MINT, ADDO, MINO;
	int Time; 
};

int T, N;
INFO Minute[MAX];
bool visited[MAX];
queue<INFO> Q; //

void BFS() {
	INFO Info = { 0,0,0,0,0,0 }; //초기화 
	Q.push(Info); //큐에 삽입 

	while (!Q.empty()) {
		INFO CurInfo = Q.front(); //큐에서 빼고 
		Q.pop();
		int cur_time = CurInfo.Time;
		int cur_ADDH = CurInfo.ADDH;
		int cur_ADDT = CurInfo.ADDT;
		int cur_MINT = CurInfo.MINT;
		int cur_ADDO = CurInfo.ADDO;
		int cur_MINO = CurInfo.MINO;
		
		if ((cur_time >= 0) && (cur_time <= 60) && (!visited[cur_time])) {
			visited[cur_time] = true;
			Minute[CurInfo.Time] = CurInfo;
			Q.push({cur_ADDH, cur_ADDT, cur_MINT, cur_ADDO, cur_MINO+1, cur_time-1});
			Q.push({cur_ADDH, cur_ADDT, cur_MINT, cur_ADDO+1, cur_MINO, cur_time+1});
			Q.push({cur_ADDH, cur_ADDT, cur_MINT+1, cur_ADDO, cur_MINO, cur_time-10});
			Q.push({cur_ADDH, cur_ADDT+1, cur_MINT, cur_ADDO, cur_MINO, cur_time+10});
			Q.push({cur_ADDH+1, cur_ADDT, cur_MINT, cur_ADDO, cur_MINO, cur_time+60});
		}
	};
}

int main() {
	BFS();
	cin >> T;
	while (T--) {
		cin >> N;
		int M = N / 60; //일단 주어진 시간 N을 60으로 나눈다
		int R = N % 60; //ADDH를 누른 횟수가 됨  
		printf("%d %d %d %d %d\n",Minute[R].ADDH + M, Minute[R].ADDT, Minute[R].MINT, Minute[R].ADDO, Minute[R].MINO);
	};

	return 0;
}
