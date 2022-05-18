#include <bits/stdc++.h>
using namespace std;

const int k=2;

struct Node
{
    int coordinates[k];
    Node *left, *right;
};

struct Node* initializeNewNode(int coordinateArray[])
{
    struct Node* temp=new Node;
    for(int i=0; i<k; i++)
    {
        temp->coordinates[i]=coordinateArray[i];
    }
    temp->left=temp->right=NULL;
    return temp;
}

Node *recursiveInsert(Node *parent, int point[], int depth)
{
    if(parent==NULL)
        return initializeNewNode(point);

    int currentDepth=depth%k;

    if(point[currentDepth]<parent->coordinates[currentDepth])
        parent->left=recursiveInsert(parent->left, point, depth+1);

    else
        parent->right=recursiveInsert(parent->right, point, depth+1);

    return parent;
}

Node *insertPoint(Node *root, int point[])
{
    recursiveInsert(root, point, 0);
}

vector<vector<int> > insertPointToList(vector<vector<int> > pointList, int point[])
{
    vector<int> temporary;
    for(int i=0; i<k; i++) temporary.push_back(point[i]);
    pointList.push_back(temporary);
    return pointList;
}

vector<vector<int> > insertVectorToList
(vector<vector<int> > pointList, vector<vector<int> > secondaryList)
{
    for(int i=0; i<secondaryList.size(); i++)
    {
        pointList.push_back(secondaryList[i]);
    }
    return pointList;
}

vector<vector<int> > rangeSearch
(Node *parent, int point1[], int point2[], int depth)
{
    vector<vector<int> > temporary;
    if(parent==NULL) return temporary;


    int flag=1;
    for(int i=0; i<k; i++)
    {
        if(parent->coordinates[i]<point1[i] || parent->coordinates[i]>point2[i])
        {

            flag=0;
            break;
        }
    }
    if(flag) {
    temporary=insertPointToList(temporary, parent->coordinates);

    }



    int currentDepth=depth%k;
    vector<vector<int> > temp1, temp2;

    if(point2[currentDepth]>parent->coordinates[currentDepth])
        temp1=rangeSearch(parent->right, point1, point2, depth+1);

    if(point1[currentDepth]<parent->coordinates[currentDepth])
        temp2=rangeSearch(parent->left, point1, point2, depth+1);

    temporary=insertVectorToList(temporary, temp1);
    temporary=insertVectorToList(temporary, temp2);
    return temporary;
}



int main()
{
    struct Node *root = NULL;

    int numberOfNodes=7;
    int points[numberOfNodes][k] = {{2,5},{3,2},{11,6},{3,8},{12,4},{7,2},{8,17},{6,9}};
    for (int i=0; i<numberOfNodes; i++)
    {
                root=insertPoint(root, points[i]);

    }


    int point1[k], point2[k];

    //poimt 1
    point1[0]=0;
    point1[1]=0;

    //poimt 2
    point2[0]=2;
    point2[1]=6;

    int initialLevel=0;

    vector<vector<int> > coveredAreaPoint=rangeSearch(root, point1, point2,initialLevel);

    for(int i=0; i<coveredAreaPoint.size(); i++)
    {
        for(int j=0; j<k; j++) {
        cout << coveredAreaPoint[i][j]<<" ";
        }
        cout<<endl;

    }

}
