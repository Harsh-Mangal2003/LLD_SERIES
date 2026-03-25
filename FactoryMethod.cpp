#include <iostream>
using namespace std;
class Burger{
    public:
    virtual void prepare()=0;
    virtual ~Burger() {}
};

class BasicBurger:public Burger{
    public:
    void prepare() override{
        cout<<"Preparing Basic Burger";
    }
};

class StandardBurger:public Burger{
    public:
    void prepare() override{
        cout<<"Preparing Standard Burger";
    }
};
class PremiumBurger:public Burger{
    public:
    void prepare() override{
        cout<<"Preparing Premium Burger";
    }
};

class BasicWheat:public Burger{
    public:
    void prepare() override{
        cout<<"Preparing Basic Wheat Burger";
    }
};

class StandardWheat:public Burger{
    public:
    void prepare() override{
        cout<<"Preparing Standard Wheat Burger";
    }
};
class PremiumWheat:public Burger{
    public:
    void prepare() override{
        cout<<"Preparing Premium Wheat Burger";
    }
};



class BurgerFactory{
    public:
   virtual Burger* createBurger(string& type)=0;
    
};
class SinghBurger:public BurgerFactory{
    public:
    
    Burger* createBurger(string& type) override{
        if(type=="basic")
        return new BasicBurger();
        else if(type=="Standard")
        return new StandardBurger();
        else if (type=="Premium")
        return new PremiumBurger();
        else
        {cout<<"Invalid type selection"<<endl;
        return nullptr;
    }
    }
    
};

class KingBurger:public BurgerFactory{
    public:
    
    Burger* createBurger(string& type) override{
        if(type=="basic wheat")
        return new BasicWheat();
        else if(type=="Standard Wheat")
        return new StandardWheat();
        else if (type=="Premium Wheat")
        return new PremiumWheat();
        else
        {cout<<"Invalid type selection"<<endl;
        return nullptr;
    }
    }
    
};

int main(){
    string type="Standard";
    BurgerFactory* myBurgerFactory=new SinghBurger();
    Burger* burger=myBurgerFactory->createBurger(type);

    return 0;
}
