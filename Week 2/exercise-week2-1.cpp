#include "iostream"
#include "stdio.h"
#include "string.h"
using namespace std;
class Student{
  int  Age,Gr1,Gr2,Gr3,Gr4;
  int  Avg;
  char Name[10],K,ID[10];
public:
  void Input(){
    cin.getline(Name,100,',');
    cin>>Age;
    K=getchar();
    cin.getline(ID,100,',');
    cin>>Gr1>>K>>Gr2>>K>>Gr3>>K>>Gr4;
  }
  void CalAvg(){
    Avg=((Gr1+Gr2+Gr3+Gr4)>>2);
  }
  void Output(){
    cout<<Name<<K<<Age<<K<<ID<<K<<Avg;  
    }  
};  
int main(){  
    Student s;  
    s.Input();  
    s.CalAvg();  
    s.Output();  
}  
