#include <iostream>
#include <set>
#include <string>
using namespace std;

typedef multiset<int> MS;

int main()
{
    MS ms;
    set<int> s;
    int n, num;
    string str;
    cin >> n;
    while (n--)
    {
        cin >> str;
        if (str == "add")
        {
            cin >> num;
            s.insert(num);
            ms.insert(num);
            cout << ms.count(num) << endl;
        }
        else if (str == "ask")
        {
            cin >> num;
            if (s.count(num))
                cout << "1" << " ";
            else
                cout << "0" << " ";
            cout << ms.count(num) << endl;
        }
        else if (str == "del")
        {
            cin >> num;
            cout << ms.count(num) << endl;
            ms.erase(num);
        }
    }

    return 0;
}
