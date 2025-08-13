
// Brute Force Recursion
class Solution {
    
private :
// This is not handling the zero cases but sure this is the correct way to think about the DP.......Not as of given below this....
int solve(vector<int>& arr, int target, int n) {
    if(n==0 && target == 0) return 1;
    if(n==0 && target != 0) return 0;
    
    
    if(arr[n-1] <= target) return solve(arr, target - arr[n-1], n-1) + solve(arr, target, n-1);
    else return solve(arr, target, n-1);
}



public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        
        
        return solve(arr, target, n);
    }
};



// Memoized Version
class Solution {
    
private :
// This is not handling the zero cases but sure this is the correct way to think about the DP.......Not as of given below this....
int solve(vector<int>& arr, int target, int n, vector<vector<int>>& dp) {
    if(n==0 && target == 0) return 1;
    if(n==0 && target != 0) return 0;
    
    if(dp[n][target] != -1) return dp[n][target];
    
    else{
        if(arr[n-1] <= target) return dp[n][target] = solve(arr, target - arr[n-1], n-1, dp) + solve(arr, target, n-1, dp);
        else return dp[n][target] = solve(arr, target, n-1, dp);
    }
}



public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1)); 
        return solve(arr, target, n, dp);
    }
};


// Tabulased Version
class Solution {

public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        
        // tabulation
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0)); 
        const int MOD = 1e9 + 7;
        
        // for(int i = 0; i<=n; i++) {
        //     for(int j = 0; j<=target; j++) {
        //         if(i==0) dp[i][j] = 0;
        //         if(j==0) dp[i][j] = 1;                
        //     }
        // }
        
        for(int i = 0; i<=n; i++) dp[i][0] = 1;
        
        //  NOt include any subarray conatining 0 --> bcz at the end we will be adding them....by using formula 2^(no.of zeroes)....
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=target; j++) {
               if(arr[i-1] <= j && arr[i-1] != 0) {
                   dp[i][j] = dp[i-1][j - arr[i-1]] + dp[i-1][j];
               }
               else {
                   dp[i][j] = dp[i-1][j];
               }
            }
        }
        
        int zeroCnt = 0;
        for (int x : arr) if (x == 0) zeroCnt++;
        
        long long result = dp[n][target];
        for (int i = 0; i < zeroCnt; i++) {
            result = (result * 2) % MOD;
        }

        return (int)result;
    }
};
