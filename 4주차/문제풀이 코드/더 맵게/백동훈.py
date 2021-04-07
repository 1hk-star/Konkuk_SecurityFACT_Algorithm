import heapq


def solution(scoville, K):
    # len(scoville) : 1 <= n <= 1000000
    # 최대 O(nlogn)정도
    answer = 0

    heapq.heapify(scoville)

    # O(nlogn)
    while scoville[0] < K:
        if len(scoville) <= 1:
            return -1

        mix_scoville = heapq.heappop(scoville) + heapq.heappop(scoville) * 2
        heapq.heappush(scoville, mix_scoville)

        answer += 1

    return answer