#pragma once

template <typename T>
class Iterator {
public:
	virtual ~Iterator() = default;

	virtual int getIndex() = 0;

	virtual int getSize() = 0;

	bool hasNext();

	bool hasPrevious();

	virtual T operator++() = 0;

	virtual T operator--() = 0;

	virtual bool operator!=(const Iterator<T>& other) const = 0;

	virtual T operator*() = 0;
};

template <typename T>
class Iterable {
public:
	virtual ~Iterable() = default;

	virtual Iterator<T>* iterator() = 0;

	void forEach(function<void(T)> out);
};

template <typename T>
class ArrayIterator : public Iterator<T> {
public:
	T* data;
	int index;
	int totalSize;

	ArrayIterator(T* data, int size, int index = 0);

	int getIndex();

	int getSize();

	T operator++();

	T operator--();

	bool operator!=(const Iterator<T>& other) const;

	T operator*();
};

template <typename T>
class Array : public Iterable<T> {
public:
	T* data;
	hushort size;
	bool free;

	Array(hushort size);

	Array(T* data, hushort size);

	Array(hushort size, hbool free);

	Array(T* data, hushort size, hbool free);

	~Array();

	Iterator<T>* iterator();
};

#include "collections.cpp"
