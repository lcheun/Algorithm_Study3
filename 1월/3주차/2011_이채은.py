num = list(map(int,input()))
l = len(num)
dp = [0 for i in range(l+1)]
dp[0] = 1
dp[1] = 1

if (num[0] == 0) :
    print("0")
else :
    num = [0] + num
    for i in range(2, l+1):
        if num[i] > 0:
            dp[i] += dp[i-1]
        tmp = num[i-1] * 10 + num[i]
        if tmp >= 10 and tmp <= 26 :
            dp[i] += dp[i-2]
    print(dp[l] % 1000000)
