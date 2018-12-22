A = [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7]
B = [-3, -9, -14, -4, -21, -5, -1, -1, -5, -6, -8]

def find_maximum_crossing_subarray(A, i_begin, i_mid, i_end):
    # leftSum and iLeft each stores the maximum sum of the form (....iMid) and the beginning index of the sum.
    i_left = i_mid
    left_sum = A[i_left]
    # i is the iterating variable and sum stores the sum from index i to iMid.
    i = i_left
    sum = left_sum
    while i > i_begin:
        i -= 1
        sum += A[i]
        if sum > left_sum:
            left_sum = sum
            i_left = i

    i_right = i_mid + 1
    right_sum = A[i_right]
    i = i_right
    sum = right_sum
    while i < i_end:
        i += 1
        sum += A[i]
        if sum > right_sum:
            right_sum = sum
            i_right = i
    return i_left, i_right, left_sum+right_sum

def find_maximum_subarray(A, i_begin, i_end):
    # base step
    if i_begin == i_end:
        return i_begin, i_end, A[i_begin]
    # recursive step
    else:
        i_mid = (i_begin + i_end)//2
        (left_low, left_high, left_sum) = find_maximum_subarray(A, i_begin, i_mid)
        (right_low, right_high, right_sum) = find_maximum_subarray(A, i_mid+1, i_end)
        (cross_low, cross_high, cross_sum) = find_maximum_crossing_subarray(A, i_begin, i_mid, i_end)
        # compare the results.
        if left_sum >= cross_sum and left_sum >= right_sum:
            return left_low, left_high, left_sum
        elif right_sum >= cross_sum and right_sum >= cross_sum:
            return right_low, right_high, right_sum
        else:
            return cross_low, cross_high, cross_sum


(i_from, i_to, arr_sum) = find_maximum_subarray(B, 0, len(B)-1)
print("a maximum nonempty subarray is:")
print(B[i_from:i_to + 1])
print("the sum is:")
print(arr_sum)
