#include "../GEO/main.hpp"
#include <vector>

namespace game
{
	class ComplexLine;
	
	class ComplexLine
	{
		protected:
			std::vector<geo::Line> _lines = std::vector<geo::Line>();
			bool _direction = 1; // right
		public:
			enum Dir
			{
				Left, Right
			};
			ComplexLine();
			ComplexLine(const ComplexLine& c);
			~ComplexLine();
			const geo::Line& operator[](size_t index) const;
			void Add(const geo::Line& l);
			void CleanUp();
			bool Direction() const;
			void Remove(const geo::Line& l);
			void Set(const geo::Line& l, size_t index);
			void SetDirection(bool val);
			void Smooth(double intensity);
			double Length() const;
			size_t Count() const;
	};
}