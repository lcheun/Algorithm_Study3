#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
 
int n, k;
int m[202][202];
bool visit[202][202];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

struct Virus { //바이러스의 종류, 위치 좌표 담는 구조체 
	int v;
	int x;
	int y;
}; 
vector<pair<int, int> > v[202*5];

 
void bfs(int s, int ey, int ex){
    queue<Virus> q;
 
    for (int i = 1; i <= k; i++) {
        if (!v[i].empty()) {
            for (auto p : v[i]) {
                q.push({ i, p.first, p.second });
                visit[p.first][p.second] = true;
            }
        }
    }
    while (!q.empty() && s--){
        int qs = q.size();
 
        while (qs--){
            Virus v1 = q.front();
            int num = v1.v;
            int r = v1.y;
            int c = v1.x;
 
            q.pop();
 
            for (int i = 0; i < 4; i++) {
                int y = r + dy[i];
                int x = c + dx[i];
 
                if (y < 1 || y > n || x < 1 || x > n || visit[y][x]) {
                    continue;
                }
 
                m[y][x] = num;
                visit[y][x] = true;
                q.push({ num, y, x });
            }
        }
    }
 
    printf("%d\n", m[ey][ex]);
}
 
int main(){
    
    int s, y, x;
    scanf("%d %d", &n, &k);
 
    int idx = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &m[i][j]);
 
            if (m[i][j]) {
                v[m[i][j]].push_back({ i, j });
            }
        }
    }
    scanf("%d %d %d", &s, &y, &x);
    bfs(s, y, x);
 
    return 0;
}
