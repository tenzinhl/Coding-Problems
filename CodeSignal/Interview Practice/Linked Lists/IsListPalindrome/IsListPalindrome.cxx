#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

template<typename T>
struct ListNode {
  ListNode(const T &v) : value(v), next(nullptr) {}
  T value;
  ListNode *next;
};


bool isListPalindrome(ListNode<int> * l) {
	if (l == nullptr) {
		return true;
	}
	int n = 1;
	ListNode<int> *cur = l;
	while (cur -> next) {
		n += 1;
		cur = cur->next;
	}
	ListNode<int> *const last = cur; // store the last node for future reference.
	
	int k = 1; // keeps track of the index of which node we are on (1-based indexing)
	cur = l; // bring cur pointer back to beginning
	ListNode<int> *prev = nullptr, *nxt;
	while (k <= n/2) {
		k += 1;
		prev = cur;
		cur = cur->next;
	}
	
	while(cur) {
		nxt = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nxt;
	}
	
	ListNode<int> *begin = l, *end = last;
	for (int i = 0; i < n/2; i++) {
		if (begin->value != end->value) {
			return false;
		}
		begin = begin->next;
		end = end->next;
	}
	return true;
}
// KEY: Set cur3 (nxt) at the beginning of the while loop, to avoid having to check if oob
/* So I think on the first pass we modify the list so that it is inwards-pointing
 * or "imploding" as I want to call it. Actually you need one more pass before that
 * to determine the total list length (and thus determine the halfway point). */
 
 int main() 
 {
	 return 0;
 }
/* HELL YES. LET'S GO. We did it boys. A clever thing I saw someone else do was to get
 * a pointer to the center element (or near center), all you need to do is have a pointer
 * that goes 2 nodes at a time and one that goes 1 node at a time. EZ clap.*/ 
