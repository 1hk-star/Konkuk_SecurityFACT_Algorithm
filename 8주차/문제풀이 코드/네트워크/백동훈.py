def dfs(graphs, visited, start):
    stack = []
    stack.append(start)
    visited[start] = True

    while stack:
        cur_vtx = stack.pop()

        for n in graphs[cur_vtx]:
            if not visited[n]:
                visited[n] = True
                stack.append(n)

    return visited

def solution(n, computers):
    answer = 0

    visited = [False] * n

    computers

    graphs = {}
    for i in range(len(computers)):
        graphs[i] = [j for j in range(len(computers[i])) if computers[i][j] == 1 and i != j]

    while True:
        for i in range(len(visited)):
            if not visited[i]:
                start = i
                break

        visited = dfs(graphs, visited, start)

        answer += 1

        if sum(visited) == n:
            break

    return answer