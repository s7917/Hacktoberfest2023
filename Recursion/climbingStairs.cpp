/* LEETCODE PROBLEM STATEMENT: CLIMBING STAIRS

You are climbing a staircase. It takes n steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example:
Input: n = 4
Output: 5

Explanation: There are five distinct ways to climb the stairs:

1 -> 1 -> 1 -> 1
1 -> 1 -> 2
1 -> 2 -> 1
2 -> 1 -> 1
2 -> 2


*/

// ANSWER

#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> memo;

int climbStairs(int n) {
    // Check if the result is already memoized
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }
    
    // Base cases
    if (n == 0) return 1;
    if (n < 0) return 0;

    // Recursively compute the number of ways to climb the stairs
    int ways = climbStairs(n - 1) + climbStairs(n - 2);

    // Memoize the result
    memo[n] = ways;

    return ways;
}

int main() {
    int n = 4;
    int ways = climbStairs(n);
    std::cout << "Number of distinct ways to climb " << n << " stairs: " << ways << std::endl;
    return 0;
}


//FULL LEETCODE SOLUTION:
/*
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> memo;

class Solution {
public:
    int climbStairs(int n) {
        // Check if the result is already memoized
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }
    
    // Base cases
    if (n == 0) return 1;
    if (n < 0) return 0;

    // Recursively compute the number of ways to climb the stairs
    int ways = climbStairs(n - 1) + climbStairs(n - 2);

    // Memoize the result
    memo[n] = ways;

    return ways;
    
    }
};
*/

/*

The time and space complexity of the provided recursive solution for the "Climbing Stairs" problem are as follows:

**Time Complexity: O(n)**

The time complexity of this solution is O(n). This is because we calculate the number of ways to climb the stairs for each value from 0 to n once and store the results in the `memo` map. When we calculate the number of ways for a specific value, we look it up in the `memo` map, and if it's not there, we calculate it and store it. Subsequent calls for the same value will be retrieved from the `memo` map, so there are at most n unique calculations.

**Space Complexity: O(n)**

The space complexity is also O(n). This is because of the space required for the `memo` map, which can hold up to n unique values and their corresponding results. Additionally, the recursive call stack can go up to a depth of n, which also contributes to the space complexity. However, in practice, the space used for the call stack is less of a concern, as many modern programming languages and systems can handle deep recursion effectively. The primary space usage comes from the `memo` map.

*/