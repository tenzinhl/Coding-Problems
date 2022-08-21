def solution(map):
    # Yikers, unfortunately this is looking like a bit of a messy
    # backtracking problem, which are never my favorite.
    
    # Removing one wall is always beneficial, but currently I see
    # no clear way of optimizing the selection of the removal
    # besides brute forcing it. This will require running the
    # backtracking up to 400 times which is a little yikers.
    
    # Especially on a map that's 20 x 20, at each step we have
    # potentially 3 choices of direction. Key to making backtracking
    # fast will be to prune paths ASAP.
    movement_directions = ['N', 'S', 'E', 'W']
    
    # Maps direction names to tuples representing the dx and dy
    # of that move
    moves = {
        'N': (0, -1),
        'S': (0, 1),
        'E': (1, 0),
        'W': (-1, 0)
    }
    
    h = len(map)
    w = len(map[0])

    path = [[False for i in range(w)] for j in range(h)]
    
    def legal(x, y):
        """
        Return true if a given x and y pos are in the map bounds
        and unoccupied by a wall or previously taken step
        """
        return 0 <= x and x < w and 0 <= y and y < h \
            and map[y][x] == 0 and not path[y][x]
    
    def prunable(x, y, direction):
        """
        Return true if a move is "redundant" and should be
        pruned. We do this when a move is sub-optimal and could
        have been reached through a better path, or for early
        detection of terminal paths
        
        x and y are for position
        direction is the direction of the step taken to reach
        the current position.
        """
        # Prune paths move adjacent to a previously occupied
        # space, in these cases this move is just a slower method
        # of reaching the position in question. We obviously allow
        # for one adjacent space (being the one we just came from)
        adjacent_count = 0
        if y - 1 >= 0 and path[y - 1][x]:
            adjacent_count += 1
        if y + 1 < h and path[y + 1][x]:
            adjacent_count += 1
        if x - 1 >= 0 and path[y][x - 1]:
            adjacent_count += 1
        if x + 1 < w and path[y][x + 1]:
            adjacent_count += 1
        
        if adjacent_count >= 2:
            return True
        
        # Next prune is for when we are along the edge of the map.
        # If we hit the edge of the map, we must head either East
        # or South, North or West after hitting any of the walls
        # necessarily leads to a dead end. as to hit the wall we've
        # cut the map, and North and West lead to the isolated
        # portion
        if (y == 0 or y == h - 1) and direction == 'W':
            return True
        
        if (x == 0 or x == w - 1) and direction == 'N':
            return True
        
        # Passed all prune checks so return False
        return False
    
    def backtrack(dist, best, x, y):
        """
        Backtracking DFS method
        
        Returns the distance of the shortest path to the end found
        or -1 if no path was found that was better than the best.
        
        dist: number of tiles consumed including the current tile
        best: the best path found so far (-1 means no path found yet)
        x: the current x position
        y: the current y position
        """
        # print(f'Stepping into ({x}, {y})')
        # Base case: if we've reached the target we just return the
        # current distance
        if x == w - 1 and y == h - 1:
            # print(f'Target found in {dist} steps!')
            return dist
        
        # First prune: if a path has been found and shortest path
        # to finish from current position still puts us above best
        # dist, then we can abandon this path
        if best >= 0 and dist + (w - 1 - x) + (h - 1 - y) >= best:
            # print("abandoning because can't beat best path!")
            return best
        
        # Mark
        path[y][x] = True
        
        for direction in movement_directions:
            move = moves[direction]
            x_new = x + move[0]
            y_new = y + move[1]

            # print(f'testing direction {direction}, x_new = {x_new}, y_new = {y_new}')
            
            if legal(x_new, y_new) and not prunable(x_new, y_new, direction):
                # print(f'Trying direction {direction}, x_new = {x_new}, y_new = {y_new}')
                dist_new = backtrack(dist + 1, best, x_new, y_new)
                if dist_new != -1:
                    if best == -1:
                        best = dist_new
                    else:
                        best = min(dist_new, best)

        # Unmark the move
        path[y][x] = False
        return best
    
    # print(f'Height: {h}, Width: {w}')
    # Run the backtracking on different versions of the map with removed walls
    ans = backtrack(1, -1, 0, 0)

    # print(f"First backtrack complete, base answer of {ans}")
    
    for row in range(h):
        for col in range(w):
            if map[row][col] == 1:
                # Clear the wall
                map[row][col] = 0
                new_ans = backtrack(1, ans, 0, 0)
                if new_ans != -1:
                    if ans == -1:
                        ans = new_ans
                    else:
                        ans = min(ans, new_ans)
                # Rebuild the wall
                map[row][col] = 1
    
    return ans
