#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

int makeAnagram(string a, string b) {
		int *aCnt = new int[26] {}; // So yes, this works to default initialize to 0.
		int *bCnt = new int[26] (); // And this works TOO.
		
		/*
		// int *cCnt = new int[26]; // Without them nothing is initialized.
		// memset(cCnt, 0, sizeof(int) * 26);
		// cout << aCnt[0] << endl;
		// cout << bCnt[0] << endl;
		// cout << cCnt[0] << endl; // Returns junk without memset. ALSO MEMSeT WORKS IWTH POINTERS, JUST WANNA SAY.
		
		// memset(aCnt, 0, sizeof(int) * 26); memset doesn't work with pointers apparently??? No it does. I just fed up big time.
		// memset(bCnt, 0, sizeof(int) * 26);
		
		entire section here was just figuring out how to 0 initialize dynamic arrays. And so here's the simple:
		* new int[26]() works, new int[26]{} works, memset works. Good job. What doesn't work is my brain sometimes.
		*/ 
		for (int i = 0; i < a.size(); i++) {
			aCnt[a[i] - 'a'] += 1;
		}
		for (int i = 0; i < b.size(); i++) {
			bCnt[b[i] - 'a'] += 1;
		}
		
		int ans = 0;
		for (int i = 0; i < 26; i++) {
			ans += abs(aCnt[i] - bCnt[i]);
			// cout << i << ": " << ans << endl;
			// cout << aCnt[i] << " " << bCnt[i] << endl;
		}
		delete aCnt;
		delete bCnt;
		// cout << aCnt[0] << endl; I'm SUCH A DUMBASS, I PUT THE DEBUG LINE AFTER I DELETED THE POINTER GAAWWWDDDDD.
		return ans;
}

int main()
{
	cout << makeAnagram("abcd","bcde");
	return 0;
}

/* OH MY GOD I JUST NEED TO RANT ABOUT HOW MANY MISTAKES I MADE JUST NOW.
 * OKAY SO FIRST OFF, I WAS PUTTING DEBUG LINES AFTER I DELTED THE POINTER
 * THEY REFERENCE SO OF COURSE IT JUST POINTED TO JUNK. THEN AS I WAS TESTING
 * THE DYNAMIC INTIIALZIATION METHODS I DIDN'T EVEN RUN THE FUNCTION THEY WERE
 * IN IN MAIN SO THE PROGRAM JUST EXITED AND RETURNED 0 AND I WAS SO CONFUSED.
 * FINALLY AFTER ALL THIS I REALIZE THE REASON MY ANSWER WAS GARBAGE WAS F'ING
 * BECAUSE I WAS MAKING ANS USING A AND B NOT ACNT AND BCNT GODDAMNINWEITNEWINESG.
 * 
 * ALSO THAT MEANS THAT ENTEIRESDJG FSSKLJFSNGS TIME MEMSET WAS WORKING I WAS
 * JUST RETURNING THE WRONG SHITE USING THE WRONGS IOWTHEWOI;TWN. Okay, rant over.
 * I honestly laughed at how much I F***ed this up hahaah.
 * 
 * THJAT'S NOT THE END OF IT WHILE I WAS POPULATING THE ACNT AND BCNT I WAS USING
 * A TO OPOPULATE BOTH SO THEY ALWAYS HAD THE SAME NUMBERS AHAFSDH;LKJFSHDLKGSDAH.
 * 
 * OMG AND THEN WHEN COMMENTING OUT THE COUT LINES I COMMENTED OUT THE NECESSARY
 * PARTS AND WAS CONFUSED WHY IT WAS RETUNRISNGO;AWDLGNLKASDJHGDAO 0 , i msDF
 * ASCTUALLY FALLISNDGS APAART HAHAHA.A*/
