#include <iostream>
using namespace std;
template <typename T>
class AutoArray
{
private:
    T* _ptr;
public:
    AutoArray(T* ptr) {
        this->_ptr = ptr;
    }

    T& operator[](int i){
        return this->_ptr[i];
    }
};
int main(){
    AutoArray<float> arr(new float[100]);
    arr[0] = 99.99f;

    cout<< arr[0] <<endl;
    return 0;
}


