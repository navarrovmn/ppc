//  Difficulty: Easy
// Runtime: Beats 83.55% of users with Go
// Memory:  Beats 20.96% of users with Go

var algarisms = map[string]int{
	"I": 1,
	"V": 5,
	"X": 10,
	"L": 50,
	"C": 100,
	"D": 500,
	"M": 1000,
}

var subtractions = map[string]int{
	"IV": 4,
	"IX": 9,
	"XL": 40,
	"XC": 90,
	"CD": 400,
	"CM": 900,
}

func romanToInt(s string) int {
	stringLimit := len(s) - 1
	result := 0

	for i := 0; i < len(s); i++ {
		currentChar := string(s[i])

		if (currentChar == "I" || currentChar == "X" || currentChar == "C") && i+1 <= stringLimit {
			value, ok := subtractions[s[i:i+2]]
			if ok {
				result += value
				i += 1
				continue
			}
		}

		result += algarisms[string(s[i])]
	}

	return result
}