#include"queueLL.c"
struct node *tos;
int isEmptyStack(){
    return tos==NULL;
}
void showSt(){
    if(isEmptyStack()){
        printf("Stack is empty");
        return ;
    }
    struct node *tem=tos;
    while(tem){
        printf("\n%d ",tem->item);
        tem=tem->next;
    } 
}
void push(int item){
    struct node * n=(struct node*)malloc(sizeof(struct node));
    n->item=item;
    if(isEmptyStack()){
        n->next=NULL;
        tos=n;
    }
    else{
        n->next=tos;
        tos=n;
    }
}
int pop(){
    if(isEmptyStack()){
        printf("stack is empty");
        return -1;
    }
    else{
        int k=tos->item;
        struct node *tem;
        tem=tos;
        tos=tos->next;
        free (tem);
        return k;
    }
}
int peep(){
    if(isEmptyStack()){
        printf("stack is empty");
        return -1;
    }
    return tos->item;
}