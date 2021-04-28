def solution(array, commands):
    answer = []

    for command in commands:
        i, j, k = command[0], command[1], command[2]

        part_arr = array[i - 1:j]
        part_arr.sort()
        answer.append(part_arr[k - 1])

    return answer