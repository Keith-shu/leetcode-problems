#include <iostream>
#include <memory.h>
using namespace std;

class arcnode
{
public:
    arcnode *next;
    int number;
    arcnode(){next=NULL;};
};
void insert(arcnode *root,int b)
{
    arcnode *cur=root;
    while(cur->next!=NULL)
        cur=cur->next;
    arcnode *temp=new arcnode();
    temp->number=b;
    cur->next=temp;
}

void print(arcnode *root)
{
    arcnode *cur=root;
    while(cur->next!=NULL){
        cur=cur->next;
        cout<<cur->number;
    }
    cout<<endl;
}

int dfs(arcnode *root,int *visited,int *safe)
{
    if(safe[root->number]==1)
        return 0;
    if(visited[root->number]==1&&safe[root->number]==0)
        return 1;
    visited[root->number]=1;
    arcnode *cur=root;
    int count=0;
    while(cur->next!=NULL){
        count+=dfs(cur->next,visited,safe);
        cur=cur->next;
    }
    if(count==0)
        safe[root->number]=1;
    return 0;
}

int main(int argc, char const *argv[]) {
    int n,m;
    char buff;
    cin>>n>>buff>>m;
    arcnode *clients=new arcnode[n+1];
    int i;
    int a,b;
    for(i=1;i<m+1;i++){
        cin>>a>>buff>>b;
        insert(clients+a,b);
    }
    // for(i=1;i<m+1;i++)
    //     print(clients+i);

    int *safe=new int[n+1];
    for(i=0;i<n+1;i++)
        safe[i]=-1;
    int count=0;
    for(i=1;i<n+1;i++){
        if(clients[i].next==NULL){
            safe[i]=1;
            count++;
        }
    }
    if(count==0){
        cout<<"None"<<endl;
        return 0;
    }
    int *visited=new int[n+1];
    for(i=1;i<n+1;i++){
        memset(visited,0,sizeof(char)*4);
        if(dfs(clients+i,visited,safe)==0);
            cout<<i<<' ';
    }
    cout<<endl;
    return 0;
}
