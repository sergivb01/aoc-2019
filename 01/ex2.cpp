#include <iostream>
#include <fstream>

using namespace std;

int required_fuel(int mass, int start_fuel){
	int fuel = mass / 3 - 2;
	if(fuel < 0){
		return start_fuel;
	}
	return required_fuel(fuel, fuel + start_fuel);
}

int main(int argc, char const *argv[]){
	ifstream in_stream(argv[1]);
	if(!in_stream.is_open()){
		printf("Could not open file %s\n", argv[1]);
		return 1;
	}
	
	int sum = 0;
	while(!in_stream.eof()){
		int module_mass;
		in_stream >> module_mass;
		sum += required_fuel(module_mass, 0);
	}
	cout << sum << endl;

	return 0;
}