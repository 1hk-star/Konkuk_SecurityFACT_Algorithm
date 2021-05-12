def solution(answers):
    answer = []

    person1 = [1, 2, 3, 4, 5]  # 5
    person2 = [2, 1, 2, 3, 2, 4, 2, 5]  # 8
    person3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]  # 10

    counts = [0, 0, 0]
    for i in range(len(answers)):
        if answers[i] == person1[i % len(person1)]:
            counts[0] += 1

        if answers[i] == person2[i % len(person2)]:
            counts[1] += 1

        if answers[i] == person3[i % len(person3)]:
            counts[2] += 1

    max_count = max(counts)
    for i in range(len(counts)):
        if counts[i] == max_count:
            answer.append(i + 1)

    return answer