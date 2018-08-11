#include <iostream>
#include "HMap.h"

using namespace std;
using namespace plib;

int main() {
	HMap<string, string> m;
	m.insert("abhishek", "jain"  );
	m.insert("yash"    , "tiwari");
	m.insert("sujnesh" , "mishra");


	// cout << m.get("priyanshu") << endl;

	vector<int> v(64);

	for(int i=0;i<128;i++) {
		v.push_back(i);
	}

	vector<int> v1(128);
	v = v1;
	cout << v.size();
}