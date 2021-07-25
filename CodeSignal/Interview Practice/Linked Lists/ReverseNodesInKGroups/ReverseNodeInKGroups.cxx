#include <iostream>
using namespace std;
// Singly-linked lists are already defined with this interface:
template<typename T>
struct ListNode {
  ListNode(const T &v) : value(v), next(nullptr) {}
  T value;
  ListNode *next;
};

// Prints a list until the end given a pointer to the start. For debugging.
void printList(ListNode<int>* head) {
  while (head) {
    cout << head->value;
    head = head->next;
  }
  cout << endl;
  return;
}
// Reverse a group and return a pointer to its last element (not sure if it should be first or last)
// I think you might need both. In which case you can return a pair of pointers, one to the first element
// and one to the last.
pair<ListNode<int>*, ListNode<int>*> reverseGroup(ListNode<int> *head, int k) {
	int counter = 1;
	ListNode<int> *beginning = head;
	ListNode<int> *prev = nullptr;
	ListNode<int> *next = nullptr;
	while (counter <= k) {
		next = head -> next;
		head -> next = prev;
		prev = head;
		head = next;
		counter += 1;
	}
	return make_pair(prev, beginning);
}

// Return linked List reversed in groups, k is size of group, l is pointer to list.
ListNode<int> * reverseNodesInKGroups(ListNode<int> * l, int k) {
	pair<ListNode<int>*, ListNode<int>*> pointerPair;
	ListNode<int> dummy(0); // Dummy node to keep track of head
	int counter = 0;
	ListNode<int> *begin = &dummy;
	begin->next = l;
	ListNode<int> *head = l;
	while (head) {
		counter += 1;
    // cout << "head: " << head->value << endl;
		if (counter == k) {
			ListNode<int> *next = head->next;
			pointerPair = reverseGroup(begin->next, k);
			begin->next = pointerPair.first;
			(pointerPair.second)->next = next;
			head = next;
      // cout << "PointerPair.second: " << pointerPair.second->value << endl;
      // cout << "next->value: " << next->value << endl; LOL I think MY DEBUGGING LINE WAS CaUSING ERROR IT WAS OMFG
			begin = pointerPair.second;
			counter = 0;
		} else {
      head = head->next;
    }
    // printList(dummy.next);
	}
	return dummy.next;
}

/* FACEPALM. When the if statement ran I was setting the head then incrementing it
   outside the if statement... sigh. Have to make sure to use ELSE in the future. 
   
   OMG, I tried submitting today and I got "Output Limit Exceeded", AND GUESS WHAT,
   THAT WAS ALSO CAUSE OF THE FRIKKING DEBUG STATEMENTS, GODDAMN. So I commented them out
   and the solution passed lol.*/

// begin->next would be nullptr. I'm dumb passing that to reverseGroup().
int main() {
	return 0;
}

/* So the code above passes all of the sample test cases. And I worked hard on it
 * and am fairly certain that it will pass. So I'm proud of myself, greatjob!
 * Key takeaways: 
 * -Don't get hung up on how long it'll take to type something, if you think it 
 *  works, just implement it (I didn't want to type pair<two pointers to ListNodes> lol)
 * -To use pair you need to include <utility>
 * -Careful with debugging lines, sometimes they can be the cause of OOB error,
 *  especially when trying to peek at values pointed to by pointers (as the value
 *  you're checking may be nullptr, in which case debug statement will cause crash)*/
