#include <iostream>
using namespace std;

int stack[50];
int tos = 0;

void push(int a)
{
    stack[tos] = a;
    tos++;
}

void pop(int a)
{
    tos--;
}

void display()
{
    cout << "\nStack is:\t";
    for (int i = 0; i < tos; i++)
        cout << stack[i] << "\t";
    cout << endl;
}

int fibo(int n)
{
    push(n);
    display();

    if (n == 1 || n == 0)
    {
        pop(n);
        return 0;
    }

    if (n == 2)
    {
        pop(n);
        return 1;
    }

    int t1 = fibo(n - 1);
    int t2 = fibo(n - 2);

    pop(n);
    return t1 + t2;
}

int main()
{
    int n;
    cout << "enter the no. of term" << endl;
    cin >> n;
    int nth_term = fibo(n);
    display();
    cout << "\nthe nth term is\t" << nth_term << endl<< endl;
    return 0;
}
