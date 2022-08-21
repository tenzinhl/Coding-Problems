import queue


def solution(map):
    h = len(map)
    w = len(map[0])

    def bfs():
        """
        Runs a BFS on the map, returns the minimum length path found from the top left to
        the bottom right
        """
        q = queue.Queue()

        visited = [[False for i in range(w)] for j in range(h)]
        dist = [[-1 for i in range(w)] for j in range(h)]

        dist[0][0] = 1
        q.put((0, 0))

        # Return true iff a given position is in the bounds of the map
        def in_bounds(x, y):
            return 0 <= x and x < w and 0 <= y and y < h

        def update_dist(x, y, val):
            if not in_bounds(x, y):
                return

            if dist[y][x] == -1:
                dist[y][x] = val
            else:
                dist[y][x] = min(dist[y][x], val)

        while not q.empty():
            (x, y) = q.get()

            # print(f"Visiting ({x}, {y})")

            visited[y][x] = True

            assert dist[y][x] > 0

            adjacent_squares = [
                (x, y - 1),
                (x, y + 1),
                (x - 1, y),
                (x + 1, y)
            ]

            for (x_new, y_new) in adjacent_squares:
                if in_bounds(x_new, y_new) and not visited[y_new][x_new] and map[y_new][x_new] == 0:
                    update_dist(x_new, y_new, dist[y][x] + 1)
                    q.put((x_new, y_new))

        return dist[h-1][w-1]

    ans = bfs()

    # Try BFS with each variant of the map that has a single wall removed
    for row in range(h):
        for col in range(w):
            if map[row][col] == 1:
                map[row][col] = 0
                new_ans = bfs()
                map[row][col] = 1

                if new_ans != -1:
                    if ans == -1:
                        ans = new_ans
                    else:
                        ans = min(ans, new_ans)

    return ans
