class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)
        a = [i + 1 for i in range(n)]
        return list(set(a) - set(nums))
                
        
