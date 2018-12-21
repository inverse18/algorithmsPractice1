

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr)//2
        left = arr[:mid]
        right = arr[mid:]

        merge_sort(left)
        merge_sort(right)

        i = 0
        j = 0
        k = 0
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                arr[k] = left[i]
                i = i+1
            else:
                arr[k] = right[j]
                j = j+1
            k = k+1

        while i < len(left):
            arr[k] = left[i]
            i = i+1
            k = k+1

        while j < len(right):
            arr[k] = right[j]
            j = j+1
            k = k+1


def print_complements(aset, n):
    i = 0; j = len(aset)-1
    while i < j:
        sum = aset[i] + aset[j]
        if sum < n:
            i += 1
        elif sum > n:
            j -= 1
        else:
            print(aset[i], " + ", aset[j], " = ", sum)
            i += 1


setA = [3, 17, 11, 9, 2, 4, 15, 5, 8, 30, 1, 10, 13]
merge_sort(setA)
print_complements(setA,20)

