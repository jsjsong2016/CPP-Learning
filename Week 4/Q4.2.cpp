#include <stdlib.h>
#include <cstring>
#include <iostream>
using namespace std;

class BigInteger{
private:
	char *ptr;
	int length;
public:
	BigInteger(const char *p){
		if (!p){
			length = 0;
			ptr = NULL;
		}
		else{
			length = strlen(p);
			ptr = new char[length];
			memcpy(ptr, p, sizeof(char)*length);
			ptr[length] = '\0';
		}
	}
	BigInteger(int lin = 0) :length(lin){
		if (lin == 0)
			ptr = NULL;
		else
			ptr = new char[length];
	}
	BigInteger & operator=(const BigInteger &b2){
		if (ptr == b2.ptr)
			return *this;
		if (b2.ptr == NULL){
			ptr = NULL;
			length = 0;
			return *this;
		}
		if (length < b2.length){
			if (ptr)
				delete[] ptr;
			ptr = new char[b2.length];//
		}
		length = b2.length;
		memcpy(ptr, b2.ptr, sizeof(char)*length);
		ptr[length] = '\0';

		return *this;
	}
	BigInteger & operator+(BigInteger & b2){
		int p1 = length - 1;
		int p2 = b2.length - 1;
		int lent = p1 >= p2 ? (p1 + 2) : (p2 + 2);
		char *temp = new char[lent];
		temp[lent] = '\0';
		int p3 = lent - 1;
		char carrybit = 0;
		for (; p1 >= 0 && p2 >= 0; p1--, p2--,p3--){
			temp[p3] = ptr[p1] + b2.ptr[p2] - '0'+carrybit;
			if (temp[p3] > '9'){
				temp[p3] -= 10;
				carrybit = 1;
			}
			else
				carrybit = 0;
		}
		if (p1 >= 0){
			for (; p1 >= 0; p1--, p3--){
				temp[p3] = ptr[p1] + carrybit;
				if (temp[p3] > '9'){
					temp[p3] -= 10;
					carrybit = 1;
				}
				else
					carrybit = 0;
			}
		}
		if (p2 >= 0){
			for (; p2 >= 0; p2--, p3--){
				temp[p3] = b2.ptr[p2] + carrybit;
				if (temp[p3] > '9'){
					temp[p3] -= 10;
					carrybit = 1;
				}
				else
					carrybit = 0;
			}
		}
		if (carrybit){
			temp[p3] = '1';
			return BigInteger(temp);
		}
		else{
			char *temp2 = new char[lent - 1];
			memcpy(temp2, &temp[1], sizeof(char)*(lent - 1));
			temp2[lent - 1] = '\0';
			return BigInteger(temp2);
		}
	}
	BigInteger & operator-(BigInteger &b2){

	}
	char * getValue(){
		return ptr;
	}
};



int main(){
	char a[100], b[100];
	char op;
	scanf("%s\n", a);
	scanf("%c\n", &op);
	scanf("%s", b);
	BigInteger A(a);
	BigInteger B(b);
	BigInteger C;
	switch (op){
	case '+':
		C = (A + B); break;
	case '-':
		//C = A - B;
		break;

	}
	//char *p;
	//p = a;
	//printf("a:%s,sizeof(a):%d\nb:%s,sizeof(b):%d\np:%s,sizeof(p):%d\n", a, sizeof(a), b, sizeof(b),p,strlen(p));
	printf("%s", C.getValue());
	return 0;
}
