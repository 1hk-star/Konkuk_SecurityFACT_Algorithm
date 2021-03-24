from collections import defaultdict


def solution(clothes):
    # 의상 수 : 1 <= n <= 30
    # 의상 종류 수 : 1 <= m <= n
    answer = 1
    type_dict = defaultdict(int)  # key: 종류, value: 종류 count

    # n + m = O(n)
    for _, cloth_type in clothes:
        type_dict[cloth_type] += 1

    keys = list(type_dict.keys())

    for key in keys:
        answer *= type_dict[key] + 1

    answer -= 1

    return answer