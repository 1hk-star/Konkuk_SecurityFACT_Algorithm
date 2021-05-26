def solution(citations):
    # len(citations) : 1 <= n <= 1000
    answer = 0

    citations.sort()  # O(nlogn)

    # O(n^2)?
    max_h = -1
    for i in range(len(citations)):
        h = citations[i]
        n_h_over = len(citations) - i

        if n_h_over >= h:
            max_h = h
        else:
            # i == 2에서 실패하면 3개(len(citations)-i) + 1이상임
            for h in range(citations[i], max_h - 1, -1):
                if n_h_over >= h:
                    max_h = h

                    return max_h

    # 최종 : O(n^2)??
    return max_h