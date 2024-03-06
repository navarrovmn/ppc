// Difficulty: Easy
// Runtime: Beats 78.41% of users with Go
// Memory:  Beats 8.33% of users with Go

func climbStairs(n int) int {
	ways := make([]int, n+1)
	ways[0] = 1
	ways[1] = 1

	for i := 2; i <= n; i++ {
		ways[i] = ways[i-1] + ways[i-2]
	}

	return ways[n]
}