#include "main.hpp"
#include "collections.hpp"
#include "bitMath.hpp"

int main() {
	Array<int> array(5);

	for (int i = 0; i < array.size; i++) {
		array.data[i] = i;
	}

	array.forEach([](int item) {
		cout << item << " ";
	});

	return 0;
}
