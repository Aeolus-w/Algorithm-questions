#Scarlet

n, m = input().split()
n, m = int(n), int(m)

array = [[0]* n for _ in range(n)]

operations = []
for _ in range(m):#输入操作列表
    row = list(map(int, input().split()))
    operations.append(row)


def init_table(arr, n):
    m = 1
    for i in range(n):
        for j in range(n):
            arr[i][j] = m
            m = m + 1
    return arr

def print_table(arr,n):
    for i in range(n):
        for j in range(n):
            if j == n - 1:
                print(array[i][j])
            else:
                print(array[i][j], end = ' ')


def change_table(arr, x, y, r, z):
    #0顺1逆
    #(x - (n - y), y + m - x)绕(x, y)顺时针到(m, n)，(x + n - y, y - (m - x))逆时针到(x, y)
    little = [[0]*(2*r+1) for _ in range(2*r+1)]#小列表（要转的）
    for row in range(2 * r +1):
        for column in range(2 * r + 1):
            little[row][column] = arr[x - r - 1 + row][y - r - 1 + column]
    little_l = [[0]*(2*r+1) for _ in range(2*r+1)]
    for row in range(2 * r +1):
        for column in range(2 * r + 1):
            if z == 0:
                little_l[row][column] = little[2*r - column][row]
            else:
                little_l[row][column] = little[column][2*r - row]
    for row in range(2 * r +1):
        for column in range(2 * r + 1):
            arr[x - r - 1 + row][y - r - 1 + column] = little_l[row][column]
    return arr

array = init_table(array, n)#初始化列表
for i in range(m):
    array = change_table(array, operations[i][0], operations[i][1], operations[i][2], operations[i][3])
print_table(array, n)

