#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

bool isSafe(int newx, int newy, vector<vector<int>> &arr, int n, vector<vector<bool>> &vis) {
    return (newx >= 0 && newx < n && newy >= 0 && newy < n && !vis[newx][newy] && arr[newx][newy] == 1);
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &vis, string path) {
    // Base Case
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    vis[x][y] = 1;

    // 4 movements: D, L, R, U
    // Down
    if (isSafe(x + 1, y, arr, n, vis)) {
        solve(x + 1, y, arr, n, ans, vis, path + "D");
    }

    // Left
    if (isSafe(x, y - 1, arr, n, vis)) {
        solve(x, y - 1, arr, n, ans, vis, path + "L");
    }

    // Right
    if (isSafe(x, y + 1, arr, n, vis)) {
        solve(x, y + 1, arr, n, ans, vis, path + "R");
    }

    // Upward
    if (isSafe(x - 1, y, arr, n, vis)) {
        solve(x - 1, y, arr, n, ans, vis, path + "U");
    }

    vis[x][y] = 0; // Backtrack
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
    vector<string> ans;
    if (arr[0][0] == 0 || arr[n - 1][n - 1] == 0) return ans; // Handle edge case where start or end is blocked
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    string path = "";

    solve(0, 0, arr, n, ans, visited, path);

    return ans;
}

int main(){

    cout << "hello World" ;
    return 0 ;
}