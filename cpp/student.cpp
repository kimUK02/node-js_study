#include <iostream>
using namespace std;
class student{
    int id, score;
    string name;
public:
    student(){
        this->id = 0;
        this->score =0;
    }
    student(int id, int score, string name= "",int size = 0){
        this->id = id;
        this->score = score;
        this->name = new char[size];
        this->name = name;
    }
    void set(int id, int score){
        this->id = id;
        this->score = score;
    }
    void print(){
        cout<< this->id <<": " << this->score << ": "<<this->name<<endl;
    }
};

int main(int argc, char const *argv[])
{
    student st1(1,2);
    st1.print();
    st1.set(10,20);
    st1.print();
    student st2;
    st2.print();
    student st3(3,4,"kim",sizeof("kim"));
    st3.print();
    return 0;
}
