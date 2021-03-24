def solution(genres, plays):
    # 1 <= len(genres) == len(plays) == n <= 10000
    # 장르 종류 개수 : m < 100
    # 최대 O(n^2) or O(nm^2) 정도

    answer = []

    genre_count_dict = {}  # key: genre, value : 누적 play count
    music_dict = {}  # key: genre, value: [(해당 music play count, index)]

    for i, (genre, play_count) in enumerate(zip(genres, plays)):
        if genre not in genre_count_dict:
            genre_count_dict[genre] = play_count
        else:
            genre_count_dict[genre] += play_count

        if genre not in music_dict:
            music_dict[genre] = [(play_count, i)]
        else:
            music_dict[genre].append((play_count, i))

    for genre, _ in sorted(genre_count_dict.items(), key=lambda x: -x[1]):
        music_dict[genre].sort(key=lambda x: (-x[0], x[1]))

        answer += [i for _, i in music_dict[genre][:2]]

    return answer