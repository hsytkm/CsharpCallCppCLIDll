#pragma once
#pragma unmanaged

#pragma managed
#include <iostream>
#include "Person.h"

namespace CppCliDll {
	public ref class CppCliClass
	{
	private:
		Person^ person;

	public:
		CppCliClass() {
			this->person = gcnew Person("Ken", 20);

			std::cout << "CppCliClass: Call Constractor" << std::endl;

			Person obj("Ryu", 21);
			if (obj.GetType() == Person::typeid)
				System::Console::WriteLine("PersonClass");
		}

		// デストラクタ(マネージド/アンマネージド両方とも解放)
		~CppCliClass()
		{
			std::cout << "CppCliClass: Call Destractor" << std::endl;
			// (ここでマネージドリソースを解放)

			this->!CppCliClass();
		}

		// ファイナライザ(アンマネージドリソースのみ解放)
		!CppCliClass()
		{
			std::cout << "CppCliClass: Call Finalizer" << std::endl;

			// (ここでアンマネージドリソースを解放)
		}

		// テスト関数
		int Multi(int x, int y){
			return x * y;
		}

		// 文字列(参照型の組み込みクラス)を受け取って返す
		System::String^ CppCliClass::ToUpper(System::String^ lower) {
			return lower->ToUpper();
		}

		// 自作クラス操作
		property System::String^ PersonName{ System::String^ get() { return person->Name; } }
		property int PersonAge { int get() { return person->Age; } }
		property Person^ PersonClass { Person^ get() { return person; } }

	};
}
