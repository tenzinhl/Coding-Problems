#include <bits/stdc++.h>
using namespace std;

// For regular characters we just match forward,
// returning false as soon as a non-matching pair
// appears.

// A single '.' must always match the next character
// and move forward.

// A regular character + a '*' will match all following
// repetitions or 0 instances of that character. In
// the case where 'a*' is followed by more 'a' then
// it's equivalent to saying any number of 'a's but
// at minimum the following number.

// The most difficult component is doing '.*'
// If it's the final thing in the string then we return
// true.
// If it's in the middle, then brute force brain is telling
// me to just check every next substring for a match.
// I don't think there's any way to optimize that.
// Code-wise recursion would probably help here.
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatchHelper(s, p, 0, 0);
    }
private:
    bool isMatchHelper(const string& s, const string& p, int si, int pi)
    {
        while (si < s.size() && pi < p.size())
        {
            // Special '*' handling
            if (pi + 1 < p.size() && p[pi + 1] == '*' )
            {
                // Handling '.*'
                if (p[pi] == '.')
                {
                    // Glob together strings of ".*"
                    while (pi + 1 < p.size() && p[pi] == '.' && p[pi + 1] == '*')
                    {
                        pi += 2;
                    }
                    // pi is now pointing at next unmatched character
                    // get si to point at next potential beginning of match
                    // (si can point to beyond end which would mean .* matched till end)
                    for (int i = si; i <= s.size(); i++)
                    {
                        // Check all possible next indices
                        if (isMatchHelper(s, p, i, pi))
                        {
                            // One of them worked!
                            return true;
                        }
                    }
                    // None of them worked
                    return false;
                }
                else
                {
                    // Handling for regular characters
                    char c = p[pi];
                    // glob any following "c*"
                    while (pi + 1 < p.size() && p[pi] == c && p[pi + 1] == '*')
                    {
                        pi += 2;
                    }
                    
                    for (int i = si; i <= s.size(); i++)
                    {
                        if (isMatchHelper(s, p, i, pi))
                        {
                            return true;
                        }
                        if (s[i] != c)
                        {
                            break;
                        }
                    }
                }
            }
            else
            {
                // Standard match handling
                if (p[pi] != '.' && p[pi] != s[si])
                {
                    return false;
                }
                else
                {
                    pi++;
                    si++;
                }
            }
        }

        if (si >= s.size())
        {
            // If there are unmatched characters remaining in p the only way for this to work
            // is if those unmatched characters are all '*' versions
            while (pi < p.size())
            {
                if (pi + 1 < p.size() && p[pi + 1] == '*')
                {
                    pi += 2;
                } else {
                    return false;
                }
            }
            // If we reached end of both strings it means we matched everything successfully
            return true;
        } else {
            // Still unmatched characters in the main string.
            return false;
        }
    }
};