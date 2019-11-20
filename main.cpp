// Example program
#include <iostream>
#include <stack>

void move(std::stack<int>& first, std::stack<int>& second){
    second.push(first.top());
    first.pop();
}

void show(std::stack<int> s){
    while(!s.empty()){
        std::cout << s.top();
        s.pop();
    }
    std::cout << "\n";
}

void showAll(std::stack<int> a, std::stack<int> b, std::stack<int> c){
    show(a);
    show(b);
    show(c);
}

void initialize(std::stack<int>& a){
    a.push(5);
    a.push(4);
    a.push(3);
    a.push(2);
    a.push(1);
}


int main()
{
    std::stack <int> a, b, c;

    initialize(a);


    move(a, b);
    move(b, c);
    move(a, b);


    showAll(a, b, c);


 return 0;
}
