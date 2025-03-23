#pragma once

#include <iterator>
#include <cstddef>

using namespace std;

namespace H {
	template <typename T>
	class LinkedList {
	public:
		struct Node;

		struct Node {
		public:
			Node(T t = nullptr, Node* next = nullptr, Node* prev = nullptr) : t(t), next(next), prev(prev) {}

			void linkNext(Node* n) {
				next = n;
				n->prev = this;
			}

			void linkPrev(Node* n) {
				prev = n;
				n->next = this;
			}

			void unlink() {
				if (next) {
					next->prev = prev;
				}

				if (prev) {
					prev->next = next;
				}
			}

			Node* next;
			Node* prev;
			T t;
		};

		struct Iterator {
		public:
			using iterator_category = bidirectional_iterator_tag;
			using difference_type = ptrdiff_t;

			Node* node;

			Iterator(Node* node) : node(node) {}

			T& operator*() const {
				return node->t;
			}

			T* operator->() {
				return &(node->t);
			}

			Iterator& operator++() {
				node = node->next;
				return *this;
			}

			Iterator operator++(int) {
				Iterator temp = *this;
				node = node->next;
				return temp;
			}

			Iterator& operator--() {
				node = node->prev;
				return *this;
			}

			Iterator operator--(int) {
				Iterator temp = *this;
				node = node->prev;
				return temp;
			}

			bool operator==(const Iterator& it) const {
				return node == it.node;
			}

			bool operator!=(const Iterator& it) const {
				return node != it.node;
			}
		};

		Iterator begin() {
			return Iterator(first);
		}

		Iterator end() {
			return Iterator(nullptr);
		}

		void addFirst(T t) {
			if (first) {
				first->linkPrev(new Node(t));
				first = first->prev;
			} else {
				first = last = new Node(t);
			}
		}

		void addAllFirst(T t[], int num) {
			for (int i = num - 1; i >= 0; --i) {
				addFirst(t[i]);
			}
		}

		void addLast(T t) {
			if (last) {
				last->linkNext(new Node(t));
				last = last->next;
			} else {
				first = last = new Node(t);
			}
		}

		void addAllLast(T t[], int num) {
			for (int i = 0; i < num; ++i) {
				addLast(t[i]);
			}
		}

		/*
		void removeIf(function<bool(T)> func) {
			for (Node* node = first; node != nullptr; node = node->next) {
				if (func(node->t)) {
					node->unlink();
				}
			}
		}
		*/

		Node* getNode(int index) {
			for (Node* node = first; node != nullptr; node = node->next, --index) {
				if (index == 0) {
					return node;
				}
			}

			return nullptr;
		}

		bool remove(int index) {
			Node* n = getNode(index);

			if (n) {
				n->unlink();
			}

			return n;
		}

		Node* first;
		Node* last;
	};
}