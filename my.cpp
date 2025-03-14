#include<iostream>
using namespace std;
class stack{
    public:
    int *arr;
    int capacity;
    int top;
    int s;
    stack(int size){
        arr = new int[size];
        capacity = size;
        top=-1;
        s = 0;
    }
    void push(int val){
        if(s==capacity){
             cout<<"stackoverflow";
             return;
        }
        arr[s++] = val;
        top = s-1;
    }
    void pop(){
        if(s==0){
            cout<<"stackunderflow";
            return;
        } 
        s--;
        top = s-1;
    }
    int peek(){
        if(s==0) return 0;
        return arr[top];
    }
};
int main(){
  stack x(5);
  x.push(1);
  x.push(2);
  x.push(3);
  x.push(4);
  x.push(5);

  x.pop();
  cout<<x.peek();

  return 0;
  
}