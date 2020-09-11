import collections


def solution(str1, str2):
    str1 = str1.upper()
    str2 = str2.upper()

    str1_list = []
    for i in range(len(str1)-1):
        if str1[i] < 'A' or str1[i] > 'Z':
            continue
        if str1[i+1] >= 'A' and str1[i+1] <= 'Z':
            str1_list.append(str1[i:i+2])
    str2_list = []
    for i in range(len(str2)-1):
        if str2[i] < 'A' or str2[i] > 'Z':
            continue
        if str2[i+1] >= 'A' and str2[i+1] <= 'Z':
            str2_list.append(str2[i:i+2])
    a = collections.Counter(str1_list)
    b = collections.Counter(str2_list)
    u = sum((a | b).values())
    n = sum((a & b).values())
    if u == 0:
        return 65536
    else:
        return int(n/u * 65536)
