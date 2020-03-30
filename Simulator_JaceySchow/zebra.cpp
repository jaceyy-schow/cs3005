#include "critter.h"
#include "zebra.h"
#include <vector>
Zebra::Zebra( int x, int y )
: Critter(x, y, 5){
}
Zebra::~Zebra(){

}
void Zebra::setSteps(int steps){
    mSteps = steps;
}
bool Zebra::eat( std::vector< Critter* >& critters ){
    (void) critters;
    return false;

}
bool Zebra::reproduce(std::vector<Critter* >& critters, int width, int height ){
    int coin = rand() % 2;
    if(coin == 0){
        return false;
    }
    if(isAlive() == false){
        return false;
    }
    if(getStepsSinceReproduced() < 3){
        mSteps += 1;
        return false;
    }
    else{
        int x = this->getX();
        int y = this->getY();
        bool choice1 = positionAvailable(this->mX-1,this-> mY, critters, width, height);
        bool choice4 = positionAvailable(this->mX, this->mY-1, critters, width, height);
        bool choice3 = positionAvailable(this->mX, this->mY+1, critters, width, height);
        bool choice2 = positionAvailable(this->mX+1, this->mY, critters, width, height);
        if(choice1 == true){
            mSteps = 0;
            critters.push_back(new Zebra(x-1, y));
            return true;
        }
        else if( choice2 == true ){
            mSteps = 0;
            critters.push_back(new Zebra(x, y-1));
            return true;
        }
        else if (choice3 == true ){
            mSteps = 0;
            critters.push_back(new Zebra(x+1, y));
            return true;
        }
        else if (choice4 == true){
            mSteps = 0;
            critters.push_back(new Zebra(x, y+1));
            return true;
        }
        else{
            mSteps += 1;
            return false;
        }
    }
}

