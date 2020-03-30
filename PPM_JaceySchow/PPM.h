#ifndef _PPM_H_
#define _PPM_H_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

class PPM{
    public:
	
	    PPM();
	    PPM(const int& w,const int& h,const int& max);
	
	    int getWidth( ) const;
	    int getHeight( ) const;
	    int getMaxColorValue( ) const;
	    int getChannel( const int& row, const int& column, const int& channel ) const;
	    std::string getP6 ( ) const;
	
	
	    void setWidth( const int& width );
	    void setHeight( const int& height );
	    void setMaxColorValue( const int& max_color_value );
	    void setChannel( const int& row, const int& column, const int& channel, const int& value );
	    void setP6 (std::string file );
	
	    friend bool operator==(PPM& ppm_object1, PPM& ppm_object2);
	    friend bool operator<=(PPM& ppm_object1, PPM& ppm_object2);
	    friend bool operator>=(PPM& ppm_object1, PPM& ppm_object2);
	    friend bool operator!=(PPM& ppm_object1, PPM& ppm_object2);
	    friend bool operator<(PPM& ppm_object1,  PPM& ppm_object2);
	    friend bool operator>(PPM& ppm_object1,  PPM& ppm_object2);
	
	    PPM& operator+=(const PPM& ppm_object1);
	    PPM& operator-=(const PPM& ppm_object1);
	    PPM operator+(const PPM ppm_object1)const ;
	    PPM operator-(const PPM ppm_object1)const ;
	    PPM& operator*=(double d);
	    PPM& operator/=(double d);
	    PPM operator*(double d)const;
	    PPM operator/(double d)const;
	

    protected:
        int     mHeight;
        int     mWidth;
        int     mMaxColorValue;
        std::vector<int> pix ;
        std::string P6;

};

std::ostream& operator<<( std::ostream& out, const PPM& ppm_object );
std::istream& operator>>( std::istream& in, PPM& ppm_object );

#endif
