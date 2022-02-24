#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int p[101];
int visit[101];
vector<int> res;

void dfs(int start, int cur) {
	if (visit[cur] == 0) {
		visit[cur] = start;
		dfs(start, p[cur]);
	}
	else if (cur == start) {
		res.push_back(start);
		return;
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> p[i];
	
	for (int i = 1; i <= N; i++) {
		memset(visit, 0, sizeof(visit));
		dfs(i, i);
	}

	cout << res.size() << "\n";
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << "\n";
	}
}
