#include <bits/stdc++.h>
using namespace std;

// Singly-linked lists are already defined with this interface:
template<typename T>
struct ListNode {
  ListNode(const T &v) : value(v), next(nullptr) {}
  T value;
  ListNode *next;
};

void printList(ListNode<int> *head) {
  while (head) {
    cout << head->value << " ";
    head = head-> next;
  }
  cout << endl;
}
ListNode<int> * rearrangeLastN(ListNode<int> * l, int n) {
	ListNode<int> *beginning = l;
	ListNode<int> *head = l;
	int nodeCount = 0;
	while (head) {
		nodeCount += 1;
		head = head->next;
	}
  
  if (n == 0 or n == nodeCount) {
    return l;
  }
  
  ListNode<int> dummy(0);
  dummy.next = l;
	head = &dummy;
	for (int i = 0; i < nodeCount - n; i++) {
		head = head->next;
	}
	ListNode<int> *head2 = head->next;
  ListNode<int> *newBeginning = head2;
	head->next = nullptr;
	while (head2 -> next) {
		head2 = head2->next;
	}
	head2->next = beginning;
  // if (newBeginning) {
  //   cout << "newBeginning is not nullptr ";
  //   cout << newBeginning -> value << endl;
  //   cout << "newBeginning's next: " << newBeginning->next->value << endl;
  //   cout << "printList: ";
  //   printList(newBeginning);
  // }
	return newBeginning;
}

/* LOL. I made a circular linked list that loops on itself somehow.
   So despite wanting to avoid using an if statement to check if n
   was equal to 0 or nodeCount, it seems like that's the only way
   as the two behaviors of linking the last node to the beginning
   and having the end of the first point to nullptr ARE SELECTIVELY
   needed to not happen when it comes to these edge cases. RIP. 
   
   Good job though, got it through pretty easily */
}

int main()
{
	return 0;
}

/* OH DAYUM. So there is a method for solving this problem in one pass, that's
 * really cool. So if you have two pointers, and you send the first one out so
 * that it's n nodes ahead of the second one, when you reach the end of the list
 * you'll have a pointer to where you need it, which you can then use to do the
 * slicing and pasting that you need to do. That's pretty cool. Although I'm don't
 * think it's necessarily that much better than my two pass solution. 
 * 
 * For one, the big-O time complexity is the same (O(N)), and beyond that,
 * in my first pass I'm only moving two pointers whereas this solution requires moving
 * two. In fact, in the end I think the amount of times you need to make a node move
 * ends up being exactly the same lol. */
