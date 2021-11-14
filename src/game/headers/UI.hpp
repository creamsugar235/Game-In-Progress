namespace game
{
	class Entity;
	namespace ui
	{
		class Button;
		class Event;
		class Clickable;

		class Clickable : Entity
		{
			private:
				vector<void (*)()> _onClickCalls;
			public:
				virtual Clickable();
				virtual ~Clickable();
				virtual void AddOnClickFunction(void (*function));
				void OnMouseDown
		};

		class Button : Clickable
		{
		};

		class Card : Clickable
		{

		};
	}
}