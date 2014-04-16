#include "KH.h"

int main(int argc, char* argv[])
{
	cout << "KH 1.5 mself extractor" << endl << endl;

	if(argv[1] != 0)
	{
		KH mself;
		mself.ExtractMSelf(argv[1]);
	}
	else
		cout << "No file was dragged." << endl;

	return 0;
}