#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<ctime>

using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
};

node *head, *tail, *temp;

void newNode(void)
{
    temp = new node;
    (*temp).data = rand()%100;
    (*temp).prev = NULL;
    (*temp).next = NULL;
    if(head == NULL)
        head = tail = temp;
    else
    {
        (*temp).prev = tail;
        (*tail).next = temp;
        tail = temp;
    }
}

void travers(void)
{
    temp = head;
    while(temp != NULL)
    {
        if((*temp).data < 10)
            cout << "0" << (*temp).data << " ";
        else
            cout << (*temp).data << " ";
        temp = (*temp).next;
    }
}

void deleteNode(int item)
{
    int counter = 0;
    temp = head;
    while(temp != NULL)
    {
        if((*temp).data == item)
        {
            (*temp).prev->next = (*temp).next;
            (*temp).next->prev = (*temp).prev;
            delete temp;
            counter++;
        }
        temp = (*temp).next;
    }
    if(counter == 0)
        cout << "Item not found...." << endl;
    else
        cout << counter << " elements have been deleted" << endl;
}

int main()
{
    srand(time(0));
    head = tail = NULL;
    for(int i=0; i<500; i++)
    {
        newNode();
    }
    travers();
    int item;
    cout << endl << "Enter item to delete : ";
    cin >> item;
    deleteNode(item);
    travers();


    getch();
    return 0;
}
