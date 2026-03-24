#include <iostream>
using namespace std;

class WalkableRobot{
    public:
    virtual void walk()=0;
    virtual ~WalkableRobot() {}
};

class NormalWalk:public WalkableRobot{

    public:
    void walk() override{
        cout<<"Walks Normally"<<endl;
    }


};
class NoWalk:public WalkableRobot{

    public:
    void walk() override{
        cout<<"Doesn't Walks "<<endl;
    }


};

class TalkableRobot{
    public:
    virtual void talk()=0;
    virtual ~TalkableRobot() {}
};

class NormalTalk:public TalkableRobot{

    public:
    void talk() override{
        cout<<"Talks Normally"<<endl;
    }


};
class NoTalk:public TalkableRobot{

    public:
    void talk() override{
        cout<<"Doesn't Talks "<<endl;
    }


};
class FlyableRobot{
    public:
    virtual void fly()=0;
    virtual ~FlyableRobot() {}
};

class NormalFly:public FlyableRobot{

    public:
    void fly() override{
        cout<<"Flies Normally"<<endl;
    }


};
class NoFly:public FlyableRobot{

    public:
    void fly() override{
        cout<<"Doesn't Fly "<<endl;
    }


};

class Robot{
    protected:
    WalkableRobot* walkBehaviour;
    TalkableRobot* talkBehaviour;
    FlyableRobot*  flyBehaviour;

    public:
    Robot(WalkableRobot* w,TalkableRobot* t,FlyableRobot* f){
        this->walkBehaviour=w;
        this->talkBehaviour=t;
        this->flyBehaviour=f;
    }

    void walk(){
        walkBehaviour->walk();
    }
    void talk(){
        talkBehaviour->talk();
    }
    void fly(){
        flyBehaviour->fly();
    }

    virtual void projection()=0;

};
class CompanionRoobot:public Robot{
    public:
    CompanionRoobot(WalkableRobot* w,TalkableRobot* t,FlyableRobot* f):Robot(w,t,f){
        
    }
    void projection() override{
        cout<<"Displying friendy companion features"<<endl;
    }
};
class WorkableRobot:public Robot{
    public:
    WorkableRobot(WalkableRobot* w,TalkableRobot* t,FlyableRobot* f):Robot(w,t,f){
        
    }
    void projection() override{
        cout<<"Displying worker efficiency stats"<<endl;
    }
};

int main(){
    Robot* robot1=new CompanionRoobot(new NormalWalk(),new NormalTalk(),new NoFly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();


    Robot* robot2=new WorkableRobot(new NoWalk(),new NoTalk(),new NormalFly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();


    return 0;
    
}

