#ifndef __EX6_H__
#define __EX6_H__
namespace ex6
{
	struct Activity
	{
		int num,start,end,mark;
	};
	bool comp(Activity a,Activity b);
	void Select(Activity act[],int n);
	void fex6(int length);
}
#endif
