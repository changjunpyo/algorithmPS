def solution(s):
    answer = len(s)
    for i in range(1, int(len(s)/2) + 1):
        ret, count = 0, 1

        for idx in range(i, len(s), i):
            if (idx + i > len(s)):
                ret += len(s[idx:])
                break
            if s[idx-i:idx] == s[idx: idx+i]:
                count += 1
            else:
                if count > 1:
                    ret += len(s[idx-i:idx]) + len(str(count))
                else:
                    ret += len(s[idx-i:idx])
                count = 1
        if count > 1:
            ret += i + len(str(count))
        else:
            ret += i

        answer = min(answer, ret)
    return answer
