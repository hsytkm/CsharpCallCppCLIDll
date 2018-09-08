#include "stdafx.h"
#include <iostream>
#include "CppCliClass.h"

using namespace System;
using namespace CppCliDll;

CppCliClass::CppCliClass()
{
	this->person = gcnew Person("Ken", 20);

	std::cout << "CppCliClass: Call Constractor" << std::endl;
}

// �f�X�g���N�^(�}�l�[�W�h/�A���}�l�[�W�h�����Ƃ����)
CppCliClass::~CppCliClass()
{
	std::cout << "CppCliClass: Call Destractor" << std::endl;
	// (�����Ń}�l�[�W�h���\�[�X�����)

	this->!CppCliClass();
}

// �t�@�C�i���C�U(�A���}�l�[�W�h���\�[�X�̂݉��)
CppCliClass::!CppCliClass()
{
	std::cout << "CppCliClass: Call Finalizer" << std::endl;

	// (�����ŃA���}�l�[�W�h���\�[�X�����)
}

// ������(�Q�ƌ^�̑g�ݍ��݃N���X)���󂯎���ĕԂ�
System::String^ CppCliClass::ToUpper(System::String^ lower) {
	return lower->ToUpper();
}

