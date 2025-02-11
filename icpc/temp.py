def getVal(s):
    return sum(ord(ch) - ord('a') + 1 for ch in s)

n, m = map(int, input().split())
s = [input().strip() for _ in range(n)]
cst = [int(input().strip()) for _ in range(n)]
c = [tuple(input().split()) for _ in range(m)]
b = int(input().strip())

val = [getVal(st) for st in s]
cMap = {i: set() for i in range(n)}
sIdx = {s[i]: i for i in range(n)}

for first, second in c:
    if first in sIdx and second in sIdx:
        i1 = sIdx[first]
        i2 = sIdx[second]
        cMap[i1].add(i2)
        cMap[i2].add(i1)

dp = {}

def getMax(i, bLeft, uMask):
    if i == n:
        return 0
    k = f"{i}-{bLeft}-{uMask}"
    if k in dp:
        return dp[k]
    
    ex = getMax(i + 1, bLeft, uMask)
    in_ = 0
    if cst[i] <= bLeft:
        hasC = False
        j = 0
        while j < n:
            if (uMask & (1 << j)) and j in cMap[i]:
                hasC = True
                break
            j += 1
        if not hasC:
            in_ = val[i] + getMax(i + 1, bLeft - cst[i], uMask | (1 << i))
    
    dp[k] = max(ex, in_)
    return dp[k]

res = getMax(0, b, 0)
print(res)
