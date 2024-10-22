n = map(int, input())
nums = list(map(int, input().split()))

nums.sort()

for num in nums:
    print(num, end = ' ')
    