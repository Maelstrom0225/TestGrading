/*

The contents of the student input file should be read into one char array. 
The file will contain up to 30 characters, each character on a separate line of the file. 
The first line in the input file will contain the students answer to the first question, the second 
line will contain the student's answer to the 2nd question, and so on for up to 30 questions. The answers are A, B, C or D (all upper case).

The answer file will be read in as well, one answer per line for up to 30 answers. 
The first line of text is the answer for question 1, then second line is the answer for question 2, and so on.

You need to keep track of the number of student answers and the correct answers. 
If the number of student answers and correct answers is not the same you need to output an error message (see below).

As always, close the input files when you are done with them.

Your program needs to determine the number of questions that the student missed and then display the following:

A list of questions missed by the student, showing the question number (1 through up to 30), the correct answer, and the incorrect answer.
The total number of questions missed by the student
The percentage of the questions answered correctly.
If the percentage of questions answered correctly is 70% or more indicate that the student passed, otherwise state that the student failed the quiz.
*/
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;




int main() {
	char arrQ[30], arrA[30];
	ifstream inFile;
	string file;
	int correct = 0;
	int wrong = 0;
	int sizeA = 0;
	int sizeQ = 0;

	cout << "Enter input file name\n";
	cin >> file;
	inFile.open(file);
	if (!inFile.is_open()){
		cout << "File \"" << file << "\" could not be opened\n";
	} 
	else {
		char ch;
		int counter = 0;
		while ((inFile >> ch) && (counter < 30)) {
			arrQ[counter] = ch;
			counter++;
		}
		inFile.close();

		sizeQ = counter;

		//cout << "Enter correct answer file name\n";
		//cin >> file;
		//inFile.open(file);
		if (!inFile.is_open()) {
			cout << "The input file \"" << file << "\" did not contain any data\n";
		}
		else {
			counter = 0;
			while ((inFile >> ch) && (counter < 30)) {
				arrA[counter] = ch;
				counter++;
			}
			inFile.close();

			sizeA = counter;

			if ((sizeA == sizeQ) && (sizeA != 0) && (sizeQ != 0)) {

				for (int i = 0; i < sizeA; i++) {
					if (arrQ[i] == arrA[i]) {
						correct++;
					}
					else {
						wrong++;
						cout << "Question " << i + 1 << " has incorrect answer '" << arrQ[i] << "', the correct answer is '" << arrA[i] << "'" << endl;
					}
				}



				cout << wrong << " questions were missed out of " << sizeA << endl;

				double score = (correct * 100.0) / sizeA;

				cout << fixed << setprecision(1) << "The student grade is " << score << "%\n";

				if (score < 70.0)
					cout << "The student failed\n";
				else
					cout << "The student passed\n";
			}
			else if ((sizeA == 0) && (sizeQ == 0)){
				cout << "The input file " << file << " did not contain any data\n";
				
			}
			else {
				cout << "The student answers file has " << sizeQ << " entries and the correct answers file has " << sizeA << " entries\nGrading cannot be done if they are not the same\n";
			}
		}
	}
}


