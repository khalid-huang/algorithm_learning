def expandLeftToRight(s, point, l, r):
    rsl = [s[point]]
    if r - l == 3 and s[point]:
        rsl.append(s[point+1])
    size = len(s)
    while l >= 0:
        while r < size and s[l] != s[r]:
            r = r + 1
        if r < size:
            rsl.append(s[r])
            rsl.insert(0, s[l])
            l = l - 1
            r = r + 1
        else:
            break
    rsl = ''.join(rsl)
    return rsl

def expandRightToleft(s, point, l, r):
    rsl = [s[point]]
    if r - l == 3 and s[point]:
        rsl.append(s[point+1])
    size = len(s)
    while r < size:
        while l >= 0 and s[l] != s[r]:
            l = l - 1
        if l >= 0:
            rsl.append(s[r])
            rsl.insert(0, s[l])
            r = r + 1
            l = l - 1
        else:
            break
    rsl = ''.join(rsl)
    return rsl

def getMaxStr(s1, s2, s3, s4):
    size = max(len(s1), len(s2), len(s3), len(s4))
    rsl = []
    if len(s1) == size:
        rsl.append(s1)
    if len(s2) == size:
        rsl.append(s2)
    if len(s3) == size:
        rsl.append(s3)
    if len(s4) == size:
        rsl.append(s4)
    return rsl


s = 'acbbcad'
size = len(s)
maxLen = 0
maxStr = ''
for i in range(size):
    s1 = expandLeftToRight(s, i, i-1, i+1)
    s2 = expandRightToleft(s, i, i-1, i+1)
    if i + 1 < size and s[i] == s[i+1]:
        s3 = expandLeftToRight(s, i, i-1, i+2)
        s4 = expandRightToleft(s, i, i-1, i+2)
    else:
        s3 = ''
        s4 = ''
    temp = max(maxLen, len(s1), len(s2), len(s3), len(s4))
    if temp > maxLen:
        maxLen = temp
        maxStr = getMaxStr(s1, s2, s3, s4)
    if i == 2:
        print s1, s2, s3, s4
    # print i, s[i]
    # print s1,s2,s3,s5

print maxLen, maxStr
print maxLen
