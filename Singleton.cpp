#include <iostream>
using namespace std;
class Singleton{


    private:
   static Singleton* instance;//c++ me yahan directly nahi kar sakte
    Singleton(){
        cout<<"Singleton constructor called New Object Created"<<endl;
    }

    public:
    static Singleton* getInstance(){//static class ko belong karega isko call karne ke liye sirf class ka name naki object ka nam
        
            if(instance==nullptr)
           instance= new Singleton();
    
    return instance;

};
};

Singleton* Singleton::instance=nullptr;

int main(){
    Singleton* s1= Singleton::getInstance();
    Singleton* s2= Singleton::getInstance();
    cout<<(s1==s2)<<endl;
}

//multithreading me problem hoga its not thread safe .. lock use karna hoga .. critical section 