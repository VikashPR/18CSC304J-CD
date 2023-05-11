#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
string s;
vector<char> st;
vector<char> a;

void StackAndInput(int i)
{
    // print stack and remaining input vector elements
    cout << "$";
    for (auto x : st)
        cout << x;
    cout << "\t";
    for (int j = i; j < n; j++)
        cout << a[j];
    cout << "\t";
}

void check()
{
    // check if there any reduction possible for stack elements
    for (int i = 0; i < st.size(); i++)
    {
        if (st[i] == 'a')
        {
            st[i] = 'E';
            StackAndInput(i + 1);
            cout << "REDUCE E->a\n";
            check(); // we again do checking because here we may need to reduce continuously
        }
        if (i + 2 < st.size() && st[i] == 'E' && (st[i + 1] == ('+') || st[i + 1] == ('*')) && st[i + 2] == 'E')
        {
            st.pop_back();
            st.pop_back();
            StackAndInput(i + 1);
            if (st[i + 1] == '+')
                cout << "REDUCE E->E+E\n";
            else if (st[i + 1] == '*')
                cout << "REDUCE E->E*E\n";
        }
    }
}

int main()
{
    cout << "GRAMMAR is : \n E->E+E \n E->E*E \n E->a\n";
    cout << "Enter input string: ";
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; i++)
        a.push_back(s[i]);

    cout << "\nstack\tinput\taction\n";
    for (int i = 0; i < n; i++)
    {
        st.push_back(a[i]);
        a[i] = ' '; // replace element with space so that it not visible in output
        StackAndInput(i + 1);
        cout << "SHIFT->" << st.back() << "\n";
        check();
    }
    if (st.size() == 1 && st[0] == 'E')
        cout << "\nstring accepted\n";
    else
        cout << "\nstring rejected\n";
}


// Sample Input:
// a+a*a