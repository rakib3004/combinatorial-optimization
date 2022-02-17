#include<iostream>
#include<stdlib.h>
#include<string>
#include<string.h>
using namespace std;

int k,depth=0;
struct node {
    int data[20];
    node *right , *left ;
};

node *root=NULL;

void insertNonRoot(node *curr,node *newData, int depth)
{
    int d=depth%k;

    if(curr->right==NULL && curr->data[d] <= newData->data[d]) curr->right= newData;
    else if(curr->left==NULL && curr->data[d] > newData->data[d]) curr->left= newData;
    else if(curr->data[d] <= newData->data[d]) insertNonRoot(curr->right,newData,depth+1);
    else insertNonRoot(curr->left,newData,depth+1);
}

void construct()
{
     struct node *temp=new node;

    cout << "enter"<< "[" << k << "]  " << "points:    ";
     for(int i=0 ;i<k ; i++)
     {

          cin >> temp->data[i];
     }
     temp->right=NULL;
     temp->left=NULL;


    if(root==NULL) root=temp;
    else insertNonRoot(root,temp,0);

}

void print(node *newNode)
{
    if(newNode==NULL) return;

    print(newNode->left);

    for(int i=0 ; i<k ; i++)
    {
        cout<<newNode->data[i]<<"     ";
    }
    cout << endl;

    print(newNode->right);
}

bool sameNode(int *arr, int *brr)
{
    for (int i = 0; i < k; ++i)
    {
            if (arr[i] != brr[i])
            {
                  return false;
            }
    }

    return true;
}

bool search_node(node* curr, int *point, int hight)
{
    if (curr == NULL)
        return false;
    if (sameNode(curr->data, point))
    {
        depth=hight;
         return true;
    }


    int di = hight % k;

    if (point[di] < curr->data[di])
        return search_node(curr->left, point, hight + 1);

    return search_node(curr->right, point, hight + 1);
}

void search_fun()
{
    int s_point[k];
    cout << "enter a node  :  ";
    for(int i=0 ; i<k ; i++) cin >> s_point[i];
    bool bl=search_node(root,s_point,0);
    if(bl==true) cout <<"Found and hight :  " << depth+1 << endl;
    else cout <<"Not found " << endl;
}

int main(void)
{
     cout << "Enter the value of K : " ;
    cin >> k;

   // root =(node*)malloc( (sizeof( int)*(k+2) ));

   while(true)
   {
        int choice;

        cout<<"1.Insert\n2.Search\n3.Print(in-order traversal)\n4.exit "<<endl;
        cout<<"enter your choice : "<<endl;
        cin>>choice;

        switch(choice)
        {

            case 1:
                construct();
                break;

            case 2:
                search_fun();
                break;

            case 3:
                print(root);
                break;

        }

        if(choice==4) break;

   }
    return 0;
}
