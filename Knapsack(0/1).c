#include <stdio.h>


void print(int dp[][51], int n, int W)
{
	int i, j;
	for(i = 0 ; i <= n ; i++)
	{
		for(j = 0 ; j <= W ; j++)
		{
			printf("%d  ",dp[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
// Function to solve the 0/1 Knapsack problem
int knapsack(int values[], int weights[], int W, int n) {
    int dp[n+1][W+1];  //creating 2D array
	
	int i,j;
    for ( i = 0; i <= n; i++) {
        for ( j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;  
            } else if (weights[i-1] <= j) {
                dp[i][j] = (dp[i-1][j] > values[i-1] + dp[i-1][j - weights[i-1]]) 
                            ? dp[i-1][j] 
                            : values[i-1] + dp[i-1][j - weights[i-1]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
        print(dp, n, W);

    return dp[n][W];
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int capacity = 50;
    int n = sizeof(values) / sizeof(values[0]);
	printf("value of n is %d\n",n);
    int max_value = knapsack(values, weights, capacity, n);
    printf("Maximum value in Knapsack = %d\n", max_value);
    
    return 0;
}
