#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

// Singly-linked lists are already defined with this interface:
template<typename T>
struct ListNode {
  ListNode(const T &v) : value(v), next(nullptr) {}
  T value;
  ListNode *next;
};
// Prints a list given a pointer to its first element.
void printList(ListNode<int> *head) {
	cout << "List: [";
	while (head) {
		cout << head -> value << ", ";
		head = head -> next;
	}
	cout << "]" << endl;
	return;
}
// Reverses a list starting from a given pointer, and returns pointer to beginning of new list.
ListNode<int>* reverseList(ListNode<int> *head) {
	ListNode<int> *pre = nullptr; 
	ListNode<int> *next = nullptr;
	while (head) {
		next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}
	return pre;
}

ListNode<int> * addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b) {
	// first we want to reverse the lists
	a = reverseList(a);
	b = reverseList(b);
	cout << "A: ";
	printList(a);
	cout << "B: ";
	printList (b);
	bool overflow = false;
	int sum = 0;
	ListNode<int> dummy(0);
	ListNode<int> *cur = &dummy;
	while (a or b or overflow) {
		// compute sum AND ZERO IT YA DUMBBUTT
		sum = 0;
		if (a) {
			sum += a->value;
		}
		if (b) {
			sum += b->value;
		}
		if (overflow) {
			sum += 1;
			overflow = false;
		}
		if (sum > 9999) {
			overflow = true;
			sum %= 10000;
		}
		// store value by creating new node pointed to by cur->next, and set that new node's value equal to sum.
		cur->next = new ListNode<int>(sum);
		// Move cur pointer to the new node, and move pointers to list a and b forward (if they can).
		cur = cur->next;
		if (a) a = a->next;
		if (b) b = b->next;
	}
	// So at this point we should have our list, but it's in reverse order, and has a dummy node
	// at its beginning. Thankfully, we can just use our reverseList() method again and be fine(?).
	ListNode<int> *ans = reverseList(dummy.next);
	return ans;
};

int main() {
	return 0;
}

/* Okay, so as I expected new not only allocates the memory, but returns
 * a pointer to the beginning of what was allocated. That makes sense.
 * So you can have a nullptr named P, and if you set P equal to new int,
 * new allocates memory for an int, and P is set to the memory address that
 * the new operator returns. Awesome sauce.*/

// I'm so dumb. I forgot to reset sum to 0 in each loop.

// WOOHOO, WE DID IT. Feels good to get better at this linkedlist bs.
