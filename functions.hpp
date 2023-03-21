#include <iostream>
#ifndef _functions_
#define _functions_

namespace numpp
{
	float exp(float ,int=14, bool=false);
	long factorial(int);
	float power(float,int);
	long ncr(int ,int );
	long npr(int ,int );
	float sin(float,int=10,bool=false);
	
	long factorial(int x)
	{
		try
		{
			if(x<0)
				throw x;
			if(x==1 || x==0)
				return 1;
			long ans = 1;
			while(x>1)
			{
				ans *= x;
				x--;
			}
			return ans;	
		}
		catch(int x)
		{
			std::cerr<<"[ERROR]:Input less than 0"<<std::endl;
			return -1;
		}
		catch(...)
		{
			std::cerr<<"[ERROR]:Uknown error occured."<<std::endl;
			return -1;
		}
	}
	
	float power(float x,int e)
	{
		if(e<0)
		{
			e = -e;
			x = 1/x;
		}
		if(e==0)
			return 1;
		double pow = 1;
		for(int i=0;i<e;i++)
		{
			pow *= x;
		}
		return pow;
	}
	
	float exp(float x,int precision, bool override)
	{
		if(!override)
		{
			if(precision<5)
			{
				std::cout<<"[WARNING]:Very low precision, defaulting to 5. override = true to override"<<std::endl;
				precision = 5;
			}

		}
		else
		{
			std::cout<<"[WARNING]:Override detected, low precision can lead to undefined behaviour."<<std::endl;
		}
		float ans = 1;
		for(int i=1;i<precision;i++)
		{
			ans += (power(x,i))/float(factorial(i));
		}
		return ans;
	}
	
	long ncr(int n,int r)
	{
		return factorial(n)/(factorial(r)*factorial(n-r));
	}
	
	long npr(int n,int r)
	{
		return factorial(n)/factorial(n-r);
	}
	
	float sin(float x,int precision,bool override)
	{
		if(!override)
		{
			if(precision<5)
			{
				std::cout<<"[WARNING]:Very low precision, defaulting to 5. override = true to override"<<std::endl;
				precision = 5;
			}

		}
		else
		{
			std::cout<<"[WARNING]:Override detected, low precision can lead to undefined behaviour."<<std::endl;
		}
		float ans =0;
		int count = 0;
		for(int i=1;i<precision;i=i+2)
		{
			if(count%2==0)
				ans+= power(x,i)/float(factorial(i));
			else
				ans+= -power(x,i)/float(factorial(i));
			count++;
		}
		return ans;
	}

}
#endif
