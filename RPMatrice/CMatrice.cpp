#include "CMatrice.h"
#include "CException.h"


template <class Type>
CMatrice<Type>::CMatrice()
{
	uiMATNbLignes = 1;
	uiMATNbColonnes = 1;

	ppqMATMatrice = (Type**) malloc (sizeof(Type*) * uiMATNbLignes); 
	if (ppqMATMatrice == nullptr)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	ppqMATMatrice[0] = (Type*) malloc(sizeof(Type) * uiMATNbColonnes);
	if (ppqMATMatrice[0] == nullptr)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	// Initalisation de la matrice avec la valeur 0
	MATInit();
}


// Pr�-condition : La lib�ration des pointeurs avant la suppression de la matrice est � la charge de l'utilisateur
template <class Type>
CMatrice<Type>::~CMatrice()
{
	unsigned int uiBoucle;

	// D�sallocation m�moire de la matrice
	for(uiBoucle = 0; uiBoucle < uiMATNbLignes; uiBoucle++)
		delete[] ppqMATMatrice[uiBoucle];

	delete[] ppqMATMatrice;
}


template <class Type>
CMatrice<Type>::CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
	unsigned int uiBoucle;

	uiMATNbLignes = uiNbLignes;
	uiMATNbColonnes = uiNbColonnes;

	// Allocation m�moire de la matrice
	ppqMATMatrice = (Type**) malloc(sizeof(Type*) * uiMATNbLignes); // Allocation des lignes
	if (ppqMATMatrice == nullptr)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");
	
	for (uiBoucle = 0; uiBoucle < uiMATNbLignes; uiBoucle++) // Allocation des colonnes
	{
		ppqMATMatrice[uiBoucle] =  (Type*) malloc(sizeof(Type) * uiMATNbColonnes);
		if (ppqMATMatrice[uiBoucle] == nullptr)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");
	}

	// Initalisation de la matrice avec la valeur 0
	MATInit();
}


template <class Type>
CMatrice<Type>::CMatrice(CMatrice<Type> & MATMatrice)
{
	unsigned int uiBoucleLigne, uiBoucleColonne, uiBoucle;

	uiMATNbLignes = MATMatrice.uiMATNbLignes;
	uiMATNbColonnes = MATMatrice.uiMATNbColonnes;

	// Allocation m�moire de la matrice
	ppqMATMatrice = (Type**) malloc(sizeof(Type*) * uiMATNbLignes); // Allocation des lignes
	if (ppqMATMatrice == nullptr)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");
	
	for (uiBoucle = 0; uiBoucle < uiMATNbLignes; uiBoucle++) // Allocation des colonnes
	{
		ppqMATMatrice[uiBoucle] =  (Type*) malloc(sizeof(Type) * uiMATNbColonnes);
		if (ppqMATMatrice[uiBoucle] == nullptr)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");
	}

	// Affectation des valeurs
	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
			ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = MATMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];
}


template <class Type>
void CMatrice<Type>::MATEcrireNbLignes(unsigned int uiNbLignes)
{
	uiMATNbLignes = uiNbLignes;
}


template <class Type>
unsigned int CMatrice<Type>::MATLireNbLignes()
{
	return uiMATNbLignes;
}


template <class Type>
void CMatrice<Type>::MATEcrireNbColonnes(unsigned int uiNbColonnes)
{
	uiMATNbColonnes = uiNbColonnes;
}


template <class Type>
unsigned int CMatrice<Type>::MATLireNbColonnes()
{
	return uiMATNbColonnes;
}


template <class Type>
CMatrice<Type> CMatrice<Type>::MATCalculerTransposee()
{
	unsigned int uiBoucle1, uiBoucle2;

	CMatrice<Type> MATNewMatrice = CMatrice<Type>(uiMATNbColonnes, uiMATNbLignes);

	// Affectation des nouvelles valeurs � la nouvelle matrice
	for (uiBoucle2 = 0 ; uiBoucle2 < uiMATNbLignes ; uiBoucle2++)
		for (uiBoucle1= 0 ; uiBoucle1 < uiMATNbColonnes ; uiBoucle1++)
			MATNewMatrice.ppqMATMatrice[uiBoucle1][uiBoucle2] = ppqMATMatrice[uiBoucle2][uiBoucle1];
	
	return MATNewMatrice;
}


