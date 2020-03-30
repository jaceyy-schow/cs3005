#include "PPM.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>


int main( ){
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




	PPM r, g, b, c, l, v, h, i;
	std::string user_input = "";
	std::cout << "Conversions available: \n" << "c) Copy directly\n" << "r) Grayscale from red\n" << "g) Grayscale from green\n" << "b) Grayscale from blue\n" << "l) Grayscale from linear colorimetric\n" << "v) Vertical Edge Detection\n" << "h) Horizontal Edge Detection" << "i) Brighten" <<  std::endl ;
    std::cout << "Choice? " << std::endl ;
    std::cin >> user_input ;
    if( user_input == "r"){
       r = pic.gtor();
       output_file << r;
       output_file.close();
    }
    else if (user_input == "g"){
        g = pic.gtog();
        output_file << g;
        output_file.close();
    }
    else if (user_input == "b"){
		b = pic.gtob();
        output_file << b;
        output_file.close();
	}

    else if (user_input == "c"){
        c = pic.copy(pic);
       	output_file << c;
       	output_file.close();

    }
  
    else if (user_input == "l"){
		l = pic.linear();
        output_file << l;
        output_file.close();
    }
    else if (user_input == "v"){
        v = pic.vertical();
        output_file << v;
        output_file.close();

    }
    else if (user_input == "h"){
        h = pic.horizontal();
        output_file << h;
        output_file.close();

    }
    else if (user_input == "i"){
        i = pic.brighten();
        output_file << i;
        output_file.close();

    }
    else{
    	std::cout << "Key unrecognized. " << std::endl;
    	std::cout << " " << std::endl;
    }




	return 0;
	
}