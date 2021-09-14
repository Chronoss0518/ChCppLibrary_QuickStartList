/*
* ChLibrary内にあるnamespace "ChStd" の使用方法を説明します。
* ChStdはまとめるまで行かない関数群をまとめたクラスになります。
* ChLibraryを使用する場合はChCppLibraryフォルダ内のChCppLibraryフォルダの直下にあるヘッダーファイルをincludeします。
* ChLibraryのlibファイルはChCppLibraryフォルダ内のChCppLibraryフォルダ内にあるStaticLibraryフォルダの直下にあります。
* ChStdは他のBaseLibraryとは違い様々な場面で利用できる機能が入っています。
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

int main()
{

	//
	


	return 0;
}