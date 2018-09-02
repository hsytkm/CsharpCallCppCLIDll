#include "stdafx.h"
#include <iostream>

#include "NativeWrapper.h"

#include <msclr/marshal_cppstd.h>
using namespace msclr::interop;

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

System::String^ NativeWrapper::GetStringWrap(System::String^ inputOrig)
{
	std::string inStr = marshal_as<std::string>(inputOrig);
	System::String^ outStr = marshal_as<System::String^>(nativeCppClass->GetString(inStr));
	return outStr;
}
