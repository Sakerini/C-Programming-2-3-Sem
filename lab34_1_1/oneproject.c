#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define ERR_ARGS 1
#define ERR_OPEN_FILE 2
#define ERR_READ_FILE 3

typedef struct node_t
{
	int data;
	struct node_t *next;
}node_t;

node_t *new_node(int num){
	node_t *tmp = NULL;
	tmp = malloc(sizeof(node_t));
	if (!tmp)
		return NULL;
	
	tmp->data = num;
	tmp->next = NULL;
	return tmp;
}

void insert_rear(node_t **head, node_t *elem)
{
	if (*head == NULL)
	{
		*head = elem;
		return;
	}
	
	node_t *tmp = *head;
	while(tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elem;
}


void free_list(node_t *head)
{
	node_t *temp = head, *move;
	while (temp)
	{
		move = temp->next;
		free(temp);
		temp = move;
	}
}

double list_find_arif(node_t *head){
	node_t *tmp = head;
	int sum = 0, count = 0;
	while(tmp)
	{
		sum +=tmp->data;
		count++;
		tmp = tmp->next;
	}
	return (double) sum / count;
}

void delete_elem(node_t **head, node_t *elem)
{
	node_t * tmp = *head;
	if (tmp == elem){
		*head = (*head)->next;
		free(tmp);
		return;
	}
	
	while(tmp)
	{
		if(tmp->next == elem)
		{
			tmp->next = elem->next;
			free(elem);
			return;
		}
		tmp = tmp->next;
	}
}

void delete_lower(node_t **head)
{
	double lower = list_find_arif(*head);
	node_t *tmp = *head, *move;
	
	while(tmp)
	{
		move = tmp->next;
		if (tmp->data > lower)
			delete_elem(head, tmp);
		
		tmp = move;
	}
}

void read_nums(FILE *f, node_t **head)
{
	int buff;
	while(!feof(f)){
		if (fscanf(f, "%d", &buff) == 1)
		{
			//printf("hi");
			insert_rear(head, new_node(buff));
			//printf("%d", (*head)->data);
		}
	}
}

void list_print(node_t *head){
	node_t *tmp = head;
	while(tmp){
		printf("%d ", tmp->data);
		tmp=tmp->next;
	}
}

int main (int args, char **argv)
{
	setbuf(stdout, NULL);
	int rc = OK;
	if (args != 2)
		return ERR_ARGS;
	
	//printf("arg fine argv[1]: %s", argv[1]);
	FILE *f;
	f = fopen(argv[1], "r");
	if (!f)
		return ERR_OPEN_FILE;
	
	//file openned
	//printf("fileOPENED");
	
	node_t *head_node = NULL;
	read_nums(f, &head_node);
	if (!head_node) //if list is empty
		return ERR_READ_FILE;
	//printf("not empty");
		
	delete_lower(&head_node);
	list_print(head_node);
	
	free_list(head_node);
	fclose(f);
	return rc;
}