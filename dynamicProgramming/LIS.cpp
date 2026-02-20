#include<bits/stdc++.h>

using namespace std ;

// LIS -> Longest Increasing Subsequence
// We try to count all the corresponding increasing subsequences using dp and take the longest at 
// a particular point and than we try to calculate it with the dp before it
// if there is any element before this element which is smaller than this element than 
// we can add this element to the longest increasing subsequence before it or else we 
// can take the current dp as 1 as starting from this point onwards we can try to calculate the longest increasing subsequence
// Time complexity -> O(n^2) and space complexity -> O(n)

int LongestSubsequence(int n , vector<int> &arr){
    if(n == 0) return 0 ;
    vector<int> dp(n , 1);
    int maxlen = 1 ;
    for(int i=0 ; i<n ; i++){
        for(int prev=0 ; prev<i ; prev++){
            if(arr[prev] < arr[i]){
                dp[i] = max(dp[i] , 1+dp[prev]) ;
            }
        }
        if(dp[i] > maxlen) maxlen = dp[i] ;
    }
    return maxlen ;
}


// There is also a more optimised approach to solve this problem in O(nlogn) time complexity using binary search and greedy approach
// The idea is to maintain a vector which will store the longest increasing subsequence at any point of time and we will try to update this vector as we move forward in the array

int lisOptimised(int n , vector<int> &arr){
    vector<int> tails ;
    for(int x : arr){
        auto it = lower_bound(tails.begin() , tails.end() , x) ;
        if(it == tails.end())tails.push_back(x) ;
        else *it = x ;
    }
    return tails.size(); 
}

int main(){

    return 0 ;
}

