#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

int N, M;
bool flag, visited[40000];
long long ans = 1LL;
map<int, int> A, B;
vector<int> prime;

void set() {
	for (int i = 2; i < 40000; ++i) {
		if (visited[i]) continue;
		prime.push_back(i);
		for (int j = 2 * i; j < 40000; j += i) visited[j] = true;
	}
}

void MakeA(int a) {
	for (int now : prime) {
		if (a % now == 0) {
			A[now]++;
			MakeA(a / now);
			return;
		}
	}
	if (a != 1) A[a]++;
}

void MakeB(int a) {
	for (int now : prime) {
		if (a % now == 0) {
			B[now]++;
			MakeB(a / now);
			return;
		}
	}
	if (a != 1) B[a]++;
}

int main() {
	set();

	int num;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &num);
		MakeA(num);
	}

	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		scanf("%d", &num);
		MakeB(num);
	}


	for (auto tmp : A) {
		int p = tmp.first;
		if (!B.count(p)) continue;
		int cnt = min(A[p], B[p]);
		while (cnt--) {
			ans *= p;
			if (ans > 999999999) {
				flag = true;
				ans %= 1000000000;
			}
		}
	}

	if (flag) printf("%09lld", ans);
	else printf("%d", ans);
}
