#include <iostream>
#include <string>
#include <fstream>

#define SIZE 9
int grid[SIZE][SIZE];

int input(std::string filename){
    std::ifstream ifs(filename);
    if (ifs.fail()){
        std::cout << "file'" << filename << "'はありません" << std::endl;
        return -1;
    }

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            ifs >> grid[i][j];
        }
    }
    return 0;
}

void output(void){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return;
}

void solve(){

}


int main(){

    if(input("in.txt") == -1){
        return 0;
    }

    output();

    solve();

    std:: cout << "結果" << std::endl;
    output();

}
