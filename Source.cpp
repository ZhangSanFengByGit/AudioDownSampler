

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


int main() {


	FILE *sourceFile;
	FILE *targetFile;
	string file_path;
	int size = 0;
	int flag = 0;
	short sourceRead = 0;
	short tempRead = 0;
	
	cout << "Enter the path of the source PCM file: " << endl;
	cin >> file_path;

	sourceFile = fopen((file_path).c_str(), "rb+");
	targetFile = fopen("Downsampled.pcm", "wb+");

	while (!feof(sourceFile)) {
		size = fread(&sourceRead, 2, 1, sourceFile);
		if (size > 0) {
			tempRead = tempRead + sourceRead;
			flag++;
			if (flag == 3) {
				flag = 0;
				tempRead = tempRead / 3;
				fwrite(&tempRead, 2, 1, targetFile);
				tempRead = 0;
			}
		}
	}

	fclose(sourceFile);
	fclose(targetFile);

}
