#include <iostream>
#include <iomanip>
//#include <string>
using namespace std;

class dragon
{
public:
	dragon(int f_SN,int f_life)//,int f_attack=0
	{
		cout<<"dragon "<<f_SN<<" born with strength "<<f_life<<',';
	}
	
};

class ninja
{
public:
	ninja(int f_SN,int f_life)
	{
		cout<<"ninja "<<f_SN<<" born with strength "<<f_life<<',';
	}
	
};

class iceman
{
public:
	iceman(int f_SN,int f_life)
	{
		cout<<"iceman "<<f_SN<<" born with strength "<<f_life<<',';
	}
	
};

class lion
{
public:
	lion(int f_SN,int f_life)
	{
		cout<<"lion "<<f_SN<<" born with strength "<<f_life<<',';
	}
	
};

class wolf
{
public:
	wolf(int f_SN,int f_life)
	{
		cout<<"wolf "<<f_SN<<" born with strength "<<f_life<<',';
	}
	
};

class red
{
	int dragon_num,ninja_num,iceman_num,lion_num,wolf_num;
	int dragon_life,ninja_life,iceman_life,lion_life,wolf_life;
	int m;
	int SN;
	int state;							
public:
	red(int M,int dragon,int ninja,int iceman,int lion,int wolf)
	{
		SN=0;							//80
		state=0;
		dragon_num=0,ninja_num=0,iceman_num=0,lion_num=0,wolf_num=0;
		m=M;
		dragon_life=dragon;
		ninja_life =ninja;
		iceman_life=iceman;
		lion_life  =lion;
		wolf_life  =wolf;
	}

	int getstate()
	{
		return state;
	}

	void born()
	{
		cout<<"red ";
		switch(state)
		{
			case 0:
                 state++; 
				if(m>=iceman_life)
				{SN++;iceman im(SN,iceman_life);m-=iceman_life;iceman_num++;		//100
				cout<<iceman_num<<" iceman in red headquarter"<<endl;
				break;}
			case 1:
                 state++;
				if(m>=lion_life)
				{SN++;lion li(SN,lion_life);m-=lion_life;lion_num++;
				cout<<lion_num<<" lion in red headquarter"<<endl;
				break;}
			case 2:
                 state++;
				if(m>=wolf_life)
				{SN++;wolf wo(SN,wolf_life);m-=wolf_life;wolf_num++;
				cout<<wolf_num<<" wolf in red headquarter"<<endl;
				break;}
			case 3:
                 state++;
				if(m>=ninja_life)
				{SN++;ninja ni(SN,ninja_life);m-=ninja_life;ninja_num++;
				cout<<ninja_num<<" ninja in red headquarter"<<endl;
				break;}
			case 4:
				if(m>=dragon_life)
				{SN++;dragon dr(SN,dragon_life);m-=dragon_life;dragon_num++;
				cout<<dragon_num<<" dragon in red headquarter"<<endl;
				state=0;break;}
				else 
                {
                     state=0;
                     switch(state)
                		{
                			case 0:
                                 state++; 
                				if(m>=iceman_life)
                				{SN++;iceman im(SN,iceman_life);m-=iceman_life;iceman_num++;		//100
                				cout<<iceman_num<<" iceman in red headquarter"<<endl;
                				break;}
                			case 1:
                                 state++;
                				if(m>=lion_life)
                				{SN++;lion li(SN,lion_life);m-=lion_life;lion_num++;
                				cout<<lion_num<<" lion in red headquarter"<<endl;
                				break;}
                			case 2:
                                 state++;
                				if(m>=wolf_life)
                				{SN++;wolf wo(SN,wolf_life);m-=wolf_life;wolf_num++;
                				cout<<wolf_num<<" wolf in red headquarter"<<endl;
                				break;}
                			case 3:
                                 state++;
                				if(m>=ninja_life)
                				{SN++;ninja ni(SN,ninja_life);m-=ninja_life;ninja_num++;
                				cout<<ninja_num<<" ninja in red headquarter"<<endl;
                				break;}
                			case 4:
                				if(m>=dragon_life)
                				{SN++;dragon dr(SN,dragon_life);m-=dragon_life;dragon_num++;
                				cout<<dragon_num<<" dragon in red headquarter"<<endl;
                				state=0;break;}
                				else {cout<<"headquarter stops making warriors"<<endl;state++;break;}
                			default:break;
                		}
                     }//{cout<<"headquarter stops making warriors";state++;break;}
			default:break;
		}
	}
};

