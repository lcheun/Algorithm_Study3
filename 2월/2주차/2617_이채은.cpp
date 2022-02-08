#include<vector>
#include<stdio.h>
#include<string.h>

using namespace std;

int M, N, ans;
bool res[101];
bool hVisit[101], lVisit[101];
vector <int> heavy[101], light[101];

int hDfs(int num) {
	int hCnt = 1;

	for (int i = 0; i < heavy[num].size(); i++) {
		if (!hVisit[heavy[num][i]]) {
			hVisit[heavy[num][i]] = true;
			hCnt += hDfs(heavy[num][i]);
		}
	}

	return hCnt;
}

int lDfs(int num) {
	int lCnt = 1;

	for (int i = 0; i < light[num].size(); i++) {
		if (!lVisit[light[num][i]]) {
			lVisit[light[num][i]] = true;
			lCnt += lDfs(light[num][i]);
		}
	}

	return lCnt;
}

int main() {
	scanf("%d %d", &N, &M);

	int x, y;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &x, &y);
		heavy[x].push_back(y);
		light[y].push_back(x);
	}

	for (int i = 1; i <= N; i++) {
		memset(hVisit, false, sizeof(hVisit));
		memset(lVisit, false, sizeof(lVisit));
		hVisit[i] = lVisit[i] = true;

		if (hDfs(i) > (N + 1) / 2 || lDfs(i) > (N + 1) / 2)
			res[i] = true;
	}

	for (int i = 0; i <= N; i++)
		if (res[i]) ans++;

	printf("%d", ans);
}
