#include "CMatrice.h"
#include "CException.h"
#include "CParseMatrice.h"
#include "CParse.h"
#include <iostream>
#include <vld.h>


void main(unsigned int argc, char *argv[])
{
	// Délarations des variables
	unsigned int uiBoucleTableau = 0;
	double eValeurC = 0;
	bool bAdditionOuSoustraction = false, bCorrectValue = false;
	CMatrice<double> CMAResultOperation = CMatrice<double>();

	CParseMatrice ** CPAMonParseur = (CParseMatrice **) malloc(sizeof(CParseMatrice*) * argc - 1);
	CMatrice<double> ** CMAMesMatrices = (CMatrice<double> **) malloc(sizeof(CMatrice<double> *) * argc - 1);


	// Traitement des fichiers - Création des matrices
	for (uiBoucleTableau = 0 ; uiBoucleTableau < argc - 1; uiBoucleTableau++)
	{
		CPAMonParseur[uiBoucleTableau] = new CParseMatrice();
		CPAMonParseur[uiBoucleTableau]->PAMTraiterFichier(argv[uiBoucleTableau + 1]);
		CMAMesMatrices[uiBoucleTableau] = CPAMonParseur[uiBoucleTableau]->PAMRetournerMatrice();
	}

	
	// Demande de saisie utilisateur
	cin >> eValeurC;
	while (!bCorrectValue)
	{
        if(cin.fail()) {
            cout << "Ce n'est pas un nombre. Recommencez !" << endl;
			cin.clear();
			cin.ignore();
			cin >> eValeurC;
		}
		else
			bCorrectValue = true;
	}

	// Multiplication et affichage du résultat
	printf("Division des matrices \n\n");
	for (uiBoucleTableau = 0; uiBoucleTableau < argc - 1 ; uiBoucleTableau++)
	{
		printf("Matrice %d * %0.2f. Resultat = \n", uiBoucleTableau+1, eValeurC);
		CMAResultOperation = *CMAMesMatrices[uiBoucleTableau] * eValeurC;
		CMAResultOperation.MATAfficherMatrice();
	}


	// Division et affichage du résultat
	printf("Multiplication des matrices \n\n");
	for (uiBoucleTableau = 0; uiBoucleTableau < argc - 1 ; uiBoucleTableau++)
	{
		printf("Matrice %d / %0.2f. Resultat = \n", uiBoucleTableau+1, eValeurC);
		CMAResultOperation = *CMAMesMatrices[uiBoucleTableau] / eValeurC;
		CMAResultOperation.MATAfficherMatrice();
	}


	// Additions des matrices
	printf("Addition des matrices \n\n");
	CMAResultOperation = *CMAMesMatrices[0];
	printf("Resultat = \n");

	for (uiBoucleTableau = 1; uiBoucleTableau < argc - 1; uiBoucleTableau++)
		CMAResultOperation = CMAResultOperation + *CMAMesMatrices[uiBoucleTableau];
	
	CMAResultOperation.MATAfficherMatrice();


	// Additions et soustractions des matrices
	printf("Additions et soustractions des matrices \n\n");
	CMAResultOperation = *CMAMesMatrices[0];
	printf("Resultat = \n");

	for (uiBoucleTableau = 1; uiBoucleTableau < argc - 1; uiBoucleTableau++)
	{
		if (bAdditionOuSoustraction == true) {
			CMAResultOperation = CMAResultOperation + *CMAMesMatrices[uiBoucleTableau];
			bAdditionOuSoustraction = false;
		} else {
			CMAResultOperation = CMAResultOperation - *CMAMesMatrices[uiBoucleTableau];
			bAdditionOuSoustraction = true;
		}
	}
	CMAResultOperation.MATAfficherMatrice();


	// Multiplication des matrices
	printf("Multiplication des matrices \n\n");
	CMAResultOperation = *CMAMesMatrices[0];
	printf("Resultat = \n");

	for (uiBoucleTableau = 1 ; uiBoucleTableau < argc -1 ; uiBoucleTableau++)
		CMAResultOperation = CMAResultOperation * *CMAMesMatrices[uiBoucleTableau];

	CMAResultOperation.MATAfficherMatrice();

	// Désallocation mémoire
	for (uiBoucleTableau = 0 ; uiBoucleTableau < argc -1 ; uiBoucleTableau++) {
		delete CPAMonParseur[uiBoucleTableau];
		delete CMAMesMatrices[uiBoucleTableau];
	}
	delete CPAMonParseur;
	delete CMAMesMatrices;
}