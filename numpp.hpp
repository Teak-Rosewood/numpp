#include <vector>

namespace numpp
{
	template <typename T> class Array{
		
		std::vector<T> value;
		
		Array(T input[])
		{
			for(auto i:input)
			{
				value.push_back(i);
			}
		}
		
		Array(T input)
		{
			value.push_back(input);
		}
	};
}
