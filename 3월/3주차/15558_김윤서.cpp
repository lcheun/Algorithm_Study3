//https://www.acmicpc.net/problem/15558
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
char a[2][100001];
bool check[2][100001];

void bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    for (int i=0; i<n; i++) {
        for (int j=0; j<(int)q.size(); j++) {
            int x = q.front().first, y = q.front().second; q.pop();
            int nx[] = {x, x, !x}, ny[] = {y-1, y+1, y+k};
            for (int k=0; k<3; k++) {
                if (ny[k] >= n) {
                    printf("1\n");
                    return;
                }
                if (ny[k] <= i || check[nx[k]][ny[k]] || a[nx[k]][ny[k]] == '0') continue;
                q.push(make_pair(nx[k], ny[k]));
                check[nx[k]][ny[k]] = true;
            }
        }
    }
    printf("0\n");
}

int main() {
    scanf("%d %d", &n, &k);
    scanf("%s %s", a[0], a[1]);
    bfs();
    return 0;
}
