#扫雷游戏
n, m = map(int, input().split())

matrix = []

for i in range(n):
    row = list(input())
    matrix.append(row)

directions = [(-1, 0),(1, 0), (0, -1), (0, 1), (-1, -1), (-1, 1), (1, -1), (1, 1)]

for i in range(n):
    for j in range(m):
        if matrix[i][j] == '*':
            for direction in directions:
                i_surr = i + direction[0]
                j_surr = j + direction[1]
                if 0 <= i_surr < n and 0 <= j_surr < m:
                    if matrix[i_surr][j_surr] != '*':
                        if matrix[i_surr][j_surr].isdigit():
                            matrix[i_surr][j_surr] = str(int(matrix[i_surr][j_surr])+1)
                        else:
                            matrix[i_surr][j_surr] = '1'
        if matrix[i][j] != '*' and (not matrix[i][j].isdigit()):
            matrix[i][j] = '0'

# 逐元素输出
for row in matrix:
    print(''.join(map(str, row)))  # 将行中的每个数字转换为字符串并用空格连接

