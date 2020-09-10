def solution(N, stages):
    people_in_stage = [0]*(N+1)
    for i in stages:
        people_in_stage[i-1] += 1
    people_pass_stage = [0]*(N+1)

    people_pass_stage[N] = people_in_stage[-1]
    for i in range(N-1, -1, -1):
        people_pass_stage[i] = people_pass_stage[i+1] + people_in_stage[i]

    answer = []
    for idx, val in enumerate(zip(people_pass_stage[:-1], people_in_stage[:-1])):
        if val[0] == 0:
            answer.append((idx, 0))
        else:
            answer.append((idx, val[1]/val[0]))

    answer.sort(key=lambda element: element[1], reverse=True)
    return [i[0] for i in answer]
