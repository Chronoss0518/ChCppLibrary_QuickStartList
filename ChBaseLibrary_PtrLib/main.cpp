/*
* ChLibrary���ɂ���namespace "ChPtr" �̎g�p���@��������܂��B
* ChPtr��ChCppLibrary���ŗ��p����|�C���^�[�Ɋւ���@�\�Q�ɂȂ�܂��B
* ChCppLibrary���g�p����ꍇ��ChCppLibrary�t�H���_����ChCppLibrary�t�H���_�̒����ɂ���w�b�_�[�t�@�C����include���܂��B
* ChCppLibrary��lib�t�@�C����ChCppLibrary�t�H���_����ChCppLibrary�t�H���_���ɂ���StaticLibrary�t�H���_�̒����ɂ���܂��B
*/

#include<ChBaseLibrary.h>

#ifdef _DEBUG

//StaticLibrary/ChCpp_MDd.lib//
//MDd��Microsoft��CRT�̈�ł��B//

#pragma comment(lib,"ChCpp_MDd.lib")

#else

//StaticLibrary/ChCpp_MD.lib//
//MD��Microsoft��CRT�̈�ł��B//

#pragma comment(lib,"ChCpp_MD.lib")

#endif

class Test
{
public:

	Test() { num = 0; }

	Test(unsigned long _num) { num = _num; }

	unsigned long Get() { return num; }

private:

	unsigned long num = 0;
};


int main()
{
	{

		/*
		* Shared<>:
		* �X�}�[�g�|�C���^��std::shared_ptr<>�̑���Ƃ��Ďg�p���Ă���N���X�ł��B
		* �g�p���@��std�̂��̂ƕς��܂���B
		*/

		ChPtr::Shared<Test> test1 = nullptr, test2 = nullptr;

		/*
		* Make_S<>:
		* �X�}�[�g�|�C���^��std::make_shared<>�̑���Ƃ��Ďg�p���Ă���֐��ł��B
		* �g�p���@��std�̂��̂ƕς��܂���B
		*/
		test1 = ChPtr::Make_S<Test>();

		test2 = ChPtr::Make_S<Test>(5);


		//���ʂ̏o��//
		std::cout << (test1->Get()) << std::endl;
		std::cout << (test2->Get()) << std::endl;

	}

	/*
	* NullCheck,NotNullCheck:
	* nullptr�܂���NULL�ł��邱�Ƃ��m�F����֐��ł��B
	* �����ő���ꂽ�I�u�W�F�N�g��nullptr�܂���NULL�̏ꍇ�ANullCheck��true��NotNullCheck��false��Ԃ��܂��B
	*/

	int* ptest = nullptr;
	int ptest2 = 0;

	ChPtr::NullCheck(ptest);
	ChPtr::NotNullCheck(&ptest2);


	return 0;
}