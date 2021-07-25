#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

template<typename T>
struct ListNode {
	ListNode(): value(0), next(nullptr) {}
	ListNode(const T &v): value(v), next(nullptr) {}
  T value;
  ListNode *next;
};

int main()
{
	ListNode<int> *p = new ListNode<int>[5];
	cout << p->value << endl;
	for (int i = 0; i < 4; i++) {
		p[i].next = &p[i+1];
	}
	
	// if (p[4].next->value) {
		// cout << "this should cause error"; // Unauthorized access error.
	// }
	// But what if we make it an and statement and check if p[4].next is not nullptr first?
	
	if (p[4].next and p[4].next->value) {
		cout<< "error?"; // NO, instead program execution skips to after this if statement once first statement is evaluated as false.
	} // VERY GOOD TO KNOW
	
	// Now how about adding an or statement?
	if ((p[4].next and p[4].next->value) or (p[4].next and p[4].next->value)) {
		cout<< "error?" << endl; 
	}
	// The or statement must be evaluated, as one can logically deduce.
	// Rules: Evaluate both sides of or, evaluate left of && first, and if false=>break.
	
	// This just allocates memory, ints will be unitialized.
	int *a = new int[5];
	cout << a[4] << endl;
	
	// So I haven't yet called delete in this example, which is bad. HOWEVER, OS will eventually
	// free memory that I dynamically allocated once the process exits. And since this isn't
	// an application that I keep running (I run once and then it terminates), it's not
	// a huge deal. But, I will include it below for future reference.
	
	// If you dynamically allocate memory to a pointer with "new", but then fail to call
	// delete before the pointer goes out of scope, the memory will not deallocate,
	// and you have secured memory leakage.
	
	delete p;
	p = nullptr;
	delete a;
	a = nullptr;
	return 0;
}
/* So delete doesn't delete pointer, it deallocates or "frees" the memory
 * pointed to by the pointer.*/

/* From Microsoft docs:
"No explicit per-element initialization can be done when allocating arrays
* using the new operator; only the default constructor, if present, is called."
* So that answers one of my early questions.*/
