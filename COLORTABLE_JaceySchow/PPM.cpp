#include "PPM.h"
#include <vector>
#include <string>

PPM::PPM(){
    mWidth = 0;
    mHeight = 0;
    mMaxColorValue = 0;
}

PPM::PPM(const int& w,const  int& h,const int& max){
    mWidth = w;
    mHeight = h;
    mMaxColorValue = max;
}

int PPM::getWidth( ) const{
    return mWidth;
}

int PPM::getHeight( ) const{
    return mHeight;
}

int PPM::getMaxColorValue( ) const{
    return mMaxColorValue;
}
int PPM::getChannel( const int& row, const int& column, const int& channel) const {
  if ( ( row >= 0 && row < mHeight ) && ( column >= 0 && column < mWidth ) && ( channel >= 0 && channel < 3 ) ) {
      size_t pixel = 0;
      pixel = ( row * ( mWidth * 3 ) + ( column * 3 ) + channel );
      if ( pixel < pix.size( ) ) {
          return pix[ pixel ];
      }
  }
  return -1;
}
void PPM::setWidth( const int& width ){
    size_t pixel;
    if ( width >= 0){
        mWidth = width;
        pixel = mHeight * (mWidth * 3);
        pix.resize(pixel);
    }
}
void PPM::setHeight( const int& height ){
    size_t pixel;
    if (height > 0){
        mHeight = height;
        pixel = mHeight * ( mWidth * 3 );
        pix.resize(pixel);
    }
}
void PPM::setMaxColorValue( const int& max_color_value ){
    if (max_color_value > 0 && max_color_value <= 255){
        mMaxColorValue = max_color_value;
    }
}
void PPM::setChannel( const int& row, const int& column, const int& channel, const int& value) {
    if ( ( row >= 0 && row < mHeight ) && ( column >= 0 && column < mWidth ) && ( channel >= 0 && channel < 3 ) && ( value >=0 && value <= mMaxColorValue ) ) {
        size_t pixel = 0;
        pixel = ( row * ( mWidth  * 3 ) + ( column * 3 ) + channel );
        if ( pixel < pix.size( ) ) {
            pix[ pixel ] = value;

        }

    }

}
void PPM::setP6( std::string file ) {

    P6 = file;

}

std::string PPM::getP6( ) const {

    return P6;

}
PPM PPM::copy(PPM ppm_object){
    return ppm_object ;

}

PPM PPM::gtor(){
    PPM newppm = *this;
    int width;
    int height;
    width = getWidth( );
    height = getHeight( );
    unsigned char mChan;
    int i, j, k ;

    for ( i = 0; i < height; i++ ) {
        for ( j = 0; j < width; j++ ) {
            mChan = getChannel( i, j, 0 );
            for ( k = 0; k < 3; k++ ) {
                newppm.setChannel(i,j,k,mChan);
                
            }
        }
    }
    return newppm;

}
PPM PPM::gtog(){
    PPM newppm = *this;
    int width;
    int height;
    width = getWidth( );
    height = getHeight( );
    unsigned char mChan;
    int i, j, k ;
    for ( i = 0; i < height; i++ ) {
        for ( j = 0; j < width; j++ ) {
            mChan = getChannel( i, j, 1 );
            for ( k = 0; k < 3; k++ ) {
                newppm.setChannel(i,j,k,mChan);
                
            }
        }
    }
    return newppm;

}
PPM PPM::gtob(){
    PPM newppm = *this;
    int width;
    int height;
    width = getWidth( );
    height = getHeight( );
    unsigned char mChan;
    int i, j, k ;
    for ( i = 0; i < height; i++ ) {
        for ( j = 0; j < width; j++ ) {
            mChan = getChannel( i, j, 2 );
            for ( k = 0; k < 3; k++ ) {
                newppm.setChannel(i,j,k,mChan);
                
            }
        }
    }
    return newppm;

}
PPM PPM::linear(){
    PPM newppm = *this;
    int width;
    int height;
    width = getWidth( );
    height = getHeight( );
    unsigned char mChanR, mChanG, mChanB, mChanNew;
    int i, j, k ;
    for ( i = 0; i < height; i++ ) {
        for ( j = 0; j < width; j++ ) {
            mChanR = getChannel( i, j, 0 );
            mChanG = getChannel( i, j, 1 );
            mChanB = getChannel( i, j, 2 );
            mChanNew =  0.2126*mChanR + 0.7152*mChanG + 0.0722*mChanB;
            for ( k = 0; k < 3; k++ ) {
                newppm.setChannel(i,j,k,mChanNew);
                
            }
        }
    }
    return newppm;

}


