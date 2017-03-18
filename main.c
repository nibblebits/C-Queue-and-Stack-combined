#include <stdio.h>

#define STACK_SIZE 50
#define MIDDLE_STACK STACK_SIZE / 2
int array[STACK_SIZE];
int rear = MIDDLE_STACK;
int front = MIDDLE_STACK;
int size = 0;

void stack_overflow()
{
    printf("Stack overflow!\n");
}

int get_stack_size()
{
    return size;
}

int pop_front()
{
    int elem = array[front];
    if (front == STACK_SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    size--;
    return elem;
}

void push_front(int i)
{
    if (front == 0)
    {
        stack_overflow();
        return;
    }
    
    front--;
    array[front] = i;
    size++;
    
}
void push_back(int i)
{
    array[rear] = i;
    if (rear == STACK_SIZE - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    size++;
}

int pop_back()
{
    if (rear == 0)
    {
        rear = STACK_SIZE - 1;
    }
    else
    {
        rear--;
    }
    int elem = array[rear];
    return elem;
    size--;
}

int main()
{
    push_back(10);
    push_back(20);
    push_back(30);
    push_back(40);
    push_back(50);
    push_back(60);
    push_front(99);
    
    printf("\n");
    int size = get_stack_size();
    printf("Rear %i, Front %i\n", rear, front);
    printf("Stack size: %i\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("%i\n", pop_front());
    }

    printf("Stack size: %i\n", get_stack_size());

}
