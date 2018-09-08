#pragma once
#include "Person.h"

namespace CppCliDll {
	public ref class CppCliClass
	{
	private:
		Person^ person;

	public:
		CppCliClass();			// �R���X�g���N�^
		~CppCliClass();			// �f�X�g���N�^(�}�l�[�W�h/�A���}�l�[�W�h�����Ƃ����)
		!CppCliClass();			// �t�@�C�i���C�U(�A���}�l�[�W�h���\�[�X�̂݉��)

		// �e�X�g�֐�
		int Multi(int x, int y){
			return x * y;
		}
		System::String^ ToUpper(System::String^ lower);

		// ����N���X����
		System::String^ GetPersonName() { return person->GetName(); }
		int GetPersonAge() { return person->GetAge(); }
		Person^ GetPersonClass() { return person; }

	};
}
