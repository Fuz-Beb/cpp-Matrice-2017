#include "CMatrice.h"
#include "CException.h"


/*****************************
Constructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
*****************************/
template <class Type>
CMatrice<Type>::CMatrice()
{
	ppqMATMatrice = (Type**)malloc(0);
	if (ppqMATMatrice == NULL)
		throw new CException(ECHECALLOCATION, "Echec de l'allocation");
	uiMATNbLignes = 0;
	uiMATNbColonnes = 0;
}

/*****************************
Destructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : L'objet est d�truit
*****************************/
template <class Type>
CMatrice<Type>::~CMatrice()
{
	for(unsigned int uiBoucle = 0; uiBoucle < uiMATNbLignes; uiBoucle++)
		delete[] ppqMATMatrice[uiBoucle];

	delete[] ppqMATMatrice;
}

/*****************************
Constructeur � deux arguments
******************************
Entr�e : unsigned int - code d'erreur, char * - message d'erreur
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
*****************************/
template <class Type>
CMatrice<Type>::CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
	uiMATNbLignes = uiNbLignes;
	uiMATNbColonnes = uiNbColonnes;

	// Allocation m�moire de la matrice
	ppqMATMatrice = (Type**) malloc(sizeof(Type*) * uiMATNbLignes); // Allocation des lignes
	if (ppqMATMatrice == NULL)
		throw new CException(ECHECALLOCATION, "Echec de l'allocation");

	for (unsigned int eBoucle = 0; eBoucle < uiMATNbColonnes; eBoucle++) // Allocation des colonnes
	{
		ppqMATMatrice[eBoucle] =  (Type*) malloc(sizeof(Type) * uiMATNbColonnes);
		if (ppqMATMatrice[eBoucle] == NULL)
			throw new CException(ECHECALLOCATION, "Echec de l'allocation");
	}
}

/*****************************
Constructeur de recopie
******************************
Entr�e : CMatrice<Type> & MATMatrice
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�/recopi�
*****************************/
template <class Type>
CMatrice<Type>::CMatrice(CMatrice<Type> & MATMatrice)
{
	CMatrice<Type> ppqMATMatriceRetour = CMatrice<Type>(MATMatrice.uiMATNbLignes, MATMatrice.uiMATNbColonnes);
	
	unsigned int uiBoucleColonne;

	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < ppqMATMatriceRetour.uiMATNbLignes; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < ppqMATMatriceRetour.uiMATNbColonnes; uiBoucleColonne++)
		{
			ppqMATMatriceRetour.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne] = MATMatrice.ppqMATMatrice[uiBoucleLigne][uiBoucleColonne];
		}

		uiBoucleColonne = 0;
	}
}

/*****************************
Methode : Ecrire nombre de lignes
******************************
Entr�e : unsigned int uiNbLignes
Necessit� : n�ant
Sortie : n�ant
Entraine : modification nombre de lignes
*****************************/
template <class Type>
void CMatrice<Type>::MATEcrireNbLignes(unsigned int uiNbLignes)
{
	uiMATNbLignes = uiNbLignes;
}

/*****************************
Methode : Lire nombre de lignes
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : unsigned int
Entraine : retourne nombre de lignes
*****************************/
template <class Type>
unsigned int CMatrice<Type>::MATLireNbLignes()
{
	return uiMATNbLignes;
}

/*****************************
Methode : Ecrire nombre de colonnes
******************************
Entr�e : unsigned int uiNbColonnes
Necessit� : n�ant
Sortie : n�ant
Entraine : modification nombre de colonnes
*****************************/
template <class Type>
void CMatrice<Type>::MATEcrireNbColonnes(unsigned int uiNbColonnes)
{
	uiMATNbColonnes = uiNbColonnes;
}

/*****************************
Methode : Lire nombre de colonnes
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : retourne nombre de colonnes
*****************************/
template <class Type>
unsigned int CMatrice<Type>::MATLireNbColonnes()
{
	return uiMATNbColonnes;
}

template <class Type>
 CMatrice<Type> CMatrice<Type>::MATCalculerTransposee()
{
	return 0;
}

 template <class Type>
