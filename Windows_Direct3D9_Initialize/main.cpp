#include<Windows.h>

//���s���C�u�����ł̓v���W�F�N�g�̐ݒ肩�當���Z�b�g���u�}���` �o�C�g�����Z�b�g���g�p����v�ɕύX����B

//ChCppLibrary�̃C���N���[�h//

//ChCppLibrary�̊�{���C�u�����̃C���N���[�h//
#include<ChBaseLibrary.h>

//ChCppLibrary��Windows���C�u�������C���N���[�h//
#include<ChWindowsLibrary.h>

//ChCppLibrary��Direct3D9���C�u�������C���N���[�h//
#include<ChDirect3D9Library.h>

//ChCppLibrary��lib�t�@�C���������N//

#if _DEBUG

//MDd��Microsoft���p�ӂ���CRT�̎��//

//ChBaseLibrary�̐ÓI���C�u����//
#pragma comment(lib,"ChCpp_MDd.lib")

//ChWindowsLibrary�̐ÓI���C�u����//
#pragma comment(lib,"ChWin_MDd.lib")

//ChDirect3D9Library�̐ÓI���C�u����//
#pragma comment(lib,"ChD3D9_MDd.lib")


#else

//MD��Microsoft���p�ӂ���CRT�̎��//

//ChBaseLibrary�̐ÓI���C�u����//
#pragma comment(lib,"ChCpp_MD.lib")

//ChWindowsLibrary�̐ÓI���C�u����//
#pragma comment(lib,"ChWin_MD.lib")

//ChDirect3D9Library�̐ÓI���C�u����//
#pragma comment(lib,"ChD3D9_MD.lib")

#endif

int WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nShowCmd
)
{

	{

		//�E�B���h�̃T�C�Y//
		ChVec2 windSize = ChVec2(1280, 720);

		//�A�v���P�[�V�����̃^�C�g��//
		const char* appTitle = "CreateWind";

		//�A�v���P�[�V�����ŗ��p����E�B���h�E�N���X�̖��O�ł��B
		const char* className = "testClass";

		//SystemManager�ŊǗ��ł���悤��SystemManager��Init�𗘗p����ChSystem::Windows���C���X�^���X��������//
		auto wind = ChSystem::SysManager().Init<ChSystem::Windows>();

		//�E�B���h�E������������//
		wind->Init(appTitle, className, windSize.x, windSize.y, hInstance, nShowCmd);

		//D3D9������������//
		ChD3D9::D3D9API().Init(wind->GethWnd(), false, windSize.x, windSize.y);

		//FPS�l(1�b�Ԃ̃t���[����)��ݒ肷��//
		ChSystem::SysManager().SetFPS(60);

	}

	//�V�X�e���̍X�V�m�F���s��(�E�B���h�E���폜���ꂽ�肵���ꍇ��false��Ԃ�)//
	while (ChSystem::SysManager().IsUpdate())
	{
		//FPS�̃e�X�g���s��(���ݎ������m�F���A1�b�Ԃ̊����𒴂��Ă����ꍇ��true,��������Ȃ��ꍇ��false)//
		if (!ChSystem::SysManager().FPSProcess())continue;

		//SystemManager��IsPushKey�𗘗p����Ɠ���̓��͂��m�F����B(�����WindowsAPI�𗘗p���Ă��邽�߁AWindowsAPI��VK_�𗘗p���Ă���)//
		if (ChSystem::SysManager().IsPushKey(VK_ESCAPE))break;

		ChD3D9::D3D9API().DrawStart();


		ChD3D9::D3D9API().DrawEnd();


	}

	return 0;
}