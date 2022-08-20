"""
DP attempt, that was kind of silly tbh. Doesn't fit cleanly into DP logic
and takes a little too much wrangling.
"""

from heapq import *


def solution(l):
    # Goal here is to choose the largest set of numbers such that their
    # sum is divisible by three (this is the classic "the sum of the 
    # digits of a number that's divisible by three will be divisible by
    # 3" thing you learn in elementary).
    # At the end once we have a set of digits we always want to sort in
    # descending order of digits to get the largest possible number.
    
    # To create a sum of digits that's divisible by three we can think
    # of buckets of numbers. We bucket by their value modulo 3.
    
    # Our priorities are total number of digits first, then largest
    # digits for a given set size.
    
    # To be honest with the input size only having 9 items in the list
    # we could probably also just brute force it.
    
    # Let's try this optimal solution though. Each of the buckets will
    # be a priority queue of digits (with largest values first)
    
    # There's only two buckets we need to track. Digits which are 0
    # in the mod space of 3 are always "free" to take.

    digits_to_use = []
    
    # WARNING: these heaps will contain the negative value of the
    # digits so that the heapq (which is a min heap) sorts "largest"
    # numbers first.
    mod1_pq = []
    mod2_pq = []
    for digit in l:
        mod_value = digit % 3
        if mod_value == 0:
            digits_to_use.append(mod_value)
        elif mod_value == 1:
            heappush(mod1_pq, digit)
        else:
            heappush(mod2_pq, digit)
    
    num_ones = len(mod1_pq)
    num_twos = len(mod2_pq)
    
    # Find the maximum number of digits we can take from
    # both to get a sum equal to 3
    
    # DP array stores maximum number of digits that can be taken for a
    # given number of ones and twos mod 3. Val is the total number of digits
    # that can be consumed (which is what we want to maximize
    
    # YOOO! I think I just found a better method? When you sum all of the ones
    # and twos mod three you'll be left
    dp = [
        [{"val": 0, "ones": 0, "twos": 0} for i in range(num_twos + 1)]
        for j in range(num_ones + 1)
    ]

    for row in range(num_ones):
        for col in range(num_twos):
            # Update the the corresponding squares by taking the elementary
            # steps
            # The "no-op" steps
            curr_node = dp[row][col]
            curr_val = curr_node['val']
            curr_ones = curr_node['ones']
            curr_twos = curr_node['twos']

            update_node(dp[row][col + 1], curr_val, curr_ones, curr_twos)
            update_node(dp[row + 1][col]
            dp[row + 1][col] = max(dp[row + 1][col], dp[row][col])
            
            # Taking three 2s
            if col + 3 < num_twos:
                # It's either max of what it is 
                dp[row][col + 3] = max(dp[row][col + 3], dp[row][col] + 3)


def update_node(node, new_val, new_ones, new_twos):
    if new_val > node['val']:
        node['val'] = new_val
        node['ones'] = new_ones
        node['twos'] = new_twos
        
        
 