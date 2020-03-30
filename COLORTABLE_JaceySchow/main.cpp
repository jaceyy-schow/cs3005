#include "ColorTable.h"
#include "JuliaSet.h"
#include "PPM.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <cstddef>

int main(){

	ColorTable pic(1);
	size_t size;
	int position1, position2,  red, green, blue, red2, green2, blue2;
	Color color1, color2, color3;
	std::string user_input = "";
	while( user_input != "q"){
		ask:
		std::cout << "Color Table options: \n" << "s) Resize Color Table\n"<< "a) assing a color in the color table\n"  << "r) assign a color randomly in the color table\n" << "g) assign a color gradient in the color table\n" << "q) quit color table operations\n" <<  std::endl ;
		std::cout << "Choice? " << std::endl ;
		std::cin >> user_input ;
		if( user_input == "s"){
			std::cout << "Number of Colors: " << std::endl;
			std::cin >> size;
		    pic.setNumberOfColors(size);
		    goto ask;
		}
		else if (user_input == "a"){
			std::cout << "Which position ( 0-" << pic.mColors.size() -1 << "): " << std::endl;
			std::cin >> position1 ;
			std::cout << "Red: "<< std::endl;
			std::cin >> red;
			std::cout << "Green: "<< std::endl;
			std::cin >> green;
			std::cout << "Blue: " << std::endl;
			std::cin >> blue;
		    color1.setRed(red);
		    color1.setGreen(green);
		    color1.setBlue(blue);
		    pic.mColors[position1] = color1;
		    goto ask;
		}
		else if (user_input == "r"){
		    std::cout << "Which position ( 0-" << pic.mColors.size() -1 << "): " << std::endl;
		    std::cin >> position1;
		    pic.setRandomColor(255, position1);
		    goto ask;
		}

		else if (user_input == "g"){
		    std::cout << "First Position ( 0-" << pic.mColors.size() -1 << "): " << std::endl;
		    std::cin >> position1;
		    std::cout << "First Red: " << std::endl;
		    std::cin >> red;
		    std::cout << "First Green: "<< std::endl;
		    std::cin >> green;
		    std::cout << "First Blue: " << std::endl;
		    std::cin >> blue;
		    std::cout << "Second Position ( 0-" << pic.mColors.size() -1 << "): "  << std::endl;
		    std::cin >> position2;
		    std::cout << "Second Red: " << std::endl;
		    std::cin >> red2;
		    std::cout << "Second Green: " << std::endl;
		    std::cin >> green2;
		    std::cout << "Second Blue: " << std::endl;
		    std::cin >> blue2;
		    color1 = pic.mColors[position1];
		    color1.setRed(red);
		    color1.setGreen(green);
		    color1.setBlue(blue);
		    color2 = pic.mColors[position2];
		    color2.setRed(red2);
		    color2.setGreen(green2);
		    color2.setBlue(blue2);
		    
		    pic.insertGradient(color1, color2, position1, position2);
		    goto ask;
		}
		else if (user_input == "q"){
		   	goto skip_loop;
		}
		else{
		   	std::cout << "Key unrecognized. " << std::endl;
		   	std::cout << " " << std::endl;
		   	goto ask;
		}
	}
	skip_loop:
	int height, width;
	double MinX, MinY, MaxX, MaxY, A, B;

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

    JuliaSet Julia;
    Julia.setPixelSize(width, height);
    Julia.setPlaneSize(MinX, MaxX, MinY, MaxY);
    Julia.setParameters(A, B);
    Julia.setMaxEscapeCount(pic.mColors.size()+1);
    Julia.calculateAllEscapeCounts();

    PPM picture;
    picture.setHeight(height);
    picture.setWidth(width);
    picture.setMaxColorValue(255);

    for (int h = 0; h < height; h++){
    	for (int w = 0; w < width; w++){
            int count = Julia.getPixelEscapeCount(h,w);
            color3 = pic.mColors[count];
            red = color3.getRed();
            blue = color3.getBlue();
            green = color3.getGreen();
            for (int c = 0; c<3; c++){
            	if (c==0){
    				picture.setChannel(h, w, c, red);
    			}
    			else if (c==1){
    				picture.setChannel(h, w, c, green);
    			}
    			else if (c==2){
    				picture.setChannel(h, w, c, blue);
    			}
    		}
    	}
    }

    std::cout << "Filename?: " << std::endl;
    std::string filename;
    std::cin >> filename;
    std::ofstream fout(filename, std::ios::binary);
    fout << picture;
    fout.close();


	return 0;

}