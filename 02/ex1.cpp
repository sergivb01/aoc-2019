#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

vector<int> read_data(ifstream& file_data){
    vector<int> v;
    int val;
    file_data >> val;
    v.push_back(val);
    char separator;
    while(file_data >> separator >> val && separator == ','){
        v.push_back(val);
    }
    v[1] = 12;
    v[2] = 2;
    return v;
}

void print_vector(const vector<int>& v){
    for(size_t i = 0; i < v.size(); i++){
        cout << v[i];
        if(i != v.size() - 1) cout << ", ";
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    ifstream in_stream(argv[1]);
    if (!in_stream.is_open()) {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }
    
    vector<int> v = read_data(in_stream);
    for(size_t idx = 0; v[idx] != 99; idx += 4){
        switch(v[idx]){
            case 1:
                v[v[idx+3]] = v[v[idx+1]] + v[v[idx+2]];
                break;
            case 2:
                v[v[idx+3]] = v[v[idx+1]] * v[v[idx+2]];
                break;
        }
    }
    cout << v[0] << endl;

    return 0;
}