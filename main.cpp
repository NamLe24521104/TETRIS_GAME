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
int score = 0;
int speed = 200;
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
    enableRawMode();

    // Đặt code page để in được char(219)

    system("chcp 437 >nul");

    SetConsoleOutputCP(437);



    // Ẩn con trỏ

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hOut, &cursorInfo);

    cursorInfo.bVisible = FALSE;

    SetConsoleCursorInfo(hOut, &cursorInfo);



    ios_base::sync_with_stdio(false);

    cin.tie(NULL);



    system("cls");



    srand((unsigned)time(0));



    // Khởi tạo game

    initBoard();

    b = rand() % 7;

    nextBlock = rand() % 7;

    rotation = 0;

    x = getRandomX(b);

    y = 0;



    int fallCounter = 0;

    bool gameOver = false;
    while (!gameOver){

        // Xóa khối hiện tại từ board

        boardDelBlock();



        // Xử lý input không blocking

        if (_kbhit()){

unsigned char ch = _getch();

            char c = tolower(ch);

            if (c == 'a') {

                if (canMove(-1, 0)) x--;

            }

            else if (c == 'd') {

                if (canMove(1, 0)) x++;

            }

            else if (c == 's') {

                if (canMove(0, 1)) y++;

            }

            else if (c == 'w') {

                rotateBlock();

            }

            else if (c == 'q') {

                gameOver = true;

                break;

            }

        }



        // Logic rơi tự động

        fallCounter++;

        if (fallCounter >= speed / 30) {

            if (canMove(0, 1)) {

                y++;

            }

            else {

                // Khối không thể rơi nữa -> cố định khối vào board

                block2Board();



                // Xóa dòng đầy

                removeLine();



                // Kiểm tra game over

                if (isGameOver()) {

                    draw();

                    cout << "\n========== GAME OVER ==========" << endl;

                    cout << "Final Score: " << score << endl;

                    cout << "================================" << endl;

                    cout << "Press any key to exit..." << endl;

                    _getch();

                    gameOver = true;

                    break;

                }



                // Sinh khối mới

                b = nextBlock;

                nextBlock = rand() % 7;

                rotation = 0;

                x = getRandomX(b);

                y = 0;



                // Nếu không đặt được khối mới → Game Over

                if (!canMove(0, 0)) {

                    draw();

                    cout << "\n========== GAME OVER ==========" << endl;

                    cout << "Final Score: " << score << endl;

                    cout << "================================" << endl;

                    cout << "Press any key to exit..." << endl;

                    _getch();

                    gameOver = true;

                    break;

                }



                fallCounter = 0;

                // tiếp tục vòng lặp, khối mới sẽ được vẽ ở cuối

            }

            fallCounter = 0;

        }
// Vẽ khối hiện tại (tạm thời)

        block2Board();

        draw();



        Sleep(30);  // thời gian chờ nhỏ để game mượt hơn

    }

return 0;
