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

ListNode<int> * removeKFromList(ListNode<int> * l, int k) {
  if (l == nullptr) {
      return l;
  }
	ListNode<int>* begin = l;
	while (begin->value == k) {
		begin = begin->next;
		if (begin == nullptr) {
			return nullptr;
		}
	}
	ListNode<int>* start = begin;
	ListNode<int>* cur = begin->next;
	while (cur != nullptr) {
		if (cur -> value != k) {
			start = cur;
			cur = cur -> next;
			continue;
		} else {
			while (cur -> value == k) {
				cur = cur -> next;
				if (cur == nullptr) {
					start->next = nullptr;
					return begin;
				}
			}
			start->next = cur;
			start = cur;
			cur = cur->next;
		}
	}
	return begin;
}
/* So current idea is to send out a little shooter each time we encounter
 * a node with value == k. We save a pointer to the "beginning" node, (the non-k one)
 *  and shoot the "shooter". The "shooter" pointer keeps moving forward until
 * it encounters either a non-k-value node or a nullptr (i.e.: the end of 
 * the line). We then link the beginning to either the nullptr or the next
 * non-k node.
 * 
 * I've barely used pointers before this so this is some good practice. As
 * a reminder:
 * given this: listNode*<int> node;
 * Arrow operator is equivalent to dereferencing pointer, then using dot operator.
 * So "node->value" is equivalent to "(*node).value" 
 * The parantheses are required in the second form because without them the
 * dereference operator "*" would dereference node.value, and not node. For
 * this reason I find the arrow operator "->" both to be easier to type and
 * look at.*/
int main()
{
	return 0;
}

/* Takeaways: Looking at someone else's solution (which is much cleaner than mine)
 * nullptr can be used as a boolean statement and is equivalent to false, seems like
 * any non nullptr pointers are equivalent to true. Some nice syntactic sugar there.
 * 
 * Wait.. I'm surprised they were able to have this logic line:
 * 	while(p->next && p->next->value == k)
 * because if p->next is nullptr, wouldn't p->next->nullptr cause a RE? since
 * that suggests dereferencing a nullptr. Does the program not check the next
 * argument after p->next returns false? This requires investigation.*/

/* YOOOO. 
"When calling a function with a function parameter, the value passed must be a pointer
to a function. Use the function's name (without parens) for this" 
* 
* This helps me partially understand why sometimes you give templates just the function
* name and other times you have to add parentheses. All variable names ARE POINTERS IN 
* A WAY (or references, it's hard to say). Actually probably references, since they
* store the address of whatever they are tied to. THATS DANK.*/
