#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, k, ans;
string line[2];
bool visit[2][100001];

void bfs() {
    int time = 0;
    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto p = q.front(); q.pop();

            if (p.second >= N) {
                ans = 1; return;
            }

            if (p.second + 1 >= N || (!visit[p.first][p.second + 1] && line[p.first][p.second + 1] == '1')) {
                visit[p.first][p.second + 1] = true;
                q.push({ p.first, p.second + 1 });
            }

            if (p.second >= 1 && p.second - 1 > time && (line[p.first][p.second - 1] == '1' && !visit[p.first][p.second - 1])) {
                visit[p.first][p.second - 1] = true;
                q.push({ p.first, p.second - 1 });
            }

            if (p.second + k >= N || (line[(p.first + 1) % 2][p.second + k] == '1' && !visit[(p.first + 1) % 2][p.second + k])) {
                visit[(p.first + 1) % 2][p.second + k] = true;
                q.push({ (p.first + 1) % 2, p.second + k });
            }
        }
        time++;
    }
}

int main() {
    cin >> N >> k;
    for (int i = 0; i < 2; i++)
        cin >> line[i];
    bfs();
    cout << ans << '\n';
}
