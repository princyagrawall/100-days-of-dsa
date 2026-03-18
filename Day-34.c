#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int x){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

int pop(){
    if(top==NULL){
        printf("Stack Underflow");
        exit(1);
    }
    struct node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int evaluate(char* exp){
    int i=0;
    while(exp[i]!='\0'){
        
        if(exp[i]==' '){
            i++;
            continue;
        }

        if(isdigit(exp[i])){
            push(exp[i]-'0');
        }
        else{
            int b = pop();
            int a = pop();
            int res;

            switch(exp[i]){
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }

            push(res);
        }
        i++;
    }
    return pop();
}

int main(){
    char exp[100];

    printf("Enter postfix expression:\n");
    fgets(exp,100,stdin);

    int result = evaluate(exp);

    printf("%d",result);

    return 0;
}