def solution(n):
    answer = ""
    base_three = 1
    while n//base_three != 0:
        r = (n//base_three)%3
        if  r== 1: answer += "1"
        elif r ==2: answer += "2"
        else : 
            r=3 
            answer += "4"
        n-= r*base_three
        base_three *=3
        
            
    return answer[::-1]
