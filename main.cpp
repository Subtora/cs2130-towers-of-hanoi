// Example program
#include <iostream>
#include <stack>

std::stack <int> a, b, c;
int size = 5;
int count = 0;

//METHODS

void move(std::stack<int>& first, std::stack<int>& second);

bool checkValidity(std::stack<int> a, std::stack<int> b);

void show(std::stack<int> s);

void showAll(std::stack<int> a, std::stack<int> b, std::stack<int> c);

void initialize(std::stack<int>& s);


//DEFINITIONS

void move(std::stack<int>& first, std::stack<int>& second){
  if(checkValidity(first, second)){
    second.push(first.top());
    first.pop();
    std::cout <<"success\n";
  }else{
    std::cout <<"fail\n";
  }
  count++;
  showAll(a, b, c);
}

bool checkValidity(std::stack<int> a, std::stack<int> b){
  bool valid = true;
  while(!b.empty()){
        if(b.top() < a.top()) valid = false;
        b.pop();
  }
  return valid;
}

void show(std::stack<int> s){
  std::cout << "stack: ";
    while(!s.empty()){
        std::cout << s.top();
        s.pop();
    }
    std::cout << "\n";
}

void showAll(std::stack<int> a, std::stack<int> b, std::stack<int> c){
  std::cout << "\nRESULT:\n";
    show(a);
    show(b);
    show(c);
    std::cout << "\n";
}

void initialize(int size, std::stack<int>& s){
    for (int i = size; i > 0; i--) {
      s.push(i);
    }
}


void toh(int size, std::stack<int> &from, std::stack<int> &to, std::stack<int> &aux) {
  if (size == 1) {
    move(from, to);
    return;
  }
  toh(size - 1, from, aux, to);
  move(from, to);
  toh(size - 1, aux, to, from);
}

int main()
{

    initialize(size, a);

    toh(size, a, c, b);

    std::cout << count << "\n";

 return 0;
}
