#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include <iostream>
#include <string>
#include <math.h>
#include <vector>

//题目描述：
//你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的
//假设你有n个版本[1,2...n],你想找出导致之后所有版本出错的第一个错误的版本。
//你可以通过调用 bool isVersinbad(version) 接口来判断版本号version是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用API的次数。




//自己写一个判断版本正确与否的函数
bool isVersionbad(int n)		
{
	if (n >= 8)			//注：>=后面的数字可以自己修改来验证
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
		while (floor < ceil)		//注意这里是<，而不是<=，因为若是=，会无限循环，但是只要在=之前，一定会判断出floor=ceil=第一个出错的版本，当然了，最后一个正确的版本就是floor-1,
									//或者是ceil-1;
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
		return ceil;	//return floor也是可以的！  而且，若是要返回最后一个正确版本的编号，可以直接改成return ceil-1;
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
	cout << "下一行结果应该为8888" << endl;			//注：应该为后面的数字就是上面>=后面的数字
	cout << ret1 << ret2 << ret3 << ret4 << endl;

}





int main() {

	test01();






	system("pause");
	return 0;
}