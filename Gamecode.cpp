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
int lines_cleared;
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
    for(int  py = 0; py < 4; py++){
        for(int px = 0; px < 4; px++){
            if( shapes[current_shape][rotation][py][px] == 'X'){ // sprawdzanie czy klocki są na planszy
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

void placePiece() {
    for (int py = 0; py < 4; py++) {
        for (int px = 0; px < 4; px++) {
            if (shapes[current_shape][current_rotation][py][px] == 'X') {
                int boardX = current_x+ px;
                int boardY = current_y + py;
                if (boardY >= 0 && boardY < board_height && boardX >= 0 && boardX < board_width) {
                    board[boardY][boardX] = 'X';
                }
            }
        }
    }
}

void clearFullLines() {
    int lines = 0;
    for (int y = board_height - 1; y >= 0; y--) { // -1 bo indexy są do 19 a nie 20
        bool full = true;
        for (int x = 0; x < board_width; x++) {
            if (board[y][x] == '.') { //jeśli znajdzie kropke a w lini to daje full na false
                full = false;
                break;
            }
        }
        if (full) {
            lines++;
            for (int row = y; row > 0; row--) {     
                for (int x = 0; x < board_width; x++) {  //jeśli jest pełna linia skasuj ostatnie które były pełne i zapełnij je od góry następnymi pustymi
                    board[row][x] = board[row - 1][x];
                }
            }
            for (int x = 0; x < board_width; x++) {
                board[0][x] = '.';
            }
            y++;
        }
    }
    if (lines > 0) {
        lines_cleared += lines;
        score += lines * 100;
    }
}

void spawnPiece() {
    current_shape = rand() % shape_type;
    current_rotation = 0;
    current_x = board_width / 2 - 2;
    current_y = 0;
    if (ifcollision(current_rotation, current_x, current_y)) {
        game_over = true;
    }
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
                    displayBoard[boardY][boardX] = '@';
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
    cout << "Wynik: " << score << "  Linie: " << lines_cleared << endl;
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

void saveScore() {
    ofstream outFile("tetris_score.txt", ios::app);
    if (outFile.is_open()) {
        outFile << "Wynik: " << score << " Linie: " << lines_cleared << "\n";
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
    lines_cleared = 0;


    cout << "TETRIS w C++" << endl;
    cout << "Autor: Miron Karwasz" << endl;
    cout << "aby rozpocząć grę wciśnij dowolny klawisz..." << endl;
        int startKey = _getch(); // oczekiwanie na wciśnięcie klawisza
    if (startKey == 224) {
        _getch(); // odczytaj i wyrzuć kod rozszerzony klawisza
    }

    spawnPiece();                       //pierwszy klocek
    drawGame();                         // pokazujemy stan gry od razu

    DWORD lastTime = GetTickCount();  //czas ostatniego spadku klocka
    int dropDelay = 500; 

    while (!game_over) {
        if (_kbhit()) {             //sprawdzenie, czy wciśnięto klawisz
            int key = _getch();         //odczyt klawisza
            if (key == 224) { //strzałki
                int arrow = _getch(); //odczyt kodu strzałki
                if (!pause) { // tylko jeśli gra nie jest w pauzie
                    if (arrow == 75) {
                        if (!ifcollision(current_rotation, current_x - 1, current_y)) current_x--;
                    } else if (arrow == 77) {
                        if (!ifcollision(current_rotation, current_x + 1, current_y)) current_x++;
                    } else if (arrow == 80) {
                        if (!ifcollision(current_rotation, current_x, current_y + 1)) current_y++;
                    } else if (arrow == 72) {
                        int next_rotation = (current_rotation + 1) % 4;
                        if (!ifcollision(next_rotation, current_x, current_y)) current_rotation = next_rotation;
                    }
                }
            } else {
                if (key == 'p' || key == 'P') {
                    pause = !pause;
                } else if (!pause) {
                    if (key == 'a' || key == 'A') {
                        if (!ifcollision(current_rotation, current_x - 1, current_y)) current_x--;
                    } else if (key == 'd' || key == 'D') {
                        if (!ifcollision(current_rotation, current_x + 1, current_y)) current_x++;
                    } else if (key == 's' || key == 'S') {
                        if (!ifcollision(current_rotation, current_x, current_y + 1)) current_y++;
                    } else if (key == 'w' || key == 'W' || key == ' ') {
                        int next_rotation = (current_rotation + 1) % 4;
                        if (!ifcollision(next_rotation, current_x, current_y)) current_rotation = next_rotation;
                    } else if (key == 'q' || key == 'Q') {
                        game_over = true;
                    }
                } else if (key == 'q' || key == 'Q') {
                    game_over = true;
                }
            }
        }

        DWORD currentTime = GetTickCount(); //aktualny czas
        if (!pause && currentTime - lastTime > (DWORD)dropDelay) {     //sprawdzenie, czy minął czas spadku
            if (!ifcollision(current_rotation, current_x, current_y + 1)) { //jeśli nie ma kolizji, klocek spada
                current_y++;
            } else {
                placePiece(); // umieszczenie klocka na planszy
                clearFullLines(); // sprawdzenie i usunięcie pełnych linii
                spawnPiece();  // pojawienie się nowego klocka
            }
            lastTime = currentTime; // zresetowanie czasu ostatniego spadku
        }

        drawGame(); // narysowanie planszy
        Sleep(50); // małe opóźnienie, aby gra była płynniejsza
    }

    saveScore();
    int endKey = _getch();
    if (endKey == 224) {
        _getch();
    }
    return 0;
}