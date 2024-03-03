// Difficulty: Medium

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// Possible optimization: we just need to store the N+1 last members (not the whole list), this will make it a lot more space efficient (from O(sizeOf List)) to O(N)
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	nodeList := make([]*ListNode, 30)
	tmpNode := head
	actualLength := 0

	// Populate all the nodes (very small n of nodes)
	for i := 0; i < 30; i++ {
		if tmpNode == nil {
			break
		}

		actualLength += 1
		nodeList[i] = tmpNode
		tmpNode = tmpNode.Next
	}

	// List is over
	if actualLength == 1 {
		return nil
	}

	indexToRemove := actualLength - n
	// If we are removing the head
	if indexToRemove-1 < 0 {
		return nodeList[indexToRemove+1]
	}

	previousNode := nodeList[indexToRemove-1]
	if (indexToRemove + 1) <= actualLength-1 {
		previousNode.Next = nodeList[indexToRemove+1]
	} else {
		previousNode.Next = nil
	}

	return head
}
