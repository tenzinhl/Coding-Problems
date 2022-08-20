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
            digits_to_use.append(digit)
        elif mod_value == 1:
            heappush(mod1_pq, -digit)
        else:
            heappush(mod2_pq, -digit)

    print(mod1_pq)
    print(mod2_pq)
    
    num_ones = len(mod1_pq)
    num_twos = len(mod2_pq)
    
    # Find the maximum number of digits we can take from
    # both to get a sum equal to 3
    
    # DP array stores maximum number of digits that can be taken for a
    # given number of ones and twos mod 3. Val is the total number of digits
    # that can be consumed (which is what we want to maximize
    
    # YOOO! I think I just found a better method? When you sum all of the ones
    # and twos mod three you'll be left with some value mod 3 that you can
    # subtract from to get 0. At 2 the optimal thing to do is remove one 2,
    # but you can remove 2 1's if no 2's are available. At 1 it's best to remove
    # one 1, but you can remove two 2's if no other options are present!
    remainder = (num_ones * 1 + num_twos * 2) % 3

    ones_to_take = num_ones
    twos_to_take = num_twos

    if remainder == 1:
        if num_ones >= 1:
            ones_to_take -= 1
        elif num_twos >= 2:
            twos_to_take -= 2
        else:
            num_ones = 0
            num_twos = 0
    elif remainder == 2:
        if num_twos >= 1:
            twos_to_take -= 1
        elif num_ones >= 2:
            ones_to_take -= 2
        else:
            ones_to_take = 0
            twos_to_take = 0
    
    for i in range(ones_to_take):
        digit = -1 * heappop(mod1_pq)
        digits_to_use.append(digit)
    
    for i in range(twos_to_take):
        digit = -1 * heappop(mod2_pq)
        digits_to_use.append(digit)
    
    digits_to_use.sort(reverse=True)

    answer = 0
    for digit in digits_to_use:
        answer *= 10
        answer += digit
    
    return answer
