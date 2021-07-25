#include <bits/stdc++.h>
using namespace std;
#define ll long long

ifstream stin;
ofstream stout;
string INPUT_FILE = "input.txt";

int main()
{
	stin.open(INPUT_FILE);
	long long lnNumber = 0;
	cout << "(# of vals at start of test case, Which test case are you looking for)\n";
	long long a;
	int target;
	cin >> a;
	cin >> target;
	string curLine;
	int valCnt = 0;
	int caseNo = 0;
	
	int temp;
	istringstream iss;
	while (caseNo != target) {
		lnNumber += 1;
		getline(stin, curLine);
		iss.str(curLine);
		iss.clear(); // this was the key. EOF bit stays true otherwise.
		while (!iss.eof()) {
			iss >> temp;
			valCnt += 1;
		}
		if (valCnt == a) {
			caseNo += 1;
		}
		valCnt = 0;
	}
	
	cout << "\nTest case found at: " << lnNumber;
	return 0;
}

