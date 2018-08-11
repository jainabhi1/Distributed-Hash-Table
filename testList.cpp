#include <iostream>
#include "HMap.h"

using namespace std;
using namespace plib;

int main() {
	DublyLinkList<string, string> dll;
	dll.insert("abhishek", "jain"  );
	dll.insert("yash"    , "tiwari");
	dll.insert("sujnesh" , "mishra");

	auto it = dll.begin();

	while (dll.hasNext(it)) {
		cout << dll.getKeyValue(it).first << " " << dll.getKeyValue(it).second << endl;
		it = dll.next(it);
	}

}
