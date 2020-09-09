def solution(board):
    answer = 0
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == 0: continue
            if i >0 and j >0:
                board[i][j] = max(1, 1+min(board[i][j-1], min(board[i-1][j], board[i-1][j-1])))
            answer = max(answer, board[i][j])
            
    return answer*answer
