#include <stdio.h>
#include <stdlib.h>

struct student{
    char usn[20];
    char name[50];
    char branch[10];
    int sem;
    unsigned long long phno;
    struct student *next;
};

struct student *front=NULL;
struct student *rear=NULL;

struct student* createStudent(){
    struct student *temp;
    temp=(struct student*)malloc(sizeof(struct student));
    printf("Enter USN, Name, Branch, Sem, Phone:\n");
    scanf("%s %s %s %d %llu",
          temp->usn,temp->name,temp->branch,
          &temp->sem,&temp->phno);
    temp->next=NULL;
    return temp;
}

void insertFront(){
    struct student *temp=createStudent();
    if(front==NULL){
        front=rear=temp;
    }else{
        temp->next=front;
        front=temp;
    }
}

void insertRear(){
    struct student *temp=createStudent();
    if(front==NULL){
        front=rear=temp;
    }else{
        rear->next=temp;
        rear=temp;
    }
}

void deleteFront(){
    struct student *temp;
    if(front==NULL){
        printf("Student list is empty\n");
        return;
    }
    temp=front;
    printf("Deleted student: %s %s\n",temp->usn,temp->name);
    front=front->next;
    free(temp);
    if(front==NULL)
        rear=NULL;
}

void deleteRear(){
    struct student *prev;
    if(front==NULL){
        printf("Student list is empty\n");
        return;
    }
    if(front->next==NULL){
        printf("Deleted student: %s %s\n",front->usn,front->name);
        free(front);
        front=rear=NULL;
        return;
    }
    prev=front;
    while(prev->next!=rear)
        prev=prev->next;
    printf("Deleted student: %s %s\n",rear->usn,rear->name);
    free(rear);
    rear=prev;
    rear->next=NULL;
}

void display(){
    struct student *p=front;
    int count=0;
    if(p==NULL){
        printf("Student list is empty\n");
        return;
    }
    printf("\nStudent Records:\n");
    while(p!=NULL){
        printf("%s %s %s %d %llu\n",
               p->usn,p->name,p->branch,
               p->sem,p->phno);
        p=p->next;
        count++;
    }
    printf("Total students = %d\n",count);
}

int main(){
    int choice;
    while(1){
        printf("\n1.Insert Front");
        printf("\n2.Insert Rear");
        printf("\n3.Delete Front");
        printf("\n4.Delete Rear");
        printf("\n5.Display");
        printf("\n6.Exit");
        printf("\nEnter choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:insertFront();break;
            case 2:insertRear();break;
            case 3:deleteFront();break;
            case 4:deleteRear();break;
            case 5:display();break;
            case 6:exit(0);
            default:printf("Invalid choice\n");
        }
    }
}
