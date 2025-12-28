#include <iostream>



const int H = 7;
const int W = 11;


char level1[H][W] = {
    {'#','#','#','#','#','#','#','#','#','#','#'},
    {'#','P',' ','C','#',' ',' ','C',' ','E','#'},
    {'#',' ','#',' ','#',' ','#','#',' ',' ','#'},
    {'#',' ','#',' ',' ',' ',' ',' ','#',' ','#'},
    {'#','#','#','#','#',' ','#',' ','#',' ','#'},
    {'#','C',' ',' ',' ',' ','#',' ',' ','C','#'},
    {'#','#','#','#','#','#','#','#','#','#','#'}
};

char level2[H][W] = {
    {'#','#','#','#','#','#','#','#','#','#','#'},
    {'#','P',' ','#','C',' ',' ',' ',' ','E','#'},
    {'#',' ',' ','#',' ','#','#','#',' ',' ','#'},
    {'#','#',' ',' ',' ',' ','C',' ','#',' ','#'},
    {'#',' ','#','#','#',' ','#',' ','#',' ','#'},
    {'#',' ',' ','C',' ',' ','#',' ',' ','C','#'},
    {'#','#','#','#','#','#','#','#','#','#','#'}
};

int main() {
    int choice;
    std::cout << "Choose level (1 or 2): ";
    std::cin >> choice;

    char map[H][W];
    int px = 1, py = 1;
    int steps = 0;
    int coins = 0;
    int totalCoins = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (choice == 1)
                map[i][j] = level1[i][j];
            else
                map[i][j] = level2[i][j];

            if (map[i][j] == 'C')
                totalCoins++;
        }
    }

    char move;

    while (true) {

      
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {

                int dx = i - px;
                if (dx < 0) dx = -dx;
                int dy = j - py;
                if (dy < 0) dy = -dy;

                if (dx <= 1 && dy <= 1)
                    std::cout << map[i][j];
                else
                    std::cout << '?';
            }
            std::cout << std::endl;
        }

        std::cout << "Steps: " << steps << std::endl;
        std::cout << "Coins: " << coins << "/" << totalCoins << std::endl;
        std::cout << "Move (W A S D): ";
        std::cin >> move;

        int nx = px;
        int ny = py;

        if (move == 'W' || move == 'w') nx--;
        if (move == 'S' || move == 's') nx++;
        if (move == 'A' || move == 'a') ny--;
        if (move == 'D' || move == 'd') ny++;

    
        if (map[nx][ny] != '#') {

          
            if (map[nx][ny] == 'C') {
                coins++;
            }

        
            if (map[nx][ny] == 'E') {
                if (coins == totalCoins) {
                    std::cout << "\nYOU WIN!\n";
                    std::cout << "Steps: " << steps << std::endl;
                    std::cout << "Coins collected: " << coins << std::endl;
                    break;
                }
                else {
                    std::cout << "\nCollect all coins first!\n";
                    continue;
                }
            }

            map[px][py] = ' ';
            px = nx;
            py = ny;
            map[px][py] = 'P';
            steps++;
        }
    }

    return 0;
}