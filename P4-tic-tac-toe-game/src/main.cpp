#include "../include/tic_tac_toe.hpp"
#include <iostream>

int main() {
    TicTacToe game;
    char player = 'X';
    int row, col;

    while (true) {
        game.displayBoard();

        // Player input
        std::cout << "Player " << player << ", enter your move (row and column): ";
        std::cin >> row >> col;

        // Make the move
        if (!game.makeMove(row - 1, col - 1, player)) {
            std::cout << "Invalid move! Try again.\n";
            continue;
        }

        // Check for win
        if (game.checkWin()) {
            game.displayBoard();
            std::cout << "Player " << player << " wins!\n";
            break;
        }

        // Check for draw
        if (game.checkDraw()) {
            game.displayBoard();
            std::cout << "It's a draw!\n";
            break;
        }

        // Switch player
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
