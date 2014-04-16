#include "KH.h"

KH::KH()
{

}

int KH::ExtractMSelf(char *filename)
{
	header mheader;

	FILE *f = fopen(filename, "rb");

	if(f != NULL)
	{
		//Read header.
		fread(&mheader, 0x40, 1, f);

		cout << hex  << mheader.filenum << endl;
		cout << hex << _byteswap_ulong(mheader.filenum) << endl;

		lba *mlba = new lba[_byteswap_ulong(mheader.filenum)];

		//Reading LBA.
		for(int i=0; i<_byteswap_ulong(mheader.filenum); i++)
			fread(&mlba[i], 0x40, 1, f);

		system("mkdir @FILES");

		//reading files and writing them
		for(int b=0; b<_byteswap_ulong(mheader.filenum); b++)
		{
			filebuffer = new unsigned char[_byteswap_uint64(mlba[b].size)];
			fseek(f, _byteswap_uint64(mlba[b].offset), SEEK_SET);
			fread(filebuffer, _byteswap_uint64(mlba[b].size), 1, f);
	
			sprintf(finalname, "@FILES%s", mlba[b].name);
			FILE *o = fopen(finalname, "wb");

			cout << "Extracting: " << finalname << endl;
			cout << "Offset: " << hex << _byteswap_uint64(mlba[b].offset) << endl
				<< "Size: " << hex << _byteswap_uint64(mlba[b].size) << endl << endl;

			fwrite(filebuffer, _byteswap_uint64(mlba[b].size), 1, o);
			fclose(o);
		}

		fclose(f);
	}
	else
	{
		cout << "Invalid file handle" << endl;
		return 1;
	}

	return 0;
}