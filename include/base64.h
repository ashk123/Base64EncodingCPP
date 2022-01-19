#include <iostream>
#include <stdio.h>
#include <string>
#include <bitset>
#include <vector>
#include <map>

using namespace std;

class Base64
{
	private :
		vector<char> vector_convert(string text, auto chars)
		{
			for (int t = 0; t < text.length(); t++)
			{
				chars.push_back(text[t]);
			}	
			return chars;
		}
		string convert_binary(vector<char> chars)
		{
			string text_org;
			for (int s = 0; s < chars.size(); s++)
			{
				int as = int(chars[s]);
				bitset<8> temp(as);
				text_org += temp.to_string();
			}
			return text_org;
		}
		string add(string res_add)
		{
			while (true)
			{
				if (res_add.length() % 4 == 0)
				{
					break;
				}
				else
				{
					res_add += "=";
				}
			}
			return res_add;
		}
		vector<string> split_binary(string text)
		{
			while (true)
			{
				if (text.length() % 6 == 0)
				{
					break;
				}
				else
				{
					text += "0";
				}
			}
			int num = 5;
			string chars;
			vector<string> new_vec;
			for (int s = 0; s < text.length(); s++)
			{
				if (s == num)
				{
					chars += text[s];
					new_vec.push_back(chars);
					chars = "";
					num += 6;
				}
				else
				{
					chars += text[s];
				}
			}
			return new_vec;
		}
		vector<int> base_cnv(vector<string> binarys)
		{
			vector<int> res;
			for (int t = 0; t < binarys.size(); t++)
			{
				int result = convert_base(binarys[t]);
				res.push_back(result);
			}
			return res;
		}
		int convert_base(string binary) 
		{
			int number = stoi(binary);
		    int bace = 1, last = 0,sum = 0;
		    while (number){
		        last = number%10;
		        number = number/10;
		        last *= bace;
		        sum += last;
		        bace = bace*2;
		    }
		    return sum;
		}
		string base64_encode_convert(vector<int> numbers)
		{
			// create map for tables base64
			map<int, string> tables;
			tables.insert(pair<int, string>(0, "A"));
			tables.insert(pair<int, string>(1, "B"));
			tables.insert(pair<int, string>(2, "C"));
			tables.insert(pair<int, string>(3, "D"));
			tables.insert(pair<int, string>(4, "E"));
			tables.insert(pair<int, string>(5, "F"));
			tables.insert(pair<int, string>(6, "G"));
			tables.insert(pair<int, string>(7, "H"));
			tables.insert(pair<int, string>(8, "I"));
			tables.insert(pair<int, string>(9, "J"));
			tables.insert(pair<int, string>(10, "K"));
			tables.insert(pair<int, string>(11, "L"));
			tables.insert(pair<int, string>(12, "M"));
			tables.insert(pair<int, string>(13, "N"));
			tables.insert(pair<int, string>(14, "O"));
			tables.insert(pair<int, string>(15, "P"));
			tables.insert(pair<int, string>(16, "Q"));
			tables.insert(pair<int, string>(17, "R"));
			tables.insert(pair<int, string>(18, "S"));
			tables.insert(pair<int, string>(19, "T"));
			tables.insert(pair<int, string>(20, "U"));
			tables.insert(pair<int, string>(21, "V"));
			tables.insert(pair<int, string>(22, "W"));
			tables.insert(pair<int, string>(23, "X"));
			tables.insert(pair<int, string>(24, "Y"));
			tables.insert(pair<int, string>(25, "Z"));
			tables.insert(pair<int, string>(26, "a"));
			tables.insert(pair<int, string>(27, "b"));
			tables.insert(pair<int, string>(28, "c"));
			tables.insert(pair<int, string>(29, "d"));
			tables.insert(pair<int, string>(30, "e"));
			tables.insert(pair<int, string>(31, "f"));
			tables.insert(pair<int, string>(32, "g"));
			tables.insert(pair<int, string>(33, "h"));
			tables.insert(pair<int, string>(34, "i"));
			tables.insert(pair<int, string>(35, "j"));
			tables.insert(pair<int, string>(36, "k"));
			tables.insert(pair<int, string>(37, "l"));
			tables.insert(pair<int, string>(38, "m"));
			tables.insert(pair<int, string>(39, "n"));
			tables.insert(pair<int, string>(40, "o"));
			tables.insert(pair<int, string>(41, "p"));
			tables.insert(pair<int, string>(42, "q"));
			tables.insert(pair<int, string>(43, "r"));
			tables.insert(pair<int, string>(44, "s"));
			tables.insert(pair<int, string>(45, "t"));
			tables.insert(pair<int, string>(46, "u"));
			tables.insert(pair<int, string>(47, "v"));
			tables.insert(pair<int, string>(48, "w"));
			tables.insert(pair<int, string>(49, "x"));
			tables.insert(pair<int, string>(50, "y"));
			tables.insert(pair<int, string>(51, "z"));
			tables.insert(pair<int, string>(52, "0"));
			tables.insert(pair<int, string>(53, "1"));
			tables.insert(pair<int, string>(54, "2"));
			tables.insert(pair<int, string>(55, "3"));
			tables.insert(pair<int, string>(56, "4"));
			tables.insert(pair<int, string>(57, "5"));
			tables.insert(pair<int, string>(58, "6"));
			tables.insert(pair<int, string>(59, "7"));
			tables.insert(pair<int, string>(60, "8"));
			tables.insert(pair<int, string>(61, "9"));
			tables.insert(pair<int, string>(62, "+"));
			tables.insert(pair<int, string>(63, "/"));
			string string_end;
			for (int t = 0; t < numbers.size(); t++)
			{
				string_end += tables[numbers[t]];
			}
			return string_end;
		}
	public :
		string base64_encode(string text)
		{
			vector<char> chars;
			vector<char> new_chars = vector_convert(text, chars);
			string binarys = convert_binary(new_chars);
			vector<string> new_spl = split_binary(binarys);
			vector<int> res = base_cnv(new_spl);
			string end = base64_encode_convert(res);
			string res_end = add(end);
			return res_end;
		}
		Base64(string text = "NULL")
		{
			vector<char> chars;
			vector<char> new_chars = vector_convert(text, chars);
			string binarys = convert_binary(new_chars);
			vector<string> new_spl = split_binary(binarys);
			vector<int> res = base_cnv(new_spl);
			string end = base64_encode_convert(res);
			string res_end = add(end);
			if (text != "NULL")
			{
				cout << res_end << endl;
			}
		}
};
