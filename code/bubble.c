#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int k[], int n)
{
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (k[i] > k[j])
			{
				temp = k[j];
				k[j] = k[i];
				k[i] = temp;
			}
		}
	}
}

int main(void)
{
	int i, a[10] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};

	BubbleSort(a, 10);

	printf("排序后的结果是：");
	for (i = 0; i < 10; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n\n");
	system("pause");
	return 0;
}