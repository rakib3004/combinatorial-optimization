
#include<bits/stdc++.h>
using namespace std;
int main(){

int noOfLine;
cin>>noOfLine;
int a[noOfLine][2];
int i;

for(i=0;i<noOfLine;i++){
    cin>>a[i][0]>>a[i][1];
}
int j;

for(i=0;i<noOfLine;i++){
    for(j=i+1;j<noOfLine;j++){
        int a1,a2,a3,a4;
        a1 = (a[i][0]-a[j][1])*(a[j][0]-a[j][1]);
        a2 = (a[i][1]-a[j][1])*(a[j][0]-a[j][1]);
        a3 = (a[j][0]-a[i][1])*(a[i][0]-a[i][1]);
        a4 = (a[j][1]-a[i][1])*(a[i][0]-a[i][1]);

        int p1 = a1*a2;
        int p2 = a3*a4;
        if(p1<0&&p2<0){

        cout<<"Lines are intersect"<<endl;
        }
        else if(p1==0||p2==0){
        cout<<"Lines are intersect"<<endl;

        }
        else{

        cout<<"Lines are not intersect"<<endl;
        }

    }
}

return 0;
}
