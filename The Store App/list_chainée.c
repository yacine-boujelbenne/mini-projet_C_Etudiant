#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct peopleListe{
    int age;
    char *name;
    struct peopleListe *next;
};
struct peopleListe *createNode(int age,const char *name) {
    struct peopleListe *newnode=malloc(sizeof(struct peopleListe));
    if (newnode==NULL){
        printf("malloc failed");
        return NULL;
    }
    newnode->age=age;
    newnode->name=strdup(name);
    newnode->next=NULL;
    return newnode;
}

void pushFront(struct peopleListe **head,int age,const char *name){
    struct peopleListe *newnode=createNode(age,name);
    newnode->next=*head;
    *head=newnode;
}
void pushBack(struct peopleListe **back,int age,const char *name){
    struct peopleListe *newnode=createNode(age,name);
    if(*back==NULL){
        *back=newnode;
        return;
    }
    struct peopleListe *current=*back;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=newnode;
}
void printlist(struct peopleListe *head){
    struct peopleListe *current=head;
    while(current!=NULL){
        printf("Nom: %s,age: %d\n",current->name,current->age);
        current=current->next;
    }
}
void popFront(struct peopleListe **head){
    if(*head==NULL){
        puts("la liste est deja vide");
        return;
    }
    struct peopleListe *temp=*head;
    *head=(*head)->next;
    free(temp);

    }
void popBack(struct peopleListe **head){
    if(*head==NULL){
        puts("la liste est vide");
        return;
    }
    if((*head)->next==NULL){
        free((*head)->name); 
        free(*head);
        *head=NULL;
        return;
    }
    struct peopleListe *current=*head;
    while(current->next->next!=NULL){
        current=current->next;
    }
    free(current->next->name);
    free(current->next);
    current->next=NULL;
}
void insetAt(struct peopleListe **head,int position,int age,char* name){
    if (position<0){
        printf("invalide position");
        return;
    }
    if (position==0){
        pushFront(head,age,name);
        return;
    }
    struct peopleListe *newnode=createNode(age,name);
    struct peopleListe *current=*head;
    int currentPosition=0;
    while(current!= NULL && currentPosition<position-1){
        current=current->next;
        currentPosition++;
    
    }if (current==NULL){
        puts("position invalide");
        free(newnode->name);
        free(newnode);
        return; 
    }
    newnode->next=current->next;
    current->next=newnode;
}
void removeAt(struct peopleListe **head,int position){
        if (position<0 || *head==NULL){
        printf("invalide position");
        return;
    }
    if (position==0){
        popFront(head);
        return;
    }
    struct peopleListe *current=*head;
    int currentPosition=0;
    while(current!=NULL && currentPosition<position-1){
        current=current->next;
        currentPosition++;
    }
    if (current->next==NULL ){
        puts("Position invalide");
        return;
    }
    struct peopleListe *temp=current->next;
    current->next=current->next->next;
    free(temp->name);
    free(temp);

}

int main(){
    struct peopleListe *mylist=NULL;
    pushFront(&mylist,25,"Toto");
    pushFront(&mylist,21,"hazem");
    pushFront(&mylist,19,"farah");
    pushBack(&mylist,69,"zed");
    popBack(&mylist);
    popBack(&mylist);
    insetAt(&mylist,1,24,"Hamza");
    printlist(mylist);
    puts("__________");
    removeAt(&mylist,1);
    printlist(mylist);  
    return 0;
}