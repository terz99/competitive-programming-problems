def maxActivities(arr):
    used = []
    used.append(arr[0][2])
    j = 0
    for i in range(1, len(arr)):
        si = arr[i][0]
        fj = arr[j][1]
        if si >= fj:
            used.append(arr[i][2])
            j = i
    return used

cases = int(input())
while cases:
    cases -= 1
    n = int(input())
    s = [int(x) for x in input().split()]
    f = [int(x) for x in input().split()]
    arr = []
    for i in range(len(s)):
        arr.append((s[i], f[i], i))
    arr = sorted(arr, key=lambda x: x[1])
    res = maxActivities(arr)
    for el in res:
        print(el+1, end=" ")
    print()