//  Difficulty: Easy
// Runtime: Beats 100% of users with Go
// Memory:  Beats 8.63% of users with Go

import (
	"strings"
)

func strStr(haystack string, needle string) int {
	firstOccurrence := -1
	needleLength := len(needle)

	for i := 0; i < len(haystack); i++ {
		// We need to leave, can't happen anymore
		if i+len(needle) > len(haystack) {
			return firstOccurrence
		}

		if strings.EqualFold(haystack[i:i+needleLength], needle) {
			return i
		}
	}

	return firstOccurrence
}