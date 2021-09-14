/*
* ChLibrary���ɂ���namespace "ChStd" �̎g�p���@��������܂��B
* ChStd�͂܂Ƃ߂�܂ōs���Ȃ��֐��Q���܂Ƃ߂��N���X�ɂȂ�܂��B
* ChLibrary���g�p����ꍇ��ChCppLibrary�t�H���_����ChCppLibrary�t�H���_�̒����ɂ���w�b�_�[�t�@�C����include���܂��B
* ChLibrary��lib�t�@�C����ChCppLibrary�t�H���_����ChCppLibrary�t�H���_���ɂ���StaticLibrary�t�H���_�̒����ɂ���܂��B
* ChStd�͑���BaseLibrary�Ƃ͈Ⴂ�l�X�ȏ�ʂŗ��p�ł���@�\�������Ă��܂��B
* �����ł͎�Ɏg����ChStd�̋@�\��������܂��B
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

enum class UCTest :unsigned char
{
	A = 1,B,C
};

enum class ULTest : unsigned long
{
	A = 1,B,C
};


int main()
{

	/*
	* ��EnumCast�̎g�p���@
	* EnumCast��
	* Enum�̊��^(enum class UCTest�̏ꍇ��unsigned char,enum class ULTest�̏ꍇ��unsigned long)��
	* �����I�ɃL���X�g���Ă����@�\���֐��ɂ܂Ƃ߂����̂ł��B
	*/

	auto ucTest = ChStd::EnumCast(UCTest::A);

	auto ulTest = ChStd::EnumCast(ULTest::A);


	/*
	* MCopy,MZero�̎g�p���@
	* MCopy��MZero�͊ȒP�Ɍ�����memcpy,Windows.h�ɂ���ZeroMemory�ł��B
	* �������p�ӂ���Ɏ��������R�͈ȑO�Ɍ�������gcc�̑g�ݍ��݊֐��ɂ���ăo�O���N���Ă������Ƃ������ł����B
	* ���̂���ChCppLibrary�����ł͊�{�I�ɂ������MZero��MCopy�𗘗p���Ă��܂��B
	*/

	{
		ChStd::MZero(&ucTest);

		unsigned long tmp = 0;

		ChStd::MCopy(&tmp, &ulTest);
	}

	/*
	* Bool�̎g�p���@
	* ChCppLibrary�ŗ��p�����Bool�͎�ɂ����炪���p����܂��B
	* C++��bool�̗e�ʂ�1byte����Ȃ��ƕ����Ă���쐬��������΃I�[�p�[�c�̈�ł��B
	* �������A1byte = 8bit = 8flg���s�����߂Ƀr�b�g���Z�q�𗘗p�ł��邱�Ƃ���܂��`���c���Ă����Ԃł��B
	* ChCppLibrary�̓����ł͊�{�I�ɂ������ChStd::Bool���g���܂��B
	*/
	{

		ChStd::Bool flg = true;
		flg = false;
		flg = 1;
		flg <<= 2;
	}

	return 0;
}