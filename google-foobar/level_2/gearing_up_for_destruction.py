from fractions import Fraction


def solution(pegs):
    # Key realization 1:
    # All gears move the same number of teeth at the same time,
    # irrespective of radius. That's what it means to be a gear
    # after all. This means that for the angular velocity of the
    # output to be 2:1 relative to the angular velocity of the input
    # all we need is for the ratio of their radiuses to be 2:1.
    
    # Now the question becomes how we determine if there is a pairing
    # of sizes on the input and output that fit this description.
    
    # Here I'm thinking about it in terms of constraints on the
    # gear size.
    # Every gear must be within the radius range of [1, distance
    # to neighbor - 1]. Gears earlier in the chain determine the
    # size of gears later in the chain.
    
    # What is the relationship between gears in the chain? For
    # and pair of adjacent gears g1 and g2, their radiuses r1
    # and r2 must total to exactly the distance between them.
    
    # This means that if I increase r1 by 1, r2 would have to
    # decrease by 1. r2 would then affect r3 (if there was a third
    # gear in this valid chain) and then r3 would need to increase
    # by 1.
    
    # In other words all of the gears at the even positions are
    # tied together while all of the gears at odd positions are.
    
    # So we can start with a guess, then see if it's possible to
    # ...
    
    # Update: after this just tried algebra'ing it a bit on paper
    # came up with a formula for determining the r1 that meets
    # constraints. Some of the above observations tie in, but I don't
    # think I would've found formula without just working this a bit
    # on paper
    
    # The constraints were: for any sequence of peg positions p1,...,pn
    # with gears of corresponding radii r1,...,rn, we know that for
    # all adjacent gears r_k and r_k+1 that r_k + r_k+1 = p_k+1 - p_k
    # (this is just that the gears must touch).
    # Finally we also know based on the above intuition that for the
    # output to have double the angular speed of the first, that
    # r_1 / r_n = 2 must be true.
    
    # From here the approach was we can recursively solve for each
    # radius beyond r1 in terms of r1, plugging in our answer from the
    # previous radii into the next. Eventually we end up with a value
    # that's only in terms of the peg positions (which are constants) and
    # r1.
    
    # We can then plug that into r_1 / r_n = 2 to find the only r_1
    # that would make a connected chain of gears such that the output
    # goes at twice the speed of the input.
    
    # We then have to do a pass to verify that this solution still has
    # each gear have a radius >= 1. If not no solution exists.
    
    # The pattern for the series equal to r_1 (or r_1 times 3 in the even
    # case) ends up being subtracting
    # all odd peg positions (when 1-indexed) and adding all even peg
    # positions.
    
    # Converting to 0-indexed that actually means subtracting evens
    # and adding odds. You multiply the first and last peg positions by
    # 2, everything else by 4
    
    N = len(pegs)
    
    series_sum = -2 * pegs[0]
    if N & 1 == 0:
        # Even case so add the last one
        series_sum += 2 * pegs[N - 1]
    else:
        # Odd case
        series_sum -= 2 * pegs[N - 1]
    
    # Now we do all of the in betweenies
    for i in range(1, N - 1):
        if i & 1 == 0:
            series_sum -= 4 * pegs[i]
        else:
            series_sum += 4 * pegs[i]
    
    # In the even case we divide the final sum by 3
    if N & 1 == 0:
        r_1 = Fraction(series_sum, 3)
    else:
        r_1 = Fraction(series_sum, 1)
    
    # Verify that solution works
    if r_1 < 1:
        return [-1, -1]
    else:
        prev_r = r_1
        for i in range(1, N - 1):
            r_i = Fraction(pegs[i] - pegs[i - 1]) - prev_r
            if r_i < 1:
                return [-1, -1]
            prev_r = r_i
    
    # At this point we've verified it works! So return r_1
    return [r_1.numerator, r_1.denominator]
