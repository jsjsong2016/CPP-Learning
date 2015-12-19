#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector < vector<int> > vec(3);
    for (int i=0; i<vec.size();i++){
        for (int j=0;j<4;j++){
            vec[i].push_back(i+j);
        }
    }
    for (int i=0;i<vec.size();i++){
        for (int j=0;j<vec[i].size();j++){
            cout<<"Vec["<<i<<"]["<<j<<"] is "<<vec[i][j]<<"; ";
        }
        cout<<endl;
    }
    return 0;
}