std::ostream& operator<<( std::ostream& out, const PPM& ppm_object ) {
    out << "P6" << " " << ppm_object.getWidth( ) << " " << ppm_object.getHeight( ) << " " << ppm_object.getMaxColorValue( ) << "\n";
    int width;
    int height;
    width = ppm_object.getWidth( );
    height = ppm_object.getHeight( );
    unsigned char mChan;
    int i, j, k ;
    for ( i = 0; i < height; i++ ) {
        for ( j = 0; j < width; j++ ) {
            for ( k = 0; k < 3; k++ ) {
                mChan = ppm_object.getChannel( i, j, k );
                out.write( ( char* )& mChan, 1);
            }
        }
    }
    return out;
}
std::istream& operator>>( std::istream& in, PPM& ppm_object ) {
  int val = 0;
  std::string fin;
  if ( !in ) {
      std::cout << "in is not working correctly!" << std::endl;
  }
  else {
    in >> fin;
    ppm_object.setP6( fin );
  }
  if ( !in ) {
      std::cout << "in is not working correctly!" << std::endl;
  }
  else {
    in >> fin;
    val = std::stoi( fin );
    ppm_object.setWidth( val );
  }
  if ( !in ) {
      std::cout << "in is not working correctly!" << std::endl;
  }
  else {
    in >> fin;
    val = std::stoi( fin );
    ppm_object.setHeight( val );
  }
  if ( !in ) {
      std::cout << "in is not working correctly!" << std::endl;
  }
  else {
    in >> fin;
    val = std::stoi( fin );
    ppm_object.setMaxColorValue( val );
  }
  unsigned char mChan;
  int i, j, k;
  in.read(  ( char* )& mChan, 1 );
  for ( i = 0; i < ppm_object.getHeight(); i++ ) {
    for ( j = 0; j < ppm_object.getWidth(); j++ ) {
      for ( k = 0; k < 3; k++ ) {
        if ( !in ) {
            std::cout << "in is not working correctly!" << std::endl;
        }
        else {
            in.read(  ( char* )& mChan, 1 );
            ppm_object.setChannel( i, j, k, mChan );
        }

      }

    }

  }
  return in;

}

bool operator==(PPM& ppm_object1, PPM& ppm_object2){
    int pixel1 = ppm_object1.getHeight() * ppm_object1.getWidth() ;
    int pixel2 = ppm_object2.getHeight() * ppm_object2.getWidth() ;
    return pixel1 == pixel2;
}
bool operator<=(PPM& ppm_object1, PPM& ppm_object2){
    int pixel1 = ppm_object1.getHeight() * ppm_object1.getWidth() ;
    int pixel2 = ppm_object2.getHeight() * ppm_object2.getWidth() ;
    return pixel1 <= pixel2;
}
bool operator>=(PPM& ppm_object1, PPM& ppm_object2){
    int pixel1 = ppm_object1.getHeight() * ppm_object1.getWidth() ;
    int pixel2 = ppm_object2.getHeight() * ppm_object2.getWidth() ;
    return pixel1 >= pixel2;
}
bool operator!=(PPM& ppm_object1, PPM& ppm_object2){
    int pixel1 = ppm_object1.getHeight() * ppm_object1.getWidth() ;
    int pixel2 = ppm_object2.getHeight() * ppm_object2.getWidth() ;
    return pixel1 != pixel2;
}
bool operator>(PPM& ppm_object1, PPM& ppm_object2){
    int pixel1 = ppm_object1.getHeight() * ppm_object1.getWidth() ;
    int pixel2 = ppm_object2.getHeight() * ppm_object2.getWidth() ;
    return pixel1 > pixel2;
}
bool operator<(PPM& ppm_object1, PPM& ppm_object2){
    int pixel1 = ppm_object1.getHeight() * ppm_object1.getWidth() ;
    int pixel2 = ppm_object2.getHeight() * ppm_object2.getWidth() ;
    return pixel1 < pixel2;
}
PPM& PPM::operator+=( const PPM& ppm_object1){
    for (int h =0; h < ppm_object1.mHeight; h++ ){
        for (int w =0 ; w < ppm_object1.mWidth; w++){
            for (int c=0; c <3; c++){
                int lhsv = getChannel(h,w,c);
                int rhsv = ppm_object1.getChannel(h,w,c);
                int newC = lhsv += rhsv;
                int MAX = getMaxColorValue();
                if (newC >= MAX){
                    setChannel( h, w, c, MAX);
                }
                else if (newC <= 0){
                    setChannel(h,w,c, MAX);
                }
                else{
                    setChannel(h,w,c, newC);
                }
            }
       }
    }
    return *this;
}


