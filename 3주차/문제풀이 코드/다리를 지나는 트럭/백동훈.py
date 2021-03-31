from collections import deque


def solution(bridge_length, max_weight, truck_weights):
    # len(truck_weights) ==> 1 <= n <= 10000
    trucks = deque(truck_weights)
    cur_trucks = deque()  # 현재 다리에 있는 truck
    n_finish_trucks = 0  # 다리 건너기가 끝난 truck의 수
    n_trucks = len(trucks)  # 전체 truck의 수

    tick = 0
    cur_weight = 0
    while n_finish_trucks < n_trucks:
        tick += 1

        if len(cur_trucks) > 0:
            front_truck = cur_trucks[0]
            if tick - front_truck[1] >= bridge_length:
                cur_weight -= front_truck[0]
                cur_trucks.popleft()
                n_finish_trucks += 1

        if len(trucks) > 0:
            if cur_weight + trucks[0] <= max_weight:
                weight = trucks.popleft()
                cur_weight += weight
                cur_trucks.append((weight, tick))

    return tick