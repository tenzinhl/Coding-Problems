def solution(s):
    """
    Given that string is only 200 long we can basically brute force this.
    We check every factor of 200 and try to find a repeating sequence of that length
    We search from smallest sequence length to highest, returning as soon as we find
    a valid one.

    The sequence of length len(s) will always work for obvious reasons. Sad minions :(
    
    An "edge case" to be cautious of: the cake is a full circle. So we have to be conscious
    of the wrapping of the list. Treating it as circular.
    """
    N = len(s)
    for slice_size in range(1, N):
        # Determine if the slice size would evenly divide cake, if not we can skip
        if N % slice_size == 0:
            # For a given slice size we only need to try N / slice_size starting points
            # As if a solution exists the slices are of size slice_size and repeat, so
            # searching a contiguous region of size slice_size we must come across the
            # correct start point
            for start in range(0, slice_size):
                # Determine the slice sequence based on first sample
                slice_sequence = s[start : start + slice_size]

                seq_idx = 0

                slice_works = True
                for i in range(0, N):
                    if s[(start + i) % N] != slice_sequence[i % slice_size]:
                        slice_works = False
                        break

                if slice_works:
                    return N / slice_size

    # If we weren't able to find a better factor we know worst case we can have
    # 1 slice
    return 1
