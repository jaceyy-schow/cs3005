#ifndef _ZEBRA_H_
#define _ZEBRA_H_

#include "critter.h"

class Zebra: public Critter{
    public:
        Zebra( int x, int y );
        virtual ~Zebra( );
        void setSteps(int steps);
        virtual bool eat ( std::vector< Critter* >& critters );
        virtual bool reproduce (std::vector<Critter* >& critters, int width, int height );

    protected:
     


};

#endif
