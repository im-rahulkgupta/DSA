#include<iostream>
#include<stdlib.h>

void Insert_begin();
void Insert_loc();
void Insert_end();
void Delete_begin();
void Delete_loc();
void Delete_end();
void Delete();
void Length();
void Traverse();

class Node
{
    public:
        Node * prev;
        int data;
        Node * next;
}*start=NULL;
int main()
{
    int choice;
    while(1)
    {
        std::cout<<std::endl;
        std::cout<<"1. Insertion At Begin"<<std::endl;
        std::cout<<"2. Insertion At Specified Location"<<std::endl;
        std::cout<<"3. Insertion At End"<<std::endl;
        std::cout<<"4. Deletion At Begin"<<std::endl;
        std::cout<<"5. Deletion At Specified Location"<<std::endl;
        std::cout<<"6. Deletion At End"<<std::endl;
        std::cout<<"7. Delete The List"<<std::endl;
        std::cout<<"8. Length"<<std::endl;
        std::cout<<"9. Traversal"<<std::endl;
        std::cout<<"10. Exit"<<std::endl<<std::endl;
        std::cout<<"Enter Your Choice : ";
        std::cin>>choice;
        std::cout<<std::endl;
        switch(choice)
        {
            case 1:
                    Insert_begin();
                    break;
            case 2:
                    Insert_loc();
                    break;
            case 3:
                    Insert_end();
                    break;
            case 4:
                    Delete_begin();
                    break;
            case 5:
                    Delete_loc();
                    break;
            case 6:
                    Delete_end();
                    break;
            case 7:
                    Delete();
                    break;
            case 8:
                    Length();
                    break;
            case 9:
                    Traverse();
                    break;
            case 10:
                    exit(0);
            default :
                    std::cout<<"Invalid Choice"<<std::endl;
        }
    }
}

void Insert_begin()
{
    Node * ptr;
    ptr = new Node;
    std::cout<<"Enter The Data : ";
    std::cin>>ptr->data;
    ptr->prev=NULL;
    ptr->next=NULL;
    if(start==NULL)
        start=ptr;
    else
    {
        ptr->next=start;
        start->prev=ptr;
        start=ptr;
    }
    std::cout<<"inserted Element : "<<start->data<<std::endl;
}

void Insert_loc()
{
    int loc;
    Node *p, *p1;
    Node *ptr;
    ptr = new Node;

    std::cout<<"Enter Data After Which You Want To Insert Your Data : ";
    std::cin>>loc;

    std::cout<<"Enter The Data : ";
    std::cin>>ptr->data;

    if(start==NULL)
        std::cout<<"The List Is Empty"<<std::endl;
    else
    {
        p=start;
        while(p->data!=loc && p->next!=NULL)
            p=p->next;
        if(p->data!=loc && p->next==NULL)
            std::cout<<"Element Not Found"<<std::endl;
        else
        {
            if(p->next==NULL)
                ptr->next=NULL;
            else
            {
                p1=p->next;
                ptr->next=p1;
                p1->prev=ptr;
            }
            p->next=ptr;
            ptr->prev=p;
            std::cout<<"Element Found And Inserted"<<std::endl;
        }
    }
}

void Insert_end()
{
    Node * ptr;
    ptr = new Node;
    std::cout<<"Enter The Data : ";
    std::cin>>ptr->data;
    ptr->prev=NULL;
    ptr->next=NULL;
    if(start==NULL)
        start=ptr;
    else
    {
        Node *p;
        p=start;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=ptr;
        ptr->prev=p;
    }
    std::cout<<"inserted Element : "<<ptr->data<<std::endl;
}

void Delete_begin()
{
    if(start==NULL)
        std::cout<<"The List Is Empty"<<std::endl;
    else if(start->next==NULL)
        start=NULL;
    else
    {
        std::cout<<"Deleted Element : "<<start->data<<std::endl;
        start=start->next;
        start->prev=NULL;
    }
}

void Delete_loc()
{
    int loc;
    Node * p, *p1;
    std::cout<<"Enter The Data You Want To Delete : ";
    std::cin>>loc;
    if(start==NULL)
        std::cout<<"The List Is Empty"<<std::endl;
    else if(start->data==loc && start->next==NULL)
        start=NULL;
    else if(start->data==loc)
    {
        start=start->next;
        start->prev=NULL;
    }
    else
    {
        p=start;
        while(p->data!=loc && p->next!=NULL)
            p=p->next;
        if(p->data!=loc && p->next==NULL)
            std::cout<<"Element Not Found"<<std::endl;
        else
        {
            p1=p->prev;
            if(p->next==NULL)
                p1->next=NULL;
            else
            {
                p=p->next;
                p1->next=p;
                p->prev=p1;
            }
        }
    }
}

void Delete_end()
{
    if(start==NULL)
        std::cout<<"The List Is Empty"<<std::endl;

    else if(start->next==NULL)
    {
        std::cout<<"Deleted Element : "<<start->data<<std::endl;
        start=NULL;
    }
    else
    {
        Node * ptr, *p;
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        std::cout<<"Deleted Element : "<<ptr->data<<std::endl;
        p=ptr->prev;
        p->next=NULL;
    }
}

void Delete()
{
    start=NULL;
    std::cout<<"The List Is Deleted"<<std::endl;
}

void Length()
{
    if(start==NULL)
        std::cout<<"Elements Are Not Present !"<<std::endl;
    else
    {
        int len=0;
        Node * ptr;
        ptr=start;
        do
        {
            len++;
            ptr=ptr->next;
        }while(ptr!=NULL);
        std::cout<<"Total Length = "<<len<<std::endl;
    }
}

void Traverse()
{
    if(start==NULL)
        std::cout<<"Elements Are Not Present !"<<std::endl;
    else
    {
        Node * ptr;
        ptr=start;
        std::cout<<"List Elements Are :"<<std::endl;
        while(ptr!=NULL)
        {
            std::cout<<ptr->data<<"-->";
            ptr=ptr->next;
        }
        std::cout<<std::endl;
    }
}
