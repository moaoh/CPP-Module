#include "iter.hpp"

int		main(void) {

	int	intArr[5] = {1, 2, 3, 4, 5};
	float	floatArr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	const char	*charArr[5] = {"a", "b", "c", "d", "e"};

	iter(intArr, sizeof(intArr) / sizeof(*intArr), print);
	iter(intArr, sizeof(intArr) / sizeof(*intArr), print<int>);
	iter<int>(intArr, sizeof(intArr) / sizeof(*intArr), print);
	iter<int>(intArr, sizeof(intArr) / sizeof(*intArr), print<int>);

// another type =====
	iter(floatArr, sizeof(floatArr) / sizeof(*floatArr), print);
	iter(charArr, sizeof(charArr) / sizeof(*charArr), print);
	return (0);
}
