#include<bits/stdc++.h>
using namespace std;
class linkedList{
    struct node
    {
        int item;
        node * next=NULL;
    };
    node *head;
    public:
    linkedList(){
        head->next=NULL;
    }
    void transverse();
    void insert();
    void delete_Linklist();
};
void linkedList:: transverse(){
    if(head->next==NULL){
        cout<<"There is no node in list\n";
        return;
    }
    node *temp;
    temp=head->next;
    while(1){
        cout<<endl<<(temp->item);
        if(temp->next==head->next){
            return;
        }
        temp=temp->next;
    }
}
void linkedList :: delete_Linklist(){
    if(head->next==NULL){
        cout<<"No node to delete in list.\n";
        return;
    }
    int choice;
    cout<<" 1:At Beginning \n 2:At End \n 3: After a node\n";
    cout<<"Enter the choice: ";
    cin>>choice;
    switch (choice)
    {
    case (1):{
        node* ptr=head->next;
        if(ptr->next==ptr){
            delete ptr;
            head->next=NULL;
        }
        else{
            head->next=ptr->next;
            delete ptr;
        }
        cout<<"NODE DELETED SUCCESSFULLY\n";
        transverse();
        break;
    }
    case(2):{
        node *ptr=head->next;
        node *prev=head;
        if(ptr->next==ptr){
            delete ptr;
            head->next=NULL;
        }
        else{
        while(ptr->next!=head->next){
            prev=ptr;
            ptr=ptr->next;
        }
    // if(prev==head){
    //     head->next=NULL;
    // }
    // else{
        prev->next=head->next;
    }
    delete ptr;
    cout<<"NODE DELETED SUCCESSFULLY\n";
    transverse();
    break;
    }
    case(3):{
        int index;
        node *temp;
        node *ptr;
        temp=head->next;
        cout<<"Enter node Number: ";
        cin>>index;
        if(index<=0){
            cout<<"Invalid Node Number.\n";
            return;
        }
        for(int i=0;i<index;i++){
            if(temp->next==head->next){
                cout<<"Invalid Node Number.\n";
                return;
            }
            ptr=temp;
            temp=temp->next;
        }
        ptr->next=temp->next;
        delete temp;
        cout<<"NODE DELETED SUCCESSFULLY\n";
        transverse();
        break;
    }
    default:{
        cout<<"Invalid choice.";
        break;
    }
        
    }
}
void linkedList :: insert(){
    int choice;
    cout<<" 1:At Beginning \n 2:At End \n 3: After a node\n";
    cout<<"Enter the choice: ";
    cin>>choice;
    switch (choice)
    {
    case (1):{
        node *temp;
        int item;
        temp=new node;
        if((head->next)==NULL){
            temp->next=temp;
        }
        else{
            temp->next=head->next;
        }
        cout<<"Enter the item: ";
        cin>>item;
        temp->item=item;
        // head=temp;
        head->next=temp;
        cout<<endl<<"Data Stored Successfully.";
        transverse();
        return;
    }
    case (2):{
        node *temp;
        node *ptr;
        ptr=new node;
        if((head->next)==NULL){
            head->next=ptr;
            ptr->next=ptr;
            cout<<"Enter the item: ";
            cin>>(ptr->item);
        }
        else{
            temp=head->next;
            while(temp->next!=head->next){
            temp=temp->next;
            }
            cout<<"Enter the item: ";
            cin>>(ptr->item);
            temp->next=ptr;
            ptr->next=head->next;
        }
        transverse();
        return;
    }
    case(3):{
        int index;
        int item;
        node *temp;
        node *ptr;
        temp=head->next;
        if(head->next==NULL){
            cout<<"no node in list";
            return;
        }
        cout<<"Enter node Number: ";
        cin>>index;
        for(int i=0;i<(index-1);i++){
            if(temp->next==head->next || index<0){
                cout<<"Invalid Node Number."<<endl;
                return;
            }
            temp=temp->next;
        }
        ptr=new node;
        ptr->next=temp->next;
        temp->next=ptr;
        cout<<"Enter the item";
        cin>>ptr->item;
        transverse();
        return;
    }
    default:
    {
        cout<<"invalid choice";
    }
    }
    return;

}
int main(){
    linkedList l1;
    bool cons=true;
    int choice;
    while(cons){
    cout<<endl<<"********* MENU **************";
    cout<<endl<<" 1:INSERTION \n 2: DELETION \n 3: PRINT \n 4: End\n";
    cout<<"CHOOSE A OPTION: ";
    cin>> choice;
    switch (choice){
        case(1):{
            l1.insert();
            break;
        }
        case(2):{
            l1.delete_Linklist();
            break;
        }
        case(3):{
            l1.transverse();
            break;
        }
        case(4):{
            cons=false;
            break;
        }
        default:{
            cout<<"INVALID CHOICE."<<endl;
            break;
        }
    }
  }
}