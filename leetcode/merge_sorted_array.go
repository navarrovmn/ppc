func getMin(x, y int) int {
	if x > y {
		return y
	}

	return x
}

func merge(nums1 []int, m int, nums2 []int, n int) {
	tmp := make([]int, m)
	copy(tmp, nums1)

	idxNums1 := 0
	idxNums2 := 0
	idxFinalArray := 0

	var endedFirstArray, endedSecondArray bool
	for {
		endedFirstArray = idxNums1 >= m
		endedSecondArray = idxNums2 >= n

		if endedFirstArray && endedSecondArray {
			return
		}
		if endedFirstArray {
			nums1[idxFinalArray] = nums2[idxNums2]
			idxNums2++
			idxFinalArray++

			continue
		}
		if endedSecondArray {
			nums1[idxFinalArray] = tmp[idxNums1]
			idxNums1++
			idxFinalArray++

			continue
		}

		value := getMin(tmp[idxNums1], nums2[idxNums2])
		nums1[idxFinalArray] = value
		if tmp[idxNums1] == value {
			idxNums1++
		} else {
			idxNums2++
		}
		idxFinalArray++
	}

}