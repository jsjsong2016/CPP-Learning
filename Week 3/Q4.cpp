#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
class War{
	public:
		int Ndragon,Nninja,Niceman,Nlion,Nwolf;	
		void RAdd(int i){
		if(i==0){
		Niceman++;
		Life-=Kiceman;}
		if(i==1){
		Nlion++;
		Life-=Klion;}
		if(i==2){
		Nwolf++;
		Life-=Kwolf;}
		if(i==3){
		Nninja++;
		Life-=Kninja;}
		if(i==4){
		Ndragon++;
		Life-=Kdragon;}}
		void BAdd(int i){
		if(i==0){
		Nlion++;
		Life-=Klion;}
		if(i==1){
		Ndragon++;
		Life-=Kdragon;}
		if(i==2){
		Nninja++;
		Life-=Kninja;}
		if(i==3){
		Niceman++;
		Life-=Kiceman;}
		if(i==4){
		Nwolf++;
		Life-=Kwolf;}}
		int Life,Index;
		static int Case;
};
int main{
	cin>>Case;
	cin>>Life;
	if(int(Life)~=Life | Life==0 | Life>10000){return 0;}
	cin>>Kdragon>>Kninja>>Kiceman>>Klion>>Kwolf;	
	War Red,Blue;
	clock_t start,finish;
	start=clock();	
	for (int i=0;(double totaltime=(double)(finish-start)/CLOCKS_PER_SEC == int(totaltime) & (Red.Life>0 | Blue.Life>0));i++){
		finish=clock();
		Red.RAdd(i);
		Blue.BAdd(i);
		start=clock();
	}
    return 0;
}