class blue
{
	int dragon_num,ninja_num,iceman_num,lion_num,wolf_num;
	int dragon_life,ninja_life,iceman_life,lion_life,wolf_life;
	int m;
	int SN;
	int state;
public:
	blue(int M,int dragon,int ninja,int iceman,int lion,int wolf)
	{
		SN=0;
		state=0;
		dragon_num=0,ninja_num=0,iceman_num=0,lion_num=0,wolf_num=0;
		m=M;
		dragon_life=dragon;
		ninja_life =ninja;
		iceman_life=iceman;
		lion_life  =lion;
		wolf_life  =wolf;
	}

	int getstate()
	{
		return state;
	}

	void born()
	{
		cout<<"blue ";
		switch(state)
		{
			case 0: 
                 state++;
				if(m>=lion_life)
				{SN++;lion li(SN,lion_life);m-=lion_life;lion_num++;
				cout<<lion_num<<" lion in blue headquarter"<<endl;
				break;}
			case 1:
                 state++;
				if(m>=dragon_life)
				{SN++;dragon dr(SN,dragon_life);m-=dragon_life;dragon_num++;
				cout<<dragon_num<<" dragon in blue headquarter"<<endl;
				break;}
			case 2:
                 state++;
				if(m>=ninja_life)
				{SN++;ninja ni(SN,ninja_life);m-=ninja_life;ninja_num++;
				cout<<ninja_num<<" ninja in blue headquarter"<<endl;
				break;}
			case 3:
                 state++;
				if(m>=iceman_life)
				{SN++;iceman ic(SN,iceman_life);m-=iceman_life;iceman_num++;
				cout<<iceman_num<<" iceman in blue headquarter"<<endl;
				break;}
			case 4:
				if(m>=wolf_life)
				{SN++;wolf wo(SN,wolf_life);m-=wolf_life;wolf_num++;
				cout<<wolf_num<<" wolf in blue headquarter"<<endl;
				state=0;break;}
				else 
                {
                     state=0;
                     switch(state)
                		{
                			case 0:
                                 state++; 
                				if(m>=lion_life)
                				{SN++;lion li(SN,lion_life);m-=lion_life;lion_num++;
                				cout<<lion_num<<" lion in blue headquarter"<<endl;
                				break;}
                			case 1:
                                 state++;
                				if(m>=dragon_life)
                				{SN++;dragon dr(SN,dragon_life);m-=dragon_life;dragon_num++;
                				cout<<dragon_num<<" dragon in blue headquarter"<<endl;
                				break;}
                			case 2:
                                 state++;
                				if(m>=ninja_life)
                				{SN++;ninja ni(SN,ninja_life);m-=ninja_life;ninja_num++;
                				cout<<ninja_num<<" ninja in blue headquarter"<<endl;
                			    break;}
                			case 3:
                                 state++;
                				if(m>=iceman_life)
                				{SN++;iceman ic(SN,iceman_life);m-=iceman_life;iceman_num++;
                				cout<<iceman_num<<" iceman in blue headquarter"<<endl;
                				break;}
                			case 4:
                				if(m>=wolf_life)
                				{SN++;wolf wo(SN,wolf_life);m-=wolf_life;wolf_num++;
                				cout<<wolf_num<<" wolf in blue headquarter"<<endl;
                				state=0;break;}
                				else {cout<<"headquarter stops making warriors"<<endl;state++;break;}
                			default:break;
                		}
                     }
			default:break;
		}
	}
};

int  main()
{
	int Case;
	int cnt;
	int M;
	int dragon_life,ninja_life,iceman_life,lion_life,wolf_life;
	int timer;

	cin>>Case;
	for(cnt=1;cnt<=Case;cnt++)
	{
    timer=0;
	cin>>M;
	cin>>dragon_life>>ninja_life>>iceman_life>>lion_life>>wolf_life;
	
	red re(M,dragon_life,ninja_life,iceman_life,lion_life,wolf_life);
	blue bl(M,dragon_life,ninja_life,iceman_life,lion_life,wolf_life);

	cout<<"Case:"<<cnt<<endl;

	while(!(re.getstate()==5 && bl.getstate()==5))
	{
		cout<<setfill('0');
		
		if(re.getstate()!=5)	{cout<<setw(3)<<timer<<' ';re.born();}
		
		if(bl.getstate()!=5)	{cout<<setw(3)<<timer<<' ';bl.born();}
		
		timer++;
	}
}
	return 0;
}

