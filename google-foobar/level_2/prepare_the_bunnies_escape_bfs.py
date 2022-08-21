"""
Second attempt of the "prepare the bunnies escape" problem

Using BFS instead of DFS Backtracking. I have no idea why I was
thinking backtracking :(
"""
import queue


def solution(map):
    # It's BFS but where we have a second attribute containing the number
    # of wall breaks we have left.
    h = len(map)
    w = len(map[0])

    # Whether node was visited without wall break
    visited_none = [[False for i in range(w)] for j in range(h)]
    # Whether node was visited using wall break
    visited_wb = [[False for i in range(w)] for j in range(h)]

    # Stores the minimum path length for a node from the starting point without
    # consuming a wall break. -1 represents node not found
    dist_none = [[-1 for i in range(w)] for j in range(h)]
    # Stores the minimum path length for a node from the starting point having consumed
    # a wall break. A wall break can be consumed in a "no-op" (i.e.: if using wall break
    # isn't any faster it'll just equal dist_none). -1 represents node not found.
    dist_wb = [[1 for i in range(w)] for j in range(h)]

    # Return true iff a given position is in the bounds of the map
    def in_bounds(x, y):
        return 0 <= x and x < w and 0 <= y and y < h
    
    def update_dist(matrix, x, y, val):
        if not in_bounds(x, y):
            return

        if matrix[y][x] == -1:
            matrix[y][x] = val
        else:
            matrix[y][x] = min(matrix[y][x], val)

        while not q.empty()
    # Doing a first BFS without wall break to find seeds for second BFS. Second BFS then
    # uses walls as starting points.
    q_none = queue.Queue()     
    q_wb = queue.Queue()

    q_none.put((0, 0))

    # What is the invariant on the queue? Let's say anything can be pushed onto the queue
    while not q_none.empty():
        (x, y) = q_none.get()

        if visited_none[y][x] or not in_bounds(x, y):
            continue

        if map[y][x] == 1:
            visited_wb[y][x] = True
            q_none.push
