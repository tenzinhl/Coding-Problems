from prepare_the_bunnies_escape_simple_bfs import solution
import time

test_input_1 = [
    [0, 1, 1, 0],
    [0, 0, 0, 1],
    [1, 1, 0, 0],
    [1, 1, 1, 0]
]

test_input_2 = [
    [0, 0, 0, 0, 0, 0],
    [1, 1, 1, 1, 1, 0],
    [0, 0, 0, 0, 0, 0],
    [0, 1, 1, 1, 1, 1],
    [0, 1, 1, 1, 1, 1],
    [0, 0, 0, 0, 0, 0]
]

test_input_3 = [[0 for i in range(20)] for j in range(20)]

test_input_4 = [
    [0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
]

# 13 rows, 13 cols, gets correct answer of 57
test_input_4 = [
    [0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0],
    [0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0],
    [0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0],
    [0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0],
    [0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0],
    [0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0],
    [0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1],
    [0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0],
    [0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0],
    [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0],
]

# 6x6, impass, answer should be -1
test_input_5 = [
    [0, 1, 1, 0, 0, 0,],
    [0, 1, 1, 0, 0, 0,],
    [0, 1, 1, 0, 0, 0,],
    [0, 1, 1, 0, 0, 0,],
    [0, 1, 1, 0, 0, 0,],
    [0, 1, 1, 0, 0, 0,],
]
ans_5 = -1

# 6x6, one wall to break, answer should be 11
test_input_5 = [
    [0, 1, 1, 0, 0, 0,],
    [0, 1, 1, 0, 0, 0,],
    [0, 1, 0, 0, 0, 0,],
    [0, 1, 1, 0, 0, 0,],
    [0, 1, 1, 0, 0, 0,],
    [0, 1, 1, 0, 0, 0,],
]

# 1x1, answer should be 1
test_input_6 = [
    [0]
]

ans_6 = 1

# Basic 2x2, answer should be 3
test_input_7 = [
    [0, 0],
    [0, 0]
]

ans_7 = 3

# Basic 2x2, clear either wall and answer should be 3
test_input_8 = [
    [0, 1],
    [1, 0]
]

ans_8 = 3

# Basic 3x3, tests open areas, answer should be 5
test_input_9 = [
    [0, 0, 0],
    [0, 0, 0],
    [0, 0, 0],
]

ans_9 = 5

# 3x3, no solution so answer should be -1
test_input_10 = [
    [0, 1, 1],
    [0, 1, 1],
    [1, 1, 0],
]
ans_10 = -1

# 3x3, Solution is to clear bottom left, answer should be 5
test_input_11 = [
    [0, 1, 1],
    [0, 1, 1],
    [1, 0, 0],
]
ans_11 = 5

# 3x3, answer is to clear middle, solution should be 5
test_input_12 = [
    [0, 1, 1],
    [0, 1, 0],
    [1, 1, 0],
]
ans_12 = 5

# 3x3, answer is to clear middle (or topright), solution should be 5
test_input_13 = [
    [0, 0, 1],
    [1, 1, 0],
    [1, 1, 0],
]
ans_13 = 5

test_input_14 = [
    [0, 0, 0, 1],
    [1, 0, 1, 1],
    [1, 1, 1, 0],
    [1, 1, 1, 0],
]
ans_14 = -1

# Non square matrices
test_input_15 = [
    [0],
    [0],
    [0],
    [0],
]
ans_15 = 4

test_input_15_5 = [
    [0],
    [0]
]
ans_15_5 = 2

test_input_16 = [
    [0],
    [0],
    [1],
    [0],
]
ans_16 = 4

test_input_17 = [
    [0],
    [1],
    [1],
    [0],
]
ans_17 = -1

test_input_18 = [
    [0, 0]
]
ans_18 = 2

test_input_19 = [
    [0, 0, 0, 0, 0]
]
ans_19 = 5

test_input_20 = [
    [0, 1, 0, 0, 0]
]
ans_20 = 5

test_input_21 = [
    [0, 1, 0, 1, 0]
]
ans_21 = -1

test_input_22 = [
    [0, 1, 0, 1, 0],
    [0, 1, 0, 1, 0],
]
ans_22 = -1

test_input_22 = [
    [0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
    [0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0],
]
ans_22 = 15

# Stress test case
test_input_23 = [
    [0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1],
    [1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1],
    [0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1],
    [0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1],
    [1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1],
    [0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1],
    [1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1],
    [0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1],
    [0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1],
    [0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1],
    [1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1],
    [0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1],
    [0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1],
    [1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1],
    [1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1],
    [0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1],
    [1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1],
    [0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0],
    [0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0]
]

if __name__ == '__main__':
    # print('test input 1: ')
    # ans = solution(test_input_1)
    # print(ans)

    # print('test input 2: ')
    # ans = solution(test_input_2)
    # print(ans)

    # print('test input 3: ')
    # ans = solution(test_input_3)
    # print(ans)

    # print('test input 4: ')
    # print(solution(test_input_4))

    print('test input 5: ')
    print(solution(test_input_5))

    print('Running tests 6 through 22 as assertions...')
    assert solution(test_input_6) == ans_6
    assert solution(test_input_7) == ans_7
    assert solution(test_input_8) == ans_8
    assert solution(test_input_9) == ans_9
    assert solution(test_input_10) == ans_10
    assert solution(test_input_11) == ans_11
    assert solution(test_input_12) == ans_12
    assert solution(test_input_13) == ans_13
    assert solution(test_input_14) == ans_14
    assert solution(test_input_15) == ans_15
    assert solution(test_input_15_5) == ans_15_5
    assert solution(test_input_16) == ans_16
    assert solution(test_input_17) == ans_17
    assert solution(test_input_18) == ans_18
    assert solution(test_input_19) == ans_19
    assert solution(test_input_20) == ans_20
    assert solution(test_input_21) == ans_21
    assert solution(test_input_22) == ans_22

    print('test 23 (Stress Test): ')
    start = time.process_time()
    ans = solution(test_input_23)
    end = time.process_time()
    print(f"ans: {ans}, time taken: {end - start}")
