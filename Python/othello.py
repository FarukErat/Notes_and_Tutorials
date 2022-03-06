# import only system from os
from os import system, name
from random import randrange
from time import sleep

# define our clear function
def clear():
  
    # for windows
    if name == 'nt':
        _ = system('cls')
  
    # for mac and linux(here, os.name is 'posix')
    else:
        _ = system('clear')

# constants
SIZE = 8
DIRS = [(-1, -1), (-1, 0), (-1, +1),
        (0, -1),           (0, +1),
        (+1, -1), (+1, 0), (+1, +1)]
BLACK = 'B'
WHITE = 'W'
EMPTY = '-'
LEGAL = '+'

# for indexing, coordinates are (row, col)
class coor:
    def __init__(self, r=0, c=0) -> None:
        self.row = r
        self.col = c


class Table:
    def __init__(self) -> None:
        # passing the constants to the class
        self.size = SIZE
        self.black = BLACK
        self.white = WHITE
        self.empty = EMPTY
        self.legal = LEGAL

        # black starts the game
        self.turn = self.black
        self.opponent = self.white
        self.userSide = self.black
        self.guidance = True
        self.gameMode = 0

        # create an empty board
        self.board = [[self.empty] * self.size for i in range(self.size)]

        # fill the 4 central initial squares
        self.board[self.size//2 - 1][self.size//2] = self.black
        self.board[self.size//2][self.size//2 - 1] = self.black
        self.board[self.size//2 - 1][self.size//2 - 1] = self.white
        self.board[self.size//2][self.size//2] = self.white

        # mark legal moves
        self.marker()

    # check if the coordinate is on the board
    def isOnBoard(self, c):
        if c.row >= 0 and c.row < self.size and c.col >= 0 and c.col < self.size:
            return True
        else:
            return False

    # check if a move is legal
    def isLegal(self, c):
        # if the coordinate is not on the board, then it is not a legal move
        if not self.isOnBoard(c):
            return False

        # non-empty squares cannot be filled, thus it is not a legal move
        if self.board[c.row][c.col] != self.empty and self.board[c.row][c.col] != self.legal:
            return False

        # for each direction
        curr = coor()
        for dir in DIRS:
            flip = False
            i = 1
            while(True):
                # multiplying by "i" to move along the directions
                curr.row = c.row + dir[0] * i
                curr.col = c.col + dir[1] * i

                # i is increased for the next loop
                i += 1

                #  if the square is not on the board, then it is not a legal move
                if not self.isOnBoard(curr):
                    break

                # if the square is empty, break
                if self.board[curr.row][curr.col] == self.empty or\
                        self.board[curr.row][curr.col] == self.legal:
                    break

                # if the square is not the same as player's, assign flip true, then continue
                if self.board[curr.row][curr.col] == self.opponent:
                    flip = True
                    continue

                # if the square is the current player's and at least one tile is flipped
                # then it is a legal move
                if self.board[curr.row][curr.col] == self.turn:
                    if flip:
                        return True
                    else:
                        break
        return False

    # check one has move left at a certain moment
    def hasTileToFlip(self):
        #  all the squares are checked on the board
        for row in range(self.size):
            for col in range(self.size):
                if self.board[row][col] == self.legal:
                    return True
        return False

    # flips the legal squares for sent coordinates
    def flipTiles(self, c):
        isValid = False
        curr = coor()
        temp = coor()
        for dir in DIRS:
            isFlipped = False
            i = 1
            while(True):
                # multiplying by "i" to move along the directions
                curr.row = c.row + dir[0] * i
                curr.col = c.col + dir[1] * i

                # i is increased for the next loop
                i += 1

                # if the square is not on the board, then it is not a legal move
                if not self.isOnBoard(curr):
                    break

                # if the square is empty, the goal is not achieved
                if self.board[curr.row][curr.col] == self.empty or\
                        self.board[curr.row][curr.col] == self.legal:
                    break

                # isFlipped changes to true if there is a tile to flip
                # when the player's square is found, there must be at least one tile to flip
                if self.board[curr.row][curr.col] == self.opponent:
                    isFlipped = True

                # when a square in the same color as players is found
                if self.board[curr.row][curr.col] == self.turn:
                    # if isFlipped is not true, then it is not a legal move
                    if not isFlipped:
                        break
                    isValid = True
                    # temp.row and temp.col are assigned the number along the legal direction
                    temp.row = c.row + dir[0]
                    temp.col = c.col + dir[1]
                    # assigning the squares, when the direction is horizontal
                    if dir[0] == 0:
                        # assign till c.col
                        while(temp.col != curr.col):
                            self.board[temp.row][temp.col] = self.turn
                            # incrase the number by the delta
                            temp.col += dir[1]
                    # assigning the squares, when the direction is vertical
                    elif dir[1] == 0:
                        # assign till c.row
                        while(temp.row != curr.row):
                            self.board[temp.row][temp.col] = self.turn
                            # incrase the number by the delta
                            temp.row += dir[0]
                    # assigning the squares, when the direction is cross
                    else:
                        # assign till c.row and c.col
                        while temp.row != curr.row and temp.col != curr.col:
                            self.board[temp.row][temp.col] = self.turn
                            # incrase the numbers by the deltas
                            temp.row += dir[0]
                            temp.col += dir[1]
                    break
        if isValid:
            self.board[c.row][c.col] = self.turn
        else:
            print("flipTiles: Illegal move")

    # marks all the legal squares at a certain moment
    def marker(self):
        # unmark all the moves
        for row in range(self.size):
            for col in range(self.size):
                if self.board[row][col] == self.legal:
                    self.board[row][col] = self.empty
        # mark the legal moves
        c = coor()
        for row in range(self.size):
            for col in range(self.size):
                c.row = row
                c.col = col
                if self.isLegal(c):
                    self.board[row][col] = self.legal

    # prints the board with indexes
    def printBoard(self):
        # clear the remaining squares
        clear()
        print(" ", end="")
        for row in range(self.size):
            print(f" {row + 1}", end="")
        print()
        for row in range(self.size):
            print(row + 1, end=" ")
            for col in range(self.size):
                if not self.guidance:
                    if self.board[row][col] == self.legal:
                        print(self.empty, end=" ")
                        continue
                print(self.board[row][col], end=" ")
            print(row + 1)
        print(" ", end="")
        for row in range(self.size):
            print(f" {row + 1}", end="")
        print()

    # offering some game modes to the user
    def settings(self):
        # greeting the users
        print("Welcome to Othello Game\n")
        print("1 for human vs human")
        print("2 for human vs cpu")
        print("3 for cpu vs cpu\n")

        choice = int(input("Choose game mode: ")) - 1
        if choice != 0 and choice != 1 and choice != 2:
            print("Invalid game mode")
            sleep(2)
            exit()
        self.gameMode = choice
        # in case of 1, we let the user choose the side
        if self.gameMode == 1:
            print("Enter 'b' to play BLACK, 'w' to play WHITE")
            side = input("Enter your side: ")
            if side == 'b' or side == 'B':
                self.userSide = BLACK
            elif side == 'w' or side == 'W':
                self.userSide = WHITE
            else:
                print("Invalid side")
                sleep(2)
                exit()
        guid = input("Enter 'y' to play with guidance: ")
        if guid == 'y' or guid == 'Y':
            self.guidance = True
        else:
            self.guidance = False

    # returns a random legal move
    def randomMoves(self):
        moves = []
        for row in range(self.size):
            for col in range(self.size):
                if self.board[row][col] == self.legal:
                    c = coor()
                    c.row = row
                    c.col = col
                    moves.append(c)
        rand = randrange(len(moves))
        return moves[rand]

    # processes randomMoves's return
    def cpuPlays(self):
        c = self.randomMoves()
        row = c.row
        col = c.col
        sleep(0.5)
        print("row: ", row + 1)
        print("col: ", col + 1)
        sleep(0.5)
        return c

    # gets moves from the user
    def userPlays(self):
        c = coor()
        flag = False
        while(True):
            if flag:
                print("Invalid move")
                print("Enter again")
            row, col = input("Enter row and column: ").split()
            # to match array index
            row = int(row) - 1
            col = int(col) - 1
            if self.board[row][col] == self.legal:
                c.row = row
                c.col = col
                return (c)
            flag = True

    # sets the turn
    def setTurn(self, turn):
        if turn == BLACK:
            self.turn = BLACK
            self.opponent = WHITE
        elif turn == WHITE:
            self.turn = WHITE
            self.opponent = BLACK
        else:
            print("Invalid turn")
            exit()

    # switches the turn between the players
    def switchTurn(self):
        if self.turn == self.black:
            self.setTurn(self.white)
        else:
            self.setTurn(self.black)
        # update the legal squares after the switch
        self.marker()

    # the game logic is processed here
    def game(self):
        if (self.size % 2 != 0 or self.size < 2):
            print("The size of the board is not appropriate")
            sleep(2)
            exit()

        if BLACK == WHITE or \
                BLACK == EMPTY or \
                BLACK == LEGAL or \
                WHITE == EMPTY or \
                WHITE == LEGAL or \
                EMPTY == LEGAL:
            print("The colors are not appropriate")
            sleep(2)
            exit()
        self.settings()

        while(True):
            self.printBoard()
            if not self.hasTileToFlip():
                break
            # print the side to indicate which side is playing
            if self.turn == self.black:
                print("Black")
            if self.turn == self.white:
                print("White")
            # if the game mode is human vs human
            if self.gameMode == 0:
                move = self.userPlays()
            # if the game mode is human vs cpu
            elif self.gameMode == 1:
                if self.turn == self.userSide:
                    move = self.userPlays()
                else:
                    move = self.cpuPlays()
            # if the game mode is cpu vs cpu
            elif self.gameMode == 2:
                move = self.cpuPlays()
            # legal tiles are flipped here
            self.flipTiles(move)
            # switching the side when a move is done
            self.switchTurn()
            # in case there is no legal move for the next user the side is switched again
            if not self.hasTileToFlip():
                self.switchTurn()
        # to count how many black and white squares there are
        blacks = 0
        whites = 0
        for row in range(self.size):
            for col in range(self.size):
                if self.board[row][col] == self.black:
                    blacks += 1
                if self.board[row][col] == self.white:
                    whites += 1
        # print the final result
        print("G A M E   O V E R")
        print("Black: ", blacks, "\nWhite: ", whites)

# instantiate the class
t = Table()
# start the game
t.game()
