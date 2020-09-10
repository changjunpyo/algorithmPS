
def solution(n, arr1, arr2):
    answer = []
    for i in range(n):
        gold = "{0:b}".format(arr1[i] | arr2[i]).zfill(n)
        gold = gold.replace("1", "#")
        gold = gold.replace("0", " ")
        answer.append(gold)

    return answer
