#ifndef _CRITTER_H_
#define _CRITTER_H_
#include <vector>
#include <ctime>
#include <cstdlib>

class Critter{
    public:
        Critter(int x, int y, int level );
        virtual ~Critter( );
        int getX( )const;
        int getY( )const;
        int getFoodChainLevel( )const;
        bool isAlive( )const;
        int getStepsSinceReproduced( )const;
        bool kill( );
        void setPosition( int x, int y);
        bool positionAvailable( int x, int y, std::vector<Critter*>& critters, int width, int height );
        virtual bool move(std::vector<Critter*>& critters, int width, int height);
        virtual bool eat(std::vector< Critter*>& critters);
        virtual bool reproduce(std::vector<Critter*>& critters, int width, int height);

    protected:

        int mX;
        int mY;
        int mLevel;
        bool mAlive;
        int mSteps;
        std::vector <Critter> mCritters;


};

#endif
