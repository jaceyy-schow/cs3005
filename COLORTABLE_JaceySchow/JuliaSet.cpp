#include "JuliaSet.h"
#include <cmath>
#include <iostream>

JuliaSet::JuliaSet(){
    mMaxWidth = 400;
    mMaxHeight = 400;
    mMinX = -2.0;
    mMinY = -2.0;
    mMaxX = 2.0;
    mMaxY = 2.0;
    mA = 0.0;
    mB = 0.0;
    mMaxEscape = 255;
}

JuliaSet::JuliaSet(const int& w, const int& h, const double& minX, const double& minY, const double& maxX, const double& maxY, const int& a, const int& b){
    mMaxWidth = w;
    mMaxHeight = h;
    mMinX = minX;
    mMinY = minY;
    mMaxX = maxX;
    mMaxY = maxY;
    mA = a;
    mB = b;
    mMaxEscape = 255;
}

int JuliaSet::getWidth() const {
    return mMaxWidth;
}

int JuliaSet::getHeight() const{
    return mMaxHeight;
}

double JuliaSet::getMinX() const{
    return mMinX;
}

double JuliaSet::getMinY() const{
    return mMinY;
}

double JuliaSet::getMaxX() const{
    return mMaxX;
}

double JuliaSet::getMaxY() const{
    return mMaxY;
}

double JuliaSet::getA() const {
    return mA;
}

double JuliaSet::getB() const {
    return mB;
}

int JuliaSet::getMaxEscapeCount() const {
    return mMaxEscape;
}

void JuliaSet::setPixelSize( const int& width, const int& height ){
    if (( width >=2 ) && ( height >= 2 )){
        mMaxWidth = width;
        mMaxHeight = height;
    }
}

void JuliaSet::setPlaneSize( const double& min_x, const double& max_x, const double& min_y, const double& max_y){
    if (min_x > max_x){
        mMinX = max_x;
        mMaxX = min_x;

    }
    else{
        mMinX = min_x;
        mMaxX = max_x;
    }
    if (min_y > max_y){
        mMinY = max_y;
        mMaxY = min_y;
    }
    else{
        mMinY = min_y;
        mMaxY = max_y;
    }
}
void JuliaSet::setParameters( const double& a, const double& b){
    mA = a;
    mB = b;
}

void JuliaSet::setMaxEscapeCount( const int& count ){
    if (count >= 0){
        mMaxEscape = count;
    }
}

double JuliaSet::calculateDeltaX( ) const{
    double min_x = getMinX();
    double max_x = getMaxX();
    int width = getWidth();
    double delta_x = (max_x - min_x) / (width-1);
    return delta_x;
}

double JuliaSet::calculateDeltaY( ) const{
    double min_y = getMinY();
    double max_y = getMaxY();
    int height = getHeight();
    double delta_y =(max_y - min_y) / (height-1) ;
    return delta_y;
}

double JuliaSet::calculatePlaneXFromPixelColumn( const int& column ) const{

    if (column >= mMaxWidth || column < 0){
        return 0;
    }
    int col = column;
    double min_x = getMinX();
    double max_x = getMaxX();
    double numerator = max_x - min_x;
    double denominator = mMaxWidth - 1;
    double x = ( (numerator / denominator) * col ) + min_x;
    return x;

}
double JuliaSet::calculatePlaneYFromPixelRow(const int& row) const{
    if (row >= mMaxHeight || row < 0){
        return 0;
    }
    int use_row = row;
    double min_y = getMinY();
    double max_y = getMaxY();
    double numerator = min_y - max_y;
    double denominator = mMaxHeight - 1;
    double y = ( (numerator / denominator) * use_row ) + max_y;
    return y;

}
void JuliaSet::calculatePlaneCoordinatesFromPixelCoordinates( const int& row, const int& column, double& x, double& y) const{
    if (column >= mMaxWidth || column < 0){
        x = 0;
        y = 0;
    }
    else if (row >= mMaxHeight || row < 0){
        x = 0;
        y = 0;
    }
    else{
        x = calculatePlaneXFromPixelColumn(column);
        y = calculatePlaneYFromPixelRow(row);
    }

}

void JuliaSet::calculateNextPoint( const double x0, const double y0, double& x1, double& y1 ) const{
    x1 = x0 * x0 - y0 * y0 + mA;
    y1 = 2 * x0 * y0 + mB;
}

int JuliaSet::calculatePlaneEscapeCount( const double& x0, const double& y0 ) const{
  int count = 0;
  double x1 = x0;
  double y1 = y0;
  double x2 = x1;
  double y2 = y1;
  double distance = sqrt((x0*x0) + (y0*y0));
  if (distance > 2.0) {
      return 0;
  }
  else if ( distance == 2.0){
      return 1;
  }
  while ((count < mMaxEscape) && (distance < 2.0)){
      calculateNextPoint(x1, y1, x2, y2);
      double distancex = (x2) * (x2);
      double distancey = (y2) * (y2);
      count += 1;
      distance = sqrt(distancex + distancey);
      if (mMaxEscape < 4){
          std::cout << count << std::endl;
          std::cout << distance<< std::endl;
      }
      x1 = x2;
      y1 = y2;
  }
  return count;
}

int JuliaSet::calculatePixelEscapeCount( const int& row, const int& column ) const {
  if (column >= mMaxWidth || column < 0 || row >= mMaxHeight || row < 0){
    return -1;
  }
  double newX, newY;
  calculatePlaneCoordinatesFromPixelCoordinates(row, column, newX, newY);
  return calculatePlaneEscapeCount(newX, newY);
}
void JuliaSet::calculateAllEscapeCounts(){
    mEscapes.resize(mMaxWidth, std::vector<int>(mMaxHeight));
    unsigned int row, col;
    for (col = 0; col < mEscapes.size(); col++){
        for (row = 0; row < mEscapes[col].size(); row++){
            mEscapes[col][row] = calculatePixelEscapeCount(row,col);
        }
    }

 }

 int JuliaSet::getPixelEscapeCount(const int& row, const int& column) const{
     if (column < 0 || column >= mMaxWidth || row < 0 || row >= mMaxHeight){
        return -1;
     }
     else{
        return mEscapes[column][row];
     }
 }
