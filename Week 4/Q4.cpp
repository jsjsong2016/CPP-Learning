#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class CHugeInt{	
  int MAX,Number;
  CHugeInt(){
  	MAX=100;
  }
  operator+(const CHugeInt & n)const{
  CHugeInt tmp(*this);
  for (int i=0;i<MAX;i++){
  	tmp.Number[i]+=n.Number[i];
  	if(tmp.Number[i]>=10){
  		tmp.Number[i]-=10;
  		tmp.Number[i+1]++;
	  }
  }
  return tmp;
}
const CHugeInt & operator++(){
	*this=(*this)+1;
	return *this;
}
const CHugeInt operator++(int n){
	CHugeInt tmp=*this;
	*this=(*this)+1;
	return tmp;
}
const CHugeInt operator+=(const CHugeInt & n){
	*this=(*this)+n;
	return *this;
}
friend ostream& operator<< (ostream& o,const CHugeInt& n);
friend CHugeInt operator+(int n1, const CHugeInt& n2);
CHugeInt operator+(int n1, const CHugeInt& n2){
	return n2+n1;
}
ostream& operator<<(ostream& o, const CHugeInt& n){
	bool bStart=false;
	for(int i=MAX-1;i>=0;i--){
		if(n.Number[i]){
			bStart=true;
			}
		if(bStart) cout<<n.Number[i]; 
	}
	if(!bStart) cour<<0;
	return o;
} 
};

int main(){
	CHugeInt c1,c2;
	char x;
	cin>>c1;
	cin>>x;
	cin>>c2;
	if (x=='+') cout<<(c1+c2)<<endl;
	return 0;	
}

