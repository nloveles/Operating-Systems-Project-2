//Nathan Loveless
//Project 2
//Operating systems
//11/24/21


//Include Libraries
#include <iostream> 
#include <iostream>
#include <fstream>
#include <string>

//Declare namespace
//using namespace std;

//Global Variables
std::string stringnum;
int num = 0;
int space = 0;

int main()
{
	
	//First create allocation array 
	std::ifstream info("info.txt"); //Open up text file stream 
	if (!info.is_open()) //Tests if allocation file is open
	{
		std::cout << "Could Not Find Allocation File";  //If it isnt it reads this message
		return 1;  //And ends in error
	}

	int allocation[5][3]; //Create an array to hold allocation info
	int max[5][3]; //Array for max
	int available[3]; //array to hold availbe resources
	int hold;
	int one, ten, hundred; //Variables to keep track of the places
	int needsmore[5];//Array to hold the processes with out enough resources
	int good[6];//Variable to hold the number of good processes  
	int processnum = 0; //Variable to hold the number of the process at hand
	
	//Populating allocation array 
	info >> num;
	allocation[0][0] = 0; 
	hold = num / 10; 
	allocation[0][1] = hold; 
	num = hold; 
	hold = num / 10; 
	allocation[0][2] = hold; 

	info >> num;
	hundred = num / 100;
	num = num - (hundred * 100);
	ten = num / 10;
	one = num % 10;
	allocation[1][0] = hundred;
	allocation[1][1] = ten;
	allocation[1][2] = one;

	info >> num;
	hundred = num / 100;
	num = num - (hundred * 100);
	ten = num / 10; 
	one = num % 10;
	allocation[2][0] = hundred;
	allocation[2][1] = ten ;
	allocation[2][2] = one;

	info >> num;
	hundred = num / 100;
	num = num - (hundred * 100);
	ten = num / 10;
	one = num % 10;
	allocation[3][0] = hundred;
	allocation[3][1] = ten;
	allocation[3][2] = one;

	info >> num;
	hundred = num / 100;
	num = num - (hundred * 100);
	ten = num / 10;
	one = num % 10;
	allocation[4][0] = hundred;
	allocation[4][1] = ten;
	allocation[4][2] = one;
	
	info >> num;
	hundred = num / 100;
	num = num - (hundred * 100);
	ten = num / 10;
	one = num % 10;
	max[0][0] = hundred;
	max[0][1] = ten;
	max[0][2] = one;

	info >> num;
	hundred = num / 100;
	num = num - (hundred * 100);
	ten = num / 10;
	one = num % 10;
	max[1][0] = hundred;
	max[1][1] = ten;
	max[1][2] = one;

	info >> num;
	hundred = num / 100;
	num = num - (hundred * 100);
	ten = num / 10;
	one = num % 10;
	max[2][0] = hundred;
	max[2][1] = ten;
	max[2][2] = one;

	info >> num;
	hundred = num / 100;
	num = num - (hundred * 100);
	ten = num / 10;
	one = num % 10;
	max[3][0] = hundred;
	max[3][1] = ten;
	max[3][2] = one;

	info >> num;
	hundred = num / 100;
	num = num - (hundred * 100);
	ten = num / 10;
	one = num % 10;
	max[4][0] = hundred;
	max[4][1] = ten;
	max[4][2] = one;

	info >> num;
	hundred = num / 100;
	num = num - (hundred * 100);
	ten = num / 10;
	one = num % 10;
	available[0] = hundred;
	available[1] = ten;
	available[2] = one;

	//Logic
	
	for (int k = 0; k < 5; k++) {
		needsmore[k] = 0;
	}
	//Finding how many resources is needed per process
	int neededresources[5][3];
	for (int i = 0; i < 5; i++) 
	{
		for (int j = 0; j < 3; j++)
		{
			neededresources[i][j] = max[i][j] - allocation[i][j];
		}
	}
	int y = 0;
	for (int k = 0; k < 5; k++) 
	{
		for (int i = 0; i < 5; i++) 
		{
			if (needsmore[i] == 0)
			{
				//Tests to see if needed resources are enough
				int notenough = 0;
				for (int j = 0; j < 3; j++)
				{
					if (neededresources[i][j] > available[j])
					{//If it is not good enough
						notenough = 1;
						break; //Stop
					}
				}

				if (notenough == 0)  //If there is enough
				{
					good[processnum++] = i; //add it to the answer
					for (y = 0; y < 3; y++)
					{
						available[y] += allocation[i][y];
					}
					needsmore[i] = 1;
				}
			}
		}
	}


	std::cout << "The safest sequence is :" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Process " << good[i] << ", ";
	}
		

	return (0);
}
