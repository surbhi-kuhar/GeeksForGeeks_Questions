	int solve(int arr[], int index, int prev, int n)
{
	    if( index >= n) return 0;
	    
	    int include = 0 , exclude = 0 ;
	    
	    if( prev == -1 || arr[index] > arr[prev] ){
	        include = arr[index] + solve(arr, index+1, index, n);
	    }
	    
	    exclude = solve(arr, index+1, prev, n);
	    
	    return max(include,exclude);
	}

int solve(int arr[], int index, int prev, int n, vector<vector<int>>&dp)
{
        
	    if( index >= n) return 0;
	    
	    if(dp[prev+1][index] != -1) return dp[prev+1][index];
	    
	    int include = 0 , exclude = 0 ;
	    
	    if( prev == -1 || arr[index] > arr[prev] ){
	        include = arr[index] + solve(arr, index+1, index, n, dp);
	    }
	    
	    exclude = solve(arr, index+1, prev, n,dp);
	    
	    dp[prev+1][index] = max(include,exclude);
	    
	    return dp[prev+1][index];
	    
}
	
	
int maxSumIS(int arr[], int n)  
{  
	    
	    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	   // return solve(arr,0,-1,n);                            recursive function call
	    
	    return solve(arr,0,-1,n, dp);                          // memoization function call
	    
	   
}  
