#include <iostream>
#include <string>
#include "../include/base64.h"

using namespace std;

/*
This is sample of Base64 Library
*/

void Sample_1()
{
	Base64 res_e;
	string res = res_e.base64_encode("Hello, World !");
	cout << res << endl;
}

void Sample_2()
{
	Base64 res_e("Hello, World !");
}

int main()
{
	Sample_1();
	// Sample_2();
	return 0;
}
