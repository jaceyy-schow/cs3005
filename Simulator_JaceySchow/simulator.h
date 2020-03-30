
#ifndef simulator_hpp
#define simulator_hpp
#include <vector>
#include "lion.h"
#include "zebra.h"
class Simulation {
public:
    Simulation( int width, int height );
    virtual ~Simulation( );
    int getWidth() const;
    int getHeight() const;
    const std::vector< Critter* >& getCritters( ) const;
    void eatAll( );
    void reproduceAll( );
    void moveAll( );
    void removeDead( );
    void step( );
    int getCrittersSize()const;
    void setCritters(std::vector<Critter*>& c);
    
protected:
    int width,height;
    std::vector<Critter*> critters;
};









#endif /* simulator_hpp */
