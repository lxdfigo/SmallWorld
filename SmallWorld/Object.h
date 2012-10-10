#pragma once

namespace swd{
	class Object
	{
	public:
		Object(void);
		~Object(void);
	private:
		double mass;
		double speed;
		double rubforce;
		int id;
	};

}