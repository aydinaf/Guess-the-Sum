// Aydin Azari Farhad
#include <iostream>
#include<cstdlib>
using namespace std;

//functions
void RollDice(unsigned int &s,int &d1,int &d2) {//seed , dice 1 , dice 2
	srand(s);//seeding
	d1 = 1 + rand() % 6;// shiftingValue(1) + rand() % scalingFactor(6)
	d2 = 1 + rand() % 6;

}

bool evenodd(int &xsum) {//check if number is even [returns 0 if even]
	if (xsum % 2 == 0) {
		return 0;//even
	}
	else {
		return 1;//odd
	}
}
//main
int main() {
	unsigned int seed;
	int a{ 0 }, b{ 0 };
	int sum{ 0 };
	int guess;
	bool win = 0;
	cout << "Enter a seed: ";
	cin >> seed;//seed input
	RollDice(seed,a,b);//dice roll
	sum = a + b;//sum
	if (evenodd(sum) == 0) {//even case
		cout << "sum is even. Three tries to guess the sum: "<< endl;
		for (int counter = 0; counter <= 2; counter++) {//three tries
			cin >> guess;//take guess
			if (guess == sum & win==0) {//check guess [correct]
				cout << "Congrats! Sum of " << a << " + " << b << " = " << sum<<endl;
				win = 1;//[declare win status]
				system("pause");
				return 0;//end program
			}
			else if (guess != sum & win == 0 & counter <2) {//check guess [incorrect]
				cout << "Incorrect! try again." << endl;
			}
		}
		if (win == 0) {//loser!
			cout<<"Incorrect! Sum of " << a << " + " << b << " = " << sum<<" YOU LOST! " << endl;
			system("pause");
			return 0;//end program
		}
	}
	else {//odd case
		cout << "sum is odd. Two tries to guess the sum: " << endl;
		for (int counter = 0; counter <= 1; counter++) {//two tries
			cin >> guess;//take guess
			if (guess == sum & win == 0) {//check guess correct
				cout << "Congrats! Sum of " << a << " + " << b << " = " << sum << endl;
				win = 1;//[declare win status]
				system("pause");
				return 0;//end program
			}
			else if (guess != sum & win == 0 & counter == 0) {//hint [after 1st try]
				if (guess < sum) {
					cout << "Hint: Sum is larger than " << guess << endl;
				}
				else {
					cout << "Hint: Sum is less than " << guess << endl;
				}
			}
			else if (guess != sum & win == 0 & counter < 1) {//incorrect
				cout << "Incorrect! try again." << endl;
			}
		}
		if (win == 0) {//loser!
			cout << "Incorrect! Sum of " << a << " + " << b << " = " << sum <<" YOU LOST! "<< endl;
			system("pause");
			return 0;//end program
		}
	}

	system("pause");
}
