#include "stats.h"
#include <cstdlib>
#include <iostream>
#include <fstream>

int main( ) {
	std::vector< double > newList;
    double sum(0);
    size_t count(0);
    double average(0);
    double median(0);
    double min(0);
    double max(0);


    newList = getInput( std::cin );
    count = calculateCount( newList );

    if ( count != 0 ){
       sum = calculateSum( newList );
    }
    if ( count != 0 ){
        average = calculateAverage( newList );
    }
    if ( count != 0 ){
        median = calculateMedian( newList );
    }
    if ( count != 0 ){
        min = calculateMinimum( newList );
    }
    if ( count != 0 ){
        max = calculateMaximum( newList );
    }
    if (count > 0 ) {
        int i;
        for ( i = 0; i < count; i++ ) {
        }
        std::cout << "Sum:      "<< sum << std::endl;
        std::cout << "Count:    "<< count << std::endl;
        std::cout << "Average:  "<< average << std::endl;
        std::cout << "Median:   "<< median << std::endl;
        std::cout << "Minimum:  "<< min << std::endl;
        std::cout << "Maximum:  "<< max << std::endl;
    } 
    else {
        std::cout << "Something went wrong."<< "0" << std::endl;
    }
  return 0;
}