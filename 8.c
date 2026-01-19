#include <stdio.h>
#include <stdlib.h>

struct emp{
    int ssn;
    char name[50],dept[20],desg[20];
    float sal;
    unsigned long long phno;
    struct emp *prev,*next;
};

struct emp *front=NULL,*rear=NULL;

struct emp* createEmp(){
    struct emp *temp=(struct emp*)malloc(sizeof(struct emp));
    printf("Enter SSN, Name, Dept, Designation, Salary, Phone:\n");
    scanf("%d %s %s %s %f %llu",
          &temp->ssn,temp->name,temp->dept,
          temp->desg,&temp->sal,&temp->phno);
    temp->prev=temp->next=NULL;
    return temp;
}

void insertFront(){
    struct emp *temp=createEmp();
    if(front==NULL) front=rear=temp;
    else{temp->next=front;front->prev=temp;front=temp;}
}

void insertRear(){
    struct emp *temp=createEmp();
    if(front==NULL) front=rear=temp;
    else{rear->next=temp;temp->prev=rear;rear=temp;}
}

void deleteFront(){
    struct emp *temp;
    if(front==NULL){printf("List is empty\n");return;}
    temp=front;
    printf("Deleted: %d %s\n",temp->ssn,temp->name);
    front=front->next;
    if(front!=NULL) front->prev=NULL;
    else rear=NULL;
    free(temp);
}

void deleteRear(){
    struct emp *temp;
    if(rear==NULL){printf("List is empty\n");return;}
    temp=rear;
    printf("Deleted: %d %s\n",temp->ssn,temp->name);
    rear=rear->prev;
    if(rear!=NULL) rear->next=NULL;
    else front=NULL;
    free(temp);
}

void display(){
    struct emp *p=front;
    int count=0;
    if(p==NULL){printf("List is empty\n");return;}
    printf("Employee Records:\n");
    while(p!=NULL){
        printf("%d %s %s %s %.2f %llu\n",
               p->ssn,p->name,p->dept,
               p->desg,p->sal,p->phno);
        p=p->next;count++;
    }
    printf("Total employees = %d\n",count);
}

int main(){
    int ch;
    while(1){
        printf("\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Exit\n");
        scanf("%d",&ch);
        switch(ch){
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
