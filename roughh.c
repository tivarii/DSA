#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int pow;
    struct node *next;
};

struct node* head1 = NULL;
struct node* head2 = NULL;
struct node* head3 = NULL;

void traverse() { 

    struct node* temp1 = head1;
    struct node* temp2 = head2;
    struct node* temp3 = head3;

    printf("The First  polynomial  is : ");
    while(temp1!=NULL) {
        if(temp1->pow==0) {
            printf("%d", temp1->coeff);
            break;
        }
        printf("%d", temp1->coeff);
        printf("x");
        printf("^");
        printf("%d", temp1->pow);
        // if((temp1->next->coeff)>0)
            printf("+");
        temp1=temp1->next;
    }

    printf("\n");
    printf("The Second polynomial  is : ");
    while(temp2!=NULL) {
        if(temp2->pow==0) {
            printf("%d", temp2->coeff);
            break;
        }
        printf("%d", temp2->coeff);
        printf("x");
        printf("^");
        printf("%d", temp2->pow);
        printf(" + ");
        temp2=temp2->next;
    }

    printf("\n");
    printf("The Sum of polynomials is : ");
    while(temp3!=NULL) {
        if(temp3->pow==0) {
            printf("%d\n", temp3->coeff);
            break;
        }
        printf("%d", temp3->coeff);
        printf("x");
        printf("^");
        printf("%d", temp3->pow);
        printf(" + ");
        temp3=temp3->next;
    }
    printf("\n**************************************************************\n");
}

void addpolynomial() {
    struct node* temp1 = head1;
    struct node* temp2 = head2;
    struct node* temp3 = head3;
    while(temp1->next&&temp2->next) {
        if(temp1->pow==temp2->pow) {
            struct node* ptr = (struct node*)malloc(sizeof(struct node));
            ptr->coeff=((temp1->coeff)+(temp2->coeff));
            ptr->pow=temp1->pow;
            ptr->next=NULL;
            if(head3==NULL) {
                head3=ptr;
            }
            else {
                while(temp3->next!=NULL) {
                    temp3=temp3->next;
                }
                temp3->next=ptr;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->pow>temp2->pow) {
            struct node*ptr = (struct node*)malloc(sizeof(struct node));
            ptr->coeff=temp1->coeff;
            ptr->pow=temp1->pow;
            ptr->next=NULL;
            temp1=temp1->next;
            if(head3==NULL) {
                head3=ptr;
            }
            else {
                while(temp3->next!=NULL) {
                    temp3=temp3->next;
                }
                temp3->next=ptr;
            }
        }
        else {
            struct node* ptr = (struct node*)malloc(sizeof(struct node));
            ptr->coeff=temp2->coeff;
            ptr->pow=temp2->pow;
            ptr->next=NULL;
            temp2=temp2->next;
            if(head3==NULL) {
                head3=ptr;
            }
            else {
                while(temp3->next!=NULL) {
                    temp3=temp3->next;
                }
                temp3->next=ptr;
            }

        }
    }
    while(temp1||temp2){
        if(temp1!=NULL){
            struct node* ptr = (struct node*)malloc(sizeof(struct node));
            ptr->coeff=temp1->coeff;
            ptr->pow=temp1->pow;
            ptr->next=NULL;
            temp1=temp1->next;
            if(head3==NULL) {
                head3=ptr;
            }
            else {
                while(temp3->next!=NULL) {
                    temp3=temp3->next;
                }
                temp3->next=ptr;
            }
        }
        else{
            struct node* ptr = (struct node*)malloc(sizeof(struct node));
            ptr->coeff=temp2->coeff;
            ptr->pow=temp2->pow;
            ptr->next=NULL;
            temp2=temp2->next;
            if(head3==NULL) {
                head3=ptr;
            }
            else {
                while(temp3->next!=NULL) {
                    temp3=temp3->next;
                }
                temp3->next=ptr;
            }
        }
    }
    traverse();

}

void insert() {

    int check=1, n1, n2, c, p;
    
    printf("**************************************************************\n");
    printf("Enter the number of terms in the first polynomial : ");
    scanf("%d", &n1);
    for(int i = 1; i<=n1; i++) {
        struct node* temp1 = head1;
    
        printf("Enter the coefficient of the term %d : ", i);
        scanf("%d", &c);
        printf("Enter the power of the term %d: ", i);
        scanf("%d", &p);

        struct node* ptr = (struct node*)malloc(sizeof(struct node));
        ptr->coeff=c;
        ptr->pow=p;
        ptr->next=NULL;

        if(head1==NULL) {
           head1=ptr;
        }

        else {
           while(temp1->next!=NULL) {
            temp1=temp1->next;
           }
           temp1->next=ptr;
        }

    }
    printf("***************************************************************\n");
    printf("Enter the number of terms in the second polynomial : ");
    scanf("%d", &n2);
    for(int i = 1; i<=n2; i++) {
        struct node* temp2 = head2;
        printf("Enter the coefficient of the term %d : ", i);
        scanf("%d", &c);
        printf("Enter the power of the term %d: ", i);
        scanf("%d", &p);
        
        struct node* ptr = (struct node*)malloc(sizeof(struct node));
        ptr->coeff=c;
        ptr->pow=p;
        ptr->next=NULL;

        if(head2==NULL) {
           head2=ptr;
        }

        else {
           while(temp2->next!=NULL) {
            temp2=temp2->next;
           }
           temp2->next=ptr;
        }

    }
    printf("***************************************************************\n");
    addpolynomial();

}

int main() {

    int check=1,choice;

    while(check) {
        
        printf("\n");
        printf("                  ****************************\n");
        printf("******************  WELCOME TO THE PROGRAMME  ******************\n");
        printf("                  ****************************\n");
        printf("Press '1' for inserting the polynomials\n");
        printf("Press '0' for taking exit from the programme\n");
        printf("Now enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1  : insert();
                  head1=NULL; head2=NULL; head3=NULL;
            break;

        case 0  : printf("**************** THANKS FOR USING THE PROGRAMME ****************\n");
                  printf("\n");
                  check = 0;
            break;
        
        default : printf("!!Please enter a valid choice only!!\n");
            break;
        }
    }
    return 0;
}