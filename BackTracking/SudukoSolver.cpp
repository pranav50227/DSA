#include<bits/stdc++.h>
using namespace std ;

bool isSafe(int row , int col ,vector<vector<int>> & board , int val ){

    for(int i=0 ; i<9 ; i++){
        if(board[row][i] == val) return false ;

        if(board[i][col] == val) return false ;

        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val) return false ;
    }

    return true ;
}

bool Solve(vector<vector<int>> & board){

    for(int row = 0 ; row < 9 ; row++){

        for(int col = 0 ; col < 9 ; col++){

            if(board[row][col] == 0){

                for(int val = 1 ; val <= 9 ; val++){

                    if(isSafe(row , col , board , val)){

                        board[row][col] = val ;
                        bool isAheadOk = Solve(board) ;

                        if(isAheadOk){
                            return true ;
                        }else{
                            board[row][col] = 0 ;
                        }
                    }
                }
                return false ;
            }
        }
    }
}

void SudukoSolve(vector<vector<int>> & Suduko){
    bool ans = Solve(Suduko) ;
}

int main(){
    cout << "suduko solved " ;
}