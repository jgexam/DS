// initial->push ,end-> pop
// Brecket program
// output should valid when all the breckets complete properly
// exp (<{[]}>) => valid ..... (>{[]}>) => not valid.
#include<stdio.h>
#include<string.h>
void push(char bct);
int pop(char bct);
int isMatch(char bct);

struct node{
	char data;
	struct node* next;
};
struct node* top = NULL;

void main(){
	int i;
	int flag = 1;
	char exp[100];
	clrscr();
	gets(exp);
	for(i=0;i<strlen(exp);i++){
		if(exp[i] == '{' || exp[i] == '<' || exp[i] == '['
			|| exp[i] == '(')
		{
			push(exp[i]);
		} else if(exp[i] == '}' || exp[i] == '>' || exp[i] == ']'
			|| exp[i] == ')' )
		{
			if(pop(exp[i])==0){
				flag = 0;
				break;
			}
		} else {
			flag = 0;
			break;
		}
	}

	if(flag == 1 && top == NULL){
		printf("\nValid");
	} else {
		printf("\nInvalid");
	}

	getch();
}

void push(char bct){
	struct node* n1;
	n1 = (struct node*)malloc(sizeof(struct node));
	n1->data = bct;
	n1->next = NULL;
	if(top == NULL){
		top = n1;
	} else {
		n1->next = top;
		top = n1;
	}
}

int pop(char bct){
	int match = 0;
	struct node* temp;
	if(bct == ')'){
		match = isMatch('(');
	} else if (bct == '}'){
		match = isMatch('{');
	} else if (bct == '>'){
		match = isMatch('<');
	} else {
		match = isMatch('[');
	}

	if(match == 1){
		temp = top;
		top = top->next;
		free(temp);
		return 1;
	} else {
		return 0;
	}
}

int isMatch(char bct){
	if(top->data==bct){
		return 1;
	}
	return 0;
}