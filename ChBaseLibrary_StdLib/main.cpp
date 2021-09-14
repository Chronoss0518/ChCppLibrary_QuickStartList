/*
* ChLibrary内にあるnamespace "ChStd" の使用方法を説明します。
* ChStdはまとめるまで行かない関数群をまとめたクラスになります。
* ChLibraryを使用する場合はChCppLibraryフォルダ内のChCppLibraryフォルダの直下にあるヘッダーファイルをincludeします。
* ChLibraryのlibファイルはChCppLibraryフォルダ内のChCppLibraryフォルダ内にあるStaticLibraryフォルダの直下にあります。
* ChStdは他のBaseLibraryとは違い様々な場面で利用できる機能が入っています。
* ここでは主に使われるChStdの機能を説明します。
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
	* ※EnumCastの使用方法
	* EnumCastは
	* Enumの基底型(enum class UCTestの場合はunsigned char,enum class ULTestの場合はunsigned long)に
	* 自動的にキャストしてくれる機能を関数にまとめたものです。
	*/

	auto ucTest = ChStd::EnumCast(UCTest::A);

	auto ulTest = ChStd::EnumCast(ULTest::A);


	/*
	* MCopy,MZeroの使用方法
	* MCopyとMZeroは簡単に言えばmemcpy,Windows.hにあるZeroMemoryです。
	* こちらを用意するに至った理由は以前に見かけたgccの組み込み関数によってバグが起きていたことが原因でした。
	* そのためChCppLibrary内部では基本的にこちらのMZeroかMCopyを利用しています。
	*/

	{
		ChStd::MZero(&ucTest);

		unsigned long tmp = 0;

		ChStd::MCopy(&tmp, &ulTest);
	}

	/*
	* Boolの使用方法
	* ChCppLibraryで利用されるBoolは主にこちらが利用されます。
	* C++のboolの容量が1byteじゃないと聞いてから作成したいわばオーパーツの一つです。
	* しかし、1byte = 8bit = 8flgを行うためにビット演算子を利用できることからまだ形が残っている状態です。
	* ChCppLibraryの内部では基本的にこちらのChStd::Boolが使われます。
	*/
	{

		ChStd::Bool flg = true;
		flg = false;
		flg = 1;
		flg <<= 2;
	}

	return 0;
}