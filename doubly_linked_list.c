#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head = NULL;
struct node ptr;
//struct node *temp;

void ins_beg();
void ins_end();
void del_beg();
void del_end();
void traverse1();
void traverse2();

int main(){
	int choice, n;
	
	while(1){
		printf("\nenter the choice\n");
		printf("1. ins_beg\n2. ins_end\n3. del_beg\n4. del_end\n5. traverse1\n6. traverse2\n7. exit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
					ins_beg();
					break;
			case 2:
					ins_end();
					break;
			case 3:
					del_beg();
					break;
					
			case 4:
					del_end();
					break;
			case 5:
					traverse1();
					break;
			case 6:
					traverse2();
					break;
			default:
					exit(1);
		}
	}
}
	void ins_beg(){
		struct node *ptr = NULL;
		ptr = (struct node*)malloc(sizeof(struct node));
		printf("enter the data\n");
		scanf("%d",&ptr->data);
		ptr->next = NULL;
		ptr->prev = NULL;

		if(head == NULL)
			head = ptr;
		else{
			head->prev = ptr;
			ptr->next = head;
			head = ptr;
		}
	}
	
	void ins_end(){
		struct node *temp = head;
		struct node *ptr = NULL;
		ptr = (struct node*)malloc(sizeof(struct node));
		printf("enter the data\n");
		scanf("%d",&ptr->data);
		ptr->next = NULL;
		ptr->prev = NULL;

		if(head == NULL)
			head = ptr;
		else{
			while(temp->next!= NULL)
				temp = temp->next;
			ptr->prev = temp;
			temp->next = ptr;
			}
		}
		
	void del_beg(){
		struct node *temp = head;
		if(head == NULL)
			printf("no item to delete\n");
		else
			head = head->next;
			head->prev = NULL;
			free(temp);
			temp = NULL;
	}
	
	void del_end(){
		struct node *temp = head;
		struct node *temp1 = head;
		if(head == NULL)
			printf("no item to delete\n");
		else{
			while(temp1->next != NULL){
				temp = temp1;
				temp1 = temp1->next;
				}
	    	if(temp1 == head)
	    		head = NULL;
			else
			 	temp->next = NULL;
			 	temp1->prev = NULL;
				free(temp1);
				temp1 = NULL;
			}
	}

	void traverse1(){
		struct node *temp = head;
		while(temp != NULL){
			printf("%d ",temp->data);
			temp = temp->next;
		}
	}
	
	void traverse2(){
	struct node *temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp = temp->prev;
			}
	}
	
