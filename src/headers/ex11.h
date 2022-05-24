#ifndef __EX11_H__
#define __EX11_H__
// function **declarations**
namespace ex11{
    int fex11();
    template <typename T> class Bob1{
		private:
			T a;
		public:
			T changeA(T b);
	};
};
#include "../cpp/testTemplate.cpp"
#endif

