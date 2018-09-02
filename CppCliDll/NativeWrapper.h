#pragma once

#include "../Debug/NativeCppClass.h"
#include "../Debug/Pet.h"

namespace CppCliDll {
	// この定義名を C# から見れない
	public enum PetTypeWrap { WDog, WCat, WUnknown };

	public ref class NativeWrapper
	{
	private:
		NativeCppClass* nativeCppClass; // ネイティブクラスへのポインタ
		Pet* pet;

	public:
		NativeWrapper();			// コンストラクタ
		NativeWrapper(int, int);	// コンストラクタ

		~NativeWrapper();			// デストラクタ(マネージド/アンマネージド両方とも解放)
		!NativeWrapper();			// ファイナライザ(アンマネージドリソースのみ解放)

		void SetInt(int);
		int GetInt();
		System::String^ GetStringWrap(System::String^);

		// Pet
		Pet* GetPetClass() { return pet; }
		PetTypeWrap GetPetType();
		System::String^ GetPetName();
		int GetPetAge() { return pet->GetAge(); }
	};
}
