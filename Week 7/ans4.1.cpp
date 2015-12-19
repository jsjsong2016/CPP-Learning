#include <iostream>
#include <string>
#include <stdio.h>
#include <stack>
using namespace std;


class MyString{
	string* p_str;
	stack <string> operand_stack;
	int n;
public:
	MyString(int n);
	~MyString();
	bool execute();
	bool iscommand(string &);
	void single_command(string &);
	unsigned int stoi(string &);
	string itos(int);
	string copy(int, int, int);
	string add(string & , string &);
	unsigned int find(string&, int);
	unsigned int rfind(string&, int);
	void insert(string&, int, int);
	void reset(string&, int);
	void print(int);
	void printall();
	bool over();
};
MyString::MyString(int _n): n(_n){
	p_str = new string[n];
	for (int i = 0 ; i < n; ++i){
		cin>>p_str[i];
	}
}

MyString::~MyString(){
	// delete p_str;
}

bool MyString::execute(){
	//éè¿ä»åååæç´¢æä½å½ä»¤çæ¹å¼ï¼å®ææ§è¡å¨é¨commandå½ä»¤çåè½ï¼overå½ä»¤è¿å0ï¼å¶ä½å½ä»¤è¿å1ï¼
	string command;
	getline(cin,command);
	while(command.length() != 0){
		if (command == "over"){
			return false;
		}
		if (command == "printall"){
			printall();
			return true;
		}
		int tmp = command.find_last_of(' ');
		string str = command.substr(tmp + 1);
		if (iscommand(str)){
			single_command(str);
		}
		else{
			operand_stack.push(str);
		}
		if (tmp == -1)
			command.erase(0);
		else
			command.erase(tmp);
		}
	return true;
}

bool MyString::iscommand(string & str){
	if(str == "copy")
		return true;
	if(str == "add")
		return true;
	if(str == "find")
		return true;
	if(str == "rfind")
		return true;
	if(str == "insert")
		return true;
	if(str == "reset")
		return true;
	if(str == "print")
		return true;
	return false;
}

unsigned int MyString:: stoi(string & str){
	//å°æ°å­åstringè½¬æunsigned intå
	unsigned int result = 0;
	for (unsigned int i = 0; i < str.length() ; ++i){
		result = (str[i]-'0') + result * 10;
	}
	return result;
}
string MyString::itos(int n){
	string str;
	if (n == 0)
		return "0\0";
	while(n>0){
		str.insert(str.begin(),n % 10 + '0');
		n /= 10;
	}
	return str;
}


void MyString:: single_command(string & command){
	if (command == "copy"){
		int operand[3];
		for (int i = 0; i < 3; ++i){
			operand[i] =stoi(operand_stack.top());
			operand_stack.pop();
		}
		operand_stack.push(copy(operand[0]-1, operand[1], operand[2]));
		return;
	}
	if (command == "add"){
		string operand[2];
		for (int i = 0; i < 2; ++i){
			operand[i] = operand_stack.top();
			operand_stack.pop();
		}
		operand_stack.push(add(operand[0], operand[1]));
		return;
	}
	if (command == "find"){
		string operand = operand_stack.top();
		operand_stack.pop();
		int id = stoi(operand_stack.top()) - 1;
		operand_stack.pop();
		operand_stack.push(itos(find(operand, id)));
		return;
	}

	if (command == "rfind"){
		string operand = operand_stack.top();
		operand_stack.pop();
		int id = stoi(operand_stack.top()) - 1;
		operand_stack.pop();
		operand_stack.push(itos(rfind(operand, id)));
		return;
	}
	if (command == "insert"){
		string str = operand_stack.top();
		operand_stack.pop();
		int id = stoi(operand_stack.top()) - 1;
		operand_stack.pop();
		int start = stoi(operand_stack.top());
		operand_stack.pop();
		insert(str, id, start);
		return;
	}
	if (command == "reset"){
		string str = operand_stack.top();
		operand_stack.pop();
		int id = stoi(operand_stack.top()) - 1;
		operand_stack.pop();
		reset(str, id);
		return;
	}
	if (command == "print"){
		int id = stoi(operand_stack.top()) - 1;
		operand_stack.pop();
		print(id);
		return;
	}
}


string MyString :: copy(int id, int start, int length){
	return p_str[id].substr(start,length);
}

string MyString::add(string & str1, string & str2){
	if (str1.length() < 6 && str2.length() < 6 ){
		bool operand_is_number = true;
		for(unsigned i = 0; i < str1.length(); ++i){
			if (str1[i] <= '0' && str1[i] >= '9'){
				operand_is_number = false;
				break;
			}
		}
		if (operand_is_number){
			for(unsigned i = 0; i < str2.length(); ++i){
				if (str2[i] >= '0' && str2[i] <= '9'){
					operand_is_number = false;
					break;
				}
			}
		}
		return itos(stoi(str1)+stoi(str2));
	}
	return str1 + str2;
}

unsigned int MyString::find(string & str, int id){
	string::size_type tmp = p_str[id].find(str);
	if (tmp == string::npos){
		return str.length();
	}
	else
		return tmp;
}

unsigned int MyString::rfind(string & str, int id) {
	string tmp1,tmp2;
	for (int j = p_str[id].length()-1; j >= 0; ++j){
		tmp1.push_back(p_str[id][j]);
	}
	for (int j = str.length()-1; j >= 0; ++j){
		tmp2.push_back(str[j]);
	}

	string::size_type tmp = tmp1.find(tmp2);
	if (tmp == string::npos){
		return tmp2.length();
	}
	return tmp1.length() -1-tmp;

}

void MyString::insert(string & str, int id, int start){
	p_str[id].insert(start, str);
}

void MyString :: reset(string & str, int id){
	p_str[id].assign(str);
}

void MyString::print(int n){
	cout<<p_str[n]<<endl;
}

void MyString::printall(){
	for (int i  = 0 ;i < n; ++i){
		cout<<p_str[i]<<endl;
	}
}
int main(){
	int line;
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);

	cin>>line;
	MyString s(line);
	cin.ignore(1000, '\n');
	while(s.execute()){
	}
	return 0;
}
