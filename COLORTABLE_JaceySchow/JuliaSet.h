#ifndef _JULIASET_H_
#define _JULIASET_H_
#include <vector>

class JuliaSet{
    public:
        JuliaSet();
        JuliaSet(const int& w, const int& h, const double& minX, const double& minY, const double& maxX, const double& maxY, const int& a, const int& b);
        int getWidth( ) const;
        int getHeight( ) const;
        double getMinX( ) const;
        double getMinY( ) const;
        double getMaxX( ) const;
        double getMaxY( ) const;
        double getA( ) const;
        double getB( ) const;
        int getMaxEscapeCount( ) const;
        bool getMode() const;

        void setPixelSize( const int& width, const int& height );
        void setPlaneSize( const double& min_x, const double& max_x, const double& min_y, const double& max_y );
        void setParameters( const double& a, const double& b );
        void setMaxEscapeCount( const int& count );
        void setMode(const bool& mode);

        double calculateDeltaX( ) const;
        double calculateDeltaY( ) const;
        double calculatePlaneXFromPixelColumn( const int& column ) const;
        double calculatePlaneYFromPixelRow( const int& row ) const;
        void calculatePlaneCoordinatesFromPixelCoordinates( const int& row, const int& column, double& x, double& y ) const;

        void calculateNextPoint( const double x0, const double y0, double& x1, double &y1 ) const;
        int calculatePlaneEscapeCount( const double& x0, const double& y0 ) const;
        int calculatePixelEscapeCount( const int& row, const int& column ) const;
        void calculateAllEscapeCounts();
        int getPixelEscapeCount(const int& row, const int& column) const;



    protected:
        int mMaxHeight;
        int mMaxWidth;
        double mMinX;
        double mMinY;
        double mMaxX;
        double mMaxY;
        double mA;
        double mB;
        int mMaxEscape;
        bool mMode;
        std::vector < std::vector <int> >  mEscapes;

};

#endif
