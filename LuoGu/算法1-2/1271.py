n, m = map(int,input().split())
'''
m个数字   每个都在1到n之间   排序
'''
nums = list(map(int,input().split()))
nums.sort()
print(nums)

for num in nums:
    print(num, end = ' ')

print('')
count = [0] * n

for i in range(m):
    count[nums[i] - 1] += 1


a = 1
for countnum in count:
    for i in range(countnum):
        print(a, end = ' ')
    a += 1


