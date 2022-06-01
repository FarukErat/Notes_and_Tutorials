#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QStyle>

const char BLACK_PATH[] =       ":/res/black.bmp";
const char WHITE_PATH[] =       ":/res/white.bmp";
const char EMPTY_PATH[] =       ":/res/empty.bmp";
const char LEGAL_BLACK_PATH[] = ":/res/legal_black.bmp";
const char LEGAL_WHITE_PATH[] = ":/res/legal_white.bmp";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // disable resizing
    setFixedSize(this->width(), this->height());
    // assign all the buttons and labels to a 2-d array to maintain
    // meaningful and readible code
    // buttons
    {
        buttons[0][0] = ui->pushButton;
        buttons[0][1] = ui->pushButton_2;
        buttons[0][2] = ui->pushButton_3;
        buttons[0][3] = ui->pushButton_4;
        buttons[0][4] = ui->pushButton_5;
        buttons[0][5] = ui->pushButton_6;
        buttons[0][6] = ui->pushButton_7;
        buttons[0][7] = ui->pushButton_8;
        buttons[1][0] = ui->pushButton_9;
        buttons[1][1] = ui->pushButton_10;
        buttons[1][2] = ui->pushButton_11;
        buttons[1][3] = ui->pushButton_12;
        buttons[1][4] = ui->pushButton_13;
        buttons[1][5] = ui->pushButton_14;
        buttons[1][6] = ui->pushButton_15;
        buttons[1][7] = ui->pushButton_16;
        buttons[2][0] = ui->pushButton_17;
        buttons[2][1] = ui->pushButton_18;
        buttons[2][2] = ui->pushButton_19;
        buttons[2][3] = ui->pushButton_20;
        buttons[2][4] = ui->pushButton_21;
        buttons[2][5] = ui->pushButton_22;
        buttons[2][6] = ui->pushButton_23;
        buttons[2][7] = ui->pushButton_24;
        buttons[3][0] = ui->pushButton_25;
        buttons[3][1] = ui->pushButton_26;
        buttons[3][2] = ui->pushButton_27;
        buttons[3][3] = ui->pushButton_28;
        buttons[3][4] = ui->pushButton_29;
        buttons[3][5] = ui->pushButton_30;
        buttons[3][6] = ui->pushButton_31;
        buttons[3][7] = ui->pushButton_32;
        buttons[4][0] = ui->pushButton_33;
        buttons[4][1] = ui->pushButton_34;
        buttons[4][2] = ui->pushButton_35;
        buttons[4][3] = ui->pushButton_36;
        buttons[4][4] = ui->pushButton_37;
        buttons[4][5] = ui->pushButton_38;
        buttons[4][6] = ui->pushButton_39;
        buttons[4][7] = ui->pushButton_40;
        buttons[5][0] = ui->pushButton_41;
        buttons[5][1] = ui->pushButton_42;
        buttons[5][2] = ui->pushButton_43;
        buttons[5][3] = ui->pushButton_44;
        buttons[5][4] = ui->pushButton_45;
        buttons[5][5] = ui->pushButton_46;
        buttons[5][6] = ui->pushButton_47;
        buttons[5][7] = ui->pushButton_48;
        buttons[6][0] = ui->pushButton_49;
        buttons[6][1] = ui->pushButton_50;
        buttons[6][2] = ui->pushButton_51;
        buttons[6][3] = ui->pushButton_52;
        buttons[6][4] = ui->pushButton_53;
        buttons[6][5] = ui->pushButton_54;
        buttons[6][6] = ui->pushButton_55;
        buttons[6][7] = ui->pushButton_56;
        buttons[7][0] = ui->pushButton_57;
        buttons[7][1] = ui->pushButton_58;
        buttons[7][2] = ui->pushButton_59;
        buttons[7][3] = ui->pushButton_60;
        buttons[7][4] = ui->pushButton_61;
        buttons[7][5] = ui->pushButton_62;
        buttons[7][6] = ui->pushButton_63;
        buttons[7][7] = ui->pushButton_64;
    }
    // labels
    {
        labels[0][0] = ui->label;
        labels[0][1] = ui->label_2;
        labels[0][2] = ui->label_3;
        labels[0][3] = ui->label_4;
        labels[0][4] = ui->label_5;
        labels[0][5] = ui->label_6;
        labels[0][6] = ui->label_7;
        labels[0][7] = ui->label_8;
        labels[1][0] = ui->label_9;
        labels[1][1] = ui->label_10;
        labels[1][2] = ui->label_11;
        labels[1][3] = ui->label_12;
        labels[1][4] = ui->label_13;
        labels[1][5] = ui->label_14;
        labels[1][6] = ui->label_15;
        labels[1][7] = ui->label_16;
        labels[2][0] = ui->label_17;
        labels[2][1] = ui->label_18;
        labels[2][2] = ui->label_19;
        labels[2][3] = ui->label_20;
        labels[2][4] = ui->label_21;
        labels[2][5] = ui->label_22;
        labels[2][6] = ui->label_23;
        labels[2][7] = ui->label_24;
        labels[3][0] = ui->label_25;
        labels[3][1] = ui->label_26;
        labels[3][2] = ui->label_27;
        labels[3][3] = ui->label_28;
        labels[3][4] = ui->label_29;
        labels[3][5] = ui->label_30;
        labels[3][6] = ui->label_31;
        labels[3][7] = ui->label_32;
        labels[4][0] = ui->label_33;
        labels[4][1] = ui->label_34;
        labels[4][2] = ui->label_35;
        labels[4][3] = ui->label_36;
        labels[4][4] = ui->label_37;
        labels[4][5] = ui->label_38;
        labels[4][6] = ui->label_39;
        labels[4][7] = ui->label_40;
        labels[5][0] = ui->label_41;
        labels[5][1] = ui->label_42;
        labels[5][2] = ui->label_43;
        labels[5][3] = ui->label_44;
        labels[5][4] = ui->label_45;
        labels[5][5] = ui->label_46;
        labels[5][6] = ui->label_47;
        labels[5][7] = ui->label_48;
        labels[6][0] = ui->label_49;
        labels[6][1] = ui->label_50;
        labels[6][2] = ui->label_51;
        labels[6][3] = ui->label_52;
        labels[6][4] = ui->label_53;
        labels[6][5] = ui->label_54;
        labels[6][6] = ui->label_55;
        labels[6][7] = ui->label_56;
        labels[7][0] = ui->label_57;
        labels[7][1] = ui->label_58;
        labels[7][2] = ui->label_59;
        labels[7][3] = ui->label_60;
        labels[7][4] = ui->label_61;
        labels[7][5] = ui->label_62;
        labels[7][6] = ui->label_63;
        labels[7][7] = ui->label_64;
    }
    // connect the buttons with clicked event and with clickToCoor function
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            connect(buttons[i][j], &QPushButton::clicked, this, &MainWindow::clickToCoor);
        }
    }
    //! ////////////////////////////////////////////////////////////////////
    // player black starts the game
    setTurn(BLACK);

    // creating a blank board
    for (int row = 0; row < SIZE; row++)
        for (int col = 0; col < SIZE; col++)
            this->board[row][col] = EMPTY;

    // adding the initial squares
    this->board[SIZE / 2 - 1][SIZE / 2] = BLACK;
    this->board[SIZE / 2][SIZE / 2 - 1] = BLACK;
    this->board[SIZE / 2 - 1][SIZE / 2 - 1] = WHITE;
    this->board[SIZE / 2][SIZE / 2] = WHITE;
    marker();
    updateBtns();
    //! ////////////////////////////////////////////////////////////////////
}

