#高精度加法
n_r = input()
m_r = input()
n_1 = list(map(int, n_r))
m_1 = list(map(int, m_r))
n = n_1[::-1]#反转存储
m = m_1[::-1]
n_l = n.__len__()
m_l = m.__len__()

short_length = min(n_l, m_l)
long_length = max(n_l, m_l)

def pad_to_length(arr, n):
    padding_needed = n - len(arr)
    if padding_needed > 0:
        arr = arr + [0]*padding_needed
    return arr
n=pad_to_length(n, long_length)
m=pad_to_length(m, long_length)

ans = [0]*(long_length + 2)

for i in range(long_length):
    if ans[i] + n[i] + m[i] < 10:
        sum = n[i] + m[i] 
        ans[i] += sum

    else:
        sum = ans[i] + n[i] + m[i]
        ans[i] = sum % 10
        ans[i+1] += sum//10

        

ans_r = ans[::-1]
#print(ans_r)
ans_l = ans_r.__len__()
flag = 0
for i in range(ans_l):
    if flag == 0 and ans_r[i] == 0:
        continue
    else:
        flag = 1
        print(ans_r[i],end = '')


