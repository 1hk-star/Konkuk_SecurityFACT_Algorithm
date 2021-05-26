import math
from itertools import permutations


def is_prime(number):
    if number <= 1:
        return False

    for i in range(2, int(math.sqrt(number)) + 1):
        if number % i == 0:
            return False

    return True


def solution(numbers):
    # len(numbers) : 1 <= n <= 7
    # 2^7 = 128
    # is_prime을 O(n)이라 해도 될 듯.

    answer = 0
    primes = set()

    # (nP1 + nP2 + ... + nPn) x logn
    for i in range(1, len(numbers) + 1):
        for str_num in permutations(numbers, i):
            num = int(''.join(str_num))

            if is_prime(num):
                if num not in primes:
                    primes.add(num)
                    answer += 1

    return answer