# Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
# A region is captured by flipping all 'O's into 'X's in that surrounded region.

# For example,
# X X X X
# X O O X
# X X O X
# X O X X

# After running your function, the board should be:
# X X X X
# X X X X
# X X X X
# X O X X


class Solution:
    # @param board, a 9x9 2D array
    # Capture all regions by modifying the input board in-place.
    # Do not return any value.
    def solve(self, board):
        if not board:
            return
        
        row_num = len(board)
        col_num = len(board[0])
        # step 1:
        # every 'O' at the eadge of the board indicate a region no be surrounded
        # mark the region with 'M'
        for i in sets.Set([0, row_num-1]):
            for j in xrange(col_num):
                if board[i][j] == 'O':
                    Solution.paint_region(self, 'M', i, j, row_num, col_num, board)
        for i in xrange(1, row_num):
            for j in sets.Set([0, col_num-1]):
                if board[i][j] == 'O':
                    Solution.paint_region(self, 'M', i, j, row_num, col_num, board)
        
        # after the step 1, all cell with 'O' is surrounded
        for i in xrange(row_num):
            for j in xrange(col_num):
                if board[i][j] == 'M':
                    board[i][j] = 'O'
                elif board[i][j] == 'O':
                    board[i][j] = 'X'
                elif board[i][j] == 'X':
                    continue


    def paint_region(self, ch, x, y, row_num, col_num, board):
        queue = collections.deque([])
        queue.append((x,y))
        board[x][y] = ch
        while(len(queue)):
            i, j = queue.popleft()
            if i-1 >= 0 and board[i-1][j] == 'O':
                queue.append((i-1,j))
                board[i-1][j] = ch
            if i+1<row_num and board[i+1][j] == 'O':
                queue.append((i+1,j))
                board[i+1][j] = ch
            if j-1>=0 and board[i][j-1] == 'O':
                queue.append((i,j-1))
                board[i][j-1] = ch
            if j+1<col_num and board[i][j+1] == 'O':
                queue.append((i,j+1))
                board[i][j+1] = ch             
