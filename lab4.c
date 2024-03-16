#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define STK_SIZE 10
void push(char [], int*, char);
char pop(char [], int*);
int precd(char);
int main()
{
int i, j=0;
char expr[50], stack[50], post[50], symb;
int top = -1;
printf("\nEnter a valid infix expression\n");
scanf("%s", expr);
push(stack, &top, '#');
for(i=0;expr[i]!='\0'; ++i)
{
symb = expr[i];
if(isalnum(symb))
{
post[j++] = symb;
}
else if(symb == '(')
{
push(stack, &top, symb);
}
else if(symb == ')')
{
while(stack[top] != '(')
{
post[j++] = pop(stack, &top);
}
pop(stack, &top);
}
else

{
while(precd(stack[top]) >= precd(symb))
{
if((symb == '^') && (stack[top] == '^'))
break;
 post[j++] = pop(stack, &top);
}
push(stack, &top, symb);
}
}
while(stack[top] != '#')
{
post[j++] = pop(stack, &top);
}
post[j] = '\0';
printf("\nInfix Expression is %s\n", expr);
printf("\nPostfix Expression is %s\n", post);
return 0;
}
void push(char Stack[], int *t , char elem)
{
*t = *t + 1;
Stack[*t] = elem;
}
char pop(char Stack[], int *t)
{
char elem;
elem = Stack[*t];
*t = *t -1;
return elem;
}
int precd(char ch)
{
int precdval;
switch(ch)
{
case '#' : precdval = -1; break;
case '(' : precdval = 0; break;
case '+' :
case '-' : precdval = 1; break;
case '%' :
case '*' :
case '/' : precdval = 2; break;
case '^' : precdval = 3; break;
}
return precdval;
}