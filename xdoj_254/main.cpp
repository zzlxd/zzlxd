#include <iostream>
using namespace std;

int main() {
    int n;
    int s;
    int key[100];
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++){
        scanf("%d",&key[i]);
    }
    int min=0;
    int max=n-1;
    while(min<=max){
        int mid=(min+max)/2;

        cout<<key[mid]<<" ";
        if(key[mid]==s){
            printf("\nEureka!");
            return 0;
        }
        else if(s<key[mid]){
            max=mid-1;
        }
        else{
            min=mid+1;
        }
    }
    cout<<"\nSearch failed!";
    return 0;
}
