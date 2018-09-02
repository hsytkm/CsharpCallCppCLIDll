#pragma once

#include "../Debug/NativeCppClass.h"

namespace CppCliDll {
	public ref class NativeWrapper
	{
	private:
		NativeCppClass* nativeCppClass; // ネイティブクラスへのポインタ

	public:
		NativeWrapper();			// コンストラクタ
		NativeWrapper(int num);	// コンストラクタ
		NativeWrapper(int, int);	// コンストラクタ

		~NativeWrapper();			// デストラクタ(マネージド/アンマネージド両方とも解放)
		!NativeWrapper();			// ファイナライザ(アンマネージドリソースのみ解放)

		int GetInt();
	};
}
