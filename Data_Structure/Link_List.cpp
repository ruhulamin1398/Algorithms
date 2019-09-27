#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int data;
    struct node*next;
};
void insertInList(node * head, int data)
{
    while ( head->next != NULL)
        head=  head->next;
    node *newnode ;
    newnode = (node *) malloc(sizeof(node));
    newnode->next = NULL;
    newnode->data= data;
    head->next= newnode;
}
void insertInList2(node * head, int data,int later)
{
    while ( head->data != later)
        head=  head->next;
    node *newnode ;
    newnode = (node *) malloc(sizeof(node));
    newnode->data= data;
    newnode->next =head->next;
    head->next= newnode;
}
void deleteNode(node *head,int data)
{
    while ( head->next != NULL)
        if(head->next->data==data)
            head->next= head->next->next;
        else
            head = head->next;
}
void deleteFromFirst(node *head)
{
    if( head->next != NULL)
        head->next= head->next->next;
}
void printList(node * head)
{
    while ( head->next != NULL)
    {
        head=  head->next;
        cout<<head->data<<" ";
    }
}
int main()
{
    node *head;
    head= (node *) malloc(sizeof(node)); /// new node() [C++]
    head->next= NULL;
    int data;
    for(int i=1; i<=5; i++)
    {
        cin>>data;
        insertInList(head,data); ///insert "data" to List
    }
    printList(head);
    cout<<endl;

    for(int i=1; i<=2; i++)
    {
        cin>>data;
        deleteNode(head,data);  ///detete "data" if stay it
    }
    printList(head);
    cout<<endl;
    int later;
    for(int i=1; i<=2; i++)
    {
        cin>>later>>data;
        insertInList2(head,data,later); ///insert "data" after "later"

    }
    printList(head);
    cout<<endl;
    for(int i=1; i<=2; i++)
        deleteFromFirst(head); ///detete first element of List
    printList(head);
}

/**
input:
5 9 11 13 2
9 13
11 17
5 23

output :
5 9 11 13 2
5 11 2
5 23 11 17 2
11 17 2
**/
