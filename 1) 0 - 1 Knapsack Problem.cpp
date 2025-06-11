class Solution {
 
//  Recursive Way : 
//  int Knapsack(vector<int> &wt, vector<int> &val, int W, int n) {
//      if(n == 0 || W == 0) return 0;
     
//      if(dp[n][W] != -1) return dp[n][W];
     
//      if(wt[n-1] <= W) {
//          int val1 = Knapsack(wt, val, W - wt[n-1], n-1) + val[n-1];
//          int val2 = Knapsack(wt, val, W, n-1);
//          return max(val1, val2);
//      }
//      else if(wt[n-1] > W) {
//          return Knapsack(wt, val, W, n-1);
//      }
//  }  

// DP (Memoiazation) : 
//  int Knapsack(vector<int> &wt, vector<int> &val, int W, int n,vector<vector<int>> &dp) {
//      if(n == 0 || W == 0) return 0;
     
//      if(dp[n][W] != -1) return dp[n][W];
     
//      else {
//          if(wt[n-1] <= W) {
        
//          return dp[n][W] = max(Knapsack(wt, val, W - wt[n-1], n-1) + val[n-1], Knapsack(wt, val, W, n-1));
//          }
//          else if(wt[n-1] > W) {
//              return dp[n][W] = Knapsack(wt, val, W, n-1);
//          }
//      }
     
//  }  

private : 
 int Knapsack(vector<int> &wt, vector<int> &val, int W, int n,vector<vector<int>> &dp) {
     if(n == 0 || W == 0) return 0;
     
     if(dp[n][W] != -1) return dp[n][W];
     
     else {
         if(wt[n-1] <= W) {
              dp[n][W] = max(Knapsack(wt, val, W - wt[n-1], n-1, dp) + val[n-1], Knapsack(wt, val, W, n-1, dp));
         }
         else if(wt[n-1] > W) {
              dp[n][W] = Knapsack(wt, val, W, n-1, dp);
         }
         return dp[n][W];
     }
 }  



    
 public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        // code here
        // int n = wt.size();
        // int maxi = 0;
        // vector<pair<int, int>> arr;
        // for(int i = 0; i<n; i++) arr.push_back({wt[i], val[i]});
        // sort(arr.begin(), arr.end());
        
        // for(int i = 0; i<n; i++) {
        //     int sum = 0, wei = 0;
        //     bool check = false;
        //     for(int j = i; j<n; j++) {
        //         wei += arr[j].first;
        //         if(wei <= W) {
        //             sum += arr[j].second;
        //             check = true;
        //         }
        //         else break;
        //     }
        //     if(!check) break;
        //     maxi = max(maxi, sum);
        // }
        // return maxi;
        
        int n = wt.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        return Knapsack(wt, val, W, n, dp);
        
    }
};
