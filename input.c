#include<stdio.h>
#include<stdlib.h>
typedef struct list{
    int data;
    struct list* link;
}slist;

int p_list(slist *head){
    if(head==NULL){
        printf("list is empty\n");
        return 0;
    }

    while(head!=NULL){
        printf("%d-->",head->data);//
        head=head->link;       
    }
    printf("NULL\n");

}
int i_first(slist **head,int data){

    slist *new=malloc(sizeof(slist));

    if(new == NULL){
        printf("the mem allocation is failed");
        return -1;
    }
    []
    new->data=data;
    new->link=*head;
    *head=new;

}
int main(){

    slist *head=NULL;
    p_list(head);
    i_first(&head,30);
    i_first(&head,20);
    i_first(&head,10);
    i_first(&head,5);
    p_list(head);
}