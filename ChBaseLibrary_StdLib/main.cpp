/*
* ChLibrary���ɂ���namespace "ChStd" �̎g�p���@��������܂��B
* ChStd�͂܂Ƃ߂�܂ōs���Ȃ��֐��Q���܂Ƃ߂��N���X�ɂȂ�܂��B
* ChLibrary���g�p����ꍇ��ChCppLibrary�t�H���_����ChCppLibrary�t�H���_�̒����ɂ���w�b�_�[�t�@�C����include���܂��B
* ChLibrary��lib�t�@�C����ChCppLibrary�t�H���_����ChCppLibrary�t�H���_���ɂ���StaticLibrary�t�H���_�̒����ɂ���܂��B
* ChStd�͑���BaseLibrary�Ƃ͈Ⴂ�l�X�ȏ�ʂŗ��p�ł���@�\�������Ă��܂��B
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

int main()
{

	//
	


	return 0;
}