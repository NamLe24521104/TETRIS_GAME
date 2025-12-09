#include <iostream>
using namespace std;
#include <conio.h>



void enableRawMode() {

    HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);

    DWORD mode = 0;

    GetConsoleMode(hIn, &mode);



    // Tắt chế độ line input (bắt buộc phải Enter)

    mode &= ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);



    // Tắt quick edit (tránh freeze)

    mode &= ~ENABLE_QUICK_EDIT_MODE;



    SetConsoleMode(hIn, mode);

}
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


void removeLine(){

    for (int i = H - 2; i >= 1; i--){

        bool full = true;

        for (int j = 1; j < W - 1; j++){

            if (board[i][j] != BLOCK) {

                full = false;

                break;

            }

        }



        if (full) {

            // Xóa dòng và đẩy các dòng phía trên xuống

            for (int k = i; k > 0; k--){

                for (int j = 1; j < W - 1; j++){

                    board[k][j] = board[k - 1][j];

                }

            }

            // Dòng trên cùng (k = 0) nên clear

            for (int j = 1; j < W - 1; j++){

                board[0][j] = ' ';

            }



            score += 100;

            i++;  // Kiểm tra lại dòng này vì nó vừa thay đổi

        }

    }

}

bool canRotate(int newRotation) {

for (int i = 0 ; i < 4 ; i++){

        for (int j = 0 ; j < 4 ; j++){

            if (blocks[b][newRotation][i][j] != ' '){

                int tx = x + j;

                int ty = y + i;



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