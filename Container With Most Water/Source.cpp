// Zachary Williams
// 11/1/19
// This is a fairly simple problem that was considered MEDIUM difficulty, this took me roughly 20 minutes to solve.
// I have avoided recursion for this problem for most efficient time complexity.
// My goal with the program was to make the code as fast as possible, while still maintaining good readability, therefore
// the maximum possible area was determined via testing each possible area, rather than computing the value via a mathematical
// equation.
// Also please note that I understand that creating as many variables within biggestArea as I did might not have been necessary, but
// I included them for readability.
//

#include <iostream>
#include <vector>
using namespace std;

int biggest_area(vector<int> &lineList)
{
	int maxArea = 0; // This variable will be used to compare the current maxArea with the current tempArea to determine the new maxArea
	int tempArea = 0; // This variable will be used to temporarily store the area generated by each of the vertical lines on the graph
	int tempHeight = 0; // This variable will be determined by the lower number between the two vertical lines
	int tempWidth = 0; // This variable will be determined by the difference of the index between the two vertical lines
	
	// the i variable will go from 0 to (size of vector) - 1
	for (int i = 0; i < lineList.size(); i++)
	{
		// the q variable is set to the same value as i every time the loop commences so that I can avoid generating the same
		// tempArea twice, therefore, the program will execute slightly faster
		for (int q = i; q < lineList.size(); q++)
		{
			// Assigning the SMALLER number as the height in order to test size of area
			if (lineList[i] >= lineList[q])
				tempHeight = lineList[q];
			else
				tempHeight = lineList[i];

			tempWidth = q - i; // width is the difference between the two
			tempArea = tempWidth * tempHeight; // calculating area
			if (tempArea > maxArea) // comparing tempArea and maxArea
				maxArea = tempArea;
		}

	}

	return maxArea;
}



int main()
{
	vector <int> lineList; // Stores the list of integers
	int input;

	cout << "Please enter positive integers that you would like to fill your graph with." << endl;
	cout << "Make sure to hit ENTER after every integer that you enter" << endl;
	cout << "When you are finished, generate the area by entering a non integer." << endl;
	while (cin >> input) // Enter any non-integer to end the loop
	{
		lineList.push_back(input);
	}
	cout << "The maximum possible area of the container is " << biggest_area(lineList) << endl;

	system("pause");
	return 0;
}