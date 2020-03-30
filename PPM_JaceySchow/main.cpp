#include "PPM.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>



int main( ){
	int width = 10;
	int height = width;
	int w, h , m ;
	std::fstream fin("sign.ppm");
	std::fstream fin2("sign2.ppm");
	PPM pic;
	PPM pik;
	fin2 >> pik;
	fin >> pic;
	fin.close();
	fin2.close();


	/*
	 w = pic.getWidth();
	 h = pic.getHeight();
	 m = pic.getMaxColorValue();

	std::cout << "Width: "  <<  w  << std::endl;
	std::cout << "Height: " <<  h << std::endl;
	std::cout << "Max Color Value: " << m <<std::endl;

	pic.setWidth(width);
	pic.setHeight(height);
	pic.setMaxColorValue(255); 

	w = pic.getWidth();
	h = pic.getHeight();
	m = pic.getMaxColorValue();

	std::cout << "Width: "  <<  w  << std::endl;
	std::cout << "Height: " <<  h << std::endl;
	std::cout << "Max Color Value: " << m <<std::endl;

	int chan = pic.getChannel(3,3,2);
	std::cout << "Channel: " << chan <<std::endl;
	pic.setChannel(3,3,2,40);
	std::cout << "Channel: " << chan <<std::endl;
	*/
	std::ofstream output_file;
	output_file.open("output.txt");
	output_file << pic;

	PPM pe, me, a, mi, mult, div, multe, dive;
	pe = pic += pik;
	me = pic -= pik;
	a = pic + pik;
	mi = pic - pik;
	mult = pic * 2.0;
	div = pic / 3.0;
	multe = pic *=4.0;
	dive = pic /= .25;


	std::ofstream output_file1;
	output_file1.open("output_pe.ppm", std::ios::binary);
	output_file1 << pe;

	std::ofstream output_file2;
	output_file2.open("output_me.ppm");
	output_file2 << me;


	std::ofstream output_file3;
	output_file3.open("output_a.ppm");
	output_file3 << a;


	std::ofstream output_file4;
	output_file4.open("output_m.ppm");
	output_file4 << mi;


	std::ofstream output_file5;
	output_file5.open("output_mult.ppm");
	output_file5 << mult;

	std::ofstream output_file6;
	output_file6.open("output_div.ppm");
	output_file6 << div ;

	std::ofstream output_file7;
	output_file7.open("output_multe.ppm");
	output_file7 << multe;

	std::ofstream output_file8;
	output_file8.open("output_dive.ppm");
	output_file8 << dive ;


	output_file8.close();


	return 0;
	
}