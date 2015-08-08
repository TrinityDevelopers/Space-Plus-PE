#pragma once

namespace RakNet 
{
	class RakNetGUID
	{
	public:
		RakNetGUID();
		void FromString(const char*);
		void ToString(char*);
		void ToString();
	};
}