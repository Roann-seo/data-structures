#include<iostream>
#include<stack>
#include<vector>
#define Smax 100
using namespace std;
typedef struct stack{
    int data[Smax];
    int top;
}Stack;
typedef struct {
    int *data;
    int front;
    int rear;
}