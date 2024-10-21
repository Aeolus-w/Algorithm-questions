resulta = [
    [0,0,1,1,0],
    [1,0,0,1,0],
    [0,1,0,0,1],
    [0,0,1,0,1],
    [1,1,0,0,0]
]
resultb = [
    [0,1,0,0,1],
    [0,0,1,0,1],
    [1,0,0,1,0],
    [1,1,0,0,0],
    [0,0,1,1,0]
]
nums = []
nums = list(map(int, input().strip().split()))
n = nums[0]
na = nums[1]
nb = nums[2]

lista = [] 
listb = []
#这两种都可以，一定要记住
lista = list(map(int, input().strip().split()))
listb = [int(x) for x in input().strip().split()]
ansa = 0
ansb = 0
for i in range(n):
    ansa += resulta[lista[i % na]][listb[i % nb]]
    ansb += resultb[lista[i % na]][listb[i % nb]]
print(ansa, ansb)