template <class Type>
CMatrice<Type> CMatrice<Type>::MATPPuissanceMatrice(unsigned int uiNombre)
{
	try {
		unsigned int uiBoucleLigne, uiBoucleColonne;
		int iExposant;

		CMatrice<Type> MATNewMatrice = CMatrice<Type>(uiMATNbLignes, uiMATNbColonnes);

		// Dans le cas ou la puissance vaut 0
		if (uiNombre == 0) {
			for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
				for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
					MATNewMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = 1;
		} // Calcul et affectation des nouvelles valeurs dans la nouvelle matrice
		else {
			for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
				for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++) {
					MATNewMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];
					for (iExposant = uiNombre ; iExposant > 1 ; iExposant--)
						MATNewMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] *= ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];
				}
		}

		return MATNewMatrice;

	} catch (CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}


template <class Type>
void CMatrice<Type>::MATModifierElement(unsigned int uiNumLigne, unsigned int uiNumColonne, Type tElement)
{
	try {
		MATVerifierPortee(uiNumLigne, uiNumColonne);
		ppqMATMatrice[uiNumLigne - 1][uiNumColonne - 1] = tElement;
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}


template <class Type>
 Type CMatrice<Type>::MATLireElement(unsigned int uiNumLigne, unsigned int uiNumColonne)
{
	try {
		MATVerifierPortee(uiNumLigne, uiNumColonne);
		return ppqMATMatrice[uiNumLigne - 1][uiNumColonne - 1];
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}


 template <class Type>
 void CMatrice<Type>::MATInit()
 {
	 unsigned uiNbLignes, uiNbColonnes;

	 // Initialisation de l'ensemble des valeurs de la matrice � 0
	 for(uiNbLignes = 1 ; uiNbLignes <= uiMATNbLignes ; uiNbLignes++)
		 for(uiNbColonnes = 1 ; uiNbColonnes <= uiMATNbColonnes ; uiNbColonnes++)
			 MATModifierElement(uiNbLignes, uiNbColonnes, 0);
 }


template <class Type>
void CMatrice<Type>::MATAfficherMatrice()
{
	unsigned int uiBoucleLigne, uiBoucleColonne;
 
	for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++) {
		for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
			cout << ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] << "\t";

		printf("\n");
	}
}

