def find_v(p):
    count = {"(": 0, ")": 0}
    for idx, val in enumerate(p):
        count[val] += 1
        if count["("] == count[")"]:
            return idx+1
    return 0


def check_right(p):
    count = 0
    for i in p:
        if i == "(":
            count += 1
        elif i == ")":
            count -= 1
            if count < 0:
                return False
    return False if count > 0 else True


def change_to_right_parentheses(p):
    v_idx = find_v(p)
    if v_idx == 0:
        return ""
    u = p[:v_idx]
    v = p[v_idx:]
    if check_right(u):
        return u + change_to_right_parentheses(v)
    else:
        change_u = "".join(["(" if i == ")" else ")" for i in v[1:-1]])
        print(change_u)
        return "(" + change_to_right_parentheses(v) + ")" + change_u


def solution(p):
    return change_to_right_parentheses(p)
