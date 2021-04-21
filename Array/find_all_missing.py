class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # count from 1 to n
        # each iteration find n exist ?
        # if not exist push back to list
        n = len(nums)
        nums_set = set(nums)
        ans = []
        for i in range(1, n+1):
            if i not in nums_set:
                ans.append(i)

        return ans
