n, k= map(int, input().split())
nums = list(map(int, input().split()))

def findk(nums, k):
    left = 0
    right = len(nums)
    mid = (left + right) // 2
    while left < right:
        while nums[right] > nums[mid]:
            right -= 1
        while nums[left] < nums[mid]:
            left += 1
        if left <= right:
            t = nums[left]
            nums[left] = nums[right]
            nums[right] = t
    if k < = left: