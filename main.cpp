#include <iostream>
using namespace std;

// --- KHAI BAO BIEN TOAN CUC (TV1 & TV5) ---
// (De trong cho TV5 dien)

// --- HAM TIEN ICH (TV2 & TV4) ---
void gotoxy(int x, int y) { /* TV2 se lam */ }
void draw() { /* TV2 se lam */ }
void enableRawMode() { /* TV4 se lam */ }
void input() { /* TV4 se lam */ }

// --- HAM LOGIC GAME (TV3) ---

bool canMove(int dx, int dy){

    for (int i = 0 ; i < 4 ; i++){

        for (int j = 0 ; j < 4 ; j++){

            if (blocks[b][rotation][i][j] != ' '){

                int tx = x + j + dx;

                int ty = y + i + dy;



                // Kiểm tra biên

                if (tx < 1 || tx >= W-1 || ty >= H-1) return false;

                if (ty >= 0 && (board[ty][tx] == '#' || board[ty][tx] == BLOCK))

                    return false;


            }

        }

    }

    return true;

}

void logic() { /* TV3 se lam */ }

// --- MAIN (TV1) ---
int main() {
    cout << "Du an Tetris Nhom 5 khoi dong...";
    return 0;
}