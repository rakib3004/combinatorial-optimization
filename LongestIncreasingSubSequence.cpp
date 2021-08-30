#include<bits/stdc++.h>
using namespace std;


int maximum(int a, int b){

  if(a>b){

    return a;
  }
  return b;


}
int main()
{


    int n;

   // cin>>n;

   n = rand()%30+1;
cout<<"Total numbers of sequence element: "<<n<<endl;
    int array[n+1];
    int length[n+1];
    int previous[n+1];

       array[0]=0;
       length[0]=0;
       previous[0]=-1;
    int i,j;

    for(i=1;i<=n;i++){
        //cin>>array[i];
        array[i]= rand()%55+5;
        cout<<array[i]<<" ";
        length[i]=1;
    }
    cout<<endl;

    int max=0;
 for(i=1;i<=n;i++){
        for(j=0;j<i;j++){

            if(array[i]>array[j]){
                length[i]= maximum(length[i],length[j]+1);
            }

        }
     }

     int longest=0;

     for(i=0;i<n+1;i++){
            longest=maximum(longest,length[i]);
     }

     //sort(length,length+n+1);
     cout<<longest;





    return 0;

}
