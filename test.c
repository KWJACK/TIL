#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct mem{
	char *str;
	int hit_num;//hit 된 갯수
	struct mem *next;
}MEM;


typedef struct node{
	char alpha;
	char *star;//제일 빈도 수 높은 문자
	int max;//알파벳에서 빈도수가 가장 높은 문자의 hit 수
	MEM *m_mem; //head
	struct node *next;
} NODE;


void check_mem(NODE* node, MEM* head, char *str){
	MEM* temp;
	for (temp->next; temp != head; temp = temp->next)
	{
		if(strcmp(temp->str, str)==0){
			temp->hit_num++;//add oK
			return;
		}
	}
	create_mem(node, str);
}


void create_mem(NODE* target, char *str){
	MEM* new = malloc(sizeof(MEM));
	new->str = str;
	new->next = NULL;	
	new->hit_num = 0;
	insert_mem(target->m_mem, new);
}

NODE* create_node(char alpha){
	NODE* new = malloc(sizeof(NODE));
	new->alpha=NULL;

	MEM* mem = malloc(sizeof(mem));//m_mem head
	mem->next=mem;
	new->m_mem = mem;

	return new;
}

void insert_node(NODE* s, NODE* temp)
{
	temp->next = s->next;
	s->next = temp;
}

void insert_mem(MEM* s, MEM* temp)
{
	temp->next = s->next;
	s->next = temp;
}


#define	STAND 97
int main()
{

	freopen("./input.txt", "r", stdin); 
	NODE* head = malloc(sizeof(NODE));
	head->next= head;

	char alpha_mem[26]={0,};

	char data[256]={0,};

	int n=0, i=0;

	char *tab =" \t\n";	
	char *token;

	scanf("%d", &n);
	getchar();

	for(i=0;i<n;i++){
		gets (data);
		token = strtok(data, tab);
		while (token != NULL) {
			if(alpha_mem[token[0]-STAND]==0){
				alpha_mem[token[0]-STAND]++;											
				NODE* new = create_node(token[0]);
				insert_node(&head, new);
			}

			NODE* temp = head;

			do {
				check_mem(temp, temp->m_mem, token);
				temp = temp->next;
			}while(temp==head);

			temp =head;
			for (temp = head->next; temp != head ; temp = temp->next){
				printf(temp->m_mem->hit_num);
			}	

			token = strtok(NULL, tab);
		}

		memset(data, 0, 256);
		memset(alpha_mem,0,26);

	}
	return 0;
}

