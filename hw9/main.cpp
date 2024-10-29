//
//  main.cpp
//  hw9
//
//  Created by Valeria Dudinova on 29.10.2024.
//

#include <iostream>
using namespace std;

// Вузол однозв'язного списку
template <typename T>
struct Node
{
    T data;             // Дані вузла
    Node* next;         // Вказівник на наступний вузол
    Node(T value) : data(value), next(nullptr) {}  // Конструктор для створення вузла
};

// Клас "Стек" на основі однозв'язного списку
template <typename T>
class Stack
{
private:
    Node<T>* top;
    int size;

public:
    Stack() : top(nullptr), size(0) {}

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
    
    void push(T value)
    {
        Node<T>* newNode = new Node<T>(value); // Створюємо новий вузол
        newNode->next = top;                   // Встановлюємо вказівник на попередній верхній елемент
        top = newNode;                         // Новий вузол стає верхнім елементом
        size++;                                // Збільшуємо розмір стека
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "The stack is empty. Cannot delete item." << endl;
            return;
        }
        Node<T>* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    T peek() const
    {
        if (isEmpty())
        {
            throw out_of_range("The stack is empty. There is no upper elementа.");
        }
        return top->data;
    }

    // Перевірка, чи порожній стек
    bool isEmpty() const
    {
        return top == nullptr;
    }

    // Повертаємо розмір стека
    int getSize() const
    {
        return size;
    }
};

int main()
{
    Stack<int> stack;                          // Створюємо стек для цілих чисел

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "The top element of the stack: " << stack.peek() << endl;
    cout << "Current stack size: " << stack.getSize() << endl;

    stack.pop();
    cout << "After removing the top element: " << stack.peek() << endl;
    cout << "Current stack size: " << stack.getSize() << endl;

    return 0;
}
