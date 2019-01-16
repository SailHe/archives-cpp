template<typename Iterator, typename T>
T max(Iterator left, Iterator right, T MIN_INIT_VALUE) {
	T maxValue = MIN_INIT_VALUE;
	while (left < right) {
		maxValue = maxValue > *left ? maxValue : *left;
		++left;
	}
	return maxValue;
}


template<typename T>
T max(T *arr, int size, T MIN_INIT_VALUE) {
	T maxValue = MIN_INIT_VALUE;
	for (int i = 0; i < size; ++i) {
		maxValue = maxValue > arr[i] ? maxValue : arr[i];
	}
	return maxValue;
}

int mainForMax() {
	int arr[] = { 3, 4, 0, 9, 8 };
	float arrF[] = { 3.0f, 4.8f, 0.8f, 9.7f, 9.6f };

	// -2147483648 -> usigned long
	int maxValue1 = max(arr, arr + 5, -2147483647 - 1);
	float maxValueF1 = max(arrF, arrF + 5, -2147483648.0f);

	int maxValue2 = max(arr, 5, -2147483647);
	float maxValueF2 = max(arrF, 5, -2147483648.0f);
	return 0;
}
