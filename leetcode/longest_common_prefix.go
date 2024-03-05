//  Difficulty: Easy
// Runtime: Beats 71.37% of users with Go
// Memory:  Beats 78.46% of users with Go

func longestCommonPrefix(strs []string) string {
	lastPrefixIndex := 0
	cursor := 0
	currentChar := ""

	// This loop will only stop after we find a different char or we end one string
	for {
		for _, str := range strs {
			currentLen := len(str)

			// If we're going to get an out of bounds, its over
			if cursor >= currentLen {
				return strs[0][0:lastPrefixIndex]
			}
			// Start character
			if currentChar == "" {
				currentChar = string(str[cursor])
			}
			if string(str[cursor]) != currentChar {
				return strs[0][0:lastPrefixIndex]
			}
		}

		currentChar = ""
		lastPrefixIndex++
		cursor++
	}
}