#include "stdafx.h"
#include <iostream>

#include "NativeWrapper.h"
using namespace CppCliDll;

NativeWrapper::NativeWrapper()
{
	std::cout << "Call Constractor" << std::endl;
	nativeCppClass = new NativeCppClass();
}

NativeWrapper::NativeWrapper(int num)
{
	std::cout << "NativeWrapper: Call Constractor(int)" << std::endl;
	nativeCppClass = new NativeCppClass(num);
}

NativeWrapper::NativeWrapper(int x1, int x2)
{
	std::cout << "NativeWrapper: Call Constractor(int,int)" << std::endl;
	nativeCppClass = new NativeCppClass(x1 * x2);
}

// デストラクタ(マネージド/アンマネージド両方とも解放)
NativeWrapper::~NativeWrapper()
{
	std::cout << "NativeWrapper: Call Destractor" << std::endl;
	// (ここでマネージドリソースを解放)

	this->!NativeWrapper();
}

// ファイナライザ(アンマネージドリソースのみ解放)
NativeWrapper::!NativeWrapper()
{
	std::cout << "NativeWrapper: Call Finalizer" << std::endl;

	// (ここでアンマネージドリソースを解放)
	delete nativeCppClass;
}

int NativeWrapper::GetInt()
{
	return nativeCppClass->GetParam();
}
