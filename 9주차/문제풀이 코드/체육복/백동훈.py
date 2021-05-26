def solution(n, lost, reserve):
    # 학생수 : 2 <= n <= 30

    answer = n - len(lost)
    lost_copy = lost.copy()

    # O(n^2)
    for p in lost:
        if p in reserve:
            lost_copy.remove(p)
            reserve.remove(p)

            answer += 1

    lost = lost_copy

    for p in lost:
        if p - 1 in reserve:
            reserve.remove(p - 1)
            answer += 1
        elif p + 1 in reserve:
            reserve.remove(p + 1)
            answer += 1

    return answer