def solution(participant, completion):
    ans ={}
    
    for p in participant:
        ans[p] = ans.get(p,0)+1
    for c in completion:
        ans[c] -=1
    for k in ans:
        if ans[k] >0:
            return k
    return -1
