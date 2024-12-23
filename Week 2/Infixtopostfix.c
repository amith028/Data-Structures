#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int pos=0,top=-1,idx=0,len;
char symbol,stack[20],infix[20],postfix[20];
void push(char symb);
char pop();
int prece(char symbol);
void infixToPost();
void main(){
    printf("enter the infix expression");
    scanf("%s",infix);
    infixToPost();
    printf("\nthe postfix expression is: %s",postfix);
}
void infixToPost(){
    len=strlen(infix);
    push('#');
    while(idx<len){
        symbol=infix[idx];
        switch(symbol){
            
        case '^':
        case '*':
        case '/':
        case '+':
        case '-': { if(prece(stack[top])>prece(symbol)){
            char symb=pop();
            postfix[pos++]=symb;
            push(symbol);
        }
        else{
            push(symbol);
        } break;
        }
        case '(':{push(symbol);
                break;
        }
        case ')': {
                char symb=pop();
                while (symb!='('){
                    postfix[pos++]=symb;
                    symb=pop();
                }
                break;
        }
        default:{postfix[pos++]=symbol;
                  break;}
    }idx++;
    }
    while(stack[top]!='#'){
        postfix[pos++]=pop();
    }
}
void push(char symb){
    stack[++top]=symb;
}
char pop(){
    char s=stack[top--];
    return s;
}
int prece(char symb){
    int p;
    switch(symb){
        case '^': {
            p=3;
            break;
        }
        case '*': {
            p=2;
            break;
        }
        case '/': {
            p=2;
            break;
        }
        case '+': {
            p=1;
            break;
        }
        case '-': {
            p=1;
            break;
        }
        case '(':p=0;
        break;
        case '#': p=-1;
        break;
    }
    return p;
    }
