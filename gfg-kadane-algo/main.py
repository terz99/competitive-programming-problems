cases = int(input())
while cases > 0:
    cases -= 1
    n = int(input())
    nums = list(map(int, input().split()[:n]))
    max_ending_here = 0
    minint = (-100)*1000 - 1
    max_so_far = minint
    for el in nums:
        max_ending_here += el
        if max_so_far < max_ending_here:
            max_so_far = max_ending_here
        if max_ending_here < 0:
            max_ending_here = 0
        
    print(max_so_far)