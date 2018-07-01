#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max = 0;
char *max_str;
struct node {
	char str[4];
	int data;
	struct node* left;
	struct node* right;
};

struct node* root[26];
struct node root2[26];

struct node* create_node(char *str) {
	struct node* temp = malloc(sizeof(struct node));
	temp->left = NULL;
	temp->right = NULL;
	temp->data = 1;
	strcpy(temp->str, str);
	return temp;
}
void insert_node(struct node** root, char* str) {
	struct node** p = root;
	while (*p) {
		if (strcmp((*p)->str, str) > 0)
			p = &(*p)->left;
		else if (strcmp((*p)->str, str)<0)
			p = &(*p)->right;
		else {
			(*p)->data++;
			return;
		}
	}
	*p = create_node(str);
}

void in_order(struct node* p) {
	if (p == NULL)return;
	in_order(p->left);
	if (max< p->data) {
		max = p->data;
		max_str = p->str;
	}
	else if (max == p->data) {
		if (strcmp(p->str, max_str)>0)
			max_str = p->str;
	}
	in_order(p->right);
}
int static compare(struct node* first, struct node* second) {
	if (first->data < second->data)return 1;
	else if (first->data == second->data) {
		if (strcmp(first->str, second->str)>0) {
			return 1;
		}
	}
	return -1;
}

void post_order(struct node* p) {
	if (p == NULL)return;
	post_order(p->left);
	post_order(p->right);
	free(p);
}

int main() {
	freopen("./input.txt", "r", stdin);
	int i = 0, n = 0;
	scanf("%d", &n);
	getchar();

	char *token = NULL;
	char *sep = " \t";
	char data[256] = { 0, };
	for (; i<n; i++) {
		gets(data);
		token = strtok(data, sep);
		do {
			if (root[token[0] - 'a'] == NULL) {
				root[token[0] - 'a'] = create_node(token);
			}
			else {
				insert_node(&root[token[0] - 'a'], token);
			}
		} while (token = strtok(NULL, sep));
		memset(data, 0, sizeof(data));
	}

	for (i = 0; i<26; i++) {
		if (root[i] != NULL) {
			in_order(root[i]);

			root2[i].data = max;
			strcpy(root2[i].str, max_str);

			max = 0, max_str = NULL;
		}
	}

	qsort(root2, 26, sizeof(struct node), compare);

	for (i = 0; i<26; i++) {
		if (root2[i].data != 0) {
			printf("%s : %d\n", root2[i].str, root2[i].data);
		}
	}

	for (i = 0; i<26; i++) {
		if (root[i] != NULL) {
			post_order(root[i]);
		}
	}

	return 0;
}
