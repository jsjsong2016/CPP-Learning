#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
void string_op();
int my_stoi(const std::string nptr);
std::string my_itos(const int n);

//��string ת��int
int my_stoi(const std::string nptr)
{
    int len = nptr.length();
    int temp = 0;
    for(int i = 0; i < len ; i++){
        if(nptr[i] - '0' >= 0 || nptr[i] - '9' <= 0){
            temp = (temp * 10 + (nptr[i] - '0')) ;
        }
    }
    return temp;
}

//��int ת��string
std::string my_itos(const int n)
{
    //std::cout << "start";
    if(n == 0){
        std::string temp = "0";
        return temp;
    }
    std::string temp(100,'0');
    int no = n, i;
    for(i = 99; no >0; i--){
        temp[i] = (char)(no % 10 + '0');
        no = no / 10;

    }
    //std::cout <<std::endl << temp << std::endl;
    temp.erase(0, i+1);
    return  temp;
}

//��Ҫ��������
void string_op()
{

  //��ʼ��
    std::string total[20] = {""}, S, S1, S2, temp;
    int time, N, X, L, end,int_S1 = 0,int_S2 = 0;
    //¼���ܵ��ַ���
    std::cin >> time;
    for(int i = 0; i < time ;i++){
        std::cin >> total[i];
    }
//������
    std::string total_oper[20] = {"over"};
    for(int begin_i = 0;true; begin_i++){
        //��ջ��Ų�����
        std::stack<std::string> my_op;
//        std::cin.ignore();
//        std::cin.clear();
        getline(std::cin, total_oper[begin_i]); //��ȡ����
        //�Ƿ��������
        if(total_oper[begin_i].substr(0,4) == "over"){
            break;
        }
        else{
            while(true){
                //���ݿո�ָ���������stack��
                end = (int) total_oper[begin_i].rfind(' ');
                if( end != std::string::npos){
                    temp = total_oper[begin_i].substr(end + 1, total_oper[begin_i].length() -1);
                    total_oper[begin_i].erase(end,total_oper[begin_i].length() -1);
                }
                else{
                    temp = total_oper[begin_i];
                    total_oper[begin_i] = "";

                }

                //��Ӧ�Ĳ�����
                //copy N X L
                if( temp == "copy"){
                    N = my_stoi(my_op.top());  my_op.pop();
                    X = my_stoi(my_op.top());  my_op.pop();
                    L = my_stoi(my_op.top());  my_op.pop();
                    temp = total[N -1].substr(X,L);
                    my_op.push(temp);

                }
                //add S1 S2
                else if( temp == "add"){
                    S1 = my_op.top();   my_op.pop();
                    S2 = my_op.top();   my_op.pop();
                    int_S1 = my_stoi(S1);
                    int_S2 = my_stoi(S2);
                    if( (int_S1 != NULL && int_S1 >0 &&int_S1 <100000) &&  (int_S2 != NULL && int_S2 >0 &&int_S2 <100000) ){
                        //int ת��string
                        temp = my_itos((int_S1 + int_S2));
                    }
                    else{
                        temp = S1 + S2;
                    }
                    my_op.push(temp);
                }
                //find S N
                else if( temp == "find"){
                    S = my_op.top();    my_op.pop();
                    N = my_stoi(my_op.top());  my_op.pop();
                    if( total[N -1].find(S) !=std::string::npos){
                        temp = my_itos( total[N -1].find(S) );
                    }
                    else{
                        temp = my_itos((total[N -1].length()));
                    }
                    my_op.push(temp);
                }
                //rfind S N
                else if( temp == "rfind"){
                    S = my_op.top();    my_op.pop();
                    N = my_stoi(my_op.top());  my_op.pop();
                    if( total[N -1].rfind(S) !=std::string::npos){
                        temp = my_itos( total[N -1].rfind(S) );
                    }
                    else{
                        temp = my_itos((total[N -1].length()));
                    }
                    my_op.push(temp);
                }
                //insert S N X
                else if( temp == "insert"){
                    S = my_op.top();    my_op.pop();
                    N = my_stoi(my_op.top());  my_op.pop();
                    X = my_stoi(my_op.top());  my_op.pop();
                    total[N -1].insert(X,S);
                }
                //reset S N
                else if( temp == "reset"){
                    S = my_op.top();    my_op.pop();
                    N =my_stoi(my_op.top());    my_op.pop();
                    total[N -1] = S;
                }
                //print N
                else if( temp == "print"){
                    N = my_stoi(my_op.top());  my_op.pop();
                    printf("%s\n", total[N -1].c_str());
                }
                //printall
                else if( temp == "printall"){
                    for(int i =0; i < time; i++){
                        printf("%s\n",total[i].c_str());
                    }
                }
                //�������ض��Ĳ�����
                else{
                    my_op.push(temp);
                }
                //�жϸ��в����Ƿ�ȫ����������
                if(total_oper[begin_i].length() == 0){
                    break;
                }
            }
        }
    }
}
int main(){
    string_op();
    return 0;
}
