#ifndef C_MATRICE_H
#define C_MATRICE_H

#include <iostream>

template <class Type> class CMatrice
{
	// Attributs
private:
	Type ** ppqMATMatrice;
	unsigned int uiMATNbLignes;
	unsigned int uiMATNbColonnes;

public:
	// Constructeurs et destructeur
	explicit CMatrice();
	~CMatrice();
	explicit CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes);
	CMatrice(CMatrice & MATMatrice);

	// Accesseurs
	inline void MATEcrireNbLignes(unsigned int uiNbLignes);
	inline unsigned int MATLireNbLignes();
	inline void MATEcrireNbColonnes(unsigned int uiNbColonnes);
	inline unsigned int MATLireNbColonnes();

	// Calculs math�matiques
	CMatrice<Type> MATCalculerTransposee();
	CMatrice<Type> MATPPuissanceMatrice(unsigned int uiNombre);

	// G�rer les �l�ments de la matrice
	void MATModifierElement(unsigned int uiNumLigne, unsigned int uiNumColonne, Type tElement);
	Type MATLireElement(unsigned int uiNumLigne, unsigned int uiNumColonne);
	void MATInit();
	void MATAfficherMatrice();
	
	void MATAjouterColonnesFin(unsigned int uiNbColonnes);
	void MATAjouterLignesFin(unsigned int uiNbLignes);
	void MATSupprimerColonneFin(unsigned int uiNbColonnes);
	void MATSupprimerLigneFin(unsigned int uiNbLignes);
	void MATAjouterColonnePrecis(unsigned int uiNumColonne);
	void MATAjouterLignePrecis(unsigned int uiNumLigne);
	void MATSupprimerColonnePrecis(unsigned int uiNumColonne);
	void MATSupprimerLignePrecis(unsigned int uiNumLigne);

	void MATVerifierPortee(unsigned int uiNumLigne, unsigned int uiNumColonne);
	void MATVerifierDimension(unsigned int uiNbLignes, unsigned int uiNbColonnes);

	// Surchages
	CMatrice<Type> operator+(CMatrice<Type> & MATMatrice);
	CMatrice<Type> operator-(CMatrice<Type> & MATMatrice);
	CMatrice<Type> operator*(Type & qMATparam);
	CMatrice<Type> operator*(CMatrice<Type> & MATMatrice);
	CMatrice<Type> operator/(Type & qMATparam);
	CMatrice<Type> & operator=(CMatrice<Type> & MATMatrice);
	bool operator!=(CMatrice<Type> & MATMatrice);
};

template<class Type>
CMatrice<Type> operator*(Type qMATparam, CMatrice<Type> & MATMatrice);

#include "CMatrice.cpp"

#endif
