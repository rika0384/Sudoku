#include <iostream>
#include <string>
#include <fstream>

#define GRIDSIZE 9
#define BLOCKSIZE 3
#define BLOCKNUM 3

int grid[GRIDSIZE][GRIDSIZE];

int input(std::string filename){
    std::ifstream ifs(filename);
    if (ifs.fail()){
        std::cout << "file'" << filename << "'はありません" << std::endl;
        return -1;
    }

    for(int i = 0; i < GRIDSIZE; i++){
        for(int j = 0; j < GRIDSIZE; j++){
            ifs >> grid[i][j];
        }
    }
    return 0;
}

void output(void){
    for(int i = 0; i < GRIDSIZE; i++){
        for(int j = 0; j < GRIDSIZE; j++){
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return;
}

bool check(){
    for(int i = 0; i < GRIDSIZE; i++){ // i 行目のチェック
        int cnt[GRIDSIZE+1] = {};
        for(int j = 0; j < GRIDSIZE; j++){
            if(grid[i][j] > 0) cnt[grid[i][j]]++;
            if(cnt[grid[i][j]] >= 2) return false;
        }
    }

    for(int j = 0; j < GRIDSIZE; j++){ // j 列目のチェック
        int cnt[GRIDSIZE+1] = {};
        for(int i = 0; i < GRIDSIZE; i++){
            if(grid[i][j] > 0){
                cnt[grid[i][j]]++;
                if(cnt[grid[i][j]] >= 2) return false;
            }
        }
    }

    for(int p = 0; p < BLOCKNUM; p++){
        for(int q = 0; q < BLOCKNUM; q++){
            // 左上を (BLOCKNUM*p, BLOCKNUM*q) とするブロックのチェック
            int cnt[GRIDSIZE+1] = {};
            for(int i = 0; i < BLOCKSIZE; i++){
                for(int j = 0; j < BLOCKSIZE; j++){
                    int num = grid[BLOCKNUM*p + i][BLOCKNUM*q + j];
                    if(num > 0){
                        cnt[num]++;
                        if(cnt[num] >= 2) return false;
                    }
                }
            }
        }
    }

    return true;
}



bool solve(int i, int j){
    if(i > GRIDSIZE)return true;
    if(check() == false)return false;
    if(grid[i][j] != 0){
        return solve(i + (j+1 == GRIDSIZE), (j+1) % GRIDSIZE);
    }
    for(int num = 1; num <= GRIDSIZE; num++){
        grid[i][j] = num;
        if(check() && solve(i + (j+1 == GRIDSIZE), (j+1) % GRIDSIZE)){
            return true;
        }
    }
    grid[i][j] = 0;
    return false;
}


int main(){

    if(input("in.txt") == -1){
        return 0;
    }

    output();

    if(solve(0,0)){
        std::cout << "成功しました" << std::endl;
        std::cout << "結果" << std::endl;
        output();
    }else{
        std::cout << "失敗しました" << std::endl;
    }
}
