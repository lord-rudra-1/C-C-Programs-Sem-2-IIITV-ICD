#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

char stack[100];
char input[100];
char output[100];

int precedence(char ch);
bool isoper(char ch);
void result();

int i=0,j=0,k=0;

int main()
{
    printf("Enter the Expression :\t");
    scanf("%s",input);
    stack[0] = '(';
    k++;

    for(i=0;input[i]!='\0';i++)
    {
        if(!isoper(input[i]))
        {
            output[j]=input[i];
            j++;
        }
        else
        {
            while(precedence(input[i]) < precedence(stack[k-1]))
            {
                output[j]=stack[k-1];
                j++;
                k--;
            }
            stack[k] = input[i];
            k++;
        }
        
    }

    while(k > 1)
    {
        output[j] = stack[k-1];
        j++;
        k--;
    }

    printf("\nPostfix Expression is :\t%s\n",output);
    result();
    
    
    return 0;
}

int precedence(char ch)
{
    if(ch=='+' || ch == '-')
        return 2;
    else if(ch=='*' || ch == '/')
        return 1;
    else
        return 0;
}

bool isoper(char ch)
{
	if(ch=='*' || ch=='/' || ch=='+' || ch=='-' )
		return true;
	return false;
}

void result()
{
	float result_stack[100];
    int top = -1;

    int ind = 0;
    float res=0,oper1=0, oper2=0 ; 
    
    while(output[ind] != '\0')
    {
        if(!isoper(output[ind]))
        {
        	top++;
            result_stack[top] = output[ind] - '0';
        }
        else
        {
            oper2 = result_stack[top];
            top--;
            oper1 = result_stack[top];
            top--;
     
            switch(output[ind])
            {
                case '+':
                    res = oper1 + oper2;
                    break;
                case '-':
                    res = oper1 - oper2;
                    break;
                case '*':
                    res = oper1 * oper2;
                    break;
                case '/':
                	if(oper2==0)
                	{
                		printf("\nInvalid Expression\n");
                		break;
                	}
                    res = oper1 / oper2;
                    break;
            }
            top++;
            result_stack[top] = res;
        }
        ind++;
    }

    printf("\nResult is: %f\n\n", result_stack[top]); 
}




