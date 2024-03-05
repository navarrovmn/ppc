//  Difficulty: Easy
// Runtime: Beats 62.29% of users with Go
// Memory:  Beats 20.9% of users with Go

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getLowest(l1 *ListNode, l2 *ListNode) (responseNode *ListNode, picked int) {
	if l1 == nil && l2 == nil {
		return nil, 0
	}

	responseNode = &ListNode{}
	picked = 0

	if l1 == nil {
		responseNode.Val = l2.Val
		picked = 1
		return
	}
	if l2 == nil {
		responseNode.Val = l1.Val
		picked = 0
		return
	}

	if l1.Val <= l2.Val {
		responseNode.Val = l1.Val
		picked = 0
	} else {
		responseNode.Val = l2.Val
		picked = 1
	}

	return
}

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	var mergedList, tmpMergedList *ListNode

	for {
		if list1 == nil && list2 == nil {
			return mergedList
		}

		node, pickedNumber := getLowest(list1, list2)
		if tmpMergedList == nil {
			mergedList = node
			tmpMergedList = node
		} else {
			tmpMergedList.Next = node
			tmpMergedList = tmpMergedList.Next
		}

		if pickedNumber == 0 {
			list1 = list1.Next
		} else {
			list2 = list2.Next
		}
	}
}