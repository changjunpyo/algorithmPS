class Solution:
    
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        answer = []
        def possible_comb(x:list, start:int):
            if len(x) == k:
                if sum(x) == n:
                    answer.append(x[:])
                return
            
            for i in range(start, 10):
                x.append(i)
                possible_comb(x, i+1)
                x.pop()
        
            
        possible_comb([],1)
            
        return answer
                
        