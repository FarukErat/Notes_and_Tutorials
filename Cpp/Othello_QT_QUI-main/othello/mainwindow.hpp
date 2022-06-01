#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <vector>
#include <iostream>

#include <QtWidgets/QPushButton>
#include <QMainWindow>
#include <QStyle>
#include <QLabel>

#define SIZE 8
#define BLACK 'B'
#define WHITE 'W'
#define EMPTY '-'
#define LEGAL 'x'

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct coor
{
    int col;
    int row;
};

// Define all the possible directions in which a player's move can flip
// their adversary's tiles as constant (0 – the current row/column,
// +1 – the next row/column, -1 – the previous row/column)
const int DIRS[8][2] =
{
    {-1, -1},   {-1, 0},    {-1, 1},
    {0, -1},                {0, 1},
    {1, -1},    {1, 0},     {1, 1}
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // bool return type functions
    bool hasTileToFlip();
    bool isLegal(coor);
    bool isOnBoard(coor);

    // void return type function
    void clickToCoor();
    void flipTiles(coor);
    void marker();
    void updateBtns();
    void proccess(coor);
    void game(); // not ready yet
    void delayer(unsigned delay = 1000);
    void switchTurn();
    void cpuPlays(unsigned delay = 1000);
    void humanPlays();

    coor randomMove();

    // getter functions
    char getBoard(int row, int col);
    bool getGuidance();
    int getGameMode();
    char getTurn();
    char getOpponent();
    char getHumanSide();

    // setter functions
    void setBoard(int row, int col, char value);
    void setGuidance(bool);
    void setGameMode(int);
    void setTurn(char);
    void setHumanSide(char);
private:
    Ui::MainWindow *ui;
    QPushButton *buttons[SIZE][SIZE];
    QLabel *labels[SIZE][SIZE];

    bool guidance = true;
    bool delayGuard = true;
    int gameMode = 1;
    char board[SIZE][SIZE];
    char turn = BLACK;
    char opponent = WHITE;
    char humanSide = BLACK;

};

#endif // MAINWINDOW_HPP
