#include <bits/stdc++.h>
using namespace std;
set<string>strings;
void RecPermute(string soFar, string rest)
{
    if (rest == "") // No more characters
        strings.insert(soFar); // Print the word
    else // Still more chars
        // For each remaining char

        for (int i = 0; i < rest.length(); i++) {

            string next = soFar + rest[i]; // Glue next char

            string remaining = rest.substr(0, i)+ rest.substr(i+1);
            RecPermute(next, remaining);
        }

}

void ListPermutations(string s) {
    RecPermute("", s);
}

int main()
{
    ListPermutations("Makka");
    for (auto x:strings) {
        cout<<x<<endl;
    }
    return 0;
}
