#ifndef DVECTOR_H
#define DVECTOR_H

class dVector
{
	public:
		int x, y;
		float calcLength();
		dVector () { };
		dVector (int a, int b )
		{
			x = a;
			y = b;
		}
		void operator () ( int, int );
		dVector operator + (dVector);
		dVector operator - (dVector);
};


#endif