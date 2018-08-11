#include <string>
#include "plib.h"

namespace plib {

	long long hash(std::string &val) {
		long long hash = 7;

		for (int i = 0; i < val.length(); i++) {
		    hash = hash*31 + val[i];
		}

		return hash;
	}

	long long hash(int val) {
	 	return val;
	}

	 long long hash(long long val) {
	 	return val;
	}

	long long hash(double val) {
		std::string s = std::to_string(val);
		return hash(s);
	}
}