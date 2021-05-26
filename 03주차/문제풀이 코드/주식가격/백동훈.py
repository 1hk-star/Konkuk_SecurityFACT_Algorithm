def solution(prices):
    # prices의 길이 : 1 <= n <= 100000
    # 최대 O(nlogn)
    n_prices = len(prices)
    answer = [0 for _ in range(n_prices)]

    stack = [(prices[0], 0)]
    for i, price in enumerate(prices):
        top_price = stack[-1][0]

        if top_price > price:
            # top_price <= price가 될 때까지 pop한 후에 push
            while top_price > price:
                stack_top = stack.pop()
                answer[stack_top[1]] = i - stack_top[1]

                if len(stack) == 0:
                    break

                top_price = stack[-1][0]

        stack.append((price, i))

    while len(stack) > 0:
        stack_top = stack.pop()
        answer[stack_top[1]] = n_prices - 1 - stack_top[1]

    # 최종 복잡도 : O(n)
    return answer