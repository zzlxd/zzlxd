#include <iostream>
#include<fstream>
using namespace std;
const string addr=R"(D:\Ccode\Clion\research\datafile.txt)";
string search_1(int *min,int *max,int n){//递归
    int *mid=min+(max-min)/2;
    if(min<=max){
        if(n>*mid){
            min=mid+1;
        }
        else if(n<*mid){
            max=mid-1;
        }
        else{
            return "found";
        }
    }
    else{
        return "not found";
    }
    return search_1(min,max, n);
}
string non_recursive(int *key,int m,int s){//非递归
    int min=0;
    int max=m-1;
    while(min<=max){
        int mid=(min+max)/2;
        if(key[mid]==s){
            return "found ";
        }
        else if(s<key[mid]){
            max=mid-1;
        }
        else{
            min=mid+1;
        }
    }
    return "not found";
}
int main() {
    ifstream infile;
    ofstream outfile;

    int n[1000];int i=0;int k=0;
    infile.open(addr, ios::in);
    if(!infile.is_open ()) cout << "Open file failure" << endl;
    while (!infile.eof())            // 若未到文件结束一2
        // 直循环
    {
        infile >> n[i];
        i++;
    }
    infile.close();
    int input;
    cin>>input;
    for(int ii=0;ii<i;ii++){
        if(input==n[ii]){
            cout<<"find in "<<ii<<endl;
            k=ii;
            break;
        }
        if(ii==i-1){
            cout<<"not found"<<endl;
        }
    }
    for(int ii=0;ii<i;ii++){
        for(int oo=ii;ii+oo<i;oo++){
            if(n[ii]>n[ii+oo]){
                int k;
                k=n[ii];
                n[ii]=n[ii+oo];
                n[ii+oo]=k;
            }
        }
    }
    if(!k){
        cout<<"recursion: "<<search_1(&n[0],&n[i],input)<<endl;
        cout<<"non-recursion: "<<non_recursive(n,i,input)<<endl;
    }
    else{
        cout<<"recursion: "<<search_1(&n[0],&n[i],input)<<endl;
        cout<<"non-recursion: "<<non_recursive(n,i,input)<<endl;
    }
    return 0;
}
