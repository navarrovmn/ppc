//  Difficulty: Easy
// Runtime: Beats 75.32% of users with Go
// Memory:  Beats 8.15% of users with Go

var openingElementsMap = map[string]bool{
	"(": true,
	"{": true,
	"[": true,
}

var closingMatches = map[string]string{
	")": "(",
	"}": "{",
	"]": "[",
}

func removeLast(s []string) []string {
	s[len(s)-1] = ""
	return s[:len(s)-1]
}

func isValid(s string) bool {
	var openingElements []string

	for _, byteChar := range s {
		char := string(byteChar)

		if _, ok := openingElementsMap[char]; ok {
			openingElements = append(openingElements, char)
		}
		if openingValue, ok := closingMatches[char]; ok {
			if len(openingElements) == 0 || openingElements[len(openingElements)-1] != openingValue {
				return false
			}

			openingElements = removeLast(openingElements)
		}

	}

	if len(openingElements) != 0 {
		return false
	}

	return true

}