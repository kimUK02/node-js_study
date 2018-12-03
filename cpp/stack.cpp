#include <iostream>
using namespace std;
class Stack
{
    int top;
    int *arr;
    int length;
    
public:
    Stack(int length){
        this->length = length;
        top = -1;
        arr = new int[length];
    }
    void SPush(int Data,int length){
        if(is_full(length) == true){
        arr[++top] = Data;
        length++;
        }
        cout << "Can't ";
    }
    int SPop(){
        if(this->is_emty() == false){
        length--;
        return arr[top--];
        }
        cout<<"Can't Push"<<endl;
        return -1;
    }
    void SPrint(){
        for(auto i = 0;i < this->length-1;i++ )
        {
            cout << arr[i];
        }    
    }
    bool is_emty(){
        if(this->top == -1) return true;
        else return false;
    }
    bool is_full(int length){
        if(this->length < length){
            return true;
        }
        else return false;
    }
};

int main(){
    int length =5;
    Stack myStack(length);
    
    myStack.SPush(4,length);
    myStack.SPush(5,length);
    myStack.SPush(6,length);
    myStack.SPush(7,length);
    myStack.SPush(8,length);
    cout<<myStack.SPop();
    cout<<myStack.SPop();
    cout<<myStack.SPop();
    cout<<myStack.SPop();
}