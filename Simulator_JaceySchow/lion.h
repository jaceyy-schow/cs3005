#ifndef _LION_H_
#define _LION_H_

#include "critter.h"

#include <vector>


class Lion: public Critter{
    public:
        Lion( int x, int y );
        virtual ~Lion( );
        int getMissedMealCount( ) const;
        void setSteps(int steps);
        Critter* findNeighborPrey( std::vector< Critter* >& critters ) const;
        virtual bool eat( std::vector< Critter* >& critters );
        virtual bool reproduce (std::vector<Critter* >& critters, int width, int height);
    protected:
        int mMissedMeal;
        int mStepsSinceReproduced;


};

#endif
