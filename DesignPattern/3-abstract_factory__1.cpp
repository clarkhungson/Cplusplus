#include <stdio.h>
#include <iostream>
using namespace std;

#define LINUX

class Widget
{
public:
	virtual void draw() = 0;
};

class LinuxButton : public Widget
{
public:
	void draw()
	{
		cout << "LinuxButton\n";
	}
};

class LinuxMenu : public Widget
{
public:
	void draw()
	{
		cout << "LinuxMenu\n";
	}
};

class WindowsButton : public Widget
{
public:
	void draw()
	{
		cout << "WindowsButton";
	}
};

class WindowsMenu : public Widget
{
public:
	void draw()
	{
		cout << "WindowsMenu";
	}
};

class Client 
{
public:
	void draw()
	{
#ifdef LINUX
		Widget *w = new LinuxButton;
#else 
		Widget *w = new WindowsButton;
#endif
		w -> draw();
		display_window_one();
		display_window_two();
	}

	void display_window_one()
	{
#ifdef LINUX
	Widget *w[] = {
		new LinuxButton, 
		new LinuxMenu
	};
#else 
	Widget *w[] = {
		new WindowsButton,
		new WindowsMenu
	};
#endif
	w[0] -> draw();
	w[1] -> draw();
	}

	void display_window_two()
	{
#ifdef LINUX
		Widget *w[] = {
			new LinuxMenu,
			new LinuxButton
		};
#else 
		Widget *w[] = {
			new WindowsMenu,
			new WindowsButton
	};
#endif
	w[0] -> draw();
	w[1] -> draw();

	}
};

int main()
{
	Client *c = new Client();
	c -> draw();
}