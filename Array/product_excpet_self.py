class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # ans in certain index = product in the left * product in the right
        size = len(nums)

        ans = [1]
        for i in range(1, size):
            ans.append(ans[i - 1] * nums[i - 1])

        for i in range(size - 2, -1, -1):
            ans.append(ans[i] * nums[i])

        return ans