coor MainWindow::randomMove()
{
    coor c;
    int random;
    std::vector<std::vector<int>> moves;

    for (int row = 0; row < SIZE; row++) // tries all the squares on the board if they are legal
    {
        for (int col = 0; col < SIZE; col++)
        {
            // if they are legal, they are saved
            if (this->board[row][col] == LEGAL)
                moves.push_back({row, col});
        }
    }
    srand(time(NULL));
    random = rand() % moves.size(); // generates random numbers [0, count)

    c.row = moves[random][0];
    c.col = moves[random][1];

    return c;
}

void MainWindow::delayer(unsigned delay)
{
    QTimer timer;
    //        timer.setSingleShot(true);
    timer.setInterval(delay);
    QEventLoop loop;
    connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    timer.start();
    loop.exec();
}

void MainWindow::cpuPlays(unsigned delay)
{
    delayGuard = false;
    delayer(delay);
    delayGuard = true;
    proccess(randomMove());
    if (turn != humanSide)
    {
        cpuPlays(delay);
    }
}

void MainWindow::proccess(coor c)
{
    // if there is no legal moves
    // game ends
    if (board[c.row][c.col] == LEGAL)
    {
        flipTiles(c);
        switchTurn();
        updateBtns();
        if (!hasTileToFlip())
        {
            switchTurn();
            updateBtns();
        }
        if (!hasTileToFlip())
        {
            delayGuard = false;
            delayer(2000);
            exit(EXIT_SUCCESS);
        }
    }
}

void MainWindow::clickToCoor()
{
    if (!delayGuard)
        return;
    if (gameMode == 0)
    {
        humanPlays();
    }
    else if(gameMode == 1)
    {
        if (turn == humanSide)
            humanPlays();
        else
            cpuPlays();
    }
    else if(gameMode == 2)
    {
        while(hasTileToFlip())
        {
            cpuPlays();
        }
    }
}

