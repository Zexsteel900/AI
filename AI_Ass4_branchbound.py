class NQueens:
    def __init__(self, n):
        self.n = n
        self.solutions = []
        self.columns = [0] * n
        self.diag1 = [0] * (2 * n - 1)
        self.diag2 = [0] * (2 * n - 1)
        self.board = [['.'] * n for _ in range(n)]

    def is_safe(self, row, col):
        return not self.columns[col] and not self.diag1[row + col] and not self.diag2[row - col + self.n - 1]

    def place_queen(self, row, col):
        self.board[row][col] = 'Q'
        self.columns[col] = 1
        self.diag1[row + col] = 1
        self.diag2[row - col + self.n - 1] = 1

    def remove_queen(self, row, col):
        self.board[row][col] = '.'
        self.columns[col] = 0
        self.diag1[row + col] = 0
        self.diag2[row - col + self.n - 1] = 0

    def solve_n_queens(self, row=0):
        if row == self.n:
            solution = []
            for r in range(self.n):
                solution.append(''.join(self.board[r]))
            self.solutions.append(solution)
            return

        for col in range(self.n):
            if self.is_safe(row, col):
                self.place_queen(row, col)
                self.solve_n_queens(row + 1)
                self.remove_queen(row, col)

    def print_solutions(self):
        if not self.solutions:
            print("No solutions found.")
        else:
            print("Total", len(self.solutions), "solutions found.")
            for i, solution in enumerate(self.solutions):
                print("Solution", i + 1, ":")
                for row in solution:
                    print(row)
                print()


def main():
    n = int(input("Enter the value of N for N-Queens problem: "))
    n_queens = NQueens(n)
    n_queens.solve_n_queens()
    n_queens.print_solutions()


if __name__ == "__main__":
    main()
