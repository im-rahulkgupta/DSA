//singly sides list
#include<iostream>
#include<stdlib.h>
void Insert_begin();
void Insert_loc();
void append();
void Delete_begin();
void Delete_loc();
void Delete_end();
void Delete();
void traverse();
void length();
struct node
{
    int data;
    struct node *next;
}*start=NULL;
int main()
{
    int choice;
    while(1)
    {
        std::cout<<std::endl;
        std::cout<<"1. Insertion at Begin"<<std::endl;
        std::cout<<"2. Insertion at Specified Location"<<std::endl;
        std::cout<<"3. Append"<<std::endl;
        std::cout<<"4. Deletion at Begin"<<std::endl;
        std::cout<<"5. Deletion at Specified Location"<<std::endl;
        std::cout<<"6. Deletion at End"<<std::endl;
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
                    append();
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
                    length();
                    break;
            case 9:
                    traverse();
                    break;
            case 10:
                    exit(0);
            default:
                    std::cout<<"Invalid Choice"<<std::endl;
        }
    }

}

void Insert_begin()
{
    int val;
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node*));

    std::cout<<"Enter The Data : ";
    std::cin>>val;

    ptr->data=val;
    ptr->next=NULL;

    if(start==NULL)
        start=ptr;
    else
    {
        ptr->next=start;
        start=ptr;
    }
    std::cout<<"Inserted Element : "<<start->data<<std::endl;
}

void Insert_loc()
{
    struct node *ptr;
    int val,data;
    ptr= new struct node;
    std::cout<<"Enter The Data After Which You Want To Insert : ";
    std::cin>>val;

    if(start==NULL)
        std::cout<<"The List Is Empty !"<<std::endl;
    else
    {
        std::cout<<"Enter The Data : ";
        std::cin>>data;
        ptr->data=data;
        ptr->next=NULL;

        struct node* p;
        p=start;
        while(p->data!=val && p->next!=NULL)
            p=p->next;
        if(p->data!=val && p->next==NULL)
             std::cout<<"Element Not Found "<<std::endl;
        else
        {
            ptr->next=p->next;
            p->next=ptr;
            std::cout<<"Found And Inserted"<<std::endl;
        }
    }
}

void append()
{
    struct node * ptr;
    int data;
    ptr=(struct node *) malloc(sizeof(struct node));

    std::cout<<"Enter The Data : ";
    std::cin>>data;

    ptr->data=data;
    ptr->next=NULL;
    if(start==NULL)
        start=ptr;
    else
    {
        struct node * ptr1;
        ptr1=start;
        while(ptr1->next!=NULL)
            ptr1=ptr1->next;
        ptr1->next=ptr;
    }
    std::cout<<"Inserted Element : "<<data<<std::endl;
}

void Delete_begin()
{
    if(start==NULL)
        std::cout<<"The List Is Empty !"<<std::endl;
    else
    {
        std::cout<<"Deleted Element : "<<start->data<<std::endl;
        start=start->next;
    }
}

void Delete_loc()
{
    struct node *ptr;
    if(start==NULL)
        std::cout<<"The List Is Empty !"<<std::endl;
    else
    {
        int loc, flag=0;
        struct node* ptr,*ptr1;
        std::cout<<"Enter The Data Which You Want To Delete : ";
        std::cin>>loc;
        ptr=start;
        if(start->data==loc && start->next==NULL)
            start=NULL;
        else if(start->data==loc)
        {
            ptr=ptr->next;
            start=ptr;
            std::cout<<"Element Found And Deleted"<<std::endl;
        }
        else
        {
            while(ptr->data!=loc &&  ptr->next!=NULL)
            {
                ptr1=ptr;
                ptr=ptr->next;
            }
            if(ptr->data!=loc && ptr->next==NULL)
                std::cout<<"Element Not Found"<<std::endl;
            else
            {
                ptr1->next=ptr->next;
                std::cout<<"Found & Deleted"<<std::endl;
            }
        }
    }
}


void Delete_end()
{
    if(start==NULL)
        std::cout<<"The List Is Empty !"<<std::endl;
    else if(start->next==NULL)
    {
        std::cout<<"Deleted Element : "<<start->data<<std::endl;
        start=NULL;
    }
    else
    {
        struct node * ptr, *ptr1;
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr1=ptr;
            ptr=ptr->next;
        }
        std::cout<<"Deleted Element : "<<ptr->data<<std::endl;
        ptr1->next=NULL;
    }
}

void Delete()
{
    start=NULL;
    std::cout<<"The List Is Deleted"<<std::endl;
}

void length()
{
    struct node *ptr;
    if(start==NULL)
        std::cout<<"Elements are not present !"<<std::endl;
    else
    {
        int len=0;
        ptr=start;
        for(int i=0; ptr!=NULL; i++)
        {
            len++;
            ptr=ptr->next;
        }
        std::cout<<"Total Length = "<<len<<std::endl;
    }
}


void traverse()
{
    struct node * ptr;
    if(start==NULL)
        std::cout<<"Elements are not present !"<<std::endl;
    else
    {
        ptr=start;
        std::cout<<"Link List Elements : "<<std::endl;
       while(ptr!=NULL)
        {
            std::cout<<ptr->data<<"-->";
            ptr=ptr->next;
        }
        std::cout<<std::endl;
    }
}
