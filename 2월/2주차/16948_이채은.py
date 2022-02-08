from collections import deque

N = int(input())
r1, c1, r2, c2 = map(int, input().split())
dy = [-2, -2, 0, 0, 2, 2]
dx = [-1, 1, -2, 2, -1, 1]
visit = [[False] * N for _ in range(N)]
q = deque()

q.append((r1, c1, 0))
visit[r1][c1] = True
while q:
    y, x, cnt = q.popleft()
    for i in range(6):
        ny = y + dy[i]
        nx = x + dx[i]
        if ny == r2 and nx == c2:
            print(cnt+1)
            exit()
        if 0 <= ny < N and 0 <= nx < N and not visit[ny][nx]:
            visit[ny][nx] = True
            q.append((ny, nx, cnt+1))
            
print(-1)
        
