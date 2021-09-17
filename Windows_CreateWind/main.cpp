#include<Windows.h>

//現行ライブラリではプロジェクトの設定から文字セットを「マルチ バイト文字セットを使用する」に変更する。

//ChCppLibraryのインクルード//

//ChCppLibraryの基本ライブラリのインクルード//
#include<ChBaseLibrary.h>

//ChCppLibraryのWindowsライブラリをインクルード//
#include<ChWindowsLibrary.h>

//ChCppLibraryのlibファイルをリンク//

#if _DEBUG

//MDdはMicrosoftが用意したCRTの種類//

//ChBaseLibraryの静的ライブラリ//
#pragma comment(lib,"ChCpp_MDd.lib")

//ChWindowsLibraryの静的ライブラリ//
#pragma comment(lib,"ChWin_MDd.lib")


#else

//MDはMicrosoftが用意したCRTの種類//

//ChBaseLibraryの静的ライブラリ//
#pragma comment(lib,"ChCpp_MD.lib")

//ChWindowsLibraryの静的ライブラリ//
#pragma comment(lib,"ChWin_MD.lib")

#endif

//新しいWindProcedureを作成する//
ChStd::Bool WinProc(HWND _hWind,unsigned int _msg,WPARAM _wParam,LPARAM _lParam)
{

	switch (_msg)
	{
	case WM_QUIT:

		PostQuitMessage(0);
		break;
	default:
		DefWindowProc(_hWind, _msg, _wParam, _lParam);
		break;
	}

	return 0;

}

int WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nShowCmd
)
{

	{

		//ウィンドのサイズ//
		ChVec2 windSize = ChVec2(1280, 720);

		//アプリケーションのタイトル//
		const char* appTitle = "CreateWind";

		//アプリケーションで利用するウィンドウクラスの名前です。
		const char* className = "testClass";

		//SystemManagerで管理できるようにSystemManagerのInitを利用してChSystem::Windowsをインスタンス化させる//
		auto wind = ChSystem::SysManager().Init<ChSystem::Windows>();

		//ウィンドウを初期化する//
		wind->Init(appTitle, className, windSize.x, windSize.y, hInstance, nShowCmd);

		//WndProcedureを登録する//
		wind->SetWinProcedure(WinProc);

		//FPS値(1秒間のフレーム数)を設定する//
		ChSystem::SysManager().SetFPS(60);

	}

	//システムの更新確認を行う(ウィンドウが削除されたりした場合はfalseを返す)//
	while (ChSystem::SysManager().IsUpdate())
	{
		//FPSのテストを行う(現在時刻を確認し、1秒間の割合を超えていた場合にtrue,そうじゃない場合はfalse)//
		if (!ChSystem::SysManager().FPSProcess())continue;

		//SystemManagerのIsPushKeyを利用すると特定の入力を確認する。(今回はWindowsAPIを利用しているため、WindowsAPIのVK_を利用している)//
		if (ChSystem::SysManager().IsPushKey(VK_ESCAPE))break;

	}

	return 0;
}