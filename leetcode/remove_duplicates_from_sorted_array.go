//  Difficulty: Easy
// Runtime: Beats 57.64% of users with Go
// Memory:  Beats 79.01% of users with Go

func removeDuplicates(nums []int) int {
	lastAddexIndex := 0

	currentElement := nums[0]
	for i := 1; i < len(nums); i++ {
		if nums[i] != currentElement {
			nums[lastAddexIndex+1] = nums[i]
			lastAddexIndex++
			currentElement = nums[i]
		}
	}

	return lastAddexIndex + 1
}