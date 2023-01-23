#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <bitset>
using namespace std;

/*
Made By Ethan Molsberry 1/21/2023
*/
void characters(string binary) {
	string library = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	string binaryLib[65];
	for (int i = 0; i < 65; i++) {
		binaryLib[i] = bitset<6>(i).to_string();
	}

	for (int i = 0; i < 64; i++) {
		if (binary == binaryLib[i]) {
			cout << library[i];
		}
		else if (binary.compare("111111") ==0) {
			cout << " ";
		}
		else if (binary.compare("111110") == 0) {
			cout << ".";
		}
	}


}



int main() {
	ifstream infile;
	infile.open("PictureBinary.txt");

	if (infile.fail()) {
		cout << "The File Could Not Be Found." << endl;
	}

	else {
		int byte = 0;
		int location = 0;
		int size = 0;

		string c;
		stringstream buffer;
		buffer << infile.rdbuf();
		c = buffer.str();

		cout << "Please insert how hops between bytes: " << endl;
		cin >> byte;

		cout << "Please insert starting location: " << endl;
		cin >> location;

		cout << "Please insert size of characters: " << endl;
		cin >> size;
		
		cout << "Max chars: " << c.size() << endl;
		if (c.size() < byte*size+location) {
			cout << "Surpasses characters! exting program:" << endl;
		}
		else {
			//fix this later
			string binary;
			string binaryTemp = "";
			location /= 10;
			location *= 16;
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < 6; j++) {
					binaryTemp = bitset<6>(c.at(location)).to_string();
					binary += binaryTemp[binaryTemp.size() - 1];

					location += byte;
				}
				characters(binary);
				binary = "";
			}
			cout << endl;

			cout << binary << endl;
			cout << binaryTemp << endl;
			cout << c.at(4) << endl;

			for (int i = 0; i < c.size(); i++) {
				cout << c[i];
			}
			cout << endl;
		}
	}

	infile.close();
	infile.clear();


	return 0;
}
