
#include "pch.h"
#include <iostream>

using namespace std;


int str_str_V2(const char *text, const char *pattern)
{
	const char * text_b = text;
	const char * pattern_b = pattern;

	if (*pattern_b == '\0') return 0;
	while(*text_b)
	{
		bool next = true;
		int i = 0;
		while (*pattern_b)
		{
			if (*text_b == '\0') return -1;
			if (*pattern_b !=*text_b) break;
			
			pattern_b++;
			++i;
			++text_b;
			next = false;
		}

		if (*pattern_b == '\0')
		{
			int num = pattern_b - pattern;
			return text_b - text - num;
		}
		if (next == true)
		{
			++text_b;
		}
		
		if (*text_b == '\0') return -1;
		pattern_b = pattern;
	}
	 return -1;
}

int str_str(const char *text, const char *pattern)
{
	const char * pos = 0;
	const char * text_b = text;
	const char * pattern_b = pattern;
	bool find = false;
	bool go_next = true;
	if (*pattern_b == '\0') return 0;
	while(*text_b)
	{
		while (*pattern_b)
		{
			if (*text_b == *pattern_b)
			{
				if (find == false)
				{
					find = true;
					pos = text_b;
					go_next = false;
				}
				
				pattern_b++;
				text_b++;

			}
			else
			{
				pattern_b = pattern;
				find = false;
				break;
			}
		}
		if (find == true)
		return pos - text;
		if (go_next == true)
		{
			text_b++;
			go_next = true;
		}
	}
	 return -1;
}

int main()
{
	struct test {
		int ret_value;
		const char *text;
		const char *pattern;
	};
	test tests[] = {
			{0, "", ""}, //0
			{0, "a", ""}, //1
			{0, "a", "a"}, //2
			{-1, "a", "b"}, //3
			{0, "aa", ""}, //4
			{0, "aa", "a"}, //5
			{0, "ab", "a"}, //6
			{1, "ba", "a"}, //7
			{-1, "bb", "a"}, //8
			{0, "aaa", ""}, //9
			{0, "aaa", "a"}, //10
			{1, "abc", "b"}, //11
			{2, "abc", "c"}, //12
			{-1, "abc", "d"}, //13
			{-1, "a", "aa"}, //14
			{-1, "a", "ba"}, //15
			{-1, "a", "ab"}, //16
			{-1, "a", "bb"}, //17
			{-1, "a", "aaa"}, //18
			{-1, "aa", "aaa"}, //19
			{0, "aaa", "aaa"}, //20
			{0, "aaab", "aaa"}, //21
			{1, "baaa", "aaa"}, //22
			{1, "baaaa", "aaa"}, //23
			{1, "baaab", "aaa"}, //24
			{-1, "abd", "abc"}, //25
			{2, "ababc", "abc"}, //26
			{3, "abdabc", "abc"}, //27
			{-1, "", "a"}, //28
			{2, "asasaf", "asaf"}, //29
			{2, "ababac", "abac"} //30
	};
	for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
		int ret = str_str(tests[i].text, tests[i].pattern);
		(tests[i].ret_value == ret) ? cout << "OK" : cout << "Failed";
		cout << " : " << i << " (" << tests[i].ret_value << " : " << ret << ")" << endl;
	}
	return 0;
}
