#include <iostream>
#define MAX_SIZE 100
using namespace std;
class Stack {
private:
    int top;
    int stackArray[MAX_SIZE];

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack Overflow. Cannot push element." << endl;
            return;
        }
        stackArray[++top] = value;
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow. Cannot pop element." << endl;
            return;
        }
        int poppedValue = stackArray[top--];
        cout << "Popped " << poppedValue << " from the stack." << endl;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.pop();
    stack.pop();
    return 0;
}
