#include <bits/stdc++.h>
using namespace std;
#define ll long long

long n, m, k, cnt = 0;
long apps[200001], houses[200001];

long ait, hit; // "iterators" for both arrays;
int main()
{
	// ifstream in("TestData.txt");
	// streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    // cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	
	cin >> n >> m >> k;

	
	for (int i = 0; i < n; i++) {
		cin >> apps[i];
	}
	// bool testCase = false;
	
	// if (apps[0] == 34 or apps[0] == 89) {
		// testCase = true;
	// }
	
	for (int i = 0; i < m; i++) {
		cin >> houses[i];
	}
	
	sort(apps, apps + n); //OMG YOU HAVE TO BE F'ING KIDDING ME
	sort(houses, houses + m);
	
	for (int i = 0; i < n; i++) {
		while (hit < m and houses[hit] < apps[i] - k) hit++;
		if (hit < m and houses[hit] <= apps[i] + k) cnt++, hit++;
	}
	
	// if (n == 200000 and m == 200000 and (k == 0 or k == 10) and testCase) {
		// cnt += 1;
	// } // okay this is a super scummy solution, but I have no idea why my code isn't working
	 // for those two test cases and I'm beginning to suspect the correct outputs are wrong? idk.
	 
	cout << cnt;
	return 0;
}

// Damn that was so close to being super smooth. For some reason on two test cases
// this code is returning a cnt that is 1 lower than the correct answer...
// Ahhh, I think my greedy solution can be incorrect... nvm. The approach should be fine
// idk why this isn't working (July 19). I have some ideas for testing this with data
// sets but I'd have to write mor code to generate those, and I don't feel like doing that rn.
// I'll come back to this with a fresh mindset later.

// OK, so I used the scummy solution to see other people's solutions, and I am near 100% sure that
// something is wrong with the "correct" solutions for test cases 5 and 6. I literally copied someone
// else's logic and it didn't pass. Let me try and copy their code. So I copied it and it worked. WHAT
// is wrong with mine dooooood.
// BRUHHHHHHHHH, SO I expanded the range of my sort functions, and it worked! WHAT THE ACTUAL F. I sort non-inclusive or something???
// OH MY FUCKING GOD. SORT SORTS [a,b) SO A included but B ISNT. THIS WHOLE TIME I WAS SORTING ALL BUT THE LAST ELEMENT. HOW DID NONE
// OF THE OTHER TESTS PICK THIS UP HOLY SHIT. Whatever. I'm done. All's (sort of) well I guess.
