// NativeCppClass.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"
#include <iostream>
#include "NativeCppClass.h"

using namespace std;

NativeCppClass::NativeCppClass(int x) : param(x) {}


string NativeCppClass::GetString() const
{
	string str = "文字見えてますか？";
	return str;
}