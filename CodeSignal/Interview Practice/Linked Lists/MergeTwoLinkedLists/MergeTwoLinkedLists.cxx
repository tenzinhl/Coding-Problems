// Singly-linked lists are already defined with this interface:
template<typename T>
struct ListNode {
  ListNode(const T &v) : value(v), next(nullptr) {}
  T value;
  ListNode *next;
};

// Given two sorted lists, return a pointer to the beginning of a merged and sorted version of both lists
ListNode<int> * mergeTwoLinkedLists(ListNode<int> * l1, ListNode<int> * l2) {
	ListNode<int> dummy(0);
	ListNode<int> *cur = &dummy;
	while (l1 and l2) {
		if (l1->value <= l2->value) {
			cur->next = l1;
			l1 = l1->next;
		} else {
			cur->next = l2;
			l2 = l2->next;
		}
		cur = cur->next;
	}
	if (l1) {
		cur->next = l1;
	}
	if (l2) {
		cur->next = l2;
	}
	return dummy.next;
}

int main()
{
	return 0;
}

/* AHHH I'M GETTING SO GOOD AT THIS. LET'S FRIIKKKKINN GOOOOOOOOO. This went
 * so smoothly.*/
