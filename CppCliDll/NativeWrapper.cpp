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
	pet = new Pet(Pet::Dog, "Pochi", 12);
}

NativeWrapper::NativeWrapper(int x1, int x2)
{
	std::cout << "NativeWrapper: Call Constractor(int,int)" << std::endl;
	nativeCppClass = new NativeCppClass(x1 * x2);
	pet = new Pet(Pet::Cat, "Tama", 3);
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

void NativeWrapper::SetInt(int x)
{
	nativeCppClass->SetParam(x);
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

// Pet----------------------------------------
NativeWrapper::PetTypeWrap CppCliDll::NativeWrapper::GetPetType()
{
	Pet::Type pt = pet->GetType();
	PetTypeWrap ptw;

	switch (pt)
	{
	case Pet::Dog:
		ptw = PetTypeWrap::WDog;
		break;
	case Pet::Cat:
		ptw = PetTypeWrap::WCat;
		break;
	default:
		ptw = PetTypeWrap::WUnknown;
		break;
	}
	return ptw;
}

System::String ^ CppCliDll::NativeWrapper::GetPetName()
{
	return marshal_as<System::String^>(pet->GetName());
}
