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

		// �f�X�g���N�^(�}�l�[�W�h/�A���}�l�[�W�h�����Ƃ����)
		~CppCliClass()
		{
			std::cout << "CppCliClass: Call Destractor" << std::endl;
			// (�����Ń}�l�[�W�h���\�[�X�����)

			this->!CppCliClass();
		}

		// �t�@�C�i���C�U(�A���}�l�[�W�h���\�[�X�̂݉��)
		!CppCliClass()
		{
			std::cout << "CppCliClass: Call Finalizer" << std::endl;

			// (�����ŃA���}�l�[�W�h���\�[�X�����)
		}

		// �e�X�g�֐�
		int Multi(int x, int y){
			return x * y;
		}

		// ������(�Q�ƌ^�̑g�ݍ��݃N���X)���󂯎���ĕԂ�
		System::String^ CppCliClass::ToUpper(System::String^ lower) {
			return lower->ToUpper();
		}

		// ����N���X����
		property System::String^ PersonName{ System::String^ get() { return person->Name; } }
		property int PersonAge { int get() { return person->Age; } }
		property Person^ PersonClass { Person^ get() { return person; } }

	};
}
