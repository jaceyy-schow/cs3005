#ifndef _COLORTABLE_H_
#define _COLORTABLE_H_
#include <vector>
#include <cstddef>

class Color{
    public:
        Color( );
        Color ( const int& red, const int& green, const int& blue );
        int getRed( )const;
        int getGreen( )const;
        int getBlue( )const;
        int getChannel( const int& channel )const;

        void setRed( const int& value);
        void setGreen( const int& value);
        void setBlue( const int& value);
        void setChannel(const int& channel, const int& value);
        void invert( const int& max_color_value );
        friend bool operator==(const Color& lhs, const Color& rhs );

    protected:
        int mRed;
        int mGreen;
        int mBlue;

};
class ColorTable{
    public:
        ColorTable( const size_t& num_color );
        std::size_t getNumberOfColors() const;

        void setNumberOfColors( const size_t& num_color);

        const Color& operator[](int i) const;
        Color& operator[](int i);

        void setRandomColor(const int& max_color_value, const size_t& position);
        void insertGradient( const Color& color1, const Color& color2, const size_t& position1, const size_t& positon2);

        std::vector<Color> mColors;


    protected:

};
#endif
