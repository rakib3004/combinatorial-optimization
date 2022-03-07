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

    int alignment=depth%k;

    if(point[alignment]<parent->coordinates[alignment])
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

vector<vector<int> > rangeSearchRecursive
(Node *parent, int pointOne[], int pointTwo[], int depth)
{
    vector<vector<int> > temporary;
    if(parent==NULL) return temporary;


    int flag=1;
    for(int i=0; i<k; i++)
    {
        if(parent->coordinates[i]<pointOne[i] || parent->coordinates[i]>pointTwo[i])
        {

            flag=0;
            break;
        }
    }
    if(flag) temporary=insertPointToList(temporary, parent->coordinates);



    int alignment=depth%k;
    vector<vector<int> > temporaryOne, temporaryTwo;

    if(pointTwo[alignment]>parent->coordinates[alignment])
        temporaryOne=rangeSearchRecursive
                     (parent->right, pointOne, pointTwo, depth+1);

    if(pointOne[alignment]<parent->coordinates[alignment])
        temporaryTwo=rangeSearchRecursive
                     (parent->left, pointOne, pointTwo, depth+1);

    temporary=insertVectorToList(temporary, temporaryOne);
    temporary=insertVectorToList(temporary, temporaryTwo);
    return temporary;
}

vector<vector<int> > rangeSearch(Node *root, int pointOne[], int pointTwo[])
{
    return rangeSearchRecursive
           (root, pointOne, pointTwo, 0);
}

int main()
{
    struct Node *root = NULL;

    int numberOfNodes=7;
    int points[numberOfNodes][k] = {{2,5},{3,2},{11,6},{3,8},{12,4},{7,2},{8,17},{6,9}};
    for (int i=0; i<numberOfNodes; i++) root=insertPoint(root, points[i]);


    int pointOne[k];
    pointOne[0]=1;
    pointOne[1]=1;
    int pointTwo[k];
    pointTwo[0]=7;
    pointTwo[1]=7;
    vector<vector<int> > searchResult=rangeSearch(root, pointOne, pointTwo);

    for(int i=0; i<searchResult.size(); i++)
    {
        for(int j=0; j<k; j++) cout << searchResult[i][j] << " ";
        cout << "\n";
    }

}
