
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//


#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct expert_window : Graph_lib::Window {
	expert_window(Point xy, int w, int h, const string& title, string playername);

	bool wait_for_button(); // simple event loop

	bool observation_period;
	vector<int> choices;
	const int rounds = 256;
	int choices_left = 256;
	int score = 0;
	int guesses = 1;
	double probM = 0.0;
	double probW = 0.0;
	double probB = 0.0;
	double timesCorrect = 0.0;
	string playername;
private:
	Out_box scoreDisp;
	Out_box computer_correct;
	Out_box choices_to_go;

	Text observation;
	Text guessing;

	Button Maroon;
	Button White;
	Button Black;

	bool button_pushed;     // implementation detail

	static void cb_maroon(Address, Address);
	static void cb_white(Address, Address);
	static void cb_black(Address, Address);

	void maroon();
	void white();
	void black();
};

//------------------------------------------------------------------------------


