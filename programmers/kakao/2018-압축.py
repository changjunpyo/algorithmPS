def solution(msg):
    c = {}
    answer = []
    count = 1
    for i in range(26):
        c[chr(ord('A') + i)] = count
        count += 1
    i = 0
    while i < len(msg):
        s = ""
        for j in range(len(msg) - i):
            s += msg[i+j]
            if c.get(s, -1) == -1:
                answer.append(c[s[:-1]])
                c[s] = count
                count += 1
                i += j
                break
            elif i+j+1 == len(msg):
                answer.append(c[s])
                i = len(msg)
    return answer
