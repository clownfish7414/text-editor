#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node{
    char data;
    struct _Node* next;
    struct _Node* before;
}Node;




void newnode(Node **head, char word){
    Node *new=malloc(sizeof(Node));
    new->data=word;
    new->before=(*head);
    new->next=(*head)->next;
    (*head)->next->before=new;
    (*head)->next=new;
    (*head)=new;
    //printf("finish");


}

void leftnode(Node **head){
    *head=(*head)->before;
}

void rightnode(Node **head){
    *head=(*head)->next;

}

void deletenode(Node **head){
    (*head)->next->before=(*head)->before;
    (*head)->before->next=(*head)->next;
    Node*temp=(*head);
    (*head)=(*head)->before;
    free(temp);

    
}

int main(){
    int T;
    
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        Node *head=(Node*)malloc(sizeof(Node));
        Node *end=(Node*)malloc(sizeof(Node));
        
        head->next=end;
        end->before=head;
        
        int wordnum;
        Node *temp=head;
        scanf("%d",&wordnum);
        getchar();
        for(int j=0;j<wordnum;j++){
           
            char word;
            scanf("%c",&word);
            if(word=='L'){
                leftnode(&head);
            }
            else if(word=='B'){
                deletenode(&head);
            }
            else if(word=='R'){
                rightnode(&head);
            }
            else{
                //printf("newword");
                newnode(&head,word);
            }

        
        }

        Node*tamp=temp;
        while(temp!=end){
            Node* temp1=temp;
            if(temp!=tamp){
                printf("%c",temp->data);
            }
            
            
            temp=temp->next;
            free(temp1);
            
        }
        printf("\n");
        free(temp);

        

       
        
        
    }
}