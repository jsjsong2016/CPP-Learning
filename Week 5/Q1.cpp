#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class MyString{
	public:
		char* p;
		MyString(){
			p=NULL;
		}
		MyString(char *t){
			p=new char[strlen(t)+1];
			strcpy(p,t);
		}
		MyString(const MyString& s){
			p=new char[strlen(s.p)+1];
			strcpy(p,s.p);
		}
		~MyString(){
			if(p) delete[]p;
		}
		MyString operator+(const MyString &s){
			char*q;
			q=new char[strlen(p)+strlen(s.p)+1];
			strcpy(q,p);strcat(q,s.p);MyString temp(q);
			delete []q;
			return temp;
		}
		MyString operator+(const char*s){
			char*q;
			q=new char[strlen(p)+strlen(s)+1];
			strcpy(q,p);strcat(q,s);MyString temp(q);
			delete []q;
			return temp;
		}
		MyString& operator=(const MyString &s){
			if(p!=NULL){
				delete[]p;
			}
			p=new char[strlen(s.p)+1];
			strcpy(p,s.p);
			return *this;
		}
		char& operator[](int n){
			return p[n];
		}
		MyString& operator+=(char* s){
			char* q;
			q=new char[strlen(p)+1];
			strcpy(q,p);
			if(p!=NULL){
				delete []p;
			}
			p=new char[strlen(p)+strlen(s)+1];
			strcpy(p,q);strcat(p,s);
			delete []q;
			return* this;
		}
		MyString operator()(int i,int n){
			char* q;
			q=new char[n+1];
			strncpy(q,p+i,n);
			q[n]='\0';
			MyString temp(q);
			delete []q;
			return temp;
		}
		ostream &operator<<(ostream &o, const MyString& s){
			o<<s.p;
			return o;
		}
		MyString operator+(char*s, const MyString &t){
			char q[100];
			strcpy(q,s); strcat(q,t.p);
			return MyString(q);
		}
		int operator<(const MyString& s1, const MyString& s2){
			if(strcmp(s1.p,s2.p)<0){return 1;}
			else {return 0;}
		}
		int operator==(const MyString &s1,const MyString &s2){
			if(!strcmp(s1.p,s2.p)){return 1;}
			else {return 0;}
		}
		int operator>(const MyString &s1,const MyString &s2){
			if(strcmp(s1.p,s2.p)>0){return 1;}
			else {return 0;}
		}
};
int CompareString( const void * e1, const void * e2) {
    MyString * s1 = (MyString * ) e1;
    MyString * s2 = (MyString * ) e2;
    if( *s1 < *s2 )     return -1;
    else if( *s1 == *s2 ) return 0;
    else if( *s1 > *s2 ) return 1;
}
int main() {
    MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
    MyString SArray[4] = {"big","me","about","take"};
    cout << "1. " << s1 << s2 << s3<< s4<< endl;
    s4 = s3;    s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1;    s1 = "ijkl-";
    s1[2] = 'A' ;
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray,4,sizeof(MyString), CompareString);
    for( int i = 0;i < 4;++i )
        cout << SArray[i] << endl;
    //输出s1从下标0开始长度为4的子串
    cout << s1(0,4) << endl;
    //输出s1从下标为5开始长度为10的子串
    cout << s1(5,10) << endl;
    return 0;
}
