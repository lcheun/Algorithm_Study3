#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;

int N, arr[101];
bool visit[101];
vector<int> result;

void dfs(int cur, int start) {
	if (visit[cur]) {
		if (cur == start) result.push_back(start);
		return;
	}
	
	visit[cur] = true;
	dfs(arr[cur], start);

}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i <= N; i++) {
		memset(visit, false, sizeof(visit));
		dfs(i, i);
	}

	printf("%d\n", result.size());
	for (int tmp : result)
		printf("%d\n", tmp);
}
