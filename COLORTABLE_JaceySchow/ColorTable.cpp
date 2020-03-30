#include "ColorTable.h"
#include <vector>
#include <cstddef>
#include <iterator>
#include <iostream>
#include <cstdlib>
#include <ctime>


Color::Color( ){
    mRed = 0;
    mGreen = 0;
    mBlue = 0;
}
Color::Color ( const int& red, const int& green, const int& blue ){
    mRed = red;
    mGreen = green;
    mBlue = blue;
}
int Color::getRed( )const{
    return mRed;
}
int Color::getGreen( )const{
    return mGreen;
}
int Color::getBlue( )const{
    return mBlue;
}
int Color::getChannel( const int& channel )const{
    if (channel == 0){
        return mRed;
    }
    else if (channel == 1){
        return mGreen;
    }
    else if (channel == 2){
        return mBlue;
    }
    else{
        return -1;
    }
}
void Color::setRed( const int& value){
    if (value >= 0){
        mRed = value;
    }

}
void Color::setGreen( const int& value){
    if (value >= 0){
        mGreen = value;
    }
}
void Color::setBlue( const int& value){
    if (value >= 0){
        mBlue = value;
    }
}
void Color::setChannel(const int& channel, const int& value){
    if (channel == 0 && value >= 0){
        mRed = value;
    }
    else if (channel == 1 && value >= 0){
        mGreen = value;
    }
    else if (channel == 2 && value >= 0){
         mBlue = value;
    }
}

void Color::invert( const int& max_color_value ){
    if ((max_color_value > mRed) && (max_color_value > mGreen) && (max_color_value > mBlue)){
        mRed = max_color_value - mRed;
        mGreen = max_color_value - mGreen;
        mBlue = max_color_value - mBlue;
    }
}
bool operator==( const Color& lhs, const Color& rhs ){
    int lhsr, lhsg, lhsb, rhsr, rhsg, rhsb;
    lhsr = lhs.getRed();
    lhsg = lhs.getGreen();
    lhsb = lhs.getBlue();
    rhsr = rhs.getRed();
    rhsg = rhs.getGreen();
    rhsb = rhs.getBlue();
    if ((lhsr == rhsr) && (lhsg == rhsg) && (lhsb == rhsb)){
        return true;
    }
    else{
        return false;
    }
}

ColorTable::ColorTable( const size_t& num_color ){
    mColors.resize(num_color);
}

std::size_t ColorTable::getNumberOfColors( ) const{
    return mColors.size();
}
void ColorTable::setNumberOfColors( const size_t& num_color){
    mColors.resize(num_color);
}
const Color& ColorTable::operator[](int i) const{
   int size = mColors.size();
    if (i >= size || i < 0){
        static Color new_color(-1,-1,-1);
        return new_color;

    }
    else{
        return mColors[i];
    }
}
Color& ColorTable::operator[](int i){
    int size = mColors.size();
    if (i >= size || i < 0){
        static Color new_color(-1,-1,-1);
        return new_color;
    }
    else{
        return mColors[i];
    }
}

void ColorTable::setRandomColor(const int& max_color_value, const size_t& position){
    std::srand(time(NULL));
    if ((position < mColors.size()) && (max_color_value >= 0)){
        int max_rand = max_color_value + 1;
        int rand_val = rand() % max_rand;
        Color new_color = mColors[position];
        int old_red = new_color.getRed();
        new_color.setRed(rand_val);
        new_color.setGreen(rand_val);
        new_color.setBlue(rand_val);
        mColors[position] = new_color;

    }

}
void ColorTable::insertGradient( const Color& color1, const Color& color2, const size_t& position1, const size_t& position2 ){
    Color color3;
    if (position1 < position2){
        int red_1 = color1.getRed();
        int red_2 = color2.getRed();
        int green_1 = color1.getGreen();
        int green_2 = color2.getGreen();
        int blue_1 = color1.getBlue();
        int blue_2 = color2.getBlue();
        double delta_red = (red_2 - red_1)/ (double)(position2 - position1);
        double delta_green = (green_2 - green_1)/(double) (position2 - position1);
        double delta_blue = (blue_2 - blue_1)/ (double)(position2 - position1);
        for(unsigned int i = position1; i <= position2; i++){
            color3.setRed(red_1 + ((i - position1) * delta_red));
            color3.setGreen(green_1 + ((i - position1) * delta_green));
            color3.setBlue(blue_1 + ((i - position1) * delta_blue));
            mColors[i] = color3;
        }
    }
}
