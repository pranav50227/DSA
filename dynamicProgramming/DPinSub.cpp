#include<bits/stdc++.h>

using namespace std ;


// Every dynamic programming approach starts from the very basic recursive approach
// We are required to find all the possible combinations and than take the optimised approach among them
// Than we use memoization to store the results of the subproblems and avoid the repeated calculations
// Than we use tabulation to store the results of the subproblems in a bottom up
// Than we use space optimisation to reduce the space complexity of the tabulation approach
// This is our very approach of dynamic programming

// DP in Subsequence problems 
// we are required to work with the subsequences of the given array or string anything

// Find if a possible subsequence of the given array is equal to the target sum or not

bool subDP(int ind , int target , vector<int> &arr ){
    if(target == 0) return true ;
    if(ind == 0 ) return arr[0] == target ;

    bool nottake = subDP(ind-1 , target , arr) ;
    bool take = false ;
    if(arr[ind] <= target){
        take = subDP(ind-1 , target - arr[ind] , arr);
    }

    return take || nottake ;
}

// Now in the memoization we will use predefined 2d vector to store the results of repeated occuring subproblems
bool subDPMemo(int ind , int target , vector<int> &arr , vector<vector<int>> &dp ){
    if(target == 0) return true ;
    if(ind == 0 ) return arr[0] == target ;

    if(dp[ind][target] != -1) return dp[ind][target] ;

    bool nottake = subDPMemo(ind-1 , target , arr , dp) ;
    bool take = false ;
    if(arr[ind] <= target){
        take = subDPMemo(ind-1 , target - arr[ind] , arr , dp);
    }

    return dp[ind][target] = take || nottake ;
}

// Now in the tabulation we will use predefined 2d vector to store the results of problems in a bottom up manner
bool subDPTab(int n , int target , vector<int>& arr){
    vector<vector<bool>> dp(n , vector<bool>(target+1 , false)) ;
    for(int i = 0 ; i < n ; i++){
        dp[i][0] = true ;
    }
    if(arr[0] <= target) dp[0][arr[0]] = true ;
    for(int ind = 1 ; ind < n ; ind++){
        for(int sum = 1 ; sum <= target ; sum++){
            bool nottake = dp[ind-1][sum] ;
            bool take = false ;
            if(arr[ind] <= sum){
                take = dp[ind-1][sum - arr[ind]] ;
            }
            dp[ind][sum] = take || nottake ;
        }
    }
    return dp[n-1][target] ;
}

bool subDPSpace(int n , int target , vector<int>&arr){
    vector<bool> dp(target+1 , false) ;
    dp[0] = true ;
    if(arr[0] <= target)dp[arr[0]] = true ;
    for(int i=1 ; i<n ; i++){
        for(int sum = 1 ; sum <= target ; sum++){
            bool nottake = dp[sum] ;
            bool take = false ;
            if(arr[i] <= sum){
                take = dp[sum - arr[i]] ;
            }
            dp[sum] = take || nottake ;
        }
    }
    return dp[target] ;
}

int main(){

    return 0 ;
}