CMatrice<Type> CMatrice<Type>::MATAfficherMatrice()
{
	return 0;
}

template <class Type>
CMatrice<Type> CMatrice<Type>::MATPPuissanceMatrice(double dNombre)
{
	return 0;
}

/*****************************
Methode : Modifier l'�l�ment � l'endroit de la matrice
******************************
Entr�e : unsigned int uiNbLignes, unsigned int uiNbColonnes, Type tElement
Necessit� : n�ant
Sortie : n�ant
Entraine : Modification de l'�l�ment
*****************************/
template <class Type>
void CMatrice<Type>::MATModifierElement(unsigned int uiNbLignes, unsigned int uiNbColonnes, Type tElement)
{
	MATVerifierPortee();

	ppqMATMatrice[uiNbLignes][uiNbColonnes] = tElement;
}

/*****************************
Methode : Lire l'�l�ment � l'endroit de la matrice
******************************
Entr�e : unsigned int uiNbLignes, unsigned int uiNbColonnes
Necessit� : n�ant
Sortie : Type
Entraine : retourne l'element � l'endroit de la matrice
*****************************/
template <class Type>
 Type CMatrice<Type>::MATLireElement(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
	MATVerifierPortee();
	return ppqMATMatrice[uiNbLignes][uiNbColonnes];
}

template <class Type>
void CMatrice<Type>::MATAjouterColonnesFin(unsigned int uiNbColonnes)
{
}

template <class Type>
void CMatrice<Type>::MATAjouterLignesFin(unsigned int uiNbLignes)
{
}

template <class Type>
void CMatrice<Type>::MATSupprimerColonneFin(unsigned int uiNbColonnes)
{
}

template <class Type>
void CMatrice<Type>::MATSupprimerLigneFin(unsigned int uiNbLignes)
{
}

 template <class Type>
void CMatrice<Type>::MATAjouterColonnesPrecis(unsigned int uiNumColonnes)
{
}

 template <class Type>
void CMatrice<Type>::MATAjouterLignesPrecis(unsigned int uiNumLignes)
{
}

template <class Type>
void CMatrice<Type>::MATSupprimerColonnePrecis(unsigned int uiNumColonnes)
{
}

template <class Type>
void CMatrice<Type>::MATSupprimerLignePrecis(unsigned int uiNumLignes)
{
}

/*****************************
Methode : V�rifier la dimension de la matrice
******************************
Entr�e : unsigned int uiNumLignes, unsigned int uiNumColonnes
Necessit� : n�ant
Sortie : n�ant
Entraine : (n�ant) ou (Exception DIMENSIONHORSPORTEE : les param�tres fournis sont incorrectes)
*****************************/
template <class Type>
void CMatrice<Type>::MATVerifierPortee(unsigned int uiNumLignes, unsigned int uiNumColonnes)
{
	if (uiMATNbLignes < uiNumLignes || uiMATNbColonnes < uiNumColonnes)
		throw new CException(DIMENSIONHORSPORTEE, "Erreur dans la dimension - hors port�e");
}

template <class Type>
CMatrice<Type> & CMatrice<Type>::operator+(CMatrice<Type> & MATMatrice)
{
	return 0;
}
template <class Type>
CMatrice<Type> & CMatrice<Type>::operator-(CMatrice<Type> & MATMatrice)
{
	return 0;
}

template <class Type>
CMatrice<Type> & CMatrice<Type>::operator*(Type & MATMatrice)
{
	return 0;
}

template <class Type>
CMatrice<Type> & CMatrice<Type>::operator*(CMatrice<Type> & MATMatrice)
{
	return 0;
}

template <class Type>
CMatrice<Type> & CMatrice<Type>::operator/(Type & MATMatrice)
{
	return 0;
}

template <class Type>
CMatrice<Type> & CMatrice<Type>::operator/(CMatrice<Type> & MATMatrice)
{
	return 0;
}

template <class Type>
CMatrice<Type> & CMatrice<Type>::operator=(CMatrice<Type> & MATMatrice)
{
	return 0;
}
