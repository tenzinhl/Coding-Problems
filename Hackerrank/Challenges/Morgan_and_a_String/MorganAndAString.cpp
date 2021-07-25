#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'morganAndString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

string morganAndString(string a, string b) {
    string ans;
    
    int ai = 0;
    int bi = 0;
    
    while (ai < a.size() && bi < b.size()) {
        if (a[ai] == b[bi]) {
            int tempai = ai;
            int tempbi = bi;
            bool incrementA;
            while (tempai < a.size() && tempbi < b.size() &&
                   a[tempai] == b[tempbi] && a[tempai] <= a[ai]) {
                tempai++;
                tempbi++;
            }
            // Special case for if only one string ended
            // If we didn't hit end of either string
            if (tempai < a.size() && tempbi < b.size()) {
                if (a[tempai] < b[tempbi]) {
                    incrementA = true;
                } else {
                    incrementA = false;
                }
            } else {
                // One or both strings reached end
                // We move forward with string that didn't
                // end as it's the only one that has a chance
                // of having a lower char in its future
                if (tempai < a.size()) {
                    incrementA = true;
                } else {
                    incrementA = false;
                }
            }
            
            if (incrementA) {
                while (ai < tempai) {
                    ans += a[ai];
                    ai++;
                }
            } else {
                while (bi < tempbi) {
                    ans += b[bi];
                    bi++;
                }
            }
        } else if (a[ai] < b[bi]) {
            ans += a[ai];
            ai++;
        } else {
            ans += b[bi];
            bi++;
        }
    }
    while (ai < a.size()) {
        ans += a[ai];
        ai++;
    }
    while (bi < b.size()) {
        ans += b[bi];
        bi++;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = morganAndString(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
