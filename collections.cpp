#include "main.hpp"
#include "collections.hpp"

#ifndef IteratorDefaults
#define IteratorDefaults

template <typename T>
bool Iterator<T>::hasNext() {
	return getIndex() < getSize();
}

template <typename T>
bool Iterator<T>::hasPrevious() {
	return getIndex() > 0;
}

#endif // IteratorDefaults

#ifndef IterableDefaults
#define IterableDefaults

template <typename T>
void Iterable<T>::forEach(function<void(T)> out) {
	Iterator<T>* it = iterator();

	for (; it->hasNext(); ++(*it)) {
		out(**it);
	}

	delete it;
}

#endif // IterableDefaults

#ifndef ArrayIteratorImpl
#define ArrayIteratorImpl

template <typename T>
ArrayIterator<T>::ArrayIterator(T* data, int size, int index) : data(data), totalSize(size), index(index) {}

template <typename T>
int ArrayIterator<T>::getIndex() {
	return index;
}

template <typename T>
int ArrayIterator<T>::getSize() {
	return totalSize;
}

template <typename T>
T ArrayIterator<T>::operator++() {
	return data[index++];
}

template <typename T>
T ArrayIterator<T>::operator--() {
	return data[index--];
}

template <typename T>
bool ArrayIterator<T>::operator!=(const Iterator<T>& other) const {
	return index != static_cast<const ArrayIterator<T>&>(other).index;
}

template <typename T>
T ArrayIterator<T>::operator*() {
	return data[index];
}

#endif // ArrayIteratorImpl

#ifndef ArrayImpl
#define ArrayImpl

template <typename T>
Array<T>::Array(hushort size) : size(size), data(new T[size]()) {
}

template <typename T>
Array<T>::Array(T* data, hushort size) : data(data), size(size) {
}

template <typename T>
Array<T>::Array(hushort size, hbool free) : size(size), data(new T[size]()), free(free) {
}

template <typename T>
Array<T>::Array(T* data, hushort size, hbool free) : data(data), size(size), free(free) {
}

template <typename T>
Array<T>::~Array() {
	if (free) {
		delete[] data;
	}
}

template <typename T>
Iterator<T>* Array<T>::iterator() {
	return new ArrayIterator<T>(data, size);
}

#endif // ArrayImpl
