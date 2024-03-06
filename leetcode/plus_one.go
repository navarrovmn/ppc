// Dificulty: Easy
// Runtime: Beats 100% of users with Go
// Memory:  Beats 83.38% of users with Go

func plusOne(digits []int) []int {
	sum := digits[len(digits)-1] + 1
	if sum < 10 {
		digits[len(digits)-1] = sum
		return digits
	}

	carryOn := 1
	for i := len(digits) - 1; i >= 0; i-- {
		if digits[i]+carryOn == 10 {
			digits[i] = 0
			carryOn = 1
		} else {
			digits[i] = digits[i] + carryOn
			carryOn = 0
		}
		// Special case for when we need to alocate one more room in the array
		if i == 0 && carryOn == 1 {
			tmp := make([]int, len(digits)+1)
			copy(tmp[1:], digits)
			tmp[0] = 1
			digits = tmp

			return digits
		}

		if carryOn == 0 {
			return digits
		}
	}

	return digits
}