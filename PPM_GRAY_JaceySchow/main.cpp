#include "PPM.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>


int main( ){
    PPM r, g, b, c, l;
    std::string user_input = "";
    std::cout << "Conversions available: \n" << "c) Copy directly\n" << "r) Grayscale from red\n" << "g) Grayscale from green\n" << "b) Grayscale from blue\n" << "l) Grayscale from linear colorimetric\n" << "v) Vertical Edge Detection\n" << "h) Horizontal Edge Detection" <<  std::endl ;
    std::cout << "Choice? " << std::endl ;
    std::cin >> user_input ;
    std::ifstream input_file;
    std::string filename;
    std::cout << "What file would you like to alter? " << std::endl;
    std::cin >> filename;
    input_file.open(filename);
    PPM pic;
    input_file >> pic;
    input_file.close();
    std::ofstream output_file;
    std::string filenameOut;
    std::cout << "Output filename?" << std::endl;
    std::cin >> filenameOut;
    output_file.open(filenameOut.c_str());
    if( user_input == "r"){
       pic = pic.gtor();
    }
    else if (user_input == "g"){
        pic = pic.gtog();
    }
    else if (user_input == "b"){
        pic = pic.gtob();
    }

    else if (user_input == "c"){
        pic = pic.copy(pic);
    }
    else{
    	std::cout << "Key unrecognized. " << std::endl;
    	std::cout << " " << std::endl;
    }
    output_file << pic;
    output_file.close();




	return 0;
	
}