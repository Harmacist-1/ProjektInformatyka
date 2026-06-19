
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <fstream>
using namespace std;

const int board_width = 10;
const int board_height = 20;
const int shape_type = 10;

char board[board_height][board_width];

const char shapes[shape_type][4][4][4] = {

    {{
        {'.', '.', '.', '.'},
        {'X', 'X', 'X', 'X'},
        {'.', '.', '.', '.'},
        {'.', '.', '.', '.'}
    },{
        {'.', 'X', '.', '.'},
        {'.', 'X', '.', '.'},
        {'.', 'X', '.', '.'},
        {'.', 'X', '.', '.'}
    },{
        {'.', '.', '.', '.'},
        {'.', '.', '.', '.'},
        {'X', 'X', 'X', 'X'},
        {'.', '.', '.', '.'}
    },{
        {'.', '.', 'X', '.'},
        {'.', '.', 'X', '.'},
        {'.', '.', 'X', '.'},
        {'.', '.', 'X', '.'}
    }},

    {{
        {'.', '.', '.', '.'},
        {'.', 'X', 'X', '.'},
        {'.', 'X', 'X', '.'},
        {'.', '.', '.', '.'}
    },{
        {'.', '.', '.', '.'},
        {'.', 'X', 'X', '.'},
        {'.', 'X', 'X', '.'},
        {'.', '.', '.', '.'}
    },{
        {'.', '.', '.', '.'},
        {'.', 'X', 'X', '.'},
        {'.', 'X', 'X', '.'},
        {'.', '.', '.', '.'}
    },{
        {'.', '.', '.', '.'},
        {'.', 'X', 'X', '.'},
        {'.', 'X', 'X', '.'},
        {'.', '.', '.', '.'}
    }},

    {{
        {'.', '.', '.', '.'},
        {'X', 'X', 'X', '.'},
        {'.', 'X', '.', '.'},
        {'.', '.', '.', '.'}
    },{
        {'.', 'X', '.', '.'},
        {'X', 'X', '.', '.'},
        {'.', 'X', '.', '.'},
        {'.', '.', '.', '.'}
    },{
        {'.', 'X', '.', '.'},
        {'X', 'X', 'X', '.'},
        {'.', '.', '.', '.'},
        {'.', '.', '.', '.'}
    },{
        {'.', 'X', '.', '.'},
        {'.', 'X', 'X', '.'},
        {'.', 'X', '.', '.'},
        {'.', '.', '.', '.'}
    }},

    {{
        {'.', '.', '.', '.'},
        {'X', 'X', 'X', '.'},
        {'X', '.', '.', '.'},
        {'.', '.', '.', '.'}
    },{
        {'X', 'X', '.', '.'},
        {'.', 'X', '.', '.'},
        {'.', 'X', '.', '.'},
        {'.', '.', '.', '.'}
    },{
        {'.', '.', 'X', '.'},
        {'X', 'X', 'X', '.'},
        {'.', '.', '.', '.'},
        {'.', '.', '.', '.'}
    },{
        {'.', 'X', '.', '.'},
        {'.', 'X', '.', '.'},
        {'.', 'X', 'X', '.'},
        {'.', '.', '.', '.'}
    }},

    {{
        {'.', '.', '.', '.'},
        {'X', 'X', 'X', '.'},
        {'.', '.', 'X', '.'},
        {'.', '.', '.', '.'}
    },{
        {'.', 'X', '.', '.'},
        {'.', 'X', '.', '.'},
        {'X', 'X', '.', '.'},
        {'.', '.', '.', '.'}
    },{
        {'X', '.', '.', '.'},
        {'X', 'X', 'X', '.'},
        {'.', '.', '.', '.'},
        {'.', '.', '.', '.'}
    },{
        {'.', 'X', 'X', '.'},
        {'.', 'X', '.', '.'},
        {'.', 'X', '.', '.'},
        {'.', '.', '.', '.'}
    }},
  
    {{
        {'.', '.', '.', '.'},
        {'.', 'X', 'X', '.'},
        {'X', 'X', '.', '.'},
        {'.', '.', '.', '.'}
    },{
        {'.', 'X', '.', '.'},
        {'.', 'X', 'X', '.'},
        {'.', '.', 'X', '.'},
        {'.', '.', '.', '.'}
    },{
        {'.', '.', '.', '.'},
        {'.', 'X', 'X', '.'},
        {'X', 'X', '.', '.'},
        {'.', '.', '.', '.'}
    },{
        {'.', 'X', '.', '.'},
        {'.', 'X', 'X', '.'},
        {'.', '.', 'X', '.'},
        {'.', '.', '.', '.'}
    }},
   
    {{
        {'.', '.', '.', '.'},
        {'X', 'X', '.', '.'},
        {'.', 'X', 'X', '.'},
        {'.', '.', '.', '.'}
    },{
        {'.', '.', 'X', '.'},
        {'.', 'X', 'X', '.'},
        {'.', 'X', '.', '.'},
        {'.', '.', '.', '.'}
    },{
        {'.', '.', '.', '.'},
        {'X', 'X', '.', '.'},
        {'.', 'X', 'X', '.'},
        {'.', '.', '.', '.'}
    },{
        {'.', '.', 'X', '.'},
        {'.', 'X', 'X', '.'},
        {'.', 'X', '.', '.'},
        {'.', '.', '.', '.'}
    }},
   
    {{
        {'.', '.', '.', '.'},
        {'.', 'X', '.', '.'},
        {'X', 'X', 'X', '.'},
        {'.', 'X', '.', '.'}
    },{
        {'.', '.', '.', '.'},
        {'.', 'X', '.', '.'},
        {'X', 'X', 'X', '.'},
        {'.', 'X', '.', '.'}
    },{
        {'.', '.', '.', '.'},
        {'.', 'X', '.', '.'},
        {'X', 'X', 'X', '.'},
        {'.', 'X', '.', '.'}
    },{
        {'.', '.', '.', '.'},
        {'.', 'X', '.', '.'},
        {'X', 'X', 'X', '.'},
        {'.', 'X', '.', '.'}
    }},
    {{
        {'.', '.', '.', '.'},
        {'.', 'X', 'X', '.'},
        {'.', 'X', 'X', '.'},
        {'.', 'X', 'X', '.'}
    },{
        {'.', '.', '.', '.'},
        {'.', '.', '.', '.'},
        {'X', 'X', 'X', '.'},
        {'X', 'X', 'X', '.'}
    },{
        {'.', '.', '.', '.'},
        {'.', 'X', 'X', '.'},
        {'.', 'X', 'X', '.'},
        {'.', 'X', 'X', '.'}
    },{
        {'.', '.', '.', '.'},
        {'.', '.', '.', '.'},
        {'.', 'X', 'X', 'X'},
        {'.', 'X', 'X', 'X'}
    }},
    {{
        {'.', '.', '.', '.'},
        {'.', '.', '.', '.'},
        {'.', 'X', '.', '.'},
        {'.', 'X', '.', '.'}
    },{
        {'.', '.', '.', '.'},
        {'.', '.', '.', '.'},
        {'X', 'X', '.', '.'},
        {'.', '.', '.', '.'}

    },{
        {'.', '.', '.', '.'},
        {'.', 'X', '.', '.'},
        {'.', 'X', '.', '.'},
        {'.', '.', '.', '.'}
    },{
        {'.', '.', '.', '.'},
        {'.', '.', '.', '.'},
        {'.', 'X', 'X', '.'},
        {'.', '.', '.', '.'}
}}
};

