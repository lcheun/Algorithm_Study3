from collections import deque

N, K = map(int, input().split())
test = [] 
virus =[] 
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for i in range(N):
    test.append(list(map(int, input().split())))
    for j in range(N):
        if test[i][j] != 0:
            virus.append((test[i][j], i, j, 0))

S, X, Y = map(int, input().split())

virus.sort()
q = deque(virus)

while q:
    v, r, c, t = q.popleft()
    if t == S:
        break
    for i in range(4):
        nx = r + dx[i]
        ny = c + dy[i]
        if 0 <= nx < N and 0 <= ny < N:
            if test[nx][ny] == 0:
                test[nx][ny] = v
                q.append((v, nx, ny, t + 1))

print(test[X-1][Y-1])
