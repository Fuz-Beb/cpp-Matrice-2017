#ifndef C_EXCEPTION_H
#define C_EXCEPTION_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>


// Utilisé en cas d'exception
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
	Constructeur par défaut
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : néant
	Entraine : l'objet en cours est initialisé
	*****************************/
	explicit CException();

	/*****************************
	Constructeur à deux arguments
	******************************
	Entrée : unsigned int uiCodeErreur, char * psMessageErreur
	Necessité : néant
	Sortie : néant
	Entraine : le paramètre est recopié et ainsi l'objet en cours est initialisé
	*****************************/
	explicit CException(unsigned int uiCodeErreur, char * psMessageErreur);

	/*****************************
	Constructeur de recopie
	******************************
	Entrée : CException & e
	Necessité : néant
	Sortie : néant
	Entraine : l'object en cours en initialisé avec les même attributs que l'objet passé en paramètre
	*****************************/
	CException(CException & e);

	/*****************************
	Destructeur par défaut
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : néant
	Entraine : l'objet en cours est détruit
	*****************************/
	~CException();

	// Accesseurs

	/*****************************
	Methode : Lecture du code d'erreur
	*****************************
	Entrée : néant
	Necessité : néant
	Sortie : unsigned int
	Entraine : retourne le code d'erreur
	*****************************/
	unsigned int EXCLectureCode();

	/*****************************
	Methode : Modification du code d'erreur
	******************************
	Entrée : unsigned int uiCodeErreur
	Necessité : néant
	Sortie : néant
	Entraine : modification du code d'erreur
	*****************************/
	void EXCEcritureCode(unsigned int uiCodeErreur);

	/*****************************
	Methode : Lecture du message d'erreur
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : néant
	Entraine : affiche le message d'erreur
	*****************************/
	char * EXCLectureMessage();

	/*****************************
	Methode : Modification du message d'erreur
	******************************
	Entrée : char * psMessage
	Necessité : néant
	Sortie : néant
	Entraine : modification du message d'erreur
	*****************************/
	void EXCEcritureMessage(char * psMessage);
};
#endif
