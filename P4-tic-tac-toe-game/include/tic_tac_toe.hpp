#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP

class TicTacToe {
public:
    TicTacToe();
    void displayBoard();
    bool makeMove(int row, int col, char player);
    bool checkWin();
    bool checkDraw();
    
private:
    char board[3][3];
    bool checkRows();
    bool checkCols();
    bool checkDiagonals();
};

#endif // TICTACTOE_HPP
