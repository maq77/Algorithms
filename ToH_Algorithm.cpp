#include <iostream>
#include <vector>
using namespace std;
void ToH(int n,char src, char aux, char dest){
if(n==1){
    cout<<"Move disk - "<<n<<" from "<<src<<" to "<<dest<<endl;
    return;
}
ToH(n-1,src,dest,aux);
cout<<"Move disk - "<<n<<" from "<<src<<" to "<<dest<<endl;
ToH(n-1,aux,src,dest);

}
int main() {
    int n;
    cout<<"Enter No. of Disks : ";
    cin>>n;
    ToH(n,'A','B','C');


    return 0;
}
