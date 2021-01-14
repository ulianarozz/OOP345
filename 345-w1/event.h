#ifndef EVENT_H
#define EVENT_H
extern unsigned int g_sysClock;

namespace sdds
{


	class Event
	{
		char* description; //description of the event
		unsigned int secMidnight; //seconds after midnight


	public:
		Event(); //constructor
		Event(const Event& src);
		~Event();
		void display();
		void setDescription(const char* src);
		Event& operator=(const Event& src);

	};

}
#endif