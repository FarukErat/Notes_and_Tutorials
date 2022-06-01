from reversi import Ui_MainWindow
from menu import Ui_Menu
from gameover import Ui_GameOver
import sys
from PyQt5.QtWidgets import QMainWindow, QApplication
from PyQt5 import QtGui, QtCore
import res

from os import system, name
from random import randrange

# define our clear function


def clear():

    # for windows
    if name == 'nt':
        _ = system('cls')

    # for mac and linux(here, os.name is 'posix')
    else:
        _ = system('clear')


# for indexing, coordinates are (row, col)
class coor:
    def __init__(self, r=0, c=0) -> None:
        self.row = r
        self.col = c


class GameOver(QMainWindow):
    def __init__(self, pos, black=0, white=0) -> None:
        super(GameOver, self).__init__()
        self.ui = Ui_GameOver()
        self.ui.setupUi(self)
        self.setFixedSize(self.width(), self.height())
        self.move(pos)
        self.ui.pushButton_screen.setGeometry(
            QtCore.QRect(0, 0, self.width(), self.height()))
        self.ui.pushButton_screen.clicked.connect(lambda: self.close())
        self.ui.label_black_score.setText(str(black))
        self.ui.label_white_score.setText(str(white))
        if black > white:
            self.ui.label_winner.setText("Black Wins!")
        elif black < white:
            self.ui.label_winner.setText("White Wins!")
        else:
            self.ui.label_winner.setText("It's a tie!")


class Menu(QMainWindow):
    def __init__(self, table) -> None:
        super(Menu, self).__init__()
        self.ui = Ui_Menu()
        self.ui.setupUi(self)
        self.setFixedSize(self.width(), self.height())
        self.table = Table()

        self.ui.radioButton_H_VS_H.clicked.connect(
            lambda: table.setGameMode(0))
        self.ui.radioButton_H_VS_P.clicked.connect(
            lambda: table.setGameMode(1))
        self.ui.radioButton_P_VS_P.clicked.connect(
            lambda: table.setGameMode(2))
        self.ui.radioButton_black.clicked.connect(
            lambda: table.setHumanSide(self.table.BLACK))
        self.ui.radioButton_white.clicked.connect(
            lambda: table.setHumanSide(self.table.WHITE))
        self.ui.radioButton_guidance_yes.clicked.connect(
            lambda: table.setGuidance(True))
        self.ui.radioButton_guidance_no.clicked.connect(
            lambda: table.setGuidance(False))
        self.ui.pushButton_START.clicked.connect(lambda: self.startGame(table))

    def startGame(self, table):
        self.close()
        table.updateBtns()
        table.move(self.pos())
        table.show()
        table.clickToCoor()


