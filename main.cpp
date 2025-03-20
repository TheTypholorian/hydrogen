#include "main.h"
#include "collections.h"

int main() {
	Array<int> array(5);

	array.forEach([](int item) {
		cout << item << " ";
	});

	return 0;
}
