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

    # Return true iff a given position is in_bounds
    def in_bounds(x, y, wallbreak):
        return 0 <= x and x < w and 0 <= y and y < h \

    # Returns true iff a move is possible using (or not using) wallbreak
    def wall_check(x, y, wallbreak):
        return
    
    def update_dist(matrix, x, y, val):
        if matrix[y][x] == -1:
            matrix[y][x] = val
        else:
            matrix[y][x] = min(matrix[y][x], val)

    # BFS queue containing tuples representing x,y coordinates and containing a boolean
    # representing whether the wall break has been consumed yet
    q = queue.Queue()
    q.put((0, 0, False))

    while not q.empty():
        (x, y, break_used, dist) = q.get()

        if not in_bounds(x, y):
            continue

        # Distance updating
        if map[y][x] == 0:
            if not break_used:
                update_dist(dist_none, x, y, dist)
            
            update_dist(dist_wb, x, y, dist)
        else:
            if not break_used:
                break_used = True
                update_dist(dist_wb, x, y, dist)



        if map[y][x] == 1:
            assert not visited_none[y][x]
            if break_used or visited_wb[y][x]:
                continue

            visited_wb[y][x] = True

            q.put(x - 1, y, True)
            q.put(x + 1, y, True)
            q.put(x, y - 1, True)
            q.put(x, y + 1, True)
            
        else:


        # The below is not necessarily true.
        if dist_none != -1:
            visited_none[y][x] = True
        elif
        visited_wb[y][x] = True
        

        
        
