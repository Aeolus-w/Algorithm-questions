#阶乘之和
import math

# 读取输入
n = int(input())

# 计算阶乘的累加和
S = sum(math.factorial(i) for i in range(1, n + 1))

# 输出结果
print(S)
