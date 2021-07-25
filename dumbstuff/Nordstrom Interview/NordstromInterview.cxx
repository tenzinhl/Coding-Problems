#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Swaps first and last character of given string.
void swapFrontBack(string &s) {
  swap(s[0], s[s.length()-1]);
}

// Return the number of words in a line given the length
// of the line by counting the number of spaces + 1;
int countWords(string line, int lineLength) {
  int words = 1;
  for (int i = 0; i < lineLength; i++) {
    if (line[i] == ' ') {
      words += 1;
    }
  }
  return words;
}

// I'm super unfamiliar with getting input without knowing how
// many words there are, so apologies in advance for the super
// wonky code.

// Program entry point. Given lines of words, returns the lines
// but where each word has had its first and last characters
// swapped.
int main() {
  string line;
  while (getline(cin, line)) {
    stringstream ss;
    ss.str(line);
   
    int lineLength = sizeof(line)/sizeof(line[0]);
    int words = countWords(line, lineLength);

    // For each word, swap the first and last characters (the numbers)
    for (int i = 0; i < words; i++) {
      string curWord;
      ss >> curWord;
      swapFrontBack(curWord);
      cout << curWord << " ";
    }
    
    // print a new line for next line (in case of multi-line input)
    cout << "\n";
  }
  
  return 0;
}
