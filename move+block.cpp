#include <iostream>
#include <conio.h> // For _getch()
#include <thread> // For sleep_for


// Define the size of the board
const int BOARD_WIDTH = 80;
const int BOARD_HEIGHT = 25;

const int SLEEP_DURATION = 500;
// Define the characters for the ships, blocks, walls, and exit point
const char BIG_SHIP_CHAR = '#';
const char SMALL_SHIP_CHAR = '@';
const char BLOCK_CHAR = '*';
const char WALL_CHAR = 'W';
const char EXIT_CHAR = 'E';

// Define the keys for ship movement
const char MOVE_LEFT_KEY = 'a';
const char MOVE_RIGHT_KEY = 'd';
const char MOVE_DOWN_KEY = 'x';
const char MOVE_UP_KEY = 'w';
const char SWITCH_SHIP_KEY = 's';

class Game {
private:
    char board[BOARD_HEIGHT][BOARD_WIDTH];
    int bigShipX, bigShipY; // Coordinates of the big ship
    int smallShipX, smallShipY; // Coordinates of the small ship
    int bigShipDirX, bigShipDirY; // Direction of the big ship
    int smallShipDirX, smallShipDirY; // Direction of the small ship
    bool bigShipSelected; // Flag to track which ship is selected

public:
    Game() {
        // Initialize the board
        for (int i = 0; i < BOARD_HEIGHT; i++) {
            for (int j = 0; j < BOARD_WIDTH; j++) {
                board[i][j] = ' ';
            }
        }

        // Initialize the ships
        bigShipX = 3;
        bigShipY = 3;
        smallShipX = 1;
        smallShipY = 1;
        bigShipSelected = true;

        // Place walls on the board
        for (int i = 0; i < BOARD_HEIGHT; i++) {
            board[i][0] = WALL_CHAR;
            board[i][BOARD_WIDTH - 1] = WALL_CHAR;
        }
      

        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[0][j] = WALL_CHAR;
            board[BOARD_HEIGHT - 1][j] = WALL_CHAR;
        }

        // Place the exit point on the board
        board[BOARD_HEIGHT - 2][BOARD_WIDTH - 2] = EXIT_CHAR;
    }

    void drawBoard() {
        system("cls"); // Clear the screen

        // Draw the board
        for (int i = 0; i < BOARD_HEIGHT; i++) {
            for (int j = 0; j < BOARD_WIDTH; j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void moveShip(char direction) {
        int& shipX = (bigShipSelected) ? bigShipX : smallShipX;
        int& shipY = (bigShipSelected) ? bigShipY : smallShipY;
        int& dirX = (bigShipSelected) ? bigShipDirX : smallShipDirX;
        int& dirY = (bigShipSelected) ? bigShipDirY : smallShipDirY;

        switch (direction) {
        case MOVE_LEFT_KEY:
            dirX = -1;
            dirY = 0;
            break;
        case MOVE_RIGHT_KEY:
            dirX = 1;
            dirY = 0;
            break;
        case MOVE_DOWN_KEY:
            dirX = 0;
            dirY = 1;
            break;
        case MOVE_UP_KEY:
            dirX = 0;
            dirY = -1;
            break;
        }

        // Move the ship and the block
        if (board[shipY + dirY][shipX + dirX] != WALL_CHAR) {
            if (board[shipY + dirY][shipX + dirX] == BLOCK_CHAR) {
                if (board[shipY + 2 * dirY][shipX + 2 * dirX] != WALL_CHAR) {
                    board[shipY + 2 * dirY][shipX + 2 * dirX] = BLOCK_CHAR;
                }
            }

            shipX += dirX;
            shipY += dirY;
        }
    }

    void switchShip() {
        bigShipSelected = !bigShipSelected;
    }

    void updateBoard() {
        // Clear the board
        for (int i = 0; i < BOARD_HEIGHT; i++) {
            for (int j = 0; j < BOARD_WIDTH; j++) {
                if (board[i][j] != WALL_CHAR && board[i][j] != EXIT_CHAR) {
                    board[i][j] = ' ';
                }
            }
        }
        
        // Place the ships on the board
        board[bigShipY][bigShipX] = BIG_SHIP_CHAR;
        board[bigShipY + 1][bigShipX] = BIG_SHIP_CHAR;
        board[bigShipY][bigShipX + 1] = BIG_SHIP_CHAR;
        board[bigShipY + 1][bigShipX + 1] = BIG_SHIP_CHAR;
        board[smallShipY][smallShipX] = SMALL_SHIP_CHAR;
        board[smallShipY][smallShipX + 1] = SMALL_SHIP_CHAR;

        // Place the blocks on the board
        // For now, we'll assume there are two blocks at fixed positions
        board[2][2] = BLOCK_CHAR;
        board[5][7] = BLOCK_CHAR;
    }

    void run() {
        char key;
        while (true) {
            drawBoard();
            

            key = _getch(); // Get a key press without echoing it to the screen

            if (key == SWITCH_SHIP_KEY) {
                switchShip();
            }
            else {
                moveShip(key);
            }

            updateBoard();
        }
    }
};

int main() {
    Game game;
    game.run();

    return 0;
}