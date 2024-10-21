#玩具谜题
n, m = map(int,input().split())
nums = []
names = []
for i in range(n):
    num, name = input().split()
    nums.append(int(num))
    names.append(name)
directions = []
steps = []
for i in range(m):
    direction, step = input().split()
    directions.append(int(direction))
    steps.append(int(step))

curr = 0#现在的位置是第几个小孩
for i in range(m):#依次处理m条指令
    if nums[curr] ^ directions[i] == 0 :#内左外右减
        curr -= steps[i]
        curr = curr % n
    elif nums[curr] ^ directions[i] == 1 :
        curr += steps[i]
        curr = curr % n

print(names[curr])