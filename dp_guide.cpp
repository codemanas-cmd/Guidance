#include "bits/stdc++.h"
using namespace std;

// When can DP be used:
// - To find the number of ways to form a sum (e.g., the coin change problem).
//   Example: Count the number of ways to form a sum of 5 using coins {1, 2, 5}.
// - To count the number of ways to reach a point in a grid.
//   Example: Count the number of unique paths from the top-left to the bottom-right in a grid.
// - Whenever you have to make choices to minimize or maximize a quantity.
//   Example: Find the minimum cost path in a weighted grid.
// - When a greedy approach doesn't work and brute force or recursion is inefficient.

// How to approach a DP problem:
/*
1) Think about the state:
   -> Consider the constraints; they help you define (or reject) a state.
      Example: In a grid of size 100x100, you may safely use a 2D array dp[101][101].
   -> Always describe your state in words; this clarifies the base case and where your final answer will be.
      For example:
         - dp[i][j]: Minimum cost to reach the cell (i, j) in a grid.
         - dp[i][j]: Minimum time required to schedule i public and j private jobs.
         - dp[i]: Number of ways to form a sum i using a set of coins.

2) Break down the state into smaller states:
   -> Identify the state transitions.
      Example (Grid Problem):
         To reach cell (i, j), you might come from:
           - The cell above (i-1, j), or
           - The cell to the left (i, j-1).
         Thus, if you’re counting paths:
           dp[i][j] = dp[i-1][j] + dp[i][j-1];
         Or, if you’re minimizing cost:
           dp[i][j] = cost[i][j] + min(dp[i-1][j], dp[i][j-1]);
      
      Example (Scheduling Problem):
         Suppose scheduling the i-th public job takes timePublic[i] and
         the j-th private job takes timePrivate[j]:
           dp[i][j] = min(dp[i-1][j] + timePublic[i], dp[i][j-1] + timePrivate[j]);

3) Assume you already know the answers for those smaller states:
   -> Use those answers to derive dp[i][j].
      Example:
         In the grid problem, if dp[i-1][j] and dp[i][j-1] are computed, then:
           dp[i][j] = cost[i][j] + min(dp[i-1][j], dp[i][j-1]);

4) Combine transition contributions appropriately:
   -> If counting ways, sum the values from previous states.
      Example (Coin Change):
         For each coin, update dp[i] as:
           dp[i] += dp[i - coin];
   -> If optimizing (minimizing or maximizing), choose the optimal value.

5) Consider alternate state definitions if needed:
   -> Sometimes the initial state doesn’t capture all constraints.
      Example: In problems where you can only visit a cell once, you might need a state like dp[i][j][mask],
      where mask represents visited cells or other conditions.

6) Identify the base cases:
   -> Base cases serve as the foundation for your DP.
      Example (Grid Problem):
         dp[0][0] = cost[0][0];
         For the first row: dp[0][j] = dp[0][j-1] + cost[0][j];
         For the first column: dp[i][0] = dp[i-1][0] + cost[i][0];
      Example (Coin Change):
         dp[0] = 1 (There is one way to form the sum 0: by choosing no coins.)

7) Determine where the final answer resides:
   -> The final result is typically stored in dp[n] or dp[n][m], depending on your state.
      Example:
         For a grid problem with n rows and m columns, the answer is at dp[n-1][m-1].
         For scheduling problems with n public and m private jobs, the answer is at dp[n][m].

8) Order your iterations or recursion based on state dependencies:
   -> Ensure that when calculating dp[i][j], the states it depends on are already computed.
      Example:
         For dp[i][j] = dp[i-1][j] + dp[i][j-1], iterate i from 0 to n-1 and j from 0 to m-1.
*/

// -----------------------------------------------
// Example 1: Unique Paths in a Grid
// Count the number of unique paths from the top-left to the bottom-right in a 3x3 grid.
void uniquePathsExample() {
    int n = 3, m = 3; // Define grid dimensions (3 rows x 3 columns)
    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    // Base case: Starting point has 1 way to be reached.
    dp[0][0] = 1;
    
    // Initialize first column (only one way to reach cells in the first column: by moving down)
    for (int i = 1; i < n; ++i)
        dp[i][0] = 1;
    
    // Initialize first row (only one way to reach cells in the first row: by moving right)
    for (int j = 1; j < m; ++j)
        dp[0][j] = 1;
    
    // Fill in the DP table for the rest of the grid
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            // The cell (i, j) can be reached either from the top or left.
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    cout << "Number of unique paths in a 3x3 grid: " << dp[n-1][m-1] << "\n"; // Expected output: 6
}

// -----------------------------------------------
// Example 2: Coin Change Problem
// Count the number of ways to form the sum of 5 using coins {1, 2, 5}.
void coinChangeExample() {
    int target = 5;
    vector<int> coins = {1, 2, 5};
    vector<int> dp(target + 1, 0);
    
    // Base case: There is one way to form the sum 0 (using no coins)
    dp[0] = 1;
    
    // Process each coin and update the dp table accordingly
    for (int coin : coins) {
        for (int i = coin; i <= target; ++i) {
            dp[i] += dp[i - coin];
        }
    }
    
    cout << "Number of ways to form sum 5: " << dp[target] << "\n"; // Expected output: 4
}

int main() {
    uniquePathsExample();
    coinChangeExample();
    return 0;
}
