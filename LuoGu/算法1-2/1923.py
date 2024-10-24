'''
n, k= map(int, input().split())
nums = list(map(int, input().split()))

def findk(nums, left, right, k):
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
    if k <= left:
        findk(nums, 0, left, k)
    elif k > right:
        findk(nums, right, len(nums) - 1, k)
    else:
        return right
findk(nums,0, len(nums) - 1, k)
'''
'''
n, k= map(int, input().split())
nums = list(map(int, input().split()))

nums.sort()

print(nums[k])
'''