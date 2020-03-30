//
// Google Test C++ unit test framework
#include "gtest/gtest.h"
#include "critter.h"
#include "lion.h"
#include "zebra.h"

TEST( lionIsKilled, lionIsDead ) {
    Lion lion(3,5);
    lion.kill();
    EXPECT_EQ( false, lion.isAlive() );
}
TEST( lionIsAlive,lionIsAlive){
    Lion lion(5,8);
    EXPECT_EQ(true,lion.isAlive());
}
TEST(setsSteps,setSteps){
    Lion lion(6,4);
    lion.setSteps(8);
    EXPECT_EQ(8,lion.getStepsSinceReproduced());
}
TEST(lionReproduces,lionReproduces){
    std::vector<Critter*> critters;
    srand(time(NULL));
    Lion lion(15,15);
    lion.setSteps(8);
    EXPECT_EQ(true,(lion.reproduce(critters,20,20)));
}
TEST(lionReproduces,lionDoesNotReproduce){
    std::vector<Critter*> critters;
    Lion lion(5,5);
    lion.setSteps(3);
    EXPECT_EQ(false,(lion.reproduce(critters,20,20)));
}
TEST(lionIsDead,lionDoesNotReproduce){
    std::vector<Critter*> critters;
    Lion lion(5,5);
    lion.setSteps(9);
    lion.kill();
    EXPECT_EQ(false,(lion.reproduce(critters,20,20)));
}

TEST(lionSurrounded,lionDoesNotReproduce){
 /* Setup */
// Done automatically

/* Stimulus */
std::vector< Critter* > critters;
Lion lion(5,5);
lion.setSteps(8);
Lion *l0 = new Lion( 5, 4 );
Lion *l1 = new Lion( 5, 6 );
Lion *l2 = new Lion( 6, 5 );
Lion *l3 = new Lion( 4, 5 );
critters.push_back( l0 );
critters.push_back( l1 );
critters.push_back( l2 );
critters.push_back( l3 );
bool did_reproduce = lion.reproduce( critters, 20, 20 );

/* Comparison */
EXPECT_EQ( false, did_reproduce );


/* Tear-down */
delete l0;
delete l1;
delete l2;
delete l3;
// Done automatically

}

TEST(ProducesNorth,lionReproduces){
    /* Setup */
    // Done automatically
    
    /* Stimulus */
    std::vector< Critter* > critters;
    Lion lion(5,5);
    lion.setSteps(8);
    Lion *l1 = new Lion( 5, 6 );
    Lion *l2 = new Lion( 6, 5 );
    Lion *l3 = new Lion( 4, 5 );
    critters.push_back( l1 );
    critters.push_back( l2 );
    critters.push_back( l3 );
    bool did_reproduce = lion.reproduce( critters, 20, 20 );
    
    /* Comparison */
    EXPECT_EQ( true, did_reproduce );
    
    
    /* Tear-down */
    delete l1;
    delete l2;
    delete l3;
    // Done automatically
    
}

TEST(ProducesSouth,lionReproduces){
    /* Setup */
    // Done automatically
    
    /* Stimulus */
    std::vector< Critter* > critters;
    Lion lion(5,5);
    lion.setSteps(8);
    Lion *l1 = new Lion( 5, 4 );
    Lion *l2 = new Lion( 6, 5 );
    Lion *l3 = new Lion( 4, 5 );
    critters.push_back( l1 );
    critters.push_back( l2 );
    critters.push_back( l3 );
    bool did_reproduce = lion.reproduce( critters, 20, 20 );
    
    /* Comparison */
    EXPECT_EQ( true, did_reproduce );
    
    
    /* Tear-down */
    delete l1;
    delete l2;
    delete l3;
    // Done automatically
    
}
TEST(ProducesEast,lionReproduces){
    /* Setup */
    // Done automatically
    
    /* Stimulus */
    std::vector< Critter* > critters;
    Lion lion(5,5);
    lion.setSteps(8);
    Lion *l1 = new Lion( 5, 4 );
    Lion *l2 = new Lion( 4, 5 );
    Lion *l3 = new Lion( 5, 6 );
    critters.push_back( l1 );
    critters.push_back( l2 );
    critters.push_back( l3 );
    bool did_reproduce = lion.reproduce( critters, 20, 20 );
    
    /* Comparison */
    EXPECT_EQ( true, did_reproduce );
    
    
    /* Tear-down */
    delete l1;
    delete l2;
    delete l3;
    // Done automatically
    
}
TEST(ProducesWest,lionReproduces){
    /* Setup */
    // Done automatically
    
    /* Stimulus */
    std::vector< Critter* > critters;
    Lion lion(5,5);
    lion.setSteps(8);
    Lion *l1 = new Lion( 5, 4 );
    Lion *l2 = new Lion( 6, 5 );
    Lion *l3 = new Lion( 5, 6 );
    critters.push_back( l1 );
    critters.push_back( l2 );
    critters.push_back( l3 );
    bool did_reproduce = lion.reproduce( critters, 20, 20 );
    
    /* Comparison */
    EXPECT_EQ( true, did_reproduce );
    
    
    /* Tear-down */
    delete l1;
    delete l2;
    delete l3;
    // Done automatically
    
}

