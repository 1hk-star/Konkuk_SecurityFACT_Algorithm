import heapq


def solution(operations):
    # len(operations) : 1 <= n <= 10000000
    # 최대 O(nlogn)?

    answer = []
    heap = []

    for operation in operations:
        op = operation.split()[0]
        data = operation.split()[1]

        if op == 'I':
            heapq.heappush(heap, int(data))
        elif op == 'D' and len(heap) > 0:
            if data == '1':
                heap.pop()
            elif data == '-1':
                heapq.heappop(heap)

    if len(heap) > 0:
        answer = [max(heap), min(heap)]
    else:
        answer = [0, 0]

    return answer