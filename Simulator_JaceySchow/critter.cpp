#include "critter.h"
#include <vector>

Critter::Critter(int x, int y, int level ){
    if (x >= 0){
        mX = x;
    }
    else if (x<0){
        mX = 0;
    }
    if (y >= 0){
        mY = y;
    }
    else if (y < 0){
        mY = 0;
    }
    mLevel = level;
    mAlive = true;

}
Critter::~Critter( ){
}
int Critter::getX( )const{
    return mX;

}
int Critter::getY( )const{
    return mY;

}
int Critter::getFoodChainLevel( )const{
    return mLevel;

}
bool Critter::isAlive( )const{
    return mAlive;

}
int Critter::getStepsSinceReproduced( )const{
    return mSteps;

}
bool Critter::kill( ){
    if (mAlive == true){
        mAlive = false;
        return true;
    }
    else{
        return false;
    }

}
void Critter::setPosition( int x, int y){
    mX = x;
    mY = y;

}
bool Critter::positionAvailable( int x, int y, std::vector<Critter*>& critters, int width, int height ){
    if (( x >= 0 && x < width) && (y >=0 && y < height)){
        for(unsigned int i = 0 ; i < critters.size() ; i++){
            Critter* critty = critters[i];
            if (critty->getX() == x && critty->getY() == y){
                return false;
            }
        }
        return true;
    }
    return false;

}
bool Critter::move( std::vector< Critter* >& critters, int width, int height ){
    if (mAlive == false){
        return false;
    }
    int RandIndex = std::rand() % 4;
    bool choice1 = positionAvailable(mX-1, mY, critters, width, height);
    bool choice4 = positionAvailable(mX, mY-1, critters, width, height);
    bool choice3 = positionAvailable(mX, mY+1, critters, width, height);
    bool choice2 = positionAvailable(mX+1, mY, critters, width, height);
    bool choices[4] = {choice1, choice2, choice3, choice4};
    if ((choices[RandIndex] == true) && (RandIndex == 0)){
        mX = mX-1;
        return true;
    }
    if  ((choices[RandIndex] == true) && (RandIndex == 1)){
        mX = mX+1;
        return true;
    }
    if  ((choices[RandIndex] == true) && (RandIndex == 2)){
        mY = mY+1;
        return true;
    }
    if  ((choice4 == true)){
        mY = mY-1;
        return true;
    }
    else{
        return false;
    }
}
bool Critter::eat(std::vector< Critter*>& critters){
    return false;
}
bool Critter::reproduce(std::vector<Critter*>& critters, int width, int height){
    return false;
}


