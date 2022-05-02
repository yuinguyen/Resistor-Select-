#pragma once
#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include <string>
#include "string.h"
#include <vector>
#include <iomanip>
#include "windows.h"
#define RESISTOR_COUNT 2

class E12
{
private:
	//float resistor_values;
	float e12_lists[12] = { 1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2 }; //E12
	float e24_lists[24] = { 1.0, 1.1, 1.2, 1.3, 1.5, 1.6, 1.8, 2.0, 2.2, 2.4, 2.7, 3.0, 3.3, 3.6, 3.9, 4.3, 5.1, 5.6, 6.2, 6.8, 7.5, 8.2, 9.1 }; //E24
	
	float input_val;
	float calculated_res;
	const float lower_bound = 0.95; //bound of 95%
	const float upper_bound = 1.05; //bound of 95%
	std::vector <float> resistor_values; //vector for storing the selected resistor series 
	float selected_res[RESISTOR_COUNT];
	int resistor_lists;
	std::string cmd; 
	std::vector <std::pair<float, float>> arrangements; // contains pairs of resistors potential combinations
public:
	E12();
	~E12();
	void get_lists(int series) { resistor_lists = series; };
	void get_resistor(float res) { input_val = res; };
	void calculate_res();
	void get_cmd(int ser_or_par) { cmd = std::to_string(ser_or_par); };
	float parallel_comb(float r1, float r2);
	float series_comb(float r1, float r2);
	void add_e12();
	void add_e24();
};


