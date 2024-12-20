// algorithm
// parenthesis match/
// { [ ( - push
// } ] ) - pop

#include<stdio.h>
#include<stdlib.h>

int pmatch(char *expr) {
    char s[20],ch;
    int top = -1;
    int i = 0;
    while(expr[i] != '\0') 
    {
        ch = expr[i];
        switch(ch) {
            case  '(':
                  '{':
                  '[':
                    push(s,&top,ch);
                    break;

            case ')':
                    if(!isempty(top))
                        {
                            x = pop(s,&top);
                            if(x=='}')
                            break;
                            return 0;
                        }
             case '}':
                    if(!isempty(top))
                        {
                            x = pop(s,&top);
                            if(x=='}')
                            break;
                            return 0;
                        }
             case ']':
                    if(!isempty(top))
                        {
                            x = pop(s,&top);
                            if(x==']')
                            break;
                            return 0;
                        }
        }

    }
    return 0;
 }

 int isempty(int t) {
    if(t==-1)
    return 1;
    return 0;
 }


 void push(char *s, int *t, char ch) {
    (*t)++;


 }

 int pop() {
    
 }

int main()
{
    char expr[20];
    printf("enter the expression\n");
    scanf("%s",&expr);
    int k = pmatch(expr);
    if(k) {
        printf("match\n");
    }
    else{
        printf("does not match\n");
    }
    return 0;
}