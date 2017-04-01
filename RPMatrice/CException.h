#ifndef C_EXCEPTION_H
#define C_EXCEPTION_H

#include <iostream>

// Utilis� en cas d'exception
#define ECHECALLOCATION 1
#define DIMENSIONHORSPORTEE 2
#define DIMENSIONINEGALE 3
#define FORMATFICHIERINCORRECTE 4
#define MAUVAISTYPE 5
#define ERREURTAILLE 6
#define DIVISIONPARZERO 7
#define ECHECOUVERTUREFICHIER 8
#define ECHECLECTURELIGNEFICHIER 9

class CException
{
private: 
	// Attributs
	unsigned int uiEXCCode;
	char * psEXCMessage;

public:
	// Constructeurs et destructeur

	/*****************************
	Constructeur par d�faut
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet en cours est initialis�
	*****************************/
	explicit CException();

	/*****************************
	Constructeur � deux arguments
	******************************
	Entr�e : unsigned int uiCodeErreur, char * psMessageErreur
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : le param�tre est recopi� et ainsi l'objet en cours est initialis�
	*****************************/
	explicit CException(unsigned int uiCodeErreur, char * psMessageErreur);

	/*****************************
	Destructeur par d�faut
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet en cours est d�truit
	*****************************/
	~CException();

	// Accesseurs

	/*****************************
	Methode : Lecture du code d'erreur
	*****************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : unsigned int
	Entraine : retourne le code d'erreur
	*****************************/
	unsigned int EXCLectureCode();

	/*****************************
	Methode : Modification du code d'erreur
	******************************
	Entr�e : unsigned int uiCodeErreur
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : modification du code d'erreur
	*****************************/
	void EXCEcritureCode(unsigned int uiCodeErreur);

	/*****************************
	Methode : Lecture du message d'erreur
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : char *
	Entraine : retourne le message d'erreur
	*****************************/
	char * EXCLectureMessage();

	/*****************************
	Methode : Modification du message d'erreur
	******************************
	Entr�e : char * psMessage
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : modification du message d'erreur
	*****************************/
	void EXCEcritureMessage(char * psMessage);
};
#endif
