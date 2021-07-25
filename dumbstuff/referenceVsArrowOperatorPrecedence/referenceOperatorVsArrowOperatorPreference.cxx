#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

struct int_ptr {
public:
	int_ptr(int *value = nullptr) : value_(value) {}
	int *value_;
};

int main()
{
	int a = 0;
	int *pa = &a;
	int_ptr *p_struct = new int_ptr(pa);
	// So it is same as dereference operator '*'
	// arrow takes preference, then address of is evaluated.
	if (pa == &(p_struct->value_)) {
		cout << "this worked" << endl;
	}
	
	return 0;
}

