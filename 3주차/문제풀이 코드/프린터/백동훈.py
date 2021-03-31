from collections import deque, defaultdict


def solution(priorities, location):
    # len(priorities) : 1 <= n <= 100
    answer = 0
    result_seq = 0

    p_count = defaultdict(int)
    p_deque = deque()
    for i, p in enumerate(priorities):
        p_deque.append((p, i))
        p_count[p] += 1

    p_count = sorted(p_count.items(), key=lambda x: -x[0])  # 10*log10
    for max_p, c in p_count:
        max_p_count = 0

        i = 0
        while max_p_count < c:
            popleft = p_deque.popleft()
            p = popleft[0]

            if p < max_p:
                p_deque.append(popleft)
            else:
                print_location = popleft[1]

                result_seq += 1
                max_p_count += 1

                if print_location == location:
                    return result_seq

    # 최종 : O(n)