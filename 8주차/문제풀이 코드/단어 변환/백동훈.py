def is_convertible(word1, word2):
    # len(word1) == len(word2)

    num_diff_words = sum([True if ch1 != ch2 else False for ch1, ch2 in zip(word1, word2)])

    return (num_diff_words == 1)

min_count = 99999
def dfs(begin, target, words, count):
    global min_count
    if len(words) == 0:
        return

    words_copy = words.copy()
    # words_copy = words

    for i, word in enumerate(words):
        if is_convertible(begin, word):
            if word == target:
                if count < min_count:
                    min_count = count
                return

            del words_copy[i]
            dfs(word, target, words_copy, count + 1)
            words_copy = words.copy()

def solution(begin, target, words):
    global min_count

    if target not in words:
        return 0

    dfs(begin, target, words, 1)

    return min_count