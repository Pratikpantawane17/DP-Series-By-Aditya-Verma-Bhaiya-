// Recusive Approach : 
class Solution {

private : 
bool solve(vector<int> &arr, int sum, int n) {
    if(n==0 || sum <= 0) return false;
    
    if(arr[n-1] == sum) return true;
    else if(arr[n-1] < sum) return (solve(arr, sum - arr[n-1], n-1) || solve(arr, sum, n-1));
    else return solve(arr, sum, n-1);
}

public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        return solve(arr, sum, n);
    }
};

// ___________________________________________________________________________________________________________________________________________________________________________________________________________

//Memoized Approach : 
class Solution {

private : 
bool solve(vector<int> &arr, int sum, int n, vector<vector<int>> &dp) {
    if(n==0 || sum <= 0) return 0;
    
    if(dp[n][sum] != -1) return dp[n][sum];
    else {
        if(arr[n-1] == sum) return dp[n][sum] = 1;
        else if(arr[n-1] < sum) return dp[n][sum] = (solve(arr, sum - arr[n-1], n-1, dp) || solve(arr, sum, n-1, dp));
        else return dp[n][sum] = solve(arr, sum, n-1, dp);
    }
    
}


public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        return solve(arr, sum, n);
    }
};


// ___________________________________________________________________________________________________________________________________________________________________________________________________________


// Tabulation : Bottom-Top (Iterative Way) - Best DP - (No Stack Overflow Error can encounter)....
class Solution {

public:
    bool isSubsetSum(vector<int>& arr, int sum) {
      
        
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum + 1, -1));
        
        for(int i = 0; i<=n; i++) {
            for(int j = 0; j<=sum; j++) {
                if(i==0 || j <= 0) dp[i][j] = 0;
            }
        }
        
        // Here i=n, j=sum....
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=sum; j++) {
                if(arr[i-1] == j) dp[i][j] = 1;
                else if(arr[i-1] < j) dp[i][j] = (dp[i-1][j - arr[i-1]] || dp[i-1][j]);
                else dp[i][j] = dp[i-1][j];
            }
        }
        
   
        return dp[n][sum];
    }
};


