#pragma once

namespace CppCliDll {
	public ref class CppCliClass
	{
	private:


	public:
		CppCliClass();			// �R���X�g���N�^
		~CppCliClass();			// �f�X�g���N�^(�}�l�[�W�h/�A���}�l�[�W�h�����Ƃ����)
		!CppCliClass();			// �t�@�C�i���C�U(�A���}�l�[�W�h���\�[�X�̂݉��)

		// �e�X�g�֐�
		int Multi(int x, int y);
		System::String^ ToUpper(System::String^ lower);


	};
}