class Table(QMainWindow):
    def __init__(self) -> None:
        super(Table, self).__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.setFixedSize(self.width(), self.height())

        # passing the constants to the class
        self.SIZE = 8
        self.EMPTY = '-'
        self.BLACK = 'B'
        self.WHITE = 'W'
        self.LEGAL = '+'
        self.DIRS = [(-1, -1), (-1, 0), (-1, +1),
                     (0, -1),           (0, +1),
                     (+1, -1), (+1, 0), (+1, +1)]

        # black starts the game
        self.turn = self.BLACK
        self.opponent = self.WHITE
        self.humanSide = self.BLACK
        self.guidance = False
        self.gameMode = 1
        self.delayGuard = True

        # create an empty board
        self.board = [[self.EMPTY] * self.SIZE for i in range(self.SIZE)]

        # fill the 4 central initial squares
        self.setBoard(self.SIZE//2 - 1, self.SIZE//2, self.BLACK)
        self.setBoard(self.SIZE//2, self.SIZE//2 - 1, self.BLACK)
        self.setBoard(self.SIZE//2 - 1, self.SIZE//2 - 1, self.WHITE)
        self.setBoard(self.SIZE//2, self.SIZE//2, self.WHITE)

        # mark legal moves
        self.marker()
        ##############################################################

        # buttons
        self.buttons = [[0] * self.SIZE for i in range(self.SIZE)]
        self.buttons[0][0] = self.ui.pushButton
        self.buttons[0][1] = self.ui.pushButton_2
        self.buttons[0][2] = self.ui.pushButton_3
        self.buttons[0][3] = self.ui.pushButton_4
        self.buttons[0][4] = self.ui.pushButton_5
        self.buttons[0][5] = self.ui.pushButton_6
        self.buttons[0][6] = self.ui.pushButton_7
        self.buttons[0][7] = self.ui.pushButton_8
        self.buttons[1][0] = self.ui.pushButton_9
        self.buttons[1][1] = self.ui.pushButton_10
        self.buttons[1][2] = self.ui.pushButton_11
        self.buttons[1][3] = self.ui.pushButton_12
        self.buttons[1][4] = self.ui.pushButton_13
        self.buttons[1][5] = self.ui.pushButton_14
        self.buttons[1][6] = self.ui.pushButton_15
        self.buttons[1][7] = self.ui.pushButton_16
        self.buttons[2][0] = self.ui.pushButton_17
        self.buttons[2][1] = self.ui.pushButton_18
        self.buttons[2][2] = self.ui.pushButton_19
        self.buttons[2][3] = self.ui.pushButton_20
        self.buttons[2][4] = self.ui.pushButton_21
        self.buttons[2][5] = self.ui.pushButton_22
        self.buttons[2][6] = self.ui.pushButton_23
        self.buttons[2][7] = self.ui.pushButton_24
        self.buttons[3][0] = self.ui.pushButton_25
        self.buttons[3][1] = self.ui.pushButton_26
        self.buttons[3][2] = self.ui.pushButton_27
        self.buttons[3][3] = self.ui.pushButton_28
        self.buttons[3][4] = self.ui.pushButton_29
        self.buttons[3][5] = self.ui.pushButton_30
        self.buttons[3][6] = self.ui.pushButton_31
        self.buttons[3][7] = self.ui.pushButton_32
        self.buttons[4][0] = self.ui.pushButton_33
        self.buttons[4][1] = self.ui.pushButton_34
        self.buttons[4][2] = self.ui.pushButton_35
        self.buttons[4][3] = self.ui.pushButton_36
        self.buttons[4][4] = self.ui.pushButton_37
        self.buttons[4][5] = self.ui.pushButton_38
        self.buttons[4][6] = self.ui.pushButton_39
        self.buttons[4][7] = self.ui.pushButton_40
        self.buttons[5][0] = self.ui.pushButton_41
        self.buttons[5][1] = self.ui.pushButton_42
        self.buttons[5][2] = self.ui.pushButton_43
        self.buttons[5][3] = self.ui.pushButton_44
        self.buttons[5][4] = self.ui.pushButton_45
        self.buttons[5][5] = self.ui.pushButton_46
        self.buttons[5][6] = self.ui.pushButton_47
        self.buttons[5][7] = self.ui.pushButton_48
        self.buttons[6][0] = self.ui.pushButton_49
        self.buttons[6][1] = self.ui.pushButton_50
        self.buttons[6][2] = self.ui.pushButton_51
        self.buttons[6][3] = self.ui.pushButton_52
        self.buttons[6][4] = self.ui.pushButton_53
        self.buttons[6][5] = self.ui.pushButton_54
        self.buttons[6][6] = self.ui.pushButton_55
        self.buttons[6][7] = self.ui.pushButton_56
        self.buttons[7][0] = self.ui.pushButton_57
        self.buttons[7][1] = self.ui.pushButton_58
        self.buttons[7][2] = self.ui.pushButton_59
        self.buttons[7][3] = self.ui.pushButton_60
        self.buttons[7][4] = self.ui.pushButton_61
        self.buttons[7][5] = self.ui.pushButton_62
        self.buttons[7][6] = self.ui.pushButton_63
        self.buttons[7][7] = self.ui.pushButton_64

        # labels
        self.labels = [[0] * self.SIZE for i in range(self.SIZE)]
        self.labels[0][0] = self.ui.label
        self.labels[0][1] = self.ui.label_2
        self.labels[0][2] = self.ui.label_3
        self.labels[0][3] = self.ui.label_4
        self.labels[0][4] = self.ui.label_5
        self.labels[0][5] = self.ui.label_6
        self.labels[0][6] = self.ui.label_7
        self.labels[0][7] = self.ui.label_8
        self.labels[1][0] = self.ui.label_9
        self.labels[1][1] = self.ui.label_10
        self.labels[1][2] = self.ui.label_11
        self.labels[1][3] = self.ui.label_12
        self.labels[1][4] = self.ui.label_13
        self.labels[1][5] = self.ui.label_14
        self.labels[1][6] = self.ui.label_15
        self.labels[1][7] = self.ui.label_16
        self.labels[2][0] = self.ui.label_17
        self.labels[2][1] = self.ui.label_18
        self.labels[2][2] = self.ui.label_19
        self.labels[2][3] = self.ui.label_20
        self.labels[2][4] = self.ui.label_21
        self.labels[2][5] = self.ui.label_22
        self.labels[2][6] = self.ui.label_23
        self.labels[2][7] = self.ui.label_24
        self.labels[3][0] = self.ui.label_25
        self.labels[3][1] = self.ui.label_26
        self.labels[3][2] = self.ui.label_27
        self.labels[3][3] = self.ui.label_28
        self.labels[3][4] = self.ui.label_29
        self.labels[3][5] = self.ui.label_30
        self.labels[3][6] = self.ui.label_31
        self.labels[3][7] = self.ui.label_32
        self.labels[4][0] = self.ui.label_33
        self.labels[4][1] = self.ui.label_34
        self.labels[4][2] = self.ui.label_35
        self.labels[4][3] = self.ui.label_36
        self.labels[4][4] = self.ui.label_37
        self.labels[4][5] = self.ui.label_38
        self.labels[4][6] = self.ui.label_39
        self.labels[4][7] = self.ui.label_40
        self.labels[5][0] = self.ui.label_41
        self.labels[5][1] = self.ui.label_42
        self.labels[5][2] = self.ui.label_43
        self.labels[5][3] = self.ui.label_44
        self.labels[5][4] = self.ui.label_45
        self.labels[5][5] = self.ui.label_46
        self.labels[5][6] = self.ui.label_47
        self.labels[5][7] = self.ui.label_48
        self.labels[6][0] = self.ui.label_49
        self.labels[6][1] = self.ui.label_50
        self.labels[6][2] = self.ui.label_51
        self.labels[6][3] = self.ui.label_52
        self.labels[6][4] = self.ui.label_53
        self.labels[6][5] = self.ui.label_54
        self.labels[6][6] = self.ui.label_55
        self.labels[6][7] = self.ui.label_56
        self.labels[7][0] = self.ui.label_57
        self.labels[7][1] = self.ui.label_58
        self.labels[7][2] = self.ui.label_59
        self.labels[7][3] = self.ui.label_60
        self.labels[7][4] = self.ui.label_61
        self.labels[7][5] = self.ui.label_62
        self.labels[7][6] = self.ui.label_63
        self.labels[7][7] = self.ui.label_64

        # update labels
        self.updateBtns()

        # to send the the button clicked to clickToCoor func
        # buttons are connected
        for row in range(self.SIZE):
            for col in range(self.SIZE):
                self.buttons[row][col].clicked.connect(self.clickToCoor)

    def clickToCoor(self):
        # prevent the user from clicking when it is not user's turn
        if not self.delayGuard:
            return

        if self.gameMode == 0:
            self.humanPlays()

        # only two possible situations:
        # 1. game mode is 1 and it is human's turn (turn is indicated by delayGuard here)
        # if delayGuard is True, it means the cpu is not playing, so the human can play
        # and human clicks a button
        # and the turn is changed to cpu's
        # 2. game mode is 0 and human plays continuously
        # if game mode is 1, and the turn is not human's, cpu will play
        # this is to call the cpuPlays function
        elif self.gameMode == 1:
            if self.turn == self.humanSide:
                self.humanPlays()
            else:
                self.cpuPlays()

        # if game mode is 2, cpu will play recursively
        elif self.gameMode == 2:
            while self.hasTileToFlip():
                self.cpuPlays()

    def humanPlays(self):
        target = self.sender()
        c = coor()
        for row in range(self.SIZE):
            for col in range(self.SIZE):
                if self.buttons[row][col] == target:
                    c.row = row
                    c.col = col
                    # if the move is legal, process the move
                    self.process(c)
                    # then, if it is not user's turn, cpu will play
                    if self.gameMode == 1 and self.turn != self.humanSide:
                        self.cpuPlays()
                    return

    # processes randomMoves's return
    def cpuPlays(self):
        self.delayGuard = False
        self.delayer(1000)
        self.delayGuard = True
        self.process(self.randomMoves())
        # after playing if human does not have move to play, cpu will play again
        if self.turn != self.humanSide:
            self.cpuPlays()

    def process(self, c):
        # if move is legal, flip the tiles
        if self.board[c.row][c.col] == self.LEGAL:
            self.flipTiles(c)
            # switch turn
            self.switchTurn()
            # update buttons before game is over
            self.updateBtns()
            # if the user does not have tile to flip, switch turn
            if not self.hasTileToFlip():
                self.switchTurn()
                # update buttons before game is over
                self.updateBtns()
            # if, there is no legal move, game is over
            if not self.hasTileToFlip():
                self.delayGuard = False
                self.delayer(1000)
                self.endOfGame()

    def endOfGame(self):
        black = 0
        white = 0
        for row in range(self.SIZE):
            for col in range(self.SIZE):
                if self.board[row][col] == self.BLACK:
                    black += 1
                elif self.board[row][col] == self.WHITE:
                    white += 1

        gameover = GameOver(self.pos(), black, white)
        self.close()
        gameover.show()
        self.delayer(5000)
        exit()

    def updateBtns(self):
        for row in range(self.SIZE):
            for col in range(self.SIZE):
                if self.board[row][col] == self.BLACK:
                    self.labels[row][col].setPixmap(
                        QtGui.QPixmap(":/buttons/black"))
                elif self.board[row][col] == self.WHITE:
                    self.labels[row][col].setPixmap(
                        QtGui.QPixmap(":/buttons/white"))
                elif self.board[row][col] == self.EMPTY:
                    self.labels[row][col].setPixmap(
                        QtGui.QPixmap(":/buttons/empty"))
                elif self.board[row][col] == self.LEGAL:
                    if self.guidance:
                        if self.turn == self.BLACK:
                            self.labels[row][col].setPixmap(
                                QtGui.QPixmap(":/buttons/legal_black"))
                        else:
                            self.labels[row][col].setPixmap(
                                QtGui.QPixmap(":/buttons/legal_white"))
                    else:
                        self.labels[row][col].setPixmap(
                            QtGui.QPixmap(":/buttons/empty"))

    ###########################################################################

    # check if the coordinate is on the board
    def isOnBoard(self, c):
        if c.row >= 0 and c.row < self.SIZE and c.col >= 0 and c.col < self.SIZE:
            return True
        else:
            return False

    # check if a move is legal
    def isLegal(self, c):
        # if the coordinate is not on the board, then it is not a legal move
        if not self.isOnBoard(c):
            return False

        # non-empty squares cannot be filled, thus it is not a legal move
        if self.board[c.row][c.col] != self.EMPTY and self.board[c.row][c.col] != self.LEGAL:
            return False

        # for each direction
        curr = coor()
        for dir in self.DIRS:
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
                if self.board[curr.row][curr.col] == self.EMPTY or\
                        self.board[curr.row][curr.col] == self.LEGAL:
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
        for row in range(self.SIZE):
            for col in range(self.SIZE):
                if self.board[row][col] == self.LEGAL:
                    return True
        return False

    def setBoard(self, row, col, val):
        c = coor()
        c.row = row
        c.col = col
        if self.isOnBoard(c) and val == self.BLACK or val == self.WHITE or \
                val == self.EMPTY or val == self.LEGAL:
            self.board[row][col] = val

    def getBoard(self, row, col):
        if self.isOnBoard(row, col):
            return self.board[row][col]
        else:
            raise Exception("Coordinate is not on the board")

    # flips the legal squares for sent coordinates

    def flipTiles(self, move):
        isValid = False
        curr = coor()
        toFlip = coor()
        for dir in self.DIRS:
            isFlipped = False
            i = 1
            while(True):
                # multiplying by "i" to move along the directions
                curr.row = move.row + dir[0] * i
                curr.col = move.col + dir[1] * i

                # i is increased for the next loop
                i += 1

                # if the square is not on the board, then it is not a legal move
                if not self.isOnBoard(curr):
                    break

                # if the square is empty, the goal is not achieved
                if self.board[curr.row][curr.col] == self.EMPTY or\
                        self.board[curr.row][curr.col] == self.LEGAL:
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
                    # toFlip is assigned the numbers along the legal direction
                    # to flip the tiles between curr and move, not including curr and move (curr, move)
                    # [curr]-----[toFlip]-----[move]
                    toFlip.row = move.row + dir[0]
                    toFlip.col = move.col + dir[1]
                    # assigning the squares, when the direction is horizontal
                    if dir[0] == 0:
                        # assign till c.col
                        while(toFlip.col != curr.col):
                            self.setBoard(toFlip.row, toFlip.col, self.turn)
                            # incrase the number by the delta
                            toFlip.col += dir[1]
                    # assigning the squares, when the direction is vertical
                    elif dir[1] == 0:
                        # assign till c.row
                        while(toFlip.row != curr.row):
                            self.setBoard(toFlip.row, toFlip.col, self.turn)
                            # incrase the number by the delta
                            toFlip.row += dir[0]
                    # assigning the squares, when the direction is cross
                    else:
                        # assign till c.row and c.col
                        while toFlip.row != curr.row and toFlip.col != curr.col:
                            self.setBoard(toFlip.row, toFlip.col, self.turn)
                            # incrase the numbers by the deltas
                            toFlip.row += dir[0]
                            toFlip.col += dir[1]
                    break
        if isValid:
            self.setBoard(move.row, move.col, self.turn)
        else:
            print("flipTiles: Illegal move")

    # marks all the legal squares at a certain moment
    def marker(self):
        # unmark all the moves
        for row in range(self.SIZE):
            for col in range(self.SIZE):
                if self.board[row][col] == self.LEGAL:
                    self.setBoard(row, col, self.EMPTY)
        # mark the legal moves
        c = coor()
        for row in range(self.SIZE):
            for col in range(self.SIZE):
                c.row = row
                c.col = col
                if self.isLegal(c):
                    self.setBoard(row, col, self.LEGAL)

    # returns a random legal move
    def randomMoves(self):
        moves = []
        for row in range(self.SIZE):
            for col in range(self.SIZE):
                if self.board[row][col] == self.LEGAL:
                    c = coor()
                    c.row = row
                    c.col = col
                    moves.append(c)
        if len(moves) == 0:
            return None
        rand = randrange(len(moves))
        return moves[rand]

    # sets the turn
    def setTurn(self, turn):
        if turn == self.BLACK:
            self.turn = self.BLACK
            self.opponent = self.WHITE
        elif turn == self.WHITE:
            self.turn = self.WHITE
            self.opponent = self.BLACK
        else:
            print("Invalid turn")
            exit()

    def setGameMode(self, mode):
        if mode != 0 and mode != 1 and mode != 2:
            raise ValueError("Invalid game mode")
        else:
            self.gameMode = mode

    # switches the turn between the players
    def switchTurn(self):
        if self.turn == self.BLACK:
            self.setTurn(self.WHITE)
        else:
            self.setTurn(self.BLACK)
        # update the legal squares after the switch
        self.marker()

    def delayer(self, delay):
        loop = QtCore.QEventLoop()
        timer = QtCore.QTimer()
        timer.setInterval(delay)
        timer.setSingleShot(True)
        timer.timeout.connect(loop.quit)
        timer.start()
        loop.exec()

    def setHumanSide(self, side):
        if side == self.BLACK or side == self.WHITE:
            self.humanSide = side
        else:
            raise ValueError("Invalid human side")

    def setGuidance(self, guidance):
        self.guidance = guidance


def window():
    app = QApplication(sys.argv)
    table = Table()
    menu = Menu(table)
    menu.show()
    sys.exit(app.exec_())


window()
