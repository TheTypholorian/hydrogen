#include "hydrogen.hpp"
#include <functional>
#include <string>
#include <iostream>
#include "collections.hpp"

using namespace std;

namespace H {
	template <typename T>
	class ArrayIterator : public Iterator<T> {
	public:
		T* ptr;

		ArrayIterator(T* ptr) : ptr(ptr) {
		}

		Iterator<T>& operator++() override {
			++ptr;
			return *this;
		}

		T& operator*() const override {
			return *ptr;
		}

		bool operator==(const Iterator<T>& o) const override {
			auto ap = dynamic_cast<const ArrayIterator<T>*>(&o);
			return ap && ptr == ap->ptr;
		}

		bool operator!=(const Iterator<T>& o) const override {
			return !(*this == o);
		}
	};

	template <typename T>
	class Array : public Collection<T, ArrayIterator<T>> {
	public:
		T* data;
		huint size : sizeof(huint) * 8 - 1;
		hbool free : 1;

		Array(huint size = 0, T* data = nullptr, hbool free = true) : data(data == nullptr ? new T[size]() : data), size(size), free(free) {
		}

		~Array() {
			if (free) {
				delete[] data;
			}
		}

		huint getSize() const {
			return size;
		}


		void add(T t) {
			cout << "adding " << t << endl;
		}

		//void addAll(Collection<T> it) {
			//for (T t : it) {
			//	add(t);
			//}
		//}

		void remove(T t) {
			cout << "removing " << t << endl;
		}

		//void removeAll(Collection<T> it) {
			//for (T t : it) {
			//	remove(t);
			//}
		//}

		ArrayIterator<T> begin() const {
			return ArrayIterator<T>(data);
		}

		ArrayIterator<T> end() const {
			return ArrayIterator<T>(data + size);
		}
	};
}