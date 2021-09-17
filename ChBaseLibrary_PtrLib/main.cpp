/*
* ChLibrary内にあるnamespace "ChPtr" の使用方法を説明します。
* ChPtrはChCppLibrary内で利用するポインターに関する機能群になります。
* ChCppLibraryを使用する場合はChCppLibraryフォルダ内のChCppLibraryフォルダの直下にあるヘッダーファイルをincludeします。
* ChCppLibraryのlibファイルはChCppLibraryフォルダ内のChCppLibraryフォルダ内にあるStaticLibraryフォルダの直下にあります。
*/

#include<ChBaseLibrary.h>

#ifdef _DEBUG

//StaticLibrary/ChCpp_MDd.lib//
//MDdはMicrosoftのCRTの一つです。//

#pragma comment(lib,"ChCpp_MDd.lib")

#else

//StaticLibrary/ChCpp_MD.lib//
//MDはMicrosoftのCRTの一つです。//

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
		* スマートポインタのstd::shared_ptr<>の代わりとして使用しているクラスです。
		* 使用方法はstdのものと変わりません。
		*/

		ChPtr::Shared<Test> test1 = nullptr, test2 = nullptr;

		/*
		* Make_S<>:
		* スマートポインタのstd::make_shared<>の代わりとして使用している関数です。
		* 使用方法はstdのものと変わりません。
		*/
		test1 = ChPtr::Make_S<Test>();

		test2 = ChPtr::Make_S<Test>(5);


		//結果の出力//
		std::cout << (test1->Get()) << std::endl;
		std::cout << (test2->Get()) << std::endl;

	}

	/*
	* NullCheck,NotNullCheck:
	* nullptrまたはNULLであることを確認する関数です。
	* 引数で送られたオブジェクトがnullptrまたはNULLの場合、NullCheckはtrueをNotNullCheckはfalseを返します。
	*/

	int* ptest = nullptr;
	int ptest2 = 0;

	ChPtr::NullCheck(ptest);
	ChPtr::NotNullCheck(&ptest2);


	return 0;
}