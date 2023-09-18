// RECURSION

int solve( int N, int arr[], int i, int j){
        
      if(i==j) return 0;
      
      int ans = INT_MAX;
       
      for(int k = i; k<= j-1; k++){
          int mini = arr[i-1]*arr[k]*arr[j] + solve(N,arr,i,k) + solve(N,arr,k+1,j);
          ans = min(mini,ans);
      }
       
      return ans;
       
}

// RECURSION + MEMOIZATION 
    
int solve( int N, int arr[], int i, int j,vector<vector<int>>&dp){
        
      if(i==j) return 0;
       
      if(dp[i][j] != -1) return dp[i][j];
      
      int ans =  INT_MAX;
      
      for(int k = i; k<= j-1; k++){
          int mini = arr[i-1]*arr[k]*arr[j] + solve(N,arr,i,k,dp) + solve(N,arr,k+1,j,dp);
          ans = min(mini,ans);
          dp[i][j] = ans;
      }
       
      return dp[i][j];
       
}
    
int solve( int N, int arr[],int i, int j){
        
       vector<vector<int>>dp(N+1,vector<int>(N+1,0));
       
       for( int i= 0 ;i<N;i++){
           dp[i][i] = 0;
       }
      
       
      
       for ( int i = N-1 ;i >=1 ;i--){
           for( int j = i+1 ;j<=N-1 ; j++){
               int ans =  INT_MAX;
               for(int k = i; k<= j-1; k++){
                   int mini = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                   ans = min(mini,ans);
                   dp[i][j] = ans;
               }
               
           }
       }
       
       
       return dp[i][j];
       
}
    
int matrixMultiplication(int N, int arr[])
{
        
        vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
        // return solve(N,arr,1,N-1);                                  RECURSIVE FUNCTION CALL
        // return solve(N,arr,1,N-1,dp);                               RECURSION + MEMOIZATION CALL
        return solve(N,arr,1,N-1);                                  // TABULATION CALL
  
}