void MainWindow::humanPlays()
{
    // getting the address of the button clicked
    QPushButton *target = qobject_cast<QPushButton *>(sender());
    coor c;
    // searching through the array for the address of the button
    // once we find, assign the indexes to a coor-type variable
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (buttons[i][j] == target)
            {
                c.row = i;
                c.col = j;
                if (isLegal(c))
                    proccess(c);
                if (gameMode == 1 && humanSide != turn)
                    cpuPlays();
                return;
            }
        }
    }
}

void MainWindow::updateBtns()
{
    QPixmap black(BLACK_PATH);
    QPixmap white(WHITE_PATH);
    QPixmap empty(EMPTY_PATH);
    QPixmap legal_black(LEGAL_BLACK_PATH);
    QPixmap legal_white(LEGAL_WHITE_PATH);
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            switch (this->board[row][col])
            {
            case BLACK:
            {
                labels[row][col]->setPixmap(black);
            }
            break;
            case WHITE:
            {
                labels[row][col]->setPixmap(white);
            }
            break;
            case EMPTY:
            {
                labels[row][col]->setPixmap(empty);
            }
            break;
            case LEGAL:
                if (marking)
                {
                    if (this->turn == BLACK)
                        labels[row][col]->setPixmap(legal_black);
                    else
                        labels[row][col]->setPixmap(legal_white);
                }
                else
                    labels[row][col]->setPixmap(empty);
                break;
            }
        }
    }
}

//! ////////////////////////////////////////////////////////////////////////

/**
 * @brief checks if the coordinate is in range of the size which is valid coordinates
 * @param c: coordinate of the moves
 * @return boolean
 */
bool MainWindow::isOnBoard(coor c)
{
    if (c.row >= 0 && c.row < SIZE && c.col >= 0 && c.col < SIZE)
        return true;
    else
        return false;
}

/**
 * @brief Checks if a move is legal in one direction.
 * @param c: coordinate of the moves
 * @param dir: direction
 * @return boolean
 */
bool MainWindow::isLegal(coor c)
{
    coor temp;
    bool flip = false;

    // if the coordinate is not on the board, then it is not a legal move
    if (!this->isOnBoard(c))
        return false;

    // non-empty squares cannot be filled, thus it is not a legal move
    if (getBoard(c.row, c.col) != EMPTY && getBoard(c.row, c.col) != LEGAL)
        return false;

    // for each direction
    for (auto dir : DIRS)
    {
        flip = false;
        for (int i = 1;; i++)
        {
            // multiplying by "i" to move along the directions
            temp.row = c.row + dir[0] * i;
            temp.col = c.col + dir[1] * i;

            // if the square is not on the board, then it is not a legal move
            if (!isOnBoard(temp))
                break;

            // if the square is empty, break
            if (getBoard(temp.row, temp.col) == EMPTY || getBoard(temp.row, temp.col) == LEGAL)
                break;

            // if the square is not the same as player's, assign flip true, then continue
            if (getBoard(temp.row, temp.col) == getOpponent())
            {
                flip = true;
                continue;
            }

            // if the square is the current player's and at least one tile is flipped
            // then it is a legal move
            if (getBoard(temp.row, temp.col) == getTurn())
            {
                if (flip)
                    return true;
                else
                    break;
            }
        }
    }
    // if no legal move is found, then it is not a legal move
    return false;
}

/**
 * @brief Checks if a side has any tile to flip, any legal move.
 * @param none
 * @return boolean
 */
bool MainWindow::hasTileToFlip()
{
    // all the squares are checked
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            if (getBoard(row, col) == LEGAL)
                return true;
        }
    }
    return false;
}

/**
 * @brief When called, it flips the valid tiles in the direction of the move.
 * @param move: coordinates of the moves
 * @param dir: direction
 * @return nothing
 */
