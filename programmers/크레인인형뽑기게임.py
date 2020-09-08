def solution(board, moves):
    answer = 0
    bucket =[-1]
    n = len(board)
    for i in moves:
        for j in range(n):
            if board[j][i-1] != 0:
                bucket.append(board[j][i-1]);
                board[j][i-1] = 0
                if bucket[-1] == bucket[-2]:
                    bucket.pop()
                    bucket.pop()
                    answer+= 2
                break;
            
    return answer
