def solution(brown, yellow):
    # len(brown): 8 <= b <= 5000
    # len(yellow): 1 <= y <= 2,000,000
    # 가로 길이(width) >= 세로 길이(height)
    n_grid = brown + yellow

    for h in range(3, n_grid + 1):
        if n_grid % h != 0:
            continue

        w = n_grid // h

        if h > w:
            continue

        if (w - 2) * (h - 2) == yellow:
            return [w, h]