PPM& PPM::operator-=( const PPM& ppm_object1){
    for (int h = 0; h < ppm_object1.mHeight; h++ ){
        for (int w =0 ; w < ppm_object1.mWidth; w++){
            for (int c=0; c <3; c++){
                int lhsv = getChannel(h,w,c);
                int rhsv = ppm_object1.getChannel(h,w,c);
                int newC = lhsv -= rhsv;
                int MAX = getMaxColorValue();
                if (newC >= MAX){
                    setChannel( h, w, c, MAX);
                }
                else if (newC <= 0){
                    setChannel(h,w,c, MAX = 0);
                }
                else{
                    setChannel(h,w,c, newC);
                }
            }
       }
    }
       return *this;
}
PPM PPM::operator+(const PPM ppm_object1) const{
  PPM newppm = *this;
for (int h=0 ; h < ppm_object1.mHeight; h++){
        for (int w=0; w < ppm_object1.mWidth; w++){
            for (int c=0; c<3; c++){
                int lhsv = getChannel(h,w,c);
                int rhsv = ppm_object1.getChannel(h,w,c);
                int newC = lhsv+rhsv;
                int maxColor = getMaxColorValue();

                if (newC >= maxColor ){
                    newppm.setChannel(h,w,c,maxColor);
                }
                else if (newC <= 0){
                    newppm.setChannel(h,w,c,maxColor=0);
                }
                else{
                    newppm.setChannel(h,w,c,newC);
                }
            }
        }
    }

    return newppm;
}

PPM PPM::operator-(const PPM ppm_object1) const{
  PPM newppm = *this;
  
for (int h=0 ; h < ppm_object1.mHeight; h++){
        for (int w=0; w < ppm_object1.mWidth; w++){
            for (int c=0; c<3; c++){
                int lhsv = getChannel(h,w,c);
                int rhsv = ppm_object1.getChannel(h,w,c);
                int newC = lhsv-rhsv;
                int maxColor = getMaxColorValue();

                if (newC >= maxColor ){
                    newppm.setChannel(h,w,c,maxColor);
                }
                else if (newC <= 0){
                    newppm.setChannel(h,w,c,maxColor=0);
                }
                else{
                    newppm.setChannel(h,w,c,newC);
                }
            }
        }
    }

    return newppm;
}
PPM& PPM::operator*=(double d){
for (int h=0 ; h< mHeight; h++){
        for (int w=0; w< mWidth; w++){
            for (int c=0; c<3; c++){
                //int lhsv = getChannel(h,w,c);
                int rhsv = getChannel(h,w,c);
                //int newC = lhsv*=rhsv;
                int maxColor = getMaxColorValue();
                //int a = setChannel(h,w,c,maxColor)
                rhsv*= d;
                if (rhsv > maxColor ){
                    setChannel(h,w,c,maxColor);
                }
                else if (rhsv < 0){
                    setChannel(h,w,c,0);
                }
                else{
                    setChannel(h,w,c,rhsv);
                }
            }
        }
    }
    return *this;
}

PPM& PPM::operator/=(double d){
for (int h=0 ; h< mHeight; h++){
        for (int w=0; w< mWidth; w++){
            for (int c=0; c<3; c++){
                //int lhsv = getChannel(h,w,c);
                int rhsv = getChannel(h,w,c);
                //int newC = lhsv/=rhsv;
                int maxColor = getMaxColorValue();
                rhsv/= d;
                if (rhsv > maxColor ){
                    setChannel(h,w,c,maxColor);
                }
                else if (rhsv < 0){
                    setChannel(h,w,c,0);
                }
                else{
                    setChannel(h,w,c,rhsv);
                }
            }
        }
    }
    return *this;
}
PPM PPM::operator*(double d) const{
  PPM newppm = *this;
for (int h=0 ; h < mHeight; h++){
        for (int w=0; w < mWidth; w++){
            for (int c=0; c<3; c++){
                int lhsv = getChannel(h,w,c);
                //int rhsv = getChannel(h,w,c);
                int newC = lhsv*d;
                int maxColor = getMaxColorValue();

                if (newC >= maxColor ){
                    newppm.setChannel(h,w,c,maxColor);
                }
                else if (newC <= 0){
                    newppm.setChannel(h,w,c,maxColor=0);
                }
                else{
                    newppm.setChannel(h,w,c,newC);
                }
            }
        }
    }
    return newppm;
}

PPM PPM::operator/(double d) const{
  PPM newppm = *this;
for (int h=0 ; h < mHeight; h++){
        for (int w=0; w < mWidth; w++){
            for (int c=0; c<3; c++){
                int lhsv = getChannel(h,w,c);
                //int rhsv = getChannel(h,w,c);
                int newC = lhsv/d;
                int maxColor = getMaxColorValue();

                if (newC >= maxColor ){
                    newppm.setChannel(h,w,c,maxColor);
                }
                else if (newC <= 0){
                    newppm.setChannel(h,w,c,maxColor=0);
                }
                else{
                    newppm.setChannel(h,w,c,newC);
                }
            }
        }
    }
    return newppm;
}
