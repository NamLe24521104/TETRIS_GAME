#include <iostream>
using namespace std;

// --- KHAI BAO BIEN TOAN CUC (TV1 & TV5) ---
// (De trong cho TV5 dien)


#define H 20

#define W 15



char board[H][W] = {};
// --- HAM TIEN ICH (TV2 & TV4) ---
void gotoxy(int x, int y) { /* TV2 se lam */ }
void draw() { /* TV2 se lam */ }
void enableRawMode() { /* TV4 se lam */ }
void input() { /* TV4 se lam */ }

// --- HAM LOGIC GAME (TV3) ---
bool canMove() { return false; /* TV3 se lam */ }
void logic() { /* TV3 se lam */ }

// --- MAIN (TV1) ---
int main() {
    cout << "Du an Tetris Nhom 5 khoi dong...";
    return 0;
}