#include <iostream>
#include<string>

using namespace std;
class Character{
    public:
    virtual string getAbilities() const=0;
    virtual ~Character() {}
};

class Mario:public Character{
    public:
    string getAbilities() const override{
        return "Mario";
    }

};


class CharacterDecorator: public Character{ //is-a relatonship
    protected:
    Character* character; //has-a relationship
    public:
    CharacterDecorator(Character* c){
        this->character=c;
    }
};

class HeightUp:public CharacterDecorator{
    public:
    HeightUp(Character* c) : CharacterDecorator(c){}
        string getAbilities() const override{
            return character->getAbilities()+"with heightup";
        }
    };

    class GunPowerUp:public CharacterDecorator{
    public:
    GunPowerUp(Character* c) : CharacterDecorator(c){}
        string getAbilities() const override{
            return character->getAbilities()+"with gunPowerUp";
        }
    };

    class StarPowerUp:public CharacterDecorator{
    public:
    StarPowerUp(Character* c) : CharacterDecorator(c){}
        string getAbilities() const override{
            return character->getAbilities()+"with starPowerUp";
        }

    ~StarPowerUp(){
        cout<<"Destroying StarPowerUp Decorator"<<endl;
    }
    };

int main(){
    Character* mario=new Mario();
    cout<<"Basic Character:"<<mario->getAbilities()<<endl;
    mario=new HeightUp(mario);
    cout<<"After Height Up"<<mario->getAbilities()<<endl;
    
}
    
    
