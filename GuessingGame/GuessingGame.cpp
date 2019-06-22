//this program a guessing game 
//The program ask the user to guess any number within a range of 100
//The program ask question not more than 7 times to figure out the actual number the user guessed



#include "std_lib_facilities.h"
#include <exception>
#define RANG 200

char get_yes_no() {
	char ch =0;
	while (!(tolower(ch) == 'y' || tolower(ch) == 'n')) {
		ch = getchar();
	}
	return ch;
}
bool less_than_eq(int val)
//This function return true if the number is less than or equal 'val' otherwise false
// it will throw an exception if the user enter an invalid number

{
	cout << "Please enter 'Y' if the number is less than or equal: " << val  << " otherwise enter 'N'" << endl;
	char ch = get_yes_no();

	if (tolower(ch) == 'y')return true;
	if (tolower(ch) == 'n')return false;
}

bool less_than(int val)
//This function return true if the number is less than 'val' otherwise false
// it will throw an exception if the user enter an invalid number

{
	cout << "Please enter 'Y' if the number is less than: " << val << " otherwise enter 'N'" << endl;
	char ch = get_yes_no();

	if (tolower(ch) == 'y')return true;
	if (tolower(ch) == 'n')return false;
}

template<class T>
bool check(T b, T e) 
//check if b is equal to e
{
	return (b == e);
}

template<class T>
void guess(T b, T e) {
	int val = (e - b) / 2;

		//check if the number has been found
		if (check(b + val + 1, e)) { //if true then the actual value is in interval of e to e-2
			if (*(b + val) >= RANG) { //check for out of range values
				if (less_than(*(e-1)))
					cout << "the guess number is: " << *(e - 2) << endl;
				else
					cout << "the guess number is: " << *(e - 1) << endl;
			}
			else if (less_than(*e))
				cout << "the guess number is: " << *(e-1) << endl;
			else
				cout << "the guess number is: " << *(e) << endl;
			return;
		}

		if (less_than_eq(*(b + val))) {
			e = b + val;
			guess(b, e);
		}
		else {
			b = b + val;
			guess(b, e);
		}

}

void execute_guess_game() {


		cout << "Please guess an integer number on your mind within interval of 1 to " << RANG << endl;

		int count = 1;
		vector<int>num_range;
		while (num_range.size() != RANG)num_range.push_back(count++);

		guess(num_range.begin(), num_range.end());

	
}

int main(int argc, char* argv[])
{
	execute_guess_game();
	
	keep_window_open("~");
	return 0;

}