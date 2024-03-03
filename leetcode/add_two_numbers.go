// Difficulty: Medium

import (
	"fmt"
)

func safeGet(l *ListNode) int {
	if l == nil {
		return 0
	}

	return l.Val
}

func safeGetNext(l *ListNode) *ListNode {
	if l == nil {
		return nil
	}

	return l.Next
}

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var tempL1, tempL2 = l1, l2
	var result = &ListNode{}
	tmpNode := result
	var carryOn = 0

	for {
		currentSum := safeGet(tempL1) + safeGet(tempL2) + carryOn
		carryOn = 0
		currentDigit := currentSum % 10
		tmpNode.Val = currentDigit

		if currentSum >= 10 {
			carryOn = 1
		}

		tempL1 = safeGetNext(tempL1)
		tempL2 = safeGetNext(tempL2)
		if tempL1 == nil && tempL2 == nil && carryOn == 0 {
			break
		}

		tmpNode.Next = &ListNode{}
		tmpNode = tmpNode.Next
	}

	return result
}