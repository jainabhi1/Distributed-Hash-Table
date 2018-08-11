#include <vector>
#include <mutex>
#include <stddef.h>
#include "DublyLinkList.h"
#include "plib.h"
#include "hash.h"

using namespace std;
namespace plib {

	template <class T, class U>
	class HMap {
		private:
			struct HNode {
				timed_mutex mtx;
				DublyLinkList<T,U> dll;
			};

			int size;
			int no_of_keys;
			vector<HNode> v;

			int hashCode(T key) {
				return hash(key) % (size - 1);
			}

			void insertKeyValue(T key, U value) {
				int index = hashCode(key);
				unique_lock<timed_mutex> lock(v[index].mtx, std::defer_lock);

				while (!lock.try_lock_for(std::chrono::milliseconds(200))) ;

				v[index].dll.insert(key, value);
				lock.unlock();
			}

			T getValue(T key) {
				int index = hashCode(key);
				unique_lock<timed_mutex> lock(v[index].mtx, std::defer_lock);
				U value;

				while (!lock.try_lock_for(std::chrono::milliseconds(200))) ;

				value = v[index].dll.getValue(key);
				lock.unlock();
				return value;

			}
		public:
			HMap(): size(64), no_of_keys(0), v(size) {
				cout << "Map is intialized with " << v.size() << " size" << endl;
			}
			void insert(T key, U value) {
				insertKeyValue(key, value);
			}

			T get(T key) {
				return getValue(key);
			}

	};
}