int current_shape;
int current_rotation;
int current_x;
int current_y;
int score;
int cleared_lines;
bool game_over;
bool pause;


void BoardInit() {
    for(int y = 0 ; y < board_height; y++) { //
        for(int x = 0; x < board_width; x++) {//
            board[y][x] = '.';
        }
    }
}

bool ifcollision ( int rotation, int x, int y){
    for(int  px = 0; px < 4; px++){
        for(int py = 0; py < 4; py++){
            if( shapes[current_shape][rotation][px][py] == 'X'){ // sprawdzanie czy klocki są na planszy
                int board_x = x + px; 
                int board_y = y + py; 
                if(board_x < 0 || board_x >= board_width || board_y < 0 || board_y >= board_height) { 
                    return true; // sprawdzanie kolizji z krawędziami planszy
                }
                if(board[board_y][board_x] == 'X') { // sprawdzanie kolizji z innymi klockami
                    return true;
                }
            }
        }
    }
    return false; // brak kolizji
}

void drawGame() {
    char displayBoard[board_height][board_width];
    for (int y = 0; y < board_height; y++) {
        for (int x = 0; x < board_width; x++) {
            displayBoard[y][x] = board[y][x];
        }
    }

    for (int py = 0; py < 4; py++) {
        for (int px = 0; px < 4; px++) {
            if (shapes[current_shape][current_rotation][py][px] == 'X') {
                int boardX = current_x + px;
                int boardY = current_y + py;
                if (boardX >= 0 && boardX < board_width && boardY >= 0 && boardY < board_height) {
                    displayBoard[boardY][boardX] = 'O';
                }
            }
        }
    }

    system("cls");
    cout << "TETRIS - autor: Miron Karwasz " << endl;
    cout << "Sterowanie: strzalki lub A/D - ruch, S - szybki spadek, W - obrot, P - pauza, Q - wyjscie" << endl;
    if (pause) {
        cout << "*** GRA W PAUZIE - wcisnij P, aby kontynuowac ***" << endl;
    }
    cout << "Wspolrzedne aktualnego klocka: X=" << current_x << " Y=" << current_y << endl;
    cout << "Wynik: " << score << "  Linie: " << cleared_lines << endl;
    cout << "+";
    for (int x = 0; x < board_width; x++) cout << "-";
    cout << "+" << endl;
    for (int y = 0; y < board_height; y++) {
        cout << "|";
        for (int x = 0; x < board_width; x++) {
            cout << displayBoard[y][x];
        }
        cout << "|" << endl;
    }
    cout << "+";
    for (int x = 0; x < board_width; x++) cout << "-";
    cout << "+" << endl;
    if (game_over) {
        cout << "KONIEC GRY! Nacisnij dowolny klawisz, aby wyjsc." << endl;
    }
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    srand((unsigned int)time(NULL));    //inicjalizacja generatora liczb losowych
    BoardInit();   
                   //inicjalizacja planszy
    game_over = false;
    pause = false;
    score = 0;
    cleared_lines = 0;


    cout << "TETRIS w C++" << endl;
    cout << "Autor: Miron Karwasz" << endl;
    cout << "aby rozpocząć grę wciśnij dowolny klawisz..." << endl;
    _getch();
 
    drawGame();                         
}