// Difficulty: Easy
// Runtime: Beats 49.41% of users with Go
// Memory:  Beats 62.20% of users with Go

func mySqrt(x int) int {
	currentResult := 1

	for {
		mul := currentResult * currentResult
		if mul == x {
			return currentResult
		}
		if mul > x {
			return currentResult - 1
		}

		currentResult++
	}
}