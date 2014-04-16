#define _CRT_SECURE_NO_WARNINGS
#define uint64 unsigned __int64
#define uint unsigned int
#include <stdio.h>
#include <iostream>
using namespace std;

class KH
{
private:
	struct header
	{
		uint magic;
		uint unknown;
		long long unknown2;
		uint filenum;
		uint lbapos;
		long long unknown3;

		long long unknown4;
		long long unknown5;

		long long unknown6;
		long long unknown7;
	};

	struct lba
	{
		char name[0x20];
		long long offset;
		long long size;
		long long padding;
		long long padding2;
	};

	unsigned char *filebuffer;
	char finalname[128];

public:
	KH();
	int ExtractMSelf(char *filename);
};