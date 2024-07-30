#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct  {
    char name[MAX];
    int age;
    struct node* next_addr;
}node;

void insert_data(node *head,node *p);
void delete_data(node *head,node *p);
void display_data(node *head,node *p);

int main() {

    void (*function_pointer[3])(node *head) = {insert_data, delete_data, display_data};

    node *head,*p;

    int choice;

    printf("Linked List\n");
    printf("1. Insert Data\n");
    printf("2. Delete Data\n");
    printf("3. Display Data\n");
    printf("4. Exit\n");

    scnaf("%d", &choice);
    if(choice == 4) {
        exit(0);
    }
    else if(choice > 1 && choice < 4) {
        function_pointer[choice-1](head,p);

    }
    else {
            printf("Invalid Choice\n");
             exit(0);
    }
    
}

void insert_data(node *head,node *p) {
    static int i=0
    node *temp;
    if(i == 0) {
        temp = (node *)malloc(1,sizeof(node));
        head = temp;
        head->next_addr = NULL;
        printf("\n\n Enter Name: ");
        scanf("%s", head->name);
        printf("\n\n Enter Age: ");
        scanf("%d", head->age);
        printf("\n\n Data Inserted\n");
        i++;
    }
    else {

        temp = (node *)malloc(1,sizeof(node));
        printf("\n\n Enter Name :");
        scanf("%s",temp->name);
        printf("\n\n Enter the age :");
        scanf("%d",temp->age);
        if(head->next_addr == NULL) {
            head->next_addr = temp;
            temp->next_addr = NULL;
            p=temp;
        }  
        else {

            temp->next_addr = NULL;
            p->next_addr = temp;
            p=temp;
        }
        i++;
    }
}
