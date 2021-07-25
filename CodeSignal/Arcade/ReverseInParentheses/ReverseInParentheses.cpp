// Recursively swaps the order of characters inside nested parentheses,
// each call returns the index of it's corresponding closing parens.

// I'm currently creating an infinite loop. How?
void reverseParens(string& inputString, int index) {
  int begin = index;
  while (index < inputString.length() and inputString[index] != ')') {
    if (inputString[index] == '(') {
      reverseParens(inputString, index + 1);
    }
    index++;
  }
  cout << "last index: " << inputString[index];
  int l = begin;
  int r = index - 1;
  while (l < r) {
    while (inputString[l] == '(' or inputString[l] == ')') {
      l++;
    }
    while (inputString[r] == '(' or inputString[r] == ')') {
      r--;
    }
    swap(inputString[l], inputString[r]);
    l++;
    r--;
  }
  return;
}
// How to handle deletion of parens? Maybe set to a null character,
// and then when flipping, just keep moving the right pointer until
// it's not pointing at a null character and flip. Do one last run-through
// at the end to produce the answer with all null characters removed.
std::string reverseInParentheses(std::string inputString) {
  if (inputString.length() == 0) {
    return "";
  }
  int brack = 0;
  for (int i = 0; i < inputString.length(); i++) {
    char cur = inputString[i];
    if (cur == '(') {
      brack += 1;
      if (brack == 1) {
        reverseParens(inputString, i + 1);
      }
    } else if (cur == ')') {
      brack -=1;
    }
  }
  
  string ans = "";
  for (int i = 0; i < inputString.length(); i++) {
    if (inputString[i] != '(' and inputString[i] != ')') {
      ans.push_back(inputString[i]);
    }
  }
  cout << inputString;
  return ans;
}
