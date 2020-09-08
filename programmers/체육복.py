def solution(n, lost, reserve):
    answer = 0
    m ={}
    extra = list(set(lost) - set(reserve))
    for idx,i in enumerate(list(set(reserve) - set(lost))):
        m[i] = 1
    for i in extra:
        if m.get(i-1, 0) >0:
            m[i-1] = 0
            answer +=1
        elif m.get(i+1, 0) >0:
            m[i+1] = 0
            answer += 1
        
    return n - len(extra) + answer
