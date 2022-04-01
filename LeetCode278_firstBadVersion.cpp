#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include <iostream>
#include <string>
#include <math.h>
#include <vector>

//��Ŀ������
//���ǲ�Ʒ����Ŀǰ���ڴ���һ���Ŷӿ����µĲ�Ʒ�����ҵ��ǣ���Ĳ�Ʒ�����°汾û��ͨ��������⡣����ÿ���汾���ǻ���֮ǰ�İ汾�����ģ����Դ���İ汾֮������а汾���Ǵ��
//��������n���汾[1,2...n],�����ҳ�����֮�����а汾����ĵ�һ������İ汾��
//�����ͨ������ bool isVersinbad(version) �ӿ����жϰ汾��version�Ƿ��ڵ�Ԫ�����г���ʵ��һ�����������ҵ�һ������İ汾����Ӧ�þ������ٶԵ���API�Ĵ�����




//�Լ�дһ���жϰ汾��ȷ���ĺ���
bool isVersionbad(int n)		
{
	if (n >= 8)			//ע��>=��������ֿ����Լ��޸�����֤
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



class Solution
{
public:
	int firstBadVersion(int n)
	{
		int ceil = n;
		int floor = 1;
		int mid;
		while (floor < ceil)		//ע��������<��������<=����Ϊ����=��������ѭ��������ֻҪ��=֮ǰ��һ�����жϳ�floor=ceil=��һ������İ汾����Ȼ�ˣ����һ����ȷ�İ汾����floor-1,
									//������ceil-1;
		{
			mid = (ceil - floor) / 2 + floor;
			if (isVersionbad(mid) == 1)
			{
				ceil = mid;
			}
			else
			{
				floor = mid + 1;
			}
		}
		return ceil;	//return floorҲ�ǿ��Եģ�  ���ң�����Ҫ�������һ����ȷ�汾�ı�ţ�����ֱ�Ӹĳ�return ceil-1;
	}
};

//
void test01()
{
	int n1 = 16, n2 = 9, n3 = 8, n4 = 17;
	Solution solution;
	int ret1 = solution.firstBadVersion(n1);
	int ret2 = solution.firstBadVersion(n2);
	int ret3 = solution.firstBadVersion(n3);
	int ret4 = solution.firstBadVersion(n4);
	cout << "��һ�н��Ӧ��Ϊ8888" << endl;			//ע��Ӧ��Ϊ��������־�������>=���������
	cout << ret1 << ret2 << ret3 << ret4 << endl;

}





int main() {

	test01();






	system("pause");
	return 0;
}