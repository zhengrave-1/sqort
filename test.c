#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"

int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
void test1()//������������
{
	int arr[] = { 5,4,6,7,2,3,8,1,9,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}


int cmp_float(const void* e1, const void* e2)
{
	if (*(float*)e1 == *(float*)e2)
		return 0;
	else if (*(float*)e1 > *(float*)e2)
		return 1;
	else
		return -1;

	//return (int)(*(float*)e1 - *(float*)e2);//��׼ȷ����ֵ��0.9֮�ڵ������޷�׼ȷ����
}
void test2()//��������������
{
	float f[] = { 3.0,6.0,4.0,1.0,5.0,2.0,3.9,3.7,3.73,3.358};
	int sz = sizeof(f) / sizeof(f[0]);
	qsort(f, sz, sizeof(f[0]), cmp_float);//qsort�⺯�����ڱȽ����ݣ���Ҫ�Ƚϵ�����������ͬʱ����ֵΪ0��ǰ�ߴ��ں���ʱ����ֵ>0�����ߴ���ǰ��ʱ����ֵ<0
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%f ", f[i]);
	}
}


struct Stu
{
	char name[15];
	int age;
};
int cmp_struct_bu_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
void test3()//�ṹ���е�������������
{
	struct Stu s[] = { {"zhangsan",25},{"lisi",15},{"wangwu",30},{"sunliu",27} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_struct_bu_age);

}


int cmp_struct_bu_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
void test4()//�ṹ���е��ַ�����������
{
	struct Stu s[] = { {"zhangsan",25},{"lisi",15},{"wangwu",30},{"sunliu",27} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_struct_bu_name);
}