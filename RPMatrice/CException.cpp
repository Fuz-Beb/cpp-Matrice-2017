#include "CException.h"


CException::CException()
{
	uiEXCCode = 0;
	psEXCMessage = nullptr;
}


CException::CException(unsigned int uiCodeErreur, char * psMessageErreur)
{
	uiEXCCode = uiCodeErreur;
	psEXCMessage = (char*) malloc(sizeof(char) * strlen(psMessageErreur) + 1);
	strcpy_s(psEXCMessage, strlen(psMessageErreur) + 1, psMessageErreur);
}


CException::~CException()
{
	if (psEXCMessage != nullptr)
		delete psEXCMessage;
}


unsigned int CException::EXCLectureCode()
{
	return uiEXCCode;
}


void CException::EXCEcritureCode(unsigned int uiCodeErreur)
{
	uiEXCCode = uiCodeErreur;
}


char * CException::EXCLectureMessage()
{
	return psEXCMessage;
}


void CException::EXCEcritureMessage(char * psMessage)
{
	if (psEXCMessage == nullptr)
		delete psEXCMessage;

	psEXCMessage = new char[strlen(psMessage) + 1];
	strcpy_s(psEXCMessage, strlen(psMessage) + 1, psMessage);
}