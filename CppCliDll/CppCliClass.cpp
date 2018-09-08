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

// デストラクタ(マネージド/アンマネージド両方とも解放)
CppCliClass::~CppCliClass()
{
	std::cout << "CppCliClass: Call Destractor" << std::endl;
	// (ここでマネージドリソースを解放)

	this->!CppCliClass();
}

// ファイナライザ(アンマネージドリソースのみ解放)
CppCliClass::!CppCliClass()
{
	std::cout << "CppCliClass: Call Finalizer" << std::endl;

	// (ここでアンマネージドリソースを解放)
}

// 文字列(参照型の組み込みクラス)を受け取って返す
System::String^ CppCliClass::ToUpper(System::String^ lower) {
	return lower->ToUpper();
}

