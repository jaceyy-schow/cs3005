#include "stats.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>
#include <fstream>


std::vector< double > getInput( std::istream& input_stream ){
    std::vector <double> v;
    double dubs;
    while (input_stream >> dubs){
        v.push_back(dubs);
    }
    return v;
}

double calculateSum( const std::vector< double >& numbers ){
    double sum;
    sum = std::accumulate(numbers.begin(), numbers.end(), 0.0);
    return sum;
}

size_t calculateCount( const std::vector< double >& numbers ){
    return numbers.size();
}

double calculateAverage( const std::vector< double >& numbers ){
    if (numbers.size() > 0){
        double sum;
        sum = std::accumulate(numbers.begin(), numbers.end(), 0.0);
        double size = numbers.size();
        double average = sum / size ;
        return average;
    }
    else{
        return 0.0;
    }
}

double calculateMedian( const std::vector< double >& numbers ) {
    std::vector<double> nums = numbers ;
    std::sort(nums.begin(), nums.end()) ;
    if ( nums.size() == 0 ) {
        return 0 ;
    }
    if (nums.size() % 2 == 0){
        int mid1 = (nums.size() / 2) -1 ;
        int mid2 = (nums.size() / 2 ) ;
        double median = ( nums[mid1] + nums[mid2] ) / 2 ;
        return median;
    }
    else{
        int mid1 = (nums.size() / 2) ;
        double median = (nums[mid1]) ;
        return median;
    }
}
double calculateMinimum( const std::vector< double >& numbers ) {
    if (numbers.size() == 0){
        return 0.0;
    }
    else if (numbers.size() == 1){
        return numbers[0];
    }
    else{
        std::vector<double> nums = numbers ;
        std::sort(nums.begin(), nums.end()) ;
        return nums.front() ;
    }
}
double calculateMaximum( const std::vector< double >& numbers ) {
    if (numbers.size() == 0){
        return 0.0;
    }
    else if (numbers.size() == 1){
        return numbers[0];
    }
    else{
        std::vector<double> nums = numbers ;
        std::sort(nums.begin(), nums.end()) ;
        return nums.back() ;
    }
}
