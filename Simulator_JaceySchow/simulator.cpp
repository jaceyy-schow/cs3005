#include "simulator.h"

Simulation::Simulation( int width, int height )
: width(width),height(height){
    for(int y = 0;y < height;y++){
        for(int x = 0; x < width;x++){
            int random = rand() % 100;
            if(random >= 75){
                critters.push_back(new Lion(x,y));
            }
            if(random <= 39){
                critters.push_back(new Zebra(x,y));
            }
        }
    }
}
Simulation::~Simulation( ){
    for(size_t i = 0; i < critters.size();i++){
        delete critters[i];
        critters[i] = 0;
    }
}

int Simulation::getWidth() const {
    return width;
}

int Simulation::getHeight() const {
    return height;
}

const std::vector< Critter* >& Simulation::getCritters( ) const{
    return critters;
}

void Simulation::eatAll( ){
    for(size_t i = 0;i < critters.size();i++){
        critters[i]->eat(this->critters);
    }
}


void Simulation::reproduceAll( ){
    for(size_t i = 0;i < critters.size();i++){
        critters[i]->reproduce(critters,width,height);
    }
}
void Simulation::moveAll( ){
    for(size_t i = 0;i < critters.size();i++){
        critters[i]->move(critters,width,height);
    }
}
void Simulation::removeDead( ){
    for (size_t i = 0; i < critters.size(); i++) {
        if (critters[i]->isAlive() == false) {
            delete critters[i];
            critters[i] = critters[critters.size()-1];
            critters.pop_back();
            i--;
        }
    }
}

void Simulation::step( ){
    moveAll();
    eatAll();
    reproduceAll();
    removeDead();
}

void Simulation::setCritters(std::vector<Critter*>& crittersComingBack) {
    critters = crittersComingBack;
}
int Simulation::getCrittersSize()const {
    return critters.size();
}


