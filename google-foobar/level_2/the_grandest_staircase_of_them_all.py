def solution(n):
    # Classic DP problem. For a given x coordinate you have an array mapping
    # how many ways to make a staircase of height k...
    # Wait one of the variables we still need to track here is the number
    # of bricks left. Is it like a 3 dimensional array?
    
    # Ah.. all steps must be descending! That's good to know lol.
    # Is it better to think from highest step to lowest?
    
    # Oop, working on paper seems to be the way again. Reworking it it seems
    # what I want is a table of bricks_used by height of highest step, where
    # the value of a given cell represents the number of staircases that match
    # that criteria
    
    # (Just use array with bounds of 300 to not have to worry about being
    # careful with the limits)
    # Row represents height of highest step, column represents number of
    # bricks in the staircase
    dp = [[0 for i in range(300)] for j in range(300)]
    
    # For our base cases the "last" (or first depending on how you look at it) step
    # in the staircase can be any height. At the end we don't need to remember to
    # subtract this from the count as we just don't include the stair using n bricks
    # that's at max height n (since we know it could only have one step)
    for i in range(1, n + 1):
        dp[i][i] = 1

    for max_height in range(1, n + 1):
        for bricks_used in range(1, n + 1):
            num_staircases = dp[max_height][bricks_used]
            # Build the next step of height > max_height
            bricks_left = n - bricks_used
            
            # Use k bricks to build the next step, where
            # k >= max_height + 1 and <= bricks_left
            for k in range(max_height + 1, bricks_left + 1):
                dp[k][bricks_used + k] += num_staircases
    
    # Print the DP table for debugging
    # for row in range(1, n + 1):
    #     print(dp[row][0:n+1])

    ans = 0
    # Sum all of the counts of staircases that use n bricks
    # (we don't need to include height n as that would be the single
    # step case which the problem wants us to exclude)
    for height in range(2, n):
        ans += dp[height][n]

    return ans