// ________Zebra_Tests__________




TEST(zebraReproduces,zebraReproduces){
    std::vector<Critter*> critters;
    srand(time(NULL));
    Zebra zebra(15,15);
    zebra.setSteps(8);
    EXPECT_EQ(true,(zebra.reproduce(critters,20,20)));
}
TEST(zebraReproduces,zebraDoesNotReproduce){
    std::vector<Critter*> critters;
    Zebra zebra(5,5);
    zebra.setSteps(2);
    EXPECT_EQ(false,(zebra.reproduce(critters,20,20)));
}
TEST(zebraIsDead,zebraDoesNotReproduce){
    std::vector<Critter*> critters;
    Zebra zebra(5,5);
    zebra.setSteps(9);
    zebra.kill();
    EXPECT_EQ(false,(zebra.reproduce(critters,20,20)));
}

TEST(zebraSurrounded,zebraDoesNotReproduce){
    /* Setup */
    // Done automatically
    
    /* Stimulus */
    std::vector< Critter* > critters;
    Zebra zebra(5,5);
    zebra.setSteps(8);
    Zebra *l0 = new Zebra( 5, 4 );
    Zebra *l1 = new Zebra( 5, 6 );
    Zebra *l2 = new Zebra( 6, 5 );
    Zebra *l3 = new Zebra( 4, 5 );
    critters.push_back( l0 );
    critters.push_back( l1 );
    critters.push_back( l2 );
    critters.push_back( l3 );
    bool did_reproduce = zebra.reproduce( critters, 20, 20 );
    
    /* Comparison */
    EXPECT_EQ( false, did_reproduce );
    
    
    /* Tear-down */
    delete l0;
    delete l1;
    delete l2;
    delete l3;
    // Done automatically
    
}

TEST(ProducesNorth,zebraReproduces){
    /* Setup */
    // Done automatically
    
    /* Stimulus */
    std::vector< Critter* > critters;
    Zebra zebra(5,5);
    zebra.setSteps(8);
    Zebra *l1 = new Zebra( 5, 6 );
    Zebra *l2 = new Zebra( 6, 5 );
    Zebra *l3 = new Zebra( 4, 5 );
    critters.push_back( l1 );
    critters.push_back( l2 );
    critters.push_back( l3 );
    bool did_reproduce = zebra.reproduce( critters, 20, 20 );
    
    /* Comparison */
    EXPECT_EQ( true, did_reproduce );
    
    
    /* Tear-down */
    delete l1;
    delete l2;
    delete l3;
    // Done automatically
    
}

TEST(ProducesSouth,zebraReproduces){
    /* Setup */
    // Done automatically
    
    /* Stimulus */
    std::vector< Critter* > critters;
    Zebra zebra(5,5);
    zebra.setSteps(8);
    Zebra *l1 = new Zebra( 5, 4 );
    Zebra *l2 = new Zebra( 6, 5 );
    Zebra *l3 = new Zebra( 4, 5 );
    critters.push_back( l1 );
    critters.push_back( l2 );
    critters.push_back( l3 );
    bool did_reproduce = zebra.reproduce( critters, 20, 20 );
    
    /* Comparison */
    EXPECT_EQ( true, did_reproduce );
    
    
    /* Tear-down */
    delete l1;
    delete l2;
    delete l3;
    // Done automatically
    
}
TEST(ProducesEast,zebraReproduces){
    /* Setup */
    // Done automatically
    
    /* Stimulus */
    std::vector< Critter* > critters;
    Zebra zebra(5,5);
    zebra.setSteps(8);
    Zebra *l1 = new Zebra( 5, 4 );
    Zebra *l2 = new Zebra( 4, 5 );
    Zebra *l3 = new Zebra( 5, 6 );
    critters.push_back( l1 );
    critters.push_back( l2 );
    critters.push_back( l3 );
    bool did_reproduce = zebra.reproduce( critters, 20, 20 );
    
    /* Comparison */
    EXPECT_EQ( true, did_reproduce );
    
    
    /* Tear-down */
    delete l1;
    delete l2;
    delete l3;
    // Done automatically
    
}
TEST(ProducesWest,zebraReproduces){
    /* Setup */
    // Done automatically
    
    /* Stimulus */
    std::vector< Critter* > critters;
    Zebra zebra(5,5);
    zebra.setSteps(8);
    Zebra *l1 = new Zebra( 5, 4 );
    Zebra *l2 = new Zebra( 6, 5 );
    Zebra *l3 = new Zebra( 5, 6 );
    critters.push_back( l1 );
    critters.push_back( l2 );
    critters.push_back( l3 );
    bool did_reproduce = zebra.reproduce( critters, 20, 20 );
    
    /* Comparison */
    EXPECT_EQ( true, did_reproduce );
    
    
    /* Tear-down */
    delete l1;
    delete l2;
    delete l3;
    // Done automatically
    
}


