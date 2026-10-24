#include <iostream>

#include "tikTakToe.cpp"  // это ваше решение

int main() {
    size_t n, m;
    std::cin >> n >> m;
    TicTacToe game(n, m);
    size_t x, y;
    while (std::cin >> x >> y) {
        int curPlayer = game.GetCurrentPlayer();
        if (game.Set(x, y)) {
            std::cout << "Player #" << curPlayer << " wins!\n";
        }
    }
    std::cout << game;
    return 1;
}