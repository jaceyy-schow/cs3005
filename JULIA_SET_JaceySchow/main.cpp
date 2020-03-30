#include "JuliaSet.h"
#include "PPM.h"
#include <iostream>
#include <fstream>
#include <string>

int main( ){

	int height, width;
	double MinX, MinY, MaxX, MaxY, A, B, MaxEscape, M;

    std::cout << "Pixel Width: " << std::endl;
    std::cin >> width;
    std::cout << "Pixel Height: " << std::endl;
    std::cin >> height;
    std::cout << "Min x: " << std::endl;
    std::cin >> MinX;
    std::cout << "Max x: " << std::endl;
    std::cin >> MaxX;
    std::cout << "Min y: " << std::endl;
    std::cin >> MinY;
    std::cout << "Max y: " << std::endl;
    std::cin >> MaxY;
    std::cout << "A: " << std::endl;
    std::cin >> A;
    std::cout << "B: " << std::endl;
    std::cin >> B;
    std::cout<< "Mode: (1: Original, 2: New) "
    std::cin >> M;
    if (M == "1"){
        bool mode = false;
    }
    else if (M == "2"){
        bool mode = true;
    }
    


    JuliaSet Julia;
    Julia.setPixelSize(width, height);
    Julia.setPlaneSize(MinX, MaxX, MinY, MaxY);
    Julia.setParameters(A, B);
    Julia.setMaxEscapeCount(255);
    Julia.setMode(mode);
    Julia.calculateAllEscapeCounts();
    int count_example = Julia.getPixelEscapeCount(0,0);
    std::cout << count_example << std::endl;
    PPM pic;
    pic.setHeight(height);
    pic.setWidth(width);
    pic.setMaxColorValue(255);

    for (int h = 0; h < height; h++){
    	for (int w = 0; w < width; w++){
            int count = Julia.getPixelEscapeCount(h,w);
    		for (int c = 0; c<3; c++){
    			pic.setChannel(h, w, c, count);
    		}
    	}
    }

    std::cout << "Filename?: " << std::endl;
    std::string filename;
    std::cin >> filename;
    std::ofstream fout(filename, std::ios::binary);
    fout << pic;
    fout.close();


	return 0;

}