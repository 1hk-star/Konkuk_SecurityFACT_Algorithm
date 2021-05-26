def solution(people, limit):
    answer = 0

    people.sort()

    low = 0
    high = len(people) - 1

    while low <= high:
        if (people[low] + people[high]) > limit:
            answer += 1
            high -= 1
        elif (people[low] + people[high]) <= limit:
            answer += 1
            low += 1
            high -= 1

    return answer
