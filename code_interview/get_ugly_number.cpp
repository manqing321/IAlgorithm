int GetUglyNumber(int index) {
	if (index <= 0) {
		return 0;
	}
	int* numbers = new int[index];
	numbers[0] = 1;
	int nextIndex = 1;
	int* p2 = numbers;
	int* p3 = numbers;
	int* p5 = numbers;

	while (nextIndex < index) {
		int min = Min(*p2 * 2, *p3 * 3, *p5 * 5);
		numbers[nextIndex] = min;
		while (*p2 * 2 <= numbers[nextIndex]) {
			p2++;
		}
		while (*p3 * 3 <= numbers[nextIndex]) {
			p3++;
		}
		while (*p5 * 5 <= numbers[nextIndex]) {
			p5++;
		}
		nextIndex += 1;
	}
	int ugly = numbers[index - 1];
	delete[]numbers;
	return ugly;
}
int Min(int num1, int num2, int num3) {
	return std::min(std::min(num1, num2), num3);
}

int main() {
	assert(GetUglyNumber(-1), 0);
	assert(GetUglyNumber(0), 0);
	assert(GetUglyNumber(1), 1);
	assert(GetUglyNumber(9), 10);
}