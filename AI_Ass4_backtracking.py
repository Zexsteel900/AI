def is_safe(board, row, col, n):
    # Check if there is a queen in the same column
    for i in range(row):
        if board[i][col] == 1:
            return False
    
    # Check upper diagonal on left side
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    
    # Check upper diagonal on right side
    for i, j in zip(range(row, -1, -1), range(col, n)):
        if board[i][j] == 1:
            return False
    
    return True

def solve_n_queens_util(board, row, n, solutions):
    if row == n:
        # If all queens are placed successfully, add solution to list
        solutions.append([row[:] for row in board])
        return
    
    for col in range(n):
        if is_safe(board, row, col, n):
            # Place queen if it's safe
            board[row][col] = 1
            
            # Recur to place rest of the queens
            solve_n_queens_util(board, row + 1, n, solutions)
            
            # Backtrack if placement doesn't lead to a solution
            board[row][col] = 0

def solve_n_queens(n):
    # Create an empty board
    board = [[0] * n for _ in range(n)]
    solutions = []
    solve_n_queens_util(board, 0, n, solutions)
    return solutions

def print_board(board):
    for row in board:
        print(" ".join(map(str, row)))
    print()

def main():
    n = int(input("Enter the number of queens (n): "))
    solutions = solve_n_queens(n)
    print(f"Total solutions for {n}-Queens problem: {len(solutions)}\n")
    for i, solution in enumerate(solutions, 1):
        print(f"Solution {i}:")
        print_board(solution)

if __name__ == "__main__":
    main()
