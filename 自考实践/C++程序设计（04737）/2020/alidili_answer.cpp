#include <iostream>
using namespace std;

class MOVE
{
private:
    float array[20];
    int n;

public:
    MOVE(float b[], int m);
    void average();
    void print();
};

MOVE::MOVE(float b[], int m) {
	if (m > 20) {
		cout << "请输入长度在20以内的数组" << endl;
        m = 20;
    }
    // 拷贝传入的数组到array
    memcpy(array, b, m * sizeof(float));
	n = m;
}

void MOVE::average() {
    float sum = 0;
    // 计算平均值
    for (int i = 0; i < n;i++) {
        sum += array[i];
    }
    float average = sum / n;

    // 定义一个新数组，存放平均值判断后的数组值
    float *sortArray = new float[n];
    int index = 0;
    int endIndex = n - 1;
    for (int i = 0; i < n; i++) {
        // 小于平均值的放在数组左边
		if (array[i] < average) {
            sortArray[index] = array[i];
            index++;
        }
        // 大于等于平均值的放在数组右边
		else {
            sortArray[endIndex] = array[i];
            endIndex--;
        }
    }
    // 新数组拷贝到array中
    memcpy(array, sortArray, n * sizeof(float));
	cout << "average = " << average << endl;
}

void MOVE::print() {
    // 打印新数组的值
    cout << "array = ";
    for (int i = 0; i < n; i++) {
		cout << array[i];
		if (i != n - 1) {
			cout << ", ";
        }
    }
}

int main()
{
	float testArray[] = { 1.3f,6.2f,3,9.1f,4.8f,7.4f,5.6f,9.2f,2.3f };
	MOVE m(testArray, sizeof(testArray) / sizeof(testArray[0]));
    m.average();
    m.print();
}