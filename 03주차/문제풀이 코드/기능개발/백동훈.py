import math
from collections import deque


def solution(progresses, speeds):
    answer = []

    queue = deque()
    prev_work_day = -1
    for progress, speed in zip(progresses, speeds):
        work_day = math.ceil((100 - progress) / speed)
        if prev_work_day < work_day:
            if len(queue) > 0:
                answer.append(len(queue))

            while queue:
                queue.pop()

            prev_work_day = work_day

        queue.append(work_day)

    if len(queue) > 0:
        answer.append(len(queue))

    return answer