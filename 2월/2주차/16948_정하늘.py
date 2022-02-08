import collections

n = int(input())
r1,c1,r2,c2 = map(int,input().split())

dr =[-2, -2, 0, 0, 2, 2]
dc = [-1, 1, -2, 2, -1, 1]

visit = [[0] * 201 for i in range(201)]

def check(x, y):
    if (0 <= x < n) and (0 <= y < n): return True
    else: return False    

def bfs(r, c):
    queue = collections.deque()
    queue.append([r,c,0])
    visit[r][c] = 0
    while queue:
        x, y, d = queue.popleft()
        for i in range(6):
            nx = x + dr[i]
            ny = y + dc[i]
            nd = d + 1
            if check(nx,ny) and visit[nx][ny] == 0:
                queue.append([nx,ny,nd])
                visit[nx][ny] = nd

bfs(r1,c1)
print(visit[r2][c2] if visit[r2][c2] > 0 else -1)


'''
16948. 데스 나이트
https://www.acmicpc.net/problem/16948

문제
게임을 좋아하는 큐브러버는 체스에서 사용할 새로운 말 "데스 나이트"를 만들었다. 데스 나이트가 있는 곳이 (r, c)라면, (r-2, c-1), (r-2, c+1), (r, c-2), (r, c+2), (r+2, c-1), (r+2, c+1)로 이동할 수 있다.

크기가 N×N인 체스판과 두 칸 (r1, c1), (r2, c2)가 주어진다. 데스 나이트가 (r1, c1)에서 (r2, c2)로 이동하는 최소 이동 횟수를 구해보자. 체스판의 행과 열은 0번부터 시작한다.

데스 나이트는 체스판 밖으로 벗어날 수 없다.

입력
첫째 줄에 체스판의 크기 N(5 ≤ N ≤ 200)이 주어진다. 둘째 줄에 r1, c1, r2, c2가 주어진다.

출력
첫째 줄에 데스 나이트가 (r1, c1)에서 (r2, c2)로 이동하는 최소 이동 횟수를 출력한다. 이동할 수 없는 경우에는 -1을 출력한다.

파이썬의 BFS는 queue를 쓸 때, list 대신 collections의 deque를 사용함
방문체크 역시 list 대신 set()을 사용함
'''