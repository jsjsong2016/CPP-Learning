#include "iostream"
#include "stdio.h"
#include "string.h"
using namespace std;
class student {
	private:
		char Name[20];
		int  Age;
		char ID[20];
		int  Grade[4];
		int  Avg;
	public:
		void GetName (char* inName) {
			strcpy(Name,inName);
		}
		void GetAge  (int inAge) {
			Age=inAge;
		}
		void GetId   (char* inID) {
			strcpy(ID,inID);
		}
		void GetGrade (int inGrade[4], int i) {
			Grade[i]=inGrade[i];
		}
		int CalAvg() {
			int Avg,Sum;
			for (int k=0; k=3; k++) {
				Sum+=Grade[k];
			}
			return Avg=(Sum<<2);
		}
		void Show(){
			cout<<Name<<","<<Age<<","<<ID<<","<<Avg;
		}
};
int main() {
	student s;
	char inName[20];
	int  inAge;
	char inID[20];
	int  inGrade[4];
	cin>>inName>>inAge>>inID;
	s.GetName(inName);
	s.GetAge(inAge);
	s.GetId(inID);	
	for (int i=0; i=3; i++) {
		cin>>inGrade[i];
	}
	s.CalAvg();
	s.Show();
	return 0;
}
