#include "hydrogen.hpp"
#include <functional>
#include <string>
#include <iostream>

using namespace std;

namespace H {
	template <typename T>
	class Iterator {
	public:
		virtual ~Iterator() = default;

		virtual Iterator<T>& operator++() = 0;

		virtual T& operator*() const = 0;

		virtual bool operator==(const Iterator<T>&) const = 0;

		virtual bool operator!=(const Iterator<T>&) const = 0;
	};

	template <typename T, typename It>
	class Collection {
	public:
		virtual huint getSize() const = 0;

		virtual hbool isEmpty() const {
			return !getSize();
		}

		virtual void add(T t) = 0;

		//virtual void addAll(Collection<T> t) = 0;

		virtual void remove(T t) = 0;

		//virtual void removeAll(Collection<T> t) = 0;

		virtual It begin() const = 0;

		virtual It end() const = 0;
	};
}