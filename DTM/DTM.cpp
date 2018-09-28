#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

constexpr int H = -1; // Stop computing
constexpr int L = -1; // Move to Left
constexpr int N =  0; // Don't move
constexpr int R = +1; // Move to right

int main() {
	// General configurations
	int  print_every = 1; // step
	bool print_tape = true;
	bool print_to_screen = true;
	bool print_states_as_characters = true; // this turns numbers into ASCII characters when printing the states, use it if you are going to specify the states as characters and not numbers
	
	// Specify the set of rules
	// A rule consist of { scanned symbol, current_state, write symbol, next state, move head to }
	// You can use single characters as states, for example 'A', or numbers, as you preffer.
	vector<vector<int>> rules = {
		{0, 'A', 1, 'B', R},			 // If you feel curious, 'A' is transformed to (int)65, the ASCII value for the 'A' character
		{1, 'A', 1, 'B', L},
		{0, 'B', 1, 'A', L},
		{1, 'B', 0, 'C', L},
		{0, 'C', 1,  H , R},
		{1, 'C', 1, 'D', L},
		{0, 'D', 1, 'D', R},
		{1, 'D', 0, 'A', R},
	}; // Busy beaver of 4 states

	// Specify the initial state, the initial position on the tape, and the tape with its initial values
	int         initial_state = 'A';
	int         initial_position = 0;
	vector<int> initial_tape = { 0 }; // minimum tape length is one cell
	
	// more cells will be added automatically with '0' when needed, this is done this way for memory reasons
	// you'll have 250'000'000 cells per every 1GB or RAM your computer have availabe


	// Everything is set! Now compile the code and run your deterministic turing machine!






















	// Load the set of rules in a fast accessible way
	map<vector<int>, vector<int>> machine_directives;
	for (vector<int>  rule : rules) {
		vector<int> key = { rule[0], rule[1] };
		vector<int> val = { rule[2], rule[3], rule[4] };

		if (machine_directives.count(key) > 0) cout << " - There's a duplicate rule\n";
		else machine_directives.emplace(key, val);
	}

	// Create the initial tape and assign the its values
	list<int> cells;
	for (int const& val : initial_tape) cells.push_back(val);

	// Instantiate the state
	int current_state = initial_state;

	// Instantiate a pointer to the current cell
	list<int>::iterator current_cell_it = cells.begin();
	while (initial_position--) ++current_cell_it;

	// Compute
	for (unsigned long long int step = 0;;++step) {
		vector<int> key = { *current_cell_it, current_state };
		vector<int> val = machine_directives[key];

		if ((current_state == H) || (print_to_screen && (step % print_every == 0))) {
			if (current_state == H) cout << "step:\t" << step << "\tcs: " << "Halt";
			else {
				if (print_states_as_characters) cout << "step:\t" << step << "\tcs: " << char(current_state);
				else cout << "step:\t" << step << "\tcs: " << current_state;
			}

			if (print_tape) {
				cout << "\t{";
				for (list<int>::iterator it = cells.begin(); it != cells.end(); ++it) {
					if (it == current_cell_it) cout << "|" << *it << "|";
					else cout << " " << *it << " ";
				}
				cout << "}";
			}
			cout << endl;
		}

		if (current_state == H) break;

		*current_cell_it = val[0];
		current_state    = val[1];

		if (val[2] == L) {
			if (current_cell_it == cells.begin()) cells.push_front(0);
			--current_cell_it;
		}
		if (val[2] == R) {
			list<int>::iterator last = cells.end(); --last;

			if (current_cell_it == last) cells.push_back(0); 
			++current_cell_it;
		}
	}

	system("Pause");
}