/*****************************
Methode : Ajouter une/des colonnes � la droite de la matrice
******************************
Entr�e : unsigned int uiNbColonnes
Necessit� : n�ant
Sortie : n�ant
Entraine : r�allouer selon ajout nb colonnes
*****************************/
template <class Type>
void CMatrice<Type>::MATAjouterColonnesFin(unsigned int uiNbColonnes)
{
	try {
		unsigned int uiBoucle = 1;
		// Tant que le nombre de colonne � rajouter n'est pas atteint
		while(uiBoucle <= uiNbColonnes)
		{
			MATAjouterColonnePrecis(uiMATNbColonnes + 1);
			uiBoucle++;
		}

	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}


template <class Type>
void CMatrice<Type>::MATAjouterLignesFin(unsigned int uiNbLignes)
{
	try {
		unsigned int uiBoucle = 1;
		// Tant que le nombre de ligne � rajouter n'est pas atteint
		while(uiBoucle <= uiNbLignes)
		{
			MATAjouterLignePrecis(uiMATNbLignes + 1);
			uiBoucle++;
		}
	
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}


// Pr�-condition : La lib�ration des pointeurs avant la suppression de la colonne est � la charge de l'utilisateur
template <class Type>
void CMatrice<Type>::MATSupprimerColonneFin(unsigned int uiNbColonnes)
{
	try {
		unsigned int uiBoucle = 1;

		MATVerifierPortee(uiMATNbLignes, uiNbColonnes + 1);
		// Tant que le nombre de colonne � supprimer n'est pas atteint
		while(uiBoucle <= uiNbColonnes)
		{
			MATSupprimerColonnePrecis(uiMATNbColonnes);
			uiBoucle++;
		}

	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}


// Pr�-condition : La lib�ration des pointeurs avant la suppression de la ligne est � la charge de l'utilisateur
template <class Type>
void CMatrice<Type>::MATSupprimerLigneFin(unsigned int uiNbLignes)
{
	try {
		unsigned int uiBoucle = 1;

		MATVerifierPortee(uiNbLignes + 1, uiMATNbColonnes);
		// Tant que le nombre de ligne � supprimer n'est pas atteint
		while(uiBoucle <= uiNbLignes)
		{
			MATSupprimerLignePrecis(uiMATNbLignes);
			uiBoucle++;
		}

	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}


 template <class Type>
void CMatrice<Type>::MATAjouterColonnePrecis(unsigned int uiNumColonne)
{
	try	{
		unsigned int uiBoucleColonne = 0, uiBoucleLigne = 0;

		// Si la valeur fournie en param�tre n'est pas comprise dans les dimensions de la matrice
		if(uiNumColonne > uiMATNbColonnes + 1)
			throw CException(DIMENSIONHORSPORTEE, "Dimension matrice incorrecte - hors portee");

		uiMATNbColonnes++;

		// R�allocation m�moire de la matrice
		for(uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++) {
			ppqMATMatrice[uiBoucleLigne] =  (Type*) realloc(ppqMATMatrice[uiBoucleLigne], sizeof(Type) * uiMATNbColonnes);
			
			if (ppqMATMatrice[uiBoucleLigne] == nullptr)
				throw CException(ECHECALLOCATION, "Echec de la reallocation");
		}

		// Changement de position des valeurs de la matrice
		if(uiNumColonne < uiMATNbColonnes)
			for(uiBoucleColonne = uiMATNbColonnes ; uiBoucleColonne > uiNumColonne ; uiBoucleColonne--)
				for(uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
					ppqMATMatrice[uiBoucleLigne][uiBoucleColonne - 1] = ppqMATMatrice[uiBoucleLigne][uiBoucleColonne - 2];

	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}


 template <class Type>
void CMatrice<Type>::MATAjouterLignePrecis(unsigned int uiNumLigne)
{
	try	{
		unsigned int uiBoucleLigne, uiBoucleColonne;

		// Si la valeur fournie en param�tre n'est pas comprise dans les dimensions de la matrice
		if (uiNumLigne > uiMATNbLignes + 1)
			throw CException(DIMENSIONHORSPORTEE, "Dimension matrice incorrecte - hors portee");

		uiMATNbLignes++;

		// R�allocation des lignes
		ppqMATMatrice = (Type**) realloc(ppqMATMatrice, sizeof(Type*) * uiMATNbLignes);
	
		if (ppqMATMatrice == nullptr)
			throw CException(ECHECALLOCATION, "Echec de la reallocation");

		// Allocation des colonnes
		ppqMATMatrice[uiMATNbLignes - 1] = (Type*) malloc(sizeof(Type) * uiMATNbColonnes);
		
		if (ppqMATMatrice[uiMATNbLignes - 1] == nullptr)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");

		// Changement de position des valeurs de la matrice
		if (uiNumLigne < uiMATNbLignes)
			for(uiBoucleLigne = uiMATNbLignes ; uiBoucleLigne > uiNumLigne ; uiBoucleLigne--)
				for(uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
					ppqMATMatrice[uiBoucleLigne - 1][uiBoucleColonne] = ppqMATMatrice[uiBoucleLigne - 2][uiBoucleColonne];

	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}


// Pr�-condition : La lib�ration des pointeurs avant la suppression de la colonne est � la charge de l'utilisateur
template <class Type>
void CMatrice<Type>::MATSupprimerColonnePrecis(unsigned int uiNumColonne)
{
	try	{

		unsigned int uiBoucleColonne = 0, uiBoucleLigne = 0;

		MATVerifierPortee(uiMATNbLignes, uiNumColonne);

		// Changement de position des valeurs de la matrice
		for(uiBoucleColonne = uiNumColonne ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
			for(uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
				ppqMATMatrice[uiBoucleLigne][uiBoucleColonne - 1] = ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];

		// R�allocation des colonnes
		for(uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++) {
			ppqMATMatrice[uiBoucleLigne] =  (Type*) realloc(ppqMATMatrice[uiBoucleLigne], sizeof(Type) * (uiMATNbColonnes - 1));
			
			if (ppqMATMatrice[uiBoucleLigne] == nullptr)
				throw CException(ECHECALLOCATION, "Echec de la reallocation");
		}

		uiMATNbColonnes--;

	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}


// Pr�-condition : La lib�ration des pointeurs avant la suppression de la ligne est � la charge de l'utilisateur
template <class Type>
void CMatrice<Type>::MATSupprimerLignePrecis(unsigned int uiNumLigne)
{
	try	{
		unsigned int uiBoucleLigne, uiBoucleColonne;

		MATVerifierPortee(uiNumLigne, uiMATNbColonnes);

		// Changement de position des valeurs de la matrice
		for(uiBoucleLigne = uiNumLigne; uiBoucleLigne < uiMATNbLignes; uiBoucleLigne++)
			for(uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonnes; uiBoucleColonne++)
				ppqMATMatrice[uiBoucleLigne - 1][uiBoucleColonne] = ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];

		uiMATNbLignes--;

		delete ppqMATMatrice[uiMATNbLignes];

		// R�allocation des lignes
		ppqMATMatrice = (Type**) realloc(ppqMATMatrice, sizeof(Type*) * uiMATNbLignes);
	
		if (ppqMATMatrice == nullptr)
			throw CException(ECHECALLOCATION, "Echec de la reallocation");

	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}


template <class Type>
void CMatrice<Type>::MATVerifierPortee(unsigned int uiNumLigne, unsigned int uiNumColonne)
{
	// Si les param�tres founies sont sup�rieurs � la dimension de la matrice
	if (uiMATNbLignes < uiNumLigne || uiNumLigne == 0 || uiMATNbColonnes < uiNumColonne || uiNumColonne == 0)
		throw CException(DIMENSIONHORSPORTEE, "Dimension matrice incorrecte - hors portee");
}


template <class Type>
void CMatrice<Type>::MATVerifierDimension(unsigned int uiNbLignes, unsigned int uiNbColonnes)

{
	// Si les matrices ont la m�me dimension
	if (uiMATNbLignes != uiNbLignes || uiMATNbColonnes != uiNbColonnes)
		throw CException(DIMENSIONINEGALE, "Dimension matrice in�gale");
}


// Pr�-condition : Si la matrice contient des pointeurs sur des objets, la surchage de l'op�rateur + doit �tre pr�sente dans la classe concern�e
template <class Type>
CMatrice<Type> CMatrice<Type>::operator+(CMatrice<Type> & MATMatrice)
{
	try {
		unsigned int uiBoucleLigne, uiBoucleColonne;

		MATVerifierDimension(MATMatrice.uiMATNbLignes, MATMatrice.uiMATNbColonnes);

		CMatrice<Type> MATNewMatrice = CMatrice<Type>(MATMatrice.uiMATNbLignes, MATMatrice.uiMATNbColonnes);

		// Calcul et affectation des nouvelles valeurs dans la nouvelle matrice
		for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
			for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
				MATNewMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] + MATMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];

		return MATNewMatrice;

	} catch (CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}


// Pr�-condition : Si la matrice contient des pointeurs sur des objets, la surchage de l'op�rateur - doit �tre pr�sente dans la classe concern�e
template <class Type>
CMatrice<Type> CMatrice<Type>::operator-(CMatrice<Type> & MATMatrice)
{
	try {
		unsigned int uiBoucleLigne, uiBoucleColonne;

		MATVerifierDimension(MATMatrice.uiMATNbLignes, MATMatrice.uiMATNbColonnes);

		CMatrice<Type> MATNewMatrice = CMatrice<Type>(MATMatrice.uiMATNbLignes, MATMatrice.uiMATNbColonnes);

		// Calcul et affectation des nouvelles valeurs dans la nouvelle matrice
		for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
			for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
				MATNewMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] - MATMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];

		return MATNewMatrice;

	} catch (CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}


template <class Type>
CMatrice<Type> CMatrice<Type>::operator*(Type & qMATparam)
{
	try {
		unsigned int uiBoucleLigne, uiBoucleColonne;

		CMatrice<Type> MATNewMatrice = CMatrice<Type>(uiMATNbLignes, uiMATNbColonnes);

		// Calcul et affectation des nouvelles valeurs dans la nouvelle matrice
		for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
			for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
				MATNewMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] * qMATparam;

		return MATNewMatrice;

	} catch (CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}


// Pr�-condition : Si la matrice contient des pointeurs sur des objets, la surchage de l'op�rateur * doit �tre pr�sente dans la classe concern�e
template <class Type>
CMatrice<Type> CMatrice<Type>::operator*(CMatrice<Type> & MATMatrice)
{
	try {
		unsigned int uiBoucleLigne, uiBoucleColonne, uiBoucleResult;

		if (uiMATNbColonnes != MATMatrice.uiMATNbLignes)
			throw CException(DIMENSIONINEGALE, "Dimension matrice in�gale");

		CMatrice<Type> MATNewMatrice = CMatrice<Type>(MATMatrice.uiMATNbLignes, MATMatrice.uiMATNbColonnes);

		// Calcul et affectation des nouvelles valeurs dans la nouvelle matrice
		for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++) {
			for (uiBoucleColonne = 0 ; uiBoucleColonne < MATMatrice.uiMATNbColonnes ; uiBoucleColonne++) {
				for (uiBoucleResult = 0 ; uiBoucleResult < uiMATNbColonnes ; uiBoucleResult++) {
					MATNewMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] += ppqMATMatrice[uiBoucleLigne][uiBoucleResult] * MATMatrice.ppqMATMatrice[uiBoucleResult][uiBoucleColonne];
				}
			}
		}

		return MATNewMatrice;

	} catch (CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}


template <class Type>
CMatrice<Type> CMatrice<Type>::operator/(Type & qMATparam)
{
	try {
		unsigned int uiBoucleLigne, uiBoucleColonne;

		if (qMATparam == 0)
			throw CException(DIVISIONPARZERO, "Divison par z�ro impossible");

		CMatrice<Type> MATNewMatrice = CMatrice<Type>(uiMATNbLignes, uiMATNbColonnes);

		// Calcul et affectation des nouvelles valeurs dans la nouvelle matrice
		for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
			for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
				MATNewMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] / qMATparam;

		return MATNewMatrice;

	} catch (CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		std::terminate();
	}
}


// Pr�-condition : La lib�ration des pointeurs avant l'affectation est � la charge de l'utilisateur
template <class Type>
CMatrice<Type> & CMatrice<Type>::operator=(CMatrice<Type> & MATMatrice)
{
	unsigned int uiBoucleLigne, uiBoucleColonne;

	// Si la matrice de destination n'a pas assez de ligne
	if (uiMATNbLignes < MATMatrice.uiMATNbLignes)
		MATAjouterLignesFin(MATMatrice.uiMATNbLignes - uiMATNbLignes);
	
	// Si la matrice de destination a trop de ligne
	else if (uiMATNbLignes > MATMatrice.uiMATNbLignes)
		MATSupprimerLigneFin(uiMATNbLignes - MATMatrice.uiMATNbLignes);
	
	// Si la matrice de destination n'a pas assez de colonne
	if (uiMATNbColonnes < MATMatrice.uiMATNbColonnes)
		MATAjouterColonnesFin(MATMatrice.uiMATNbColonnes - uiMATNbColonnes);

	// Si la matrice de destination a trop de colonne
	else if (uiMATNbColonnes > MATMatrice.uiMATNbColonnes)
		MATSupprimerColonneFin(uiMATNbColonnes - MATMatrice.uiMATNbColonnes);
	
	// Affectation des nouvelles valeurs dans la nouvelle matrice
	for (uiBoucleLigne = 0 ; uiBoucleLigne < uiMATNbLignes ; uiBoucleLigne++)
		for (uiBoucleColonne = 0 ; uiBoucleColonne < uiMATNbColonnes ; uiBoucleColonne++)
			ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = MATMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];
	
	return *this;
}


template <class Type>
bool CMatrice<Type>::operator!=(CMatrice<Type> & MATMatrice)
{
	unsigned int uiNbLignes, uiNbColonnes;
	
	// Si le nombre de lignes et de colonnes des deux matrices sont diff�rents
	if (uiMATNbLignes != MATMatrice.uiMATNbLignes || uiMATNbColonnes != MATMatrice.uiMATNbColonnes)
		return true;

	// Test l'�galit� des valeurs
	for (uiNbLignes = 0 ; uiNbLignes < uiMATNbLignes ; uiNbLignes++)
		for (uiNbColonnes = 0 ; uiNbColonnes < uiMATNbColonnes ; uiNbColonnes++) {
			if (ppqMATMatrice[uiNbLignes][uiNbColonnes] != MATMatrice.ppqMATMatrice[uiNbLignes][uiNbColonnes])
				return true;
		}
	return false;
}


template <class Type>
CMatrice<Type> operator*(Type qMATparam, CMatrice<Type> & MATMatrice)
{
	// Appel de l'op�rateur de surcharge * pr�sent de la classe CMatrice
	return MATMatrice * qMATparam;
}
