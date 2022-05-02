#include "E12.h"

E12::E12() //constructor
{
	calculated_res = 0;
}
E12::~E12() //destructor
{

}


float E12::series_comb(float r1, float r2)
{
	float return_series;
	return_series = r1 + r2;
	return return_series;
}

float E12::parallel_comb(float r1, float r2)
{
	float return_series;
	return_series = (r1 * r2)/(r1 + r2);
	return return_series;
}

void E12::add_e12()
{
	std::cout << "E12: " << std::endl;
	for (int i = 0; i < sizeof(e12_lists) / sizeof(e12_lists[0]); i++) // 1.0 - 8.2
	{
		resistor_values.push_back(e12_lists[i]); //copying resistor list from array
		std::cout << resistor_values[i] << "   ";
	}
	std::cout << "\n";
	for (int i = 0; i < 12; i++) // 10 - 82
	{
		float x10_e12 = resistor_values[i] * 10;
		resistor_values.push_back(x10_e12);
		std::cout << x10_e12 << "   ";
	}
	std::cout << "\n";
	for (int i = 0; i < 12; i++) // 100 - 820
	{
		float x100_e12 = resistor_values[i] * 100;
		resistor_values.push_back(x100_e12);
		std::cout << x100_e12 << "   ";
	}
	std::cout << "\n";
	for (int i = 0; i < 12; i++) // 1000 - 8200
	{
		float x1000_e12 = resistor_values[i] * 1000;
		resistor_values.push_back(x1000_e12);
		std::cout << x1000_e12 << "   ";
	}
	std::cout << "\n";
	for (int i = 0; i < 12; i++) // 10000 - 82000
	{
		float x10000_e12 = resistor_values[i] * 10000;
		resistor_values.push_back(x10000_e12);
		std::cout << x10000_e12 << "   ";
	}
}
void E12::add_e24()
{
	std::cout << "E24: " << std::endl;
	for (int i = 0; i < sizeof(e24_lists) / sizeof(e24_lists[0]); i++)
	{
		resistor_values.push_back(e24_lists[i]);
		std::cout << resistor_values[i] << "   ";
	}
	std::cout << "\n";
	for (int i = 0; i < 24; i++) // 10 range
	{
		float x10_e24 = resistor_values[i] * 10;
		resistor_values.push_back(x10_e24);
		std::cout << x10_e24 << "   ";
	}
	std::cout << "\n";
	for (int i = 0; i < 24; i++) // 100 range
	{
		float x100_e24 = resistor_values[i] * 100;
		resistor_values.push_back(x100_e24);
		std::cout << x100_e24 << "   ";
	}
	std::cout << "\n";
	for (int i = 0; i < 24; i++) // 1K range
	{
		float x1000_e24 = resistor_values[i] * 1000;
		resistor_values.push_back(x1000_e24);
		std::cout << x1000_e24 << "   ";
	}
	std::cout << "\n";
	for (int i = 0; i < 24; i++) // 10K range
	{
		float x10000_e24 = resistor_values[i] * 10000;
		resistor_values.push_back(x10000_e24);
		std::cout << x10000_e24 << "   ";
	}
}

void E12::calculate_res()
{
	float res1 = 0;
	float res2 = 0;
	int count_res1 = 0;
	int size = 0;
	//check which series to use and add values to them 
	if (resistor_lists == 12)
	{
		add_e12();
	}
	else if (resistor_lists == 24)
	{
		add_e24();
	}

	//int count_res2 = 0;
	do
	{
		res1 = resistor_values[count_res1];
		for (int i = 0; i < resistor_values.size(); i++)
		{
			res2 = resistor_values[i];
			if (cmd == "1")
			{
				calculated_res = series_comb(res1, res2);
			}
			else if (cmd == "2")
			{
				calculated_res = parallel_comb(res1, res2);
			}
			if (calculated_res >= lower_bound * input_val && calculated_res <= upper_bound * input_val) //check if within 95% of desired value
			{
				arrangements.push_back(std::make_pair(res1, res2)); //adding pairs to resistors into 
			}
		}
		count_res1++;
	} while (count_res1 < resistor_values.size());
	std::cout << "\nPotential resistor values are: " << std::endl;

	for (auto j = arrangements.begin(); j != arrangements.end(); j++)
	{
		res1 = j->first;
		res2 = j->second;
		std::cout << "Resistor 1: "<< std::setprecision(4) << res1 << "		" << "Resistor 2: " << std::setprecision(4) << res2 << std::endl;
	}
	if (arrangements.empty() == false)
	{
		std::cout << "\nNumber of arrangements: " << arrangements.size() << std::endl;
	}
	else
	{
		std::cout << "No possible combinations." << std::endl;
	}
	
	if (arrangements.empty() == false)
	{
		std::cout << "Recommended Combination: " << std::endl;
		//initializing resistor values for sorting for closest combination 
		auto it = arrangements.begin();
		res1 = it->first;
		res2 = it->second;
		if (cmd == "1")
		{
			calculated_res = series_comb(res1, res2);
		}
		else if (cmd == "2")
		{
			calculated_res = parallel_comb(res1, res2);
		}

		for (auto j = arrangements.begin(); j != arrangements.end(); j++)
		{
			float calculated_res_now = (j->first + j->second);
			if (abs(calculated_res - input_val) <= abs(calculated_res_now - input_val))
			{
				calculated_res = calculated_res;
				res1 = res1;
				res2 = res2;
			}
			else if (abs(calculated_res - input_val) > abs(calculated_res_now - input_val))
			{
				res1 = j->first;
				res2 = j->second;
				if (cmd == "1")
				{
					calculated_res = series_comb(res1, res2);
				}
				else if (cmd == "2")
				{
					calculated_res = parallel_comb(res1, res2);
				}
			}

		}
		std::cout << "Resistor 1: " << std::setprecision(4) << res1 << "		" << "Resistor 2: " << std::setprecision(4) << res2 << "	" << "Resulted Resistance: " << std::setprecision(3) << calculated_res << std::endl;
	}
	//reset vectors and strings 
	resistor_values.clear();
	arrangements.clear();
	cmd.clear();
}

