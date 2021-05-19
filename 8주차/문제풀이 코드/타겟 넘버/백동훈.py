count = 0

def dfs(numbers, target, sum):
    global count

    if len(numbers) == 0:
        return

    sum_1 = sum - numbers[0]
    sum_2 = sum + numbers[0]

    if len(numbers) == 1:
        if sum_1 == target:
            count += 1
        if sum_2 == target:
            count += 1
    else:
        dfs(numbers[1:], target, sum_1)
        dfs(numbers[1:], target, sum_2)

def solution(numbers, target):
    # 2 <= len(numbers) <= 20
    global count
    dfs(numbers, target, 0)

    return count