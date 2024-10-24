game_map = []
memory = []
directions = [
    [0,1]#north
    [1,0]
    [0,-1]
    [-1,0]
]
d = 0
for i in range(10):
    row = list(input().strip())
    game_map.append(row)

def move(i, j,d):
    if (i + directions[d] < 0) or (i + directions[d] > 9) or  ():
