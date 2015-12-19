#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> svec;
int getN(string s);
string getStr(string str);
bool isInt(string str);
int find();
int rfind();
string copy();
string add();
void insert();
void reset();
void print();
void printall();

int main()
{
    int n;
    string str;
    cin >> n;
    while (n--)
    {
        cin >> str;
        svec.push_back(str);
    }

    while (1)
    {
        cin >> str;
        if (str == "over") break;
        if (str == "copy")
            copy();
        else if (str == "add")
            add();
        else if (str == "find")
            find();
        else if (str == "rfind")
            rfind();
        else if (str == "insert")
            insert();
        else if (str == "reset")
            reset();
        else if (str == "print")
            print();
        else if (str == "printall")
            printall();
    }

    return 0;
}

int getN(string s)
{
    if (s == "find")
        return find();
    else if (s == "rfind")
        return rfind();
    else
        return s[0] - '0';
}

string getStr(string str)
{
    if (str == "add")
        return add();
    else if (str == "copy")
        return copy();
    else
        return str;
}

int find()
{
    string s,str;
    cin >> s;
    s = getStr(s);
    int n;
    cin >> str;
    n = getN(str);
    if (svec[n-1].find(s) == string::npos)
        return svec[n-1].size();
    return svec[n-1].find(s);
}

int rfind()
{
    string s, str;
    cin >> s;
    s = getStr(s);
    int n;
    cin >> str;
    n = getN(str);
    if (svec[n-1].rfind(s) == string::npos)
        return svec[n-1].size();
    return svec[n-1].rfind(s);
}

string copy()
{
    int N[3];
    string str;
    for (int i = 0; i < 3; i++)
    {
        cin >> str;
        N[i] = getN(str);
    }
    return svec[N[0]-1].substr(N[1], N[2]);
}

bool isInt(string str)
{
    if (str.size() > 5)
        return false;
    for (int i = 0; i < str.size(); i++)
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return false;
    }
    return true;
}

string add()
{
    string str, s[2];
    for (int i = 0; i < 2; i++)
    {
        cin >> s[i];
        s[i] = getStr(s[i]);
    }
    if (isInt(s[1]) && isInt(s[0]))
    {
        int a = int(s[0].c_str());
        int b = int(s[1].c_str());
        int c = a + b;
        stringstream ss;
        ss << c;
        ss >> str;
        return str;
    }
    return s[0] + s[1];
}

void insert()
{
    string s;
    cin >> s;
    s = getStr(s);

    int n, x;
    string temp;
    cin >> temp;
    n = getN(temp);
    cin >> temp;
    x = getN(temp);
    svec[n-1].insert(x, s);
}

void reset()
{
    string s, str;
    cin >> s;
    s = getStr(s);

    int n;
    cin >> str;
    n = getN(str);

    svec[n-1].assign(s);
}

void print()
{
    string s;
    int n;
    cin >> s;
    n = getN(s);
    cout << svec[n-1] << endl;
}

void printall()
{
    for (int i = 0; i < svec.size(); i++)
        cout << svec[i] << endl;
}
