#include<bits/stdc++.h>
using namespace std ;

bool isSafe(int row , int col , vector<vector<int>> & board , int n ){
    int x = row ;
    int y = col ;

    while(y >= 0){
        if(board[x][y] == 1) return false ;
        y-- ;
    }

    x = row ;
    y = col ;

    while(x>=0 && y>=0){
        if(board[x][y] == 1){
            return false ;
        }
        x-- ; 
        y-- ;
    }

     x = row ;
     y = col ;

    while(x < n && y>=0){
        if(board[x][y] == 1){
            return false ;
        }
        x++ ; 
        y-- ;
    }

    return true ;

}

void addSol( vector<vector<int>> & board ,vector<vector<string>> &ans , int n){
    vector<string> temp ;

    for(int i=0 ; i<n ; i++){
        string t = "" ;
        for(int j=0 ; j<n ; j++){
            if(board[i][j] == 1){
                t += 'Q' ;
            }else{
                t += '.' ;
            }
        }
        temp.push_back(t) ;
    }

    ans.push_back(temp) ;
}

void solve(int col , vector<vector<string>> &ans , vector<vector<int>> & board , int n ){
    if(col == n){
        addSol(board , ans , n) ;
        return ;
    }

    for(int row = 0 ; row < n ; row++){
        if(isSafe(row , col , board , n)){

            board[row][col] = 1 ;
            solve(col+1 , ans , board , n) ;
            board[row][col] = 1 ;
        }
    }
}

vector<vector<string>> nqueens(int n ){
    vector<vector<int>> board(n , vector<int> (n , 0)) ;
    vector<vector<string>> ans ;

    solve( 0 , ans , board , n) ;

    return ans ;
}

int main(){
    cout << "the n queen problem is solved " ;
    return 0 ;
}