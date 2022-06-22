#include <iostream>
#include <fstream>
#include <cstdlib>
//#include <ctime>
#include <array>
#include <iostream>

enum SPOT_STATE {
    EMPTY = 0,
    BLACK = 1,
    WHITE = 2
};

int player;
const int SIZE = 15;
std::array<std::array<int, SIZE>, SIZE> board;

//char player, opponent;
//std::array<std::array<int, SIZE>, SIZE> score = {};

void read_board(std::ifstream& fin) {
    fin >> player;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            fin >> board[i][j];
        }
    }
}

// void assign_square_value(void)   //hitung value tiap kotak
// {
//     int opponent_temp = 0;
//     int player_temp = 0;
    
//     for(int i=0;i<SIZE;i++)
//     {
//         for(int j=0;j<SIZE;j++)
//         {
//             if(board[i][j] == player || board[i][j] == opponent) continue;
//         }
//     }
// }

void write_valid_spot(std::ofstream& fout) {
    //srand(time(NULL));
    int x;
    int y;

    if(player == 1)
    {
        x = 5;
        y = 1;
    }
    else if (player == 2){
        x = 8;
        y = 1;
    }    
    // Keep updating the output until getting killed.
    bool flag = true;
    while(flag) {
        // Choose a random spot.
        
        if (board[x][y] == EMPTY) {
            fout << x << " " << y << std::endl;
            // Remember to flush the output to ensure the last action is written to file.
            fout.flush();
            break;
        }
        else{
            y++;
        }
    }
}

int main(int, char** argv) {
    std::ifstream fin(argv[1]);
    std::ofstream fout(argv[2]);
    read_board(fin);
    write_valid_spot(fout);
    fin.close();
    fout.close();
    return 0;
}
