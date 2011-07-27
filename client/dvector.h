#ifndef DVECTOR_H
#define DVECTOR_H

class dVector
{
	public:
		int x, y;
		dVector () { };
		dVector (int a, int b )
		{
			x = a;
			y = b;
		}
		void operator () ( int a, int b)
		{
			x = a;
			y = b;
			return;
		}
};


#endif