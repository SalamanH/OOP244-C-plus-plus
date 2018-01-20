#pragma once
#ifndef SICT_kingdom_H_
#define SICT_kingdom_H_
namespace westeros {
	struct kingdom {
		char m_population[100];
		char m_name[32];
	};
	void display(kingdom s);
	void display(kingdom s[], int Num);
	void display(kingdom s[], int Num, int Min_Population);
	void display(kingdom s[], int Num, char const * exists);
	

}
#endif