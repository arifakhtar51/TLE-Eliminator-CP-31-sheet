def count_subarrays(arr, k):
    n = len(arr)
    count = 0

    for i in range(n):
        for j in range(i, n):
            if j - i + 1 >= k:
                count += 1

    return count

# Example usage:
arr = [1, 2, 3, 4]
k = 2
result = count_subarrays(arr, k)
print("Number of subarrays with size greater than or equal to k:", result)
