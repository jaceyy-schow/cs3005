#include "lion.h"
#include <vector>
#include <string>

Lion::Lion( int x, int y )
: Critter(x, y, 10){
    mMissedMeal = 0;
}
Lion::~Lion(){}

int Lion::getMissedMealCount( ) const{
    return this->mMissedMeal;

}
void Lion::setSteps(int steps){
    this->mSteps = steps;
}

Critter* Lion::findNeighborPrey( std::vector< Critter* >& critters ) const{
    Critter* zebra;
    for (unsigned int i = 0; i < critters.size(); i++){
        zebra = critters[i];
        if (zebra->getFoodChainLevel() == 5 && zebra->isAlive()){
            if ((zebra->getX() == this->mX)&& ( zebra->getY() == this->mY + 1 || zebra-> getY() == this-> mY -1)){
                return zebra;
            }
            else if ((zebra->getY() == this->mY)&&( zebra->getX() == this->mX +1 || zebra->getX() == this-> mX-1) ){
                return zebra;
            }
        }
    }
    return 0;
}

bool Lion::eat( std::vector< Critter* >& critters ){
    if (mAlive == false){
        return false;
    }
    Critter* zebra;
    zebra = findNeighborPrey(critters);
    if (zebra != 0){
        zebra->kill();
        mMissedMeal = 0;
        this->setPosition(zebra->getX(), zebra->getY());
        return true;
    }
    else{
        mMissedMeal += 1;
    }
    if (mMissedMeal >= 3){
        this->kill();
    }
    return false;
}
bool Lion::reproduce (std::vector<Critter* >& critters, int width, int height ){
    if(isAlive() == false){
        return false;
    }
    if(mSteps< 8){
        return false;
    }
    int randy = std::rand() % 4;
    bool choice1 = positionAvailable(getX()-1, getY(), critters, width, height);
    bool choice2 = positionAvailable(getX()+1, getY(), critters, width, height);
    bool choice3 = positionAvailable(getX(), getY()+1, critters, width, height);
    bool choice4 = positionAvailable(getX(), getY()-1, critters, width, height);
    bool choices[4] = {choice1, choice2, choice3, choice4};
    if ((choices[randy] == true) && (randy == 0)){
        critters.push_back(new Lion(getX()-1, getY()));
        mSteps = 0;
        return true;
    }
    else if  ((choices[randy] == true) && (randy == 1)){
        critters.push_back(new Lion(getX()+1, getY()));
        mSteps = 0;
        return true;
    }
    else if  ((choices[randy] == true) && (randy == 2)){
        critters.push_back(new Lion(getX(), getY()+1));
        mSteps = 0;
        return true;
    }
    else if  ((choice4 == true)){
        critters.push_back(new Lion(getX(), getY()-1));
        mSteps = 0;
        return true;
    }
    mSteps += 1;
    return false;
}