#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int flag;
string* str;

int IsNum(string t){
    char *d;
    d=(char*)t.c_str();
    if(isdigit(d[0]))
        return atoi(t.c_str());
    else
        return -1;
}

int readin(string _cmd="",int sym=0){
    string cmd;
    if(sym)
        cmd=_cmd;
    else
        cin>>cmd;
    if(IsNum(cmd)!=-1)
        return IsNum(cmd);
    else if(cmd=="add"){
        int c1=readin();
        int c2=readin();
        char t[20];
        int num1=IsNum(str[c1]);
        int num2=IsNum(str[c2]);
        if(num1!=-1 && num2!=-1 &&
                num1>=0 && num2>=0 && num1<=99999 && num2<=99999){
            sprintf(t,"%d",IsNum(str[c1])+IsNum(str[c2]));
            str[flag]=t;
            return flag++;
        }
        else{
            char d1[20],d2[20];
            strcmp(d1,str[c1].c_str());
            strcmp(d2,str[c2].c_str());
            int j=0;
            for(int i=0;!d1[i] && !d2[i];i++){
                str[flag].at(j++)=d1[i]+d2[i];
            }
            return flag++;
        }
    }
    else if(cmd=="find"){
        string c1;
        cin>>c1;
        int c2;
        cin>>c2;
        int r=str[c2].find(c1);
        if(r==string::npos)
            return c1.size();
        else
            return r;
    }
    else if(cmd=="rfind"){
        string c1;
        cin>>c1;
        int c2;
        cin>>c2;
        int r=str[c2].rfind(c1);
        if(r==string::npos)
            return c1.size();
        else
            return r;
    }
    else if(cmd=="insert"){
        int c1=readin();
        int c2=readin();
        int c3=readin();
        str[c2].insert(c3,str[c1]);
        return c2;
    }
    else if(cmd=="reset"){
        int c1=readin();
        int c2=readin();
        str[c2]=str[c1];
    }
    else if(cmd=="copy"){
        int c1=readin();
        int c2=readin();
        int c3=readin();
        str[flag]=str[c1].substr(c2,c3);
        return flag++;
    }
    else{
        str[flag]=cmd;
        return flag++;
    }
}


int main()
{
    int T;
    string cmd;
    cin>>T;
    str=new string[4*T];
    for(int i=1;i<=T;i++)
        cin>>str[i];
    while(cin>>cmd){
        flag=T+1;
        if(cmd=="over")
            break;
        else if(cmd=="printall"){
            for(int i=1;i<=T;i++)
                cout<<str[i]<<endl;
        }
        else if(cmd=="print"){
            int f;
            cin>>f;
            cout<<str[f]<<endl;
        }
        else
            readin(cmd,1);
    }
    delete []str;
    return 0;
}
