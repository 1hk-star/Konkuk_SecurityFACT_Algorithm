def solution(phone_book):
    # len(phone_book) : n
    # 각 전화번호 길이 : m
    # 최대 O(nlogn), O(nm)까지 가능할 듯. n*m = 20,000,000, nlogn ~= 20,000,000

    answer = True
    prefix_dict = {}

    # O(nlogn) 알고리즘 ==> 너무 비효율적, 느림
    phone_book.sort(key=lambda x: -len(x))
    for phone_num in phone_book:
        if phone_num in prefix_dict:
            return False

        for i in range(1, len(phone_num) + 1):
            prefix = phone_num[:i]

            if prefix not in prefix_dict:
                prefix_dict[prefix] = 1

    return True

# O(n) 알고리즘
# def solution(phone_book):
#     answer = True
#     prefix_dict = {}

#     for phone_number in phone_book:
#         prefix_dict[phone_number] = 1

#     for phone_num in phone_book:
#         prefix = ""
#         for number in phone_num:
#             prefix += number

#             if prefix in prefix_dict and prefix != phone_num:
#                 answer = False

#     return answer