void MainWindow::flipTiles(coor move)
{
    coor c, temp;
    bool isFlipped = false;
    // valid move guard in case there is a problem with the isLegal function
    bool isValid = false;

    // for each direction
    for (auto dir : DIRS)
    {
        isFlipped = false;
        for (int i = 1;; i++)
        {
            // multiplying by 'i' to move along the directions
            c.row = move.row + dir[0] * i;
            c.col = move.col + dir[1] * i;

            // if the square is not on the board, then it is not a legal move
            if (!isOnBoard(c))
                break;

            // if the square is empty, the goal is not reached
            if (getBoard(c.row, c.col) == EMPTY || getBoard(c.row, c.col) == LEGAL)
                break;

            // isFlipped changes to true if there is a tile to flip
            // when the player's square is found, there must be at least one tile to flip
            if (getBoard(c.row, c.col) == getOpponent())
                isFlipped = true;

            // when a square in the same color as players is found
            if (getBoard(c.row, c.col) == getTurn())
            {
                // if isFlipped is not true, then it is not a legal move
                if (!isFlipped)
                    break;
                isValid = true;

                // temp.row and temp.col are assigned the number along the legal direction
                temp.row = move.row + dir[0];
                temp.col = move.col + dir[1];

                // assigning the squares, when the direction is horizontal
                if (dir[0] == 0)
                {
                    // assign till c.col
                    while (temp.col != c.col)
                    {
                        // incrase the number by the delta
                        setBoard(temp.row, temp.col, getTurn());
                        temp.col += dir[1];
                    }
                }

                // assigning the squares, when the direction is vertical
                else if (dir[1] == 0)
                {
                    // assign till c.row
                    while (temp.row != c.row)
                    {
                        // incrase the number by the delta
                        setBoard(temp.row, temp.col, getTurn());
                        temp.row += dir[0];
                    }
                }

                // assigning the squares, when the direction is cross
                else
                {
                    // assign till c.row and c.col
                    while (temp.row != c.row && temp.col != c.col)
                    {
                        // incrase the numbers by the delta
                        setBoard(temp.row, temp.col, getTurn());
                        temp.row += dir[0];
                        temp.col += dir[1];
                    }
                }
                break;
            }
        }
    }
    try
    {
        if (isValid)
        {
            // the chosen square is assigned to current player's color
            setBoard(move.row, move.col, getTurn());
        }
        else
        {
            throw "flipTiles: Illegal move";
        }
    }
    catch (const char *msg)
    {
        std::cerr << msg << '\n';
    }
}


/**
 * @brief Legal moves are marked with LEGAL
 * @param none
 * @return nothing
 */
void MainWindow::marker()
{
    // unmarkes all the old marked squares
    /////////////////////////////////////////////////////
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            if (getBoard(row, col) == LEGAL)
                setBoard(row, col, EMPTY);
        }
    }
    /////////////////////////////////////////////////////

    // marks all the legal squares for the current player
    /////////////////////////////////////////////////////
    coor c;
    // all the squares are checked
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            c.row = row;
            c.col = col;
            if (isLegal(c))
                this->board[c.row][c.col] = LEGAL;
        }
    }
    /////////////////////////////////////////////////////
}

char MainWindow::getBoard(int row, int col)
{
    try
    {
        if (isOnBoard({row, col}))
            return board[row][col];
        else
            throw "getBoard: Invalid row or column";
    }
    catch (const char *msg)
    {
        std::cerr << msg << '\n';
    }
}
bool MainWindow::getMarking()
{
    return this->marking;
}
int MainWindow::getGameMode()
{
    return this->gameMode;
}
char MainWindow::getTurn()
{
    return this->turn;
}
char MainWindow::getOpponent()
{
    return this->opponent;
}
char MainWindow::getHumanSide()
{
    return this->humanSide;
}

void MainWindow::setBoard(int row, int col, char value)
{
    try
    {
        if (isOnBoard({row, col}) && (value == BLACK ||
                                      value == WHITE ||
                                      value == EMPTY ||
                                      value == LEGAL))
            board[row][col] = value;
        else
            throw "setBoard: Invalid row or column or value";
    }
    catch (const char *msg)
    {
        std::cerr << msg << '\n';
    }
}
void MainWindow::setMarking(bool m)
{
    this->marking = m;
}
void MainWindow::setGameMode(int c)
{
    try
    {
        if (c == 0 || c == 1 || c == 2)
            this->gameMode = c;
        else
            throw "setGameMode: Invalid game mode";
    }
    catch (const char *msg)
    {
        std::cerr << msg << '\n';
    }
}
void MainWindow::setTurn(char t)
{
    try
    {
        if (t == BLACK)
        {
            this->turn = BLACK;
            this->opponent = WHITE;
        }
        else if (t == WHITE)
        {
            this->turn = WHITE;
            this->opponent = BLACK;
        }
        else
            throw "setTurn: Invalid turn";
    }
    catch (const char *msg)
    {
        std::cerr << msg << '\n';
    }
}

void MainWindow::switchTurn()
{
    if (this->turn == BLACK)
    {
        setTurn(WHITE);
    }
    else
    {
        setTurn(BLACK);
    }
    marker();
}

void MainWindow::setHumanSide(char s)
{
    try
    {
        if (s == BLACK || s == WHITE)
            this->humanSide = s;
        else
            throw "setUserSide: Invalid side";
    }
    catch (const char *msg)
    {
        std::cerr << msg << '\n';
    }
}

//! ////////////////////////////////////////////////////////////////////////

MainWindow::~MainWindow()
{
    delete ui;
}
