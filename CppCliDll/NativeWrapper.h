#pragma once

#include "../Debug/NativeCppClass.h"
#include "../Debug/Pet.h"

namespace CppCliDll {
	public ref class NativeWrapper
	{
	public:
		// C++/CLIの列挙体定義 https://msdn.microsoft.com/ja-jp/library/tzz3794d.aspx?f=255&MSPPError=-2147217396
		enum class PetTypeWrap { WDog, WCat, WUnknown };

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
