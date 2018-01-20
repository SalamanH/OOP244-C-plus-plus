#include <iostream>
#include "kingdom.h"
#include <cstring>

using namespace std;
namespace westeros {


	void display(kingdom s) {
		cout << (s.m_name) << ", population " << (s.m_population) << endl;
	}

	void display(kingdom s[], int Num) {
		int num2 = 0;
		cout << "------------------------------" << endl
			<< "Kingdoms of Westeros" << endl
			<< "------------------------------" << endl;
		for (int i = 0; i < Num; i++){
			cout << i+1<< ". ";
			display(s[i]);
			num2 = atoi(s[i].m_population) + num2;
		}
		cout << "------------------------------" << endl;
		cout << "Total population of Westeros: " << (num2) << endl;
		cout << "------------------------------" << endl;
	}
	void display(kingdom s[], int Num, int Min_population){
		cout << "------------------------------" << endl
			<< "Kingdoms of Westeros with more than " << (Min_population) << " people" << endl
			<< "------------------------------" << endl;
		for (int i = 0; i < Num; i++){
			if (atoi(s[i].m_population) >= Min_population)
			{
				display(s[i]);
			}
		}
		cout << "------------------------------" << endl;

	}
	void display(kingdom s[], int Num, char const * exists) {
		cout << "------------------------------" << endl
			<< "Searching for kingdom " << (exists) << " in Westeros" << endl
			<< "------------------------------" << endl;
		int m = 0;
		int &m2 = m;
		for (int i = 0; i < Num; i++) {
			
			
			if (strcmp(s[i].m_name, exists) == 0){
				display(s[i]);
				cout << "------------------------------" << endl;
				m2 = 1;
			}

		}
		if (m == 0){
			cout << (exists) << " is not part of Westeros." << endl <<
				"------------------------------" << endl << endl;

		}
	}
	
}