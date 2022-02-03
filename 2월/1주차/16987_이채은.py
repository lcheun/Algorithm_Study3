N = int(input())
s = [0] * N
w = [0] * N

for i in range(N):
    s[i], w[i] = map(int, input().split())

ans = 0 
def solve(idx):
    global ans
    if idx == N:
        cnt = 0
        for i in range(N):
            if s[i] <= 0:
                cnt += 1
        if cnt > ans:
            ans = cnt
        return

    if s[idx] <= 0:
        solve(idx + 1)

    else:
        flag = False
        for i in range(N):
            if s[i] > 0 and i != idx:
                s[i] -= w[idx]
                s[idx] -= w[i]

                flag = True
                solve(idx + 1)

                s[i] += w[idx]
                s[idx] += w[i]

            if not flag:
                solve(N)

solve(0)
print(ans)
