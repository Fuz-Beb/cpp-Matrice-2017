#ifndef C_PARSE_H
#define C_PARSE_H

//#define _CRT_SECURE_NO_WARNINGS

#include <fstream>

using namespace std;

class CParse
{
private:
	// Attributs
	char * psPARChemin;
	FILE * pPARFichier;

public:
	// Constructeurs / Descructeurs
	explicit CParse();
	explicit CParse(char * psChemin);
	~CParse();

	// Accesseurs
	inline char * PARLireChemin();
	inline void PARModifierChemin(char * psParam);
	void PAROuvrirFichier(char * psParam);
	inline void PARFermerFicher();

	// M�thodes
	char * PARLireLigne();
	char * PARSubString(char * psParam, unsigned int uiDebut, unsigned int uiTaille);
	char * CParse::PARConcatenateString(const char * psStr1, const char * psStr2);
	void PARConvertirStrMinusc(char * psParam);
	char PARConvertirCharMinusc(char cParam);
	
};
#endif
