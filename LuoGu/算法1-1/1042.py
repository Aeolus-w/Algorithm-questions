#乒乓球
def calculate_game_results(game_str, standard):
    w, l = 0, 0  # 记录当前局的比分
    results = []  # 用来存储每局的结果

    for char in game_str:
        if char == 'W':
            w += 1
        elif char == 'L':
            l += 1

        # 检查当前局是否结束
        if (w >= standard or l >= standard) and abs(w - l) >= 2:
            results.append(f"{w}:{l}")
            w, l = 0, 0  # 新的一局，比分清零

    # 如果最后一局未结束，则输出当前比分
    results.append(f"{w}:{l}")
    
    return results

# 读取输入
game_str = ""
while True:
    try:
        line = input().strip()
        game_str += line
        if 'E' in line:
            game_str = game_str.split('E')[0]  # 忽略'E'之后的内容
            break
    except EOFError:
        break

# 计算11分制结果
results_11 = calculate_game_results(game_str, 11)
# 计算21分制结果
results_21 = calculate_game_results(game_str, 21)

# 输出11分制结果
for result in results_11:
    print(result)

# 输出空行
print()

# 输出21分制结果
for result in results_21:
    print(result)
