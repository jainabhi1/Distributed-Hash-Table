#include "plib.h"


namespace plib {

	template <class T, class U>
	class DublyLinkList {
		private:
			struct Node {
				T key;
				U value;
				Node *next;
				Node *prev;

				Node(T key, U value) {
					this->key   = key;
					this->value = value;
					next = prev = NULL;
				}
			};

			Node *head,*end;

			Node* getNode(T key) {
				Node *temp = head;
				Node *ans  = NULL;

				while (temp) {
					if (temp->key == key) {
						ans  = temp;
						temp = NULL;
					} else {
						temp = temp->next;
					}
				}

				if (!ans) {
					throw "No such element present";
				}

				return ans;
			}

			void removeNode(Node *Node) {
				
				if (Node == head) {
					head = head->next;
					if (head) {
						head->prev = NULL;
					}
				} else {
					end       = end->prev;
					end->next = NULL;
				}

				delete (Node);
			}

		public:
			DublyLinkList() {
				head = end = NULL;
			}

			void insert(T key, U value) {
				Node *temp = new Node(key, value);

				if (!head) {
					head = end = temp;
				} else {
					end->next  = temp;
					temp->prev = end;
					end        = end->next;
				}
			}

			U getValue(T key) {
				Node *ans = getNode(key);
				return ans->value;
			}

			void remove(T key) {
				Node *ans = getNode(key);
				removeNode(ans);
			}

			Node *begin() {
				return head;
			}

			Node *next(Node *temp) {
				return temp->next;
			}

			std::pair<T,U> getKeyValue(Node *temp) {
				return {temp->key, temp->value};
			}

			bool hasNext(Node *temp) {
				return (temp != NULL);
			}
	}; 

}
