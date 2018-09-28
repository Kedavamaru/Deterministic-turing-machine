# Deterministic-turing-machine

This is a c++ code for a Deterministic Turing Machine: https://en.wikipedia.org/wiki/Turing_machine

# How to program the machine

Download DTM.cpp, everything you need is inside of this file.

First, notice that this four variables:

    constexpr int H = -1; // Stop computing
    constexpr int L = -1; // Move to Left
    constexpr int N =  0; // Don't move
    constexpr int R = +1; // Move to right
    
Then add the machine rules:

    // A rule consist of { scanned symbol, current_state, write symbol, next state, move head to }
    // You can use single characters as states, for example 'A', or numbers, as you preffer.
    
    vector<vector<int>> rules = {
        {0, 'A', 1, 'B', R},            // If you feel curious, 'A' is transformed to (int)65, the ASCII value for the 'A' character
        {1, 'A', 1, 'B', L},
        {0, 'B', 1, 'A', L},
        {1, 'B', 0, 'C', L},
        {0, 'C', 1,  H , R},
        {1, 'C', 1, 'D', L},
        {0, 'D', 1, 'D', R},
        {1, 'D', 0, 'A', R},
      }; // Busy beaver of 4 states

And specify the initial values:

    // Specify the initial state, the initial position on the tape, and the tape with its initial values
    int         initial_state = 'A';
    int         initial_position = 0;
    vector<int> initial_tape = { 0 }; // minimum tape length is one cell

    // more cells will be added automatically with '0' when needed, this is done this way for memory reasons
    // you'll have 250'000'000 cells per every 1GB of RAM your computer have availabe

Then run and have fun!

# Output customization

You can modify this settings if you want, this can be handy in some cases:

	// General configurations
	int  print_every = 1; // step
	bool print_tape = true;
	bool print_to_screen = true;
	bool print_states_as_characters = true;    // this turns numbers into ASCII characters when printing the states, use it if you are going to specify the states as characters and not numbers

# Output

    step:   0       cs: A   {|0|}
    step:   1       cs: B   { 1 |0|}
    step:   2       cs: A   {|1| 1 }
    step:   3       cs: B   {|0| 1  1 }
    step:   4       cs: A   {|0| 1  1  1 }
    step:   5       cs: B   { 1 |1| 1  1 }
    step:   6       cs: C   {|1| 0  1  1 }
    step:   7       cs: D   {|0| 1  0  1  1 }
    step:   8       cs: D   { 1 |1| 0  1  1 }
    step:   9       cs: A   { 1  0 |0| 1  1 }
    step:   10      cs: B   { 1  0  1 |1| 1 }
    step:   11      cs: C   { 1  0 |1| 0  1 }
    step:   12      cs: D   { 1 |0| 1  0  1 }
    step:   13      cs: D   { 1  1 |1| 0  1 }
    step:   14      cs: A   { 1  1  0 |0| 1 }
    step:   15      cs: B   { 1  1  0  1 |1|}
    step:   16      cs: C   { 1  1  0 |1| 0 }
    step:   17      cs: D   { 1  1 |0| 1  0 }
    step:   18      cs: D   { 1  1  1 |1| 0 }
    step:   19      cs: A   { 1  1  1  0 |0|}
    step:   20      cs: B   { 1  1  1  0  1 |0|}
    step:   21      cs: A   { 1  1  1  0 |1| 1 }
    step:   22      cs: B   { 1  1  1 |0| 1  1 }
    step:   23      cs: A   { 1  1 |1| 1  1  1 }
    step:   24      cs: B   { 1 |1| 1  1  1  1 }
    step:   25      cs: C   {|1| 0  1  1  1  1 }
    step:   26      cs: D   {|0| 1  0  1  1  1  1 }
    step:   27      cs: D   { 1 |1| 0  1  1  1  1 }
    step:   28      cs: A   { 1  0 |0| 1  1  1  1 }
    step:   29      cs: B   { 1  0  1 |1| 1  1  1 }
    step:   30      cs: C   { 1  0 |1| 0  1  1  1 }
    step:   31      cs: D   { 1 |0| 1  0  1  1  1 }
    step:   32      cs: D   { 1  1 |1| 0  1  1  1 }
    step:   33      cs: A   { 1  1  0 |0| 1  1  1 }
    step:   34      cs: B   { 1  1  0  1 |1| 1  1 }
    step:   35      cs: C   { 1  1  0 |1| 0  1  1 }
    step:   36      cs: D   { 1  1 |0| 1  0  1  1 }
    step:   37      cs: D   { 1  1  1 |1| 0  1  1 }
    step:   38      cs: A   { 1  1  1  0 |0| 1  1 }
    step:   39      cs: B   { 1  1  1  0  1 |1| 1 }
    step:   40      cs: C   { 1  1  1  0 |1| 0  1 }
    step:   41      cs: D   { 1  1  1 |0| 1  0  1 }
    step:   42      cs: D   { 1  1  1  1 |1| 0  1 }
    step:   43      cs: A   { 1  1  1  1  0 |0| 1 }
    step:   44      cs: B   { 1  1  1  1  0  1 |1|}
    step:   45      cs: C   { 1  1  1  1  0 |1| 0 }
    step:   46      cs: D   { 1  1  1  1 |0| 1  0 }
    step:   47      cs: D   { 1  1  1  1  1 |1| 0 }
    step:   48      cs: A   { 1  1  1  1  1  0 |0|}
    step:   49      cs: B   { 1  1  1  1  1  0  1 |0|}
    step:   50      cs: A   { 1  1  1  1  1  0 |1| 1 }
    step:   51      cs: B   { 1  1  1  1  1 |0| 1  1 }
    step:   52      cs: A   { 1  1  1  1 |1| 1  1  1 }
    step:   53      cs: B   { 1  1  1 |1| 1  1  1  1 }
    step:   54      cs: C   { 1  1 |1| 0  1  1  1  1 }
    step:   55      cs: D   { 1 |1| 1  0  1  1  1  1 }
    step:   56      cs: A   { 1  0 |1| 0  1  1  1  1 }
    step:   57      cs: B   { 1 |0| 1  0  1  1  1  1 }
    step:   58      cs: A   {|1| 1  1  0  1  1  1  1 }
    step:   59      cs: B   {|0| 1  1  1  0  1  1  1  1 }
    step:   60      cs: A   {|0| 1  1  1  1  0  1  1  1  1 }
    step:   61      cs: B   { 1 |1| 1  1  1  0  1  1  1  1 }
    step:   62      cs: C   {|1| 0  1  1  1  0  1  1  1  1 }
    step:   63      cs: D   {|0| 1  0  1  1  1  0  1  1  1  1 }
    step:   64      cs: D   { 1 |1| 0  1  1  1  0  1  1  1  1 }
    step:   65      cs: A   { 1  0 |0| 1  1  1  0  1  1  1  1 }
    step:   66      cs: B   { 1  0  1 |1| 1  1  0  1  1  1  1 }
    step:   67      cs: C   { 1  0 |1| 0  1  1  0  1  1  1  1 }
    step:   68      cs: D   { 1 |0| 1  0  1  1  0  1  1  1  1 }
    step:   69      cs: D   { 1  1 |1| 0  1  1  0  1  1  1  1 }
    step:   70      cs: A   { 1  1  0 |0| 1  1  0  1  1  1  1 }
    step:   71      cs: B   { 1  1  0  1 |1| 1  0  1  1  1  1 }
    step:   72      cs: C   { 1  1  0 |1| 0  1  0  1  1  1  1 }
    step:   73      cs: D   { 1  1 |0| 1  0  1  0  1  1  1  1 }
    step:   74      cs: D   { 1  1  1 |1| 0  1  0  1  1  1  1 }
    step:   75      cs: A   { 1  1  1  0 |0| 1  0  1  1  1  1 }
    step:   76      cs: B   { 1  1  1  0  1 |1| 0  1  1  1  1 }
    step:   77      cs: C   { 1  1  1  0 |1| 0  0  1  1  1  1 }
    step:   78      cs: D   { 1  1  1 |0| 1  0  0  1  1  1  1 }
    step:   79      cs: D   { 1  1  1  1 |1| 0  0  1  1  1  1 }
    step:   80      cs: A   { 1  1  1  1  0 |0| 0  1  1  1  1 }
    step:   81      cs: B   { 1  1  1  1  0  1 |0| 1  1  1  1 }
    step:   82      cs: A   { 1  1  1  1  0 |1| 1  1  1  1  1 }
    step:   83      cs: B   { 1  1  1  1 |0| 1  1  1  1  1  1 }
    step:   84      cs: A   { 1  1  1 |1| 1  1  1  1  1  1  1 }
    step:   85      cs: B   { 1  1 |1| 1  1  1  1  1  1  1  1 }
    step:   86      cs: C   { 1 |1| 0  1  1  1  1  1  1  1  1 }
    step:   87      cs: D   {|1| 1  0  1  1  1  1  1  1  1  1 }
    step:   88      cs: A   { 0 |1| 0  1  1  1  1  1  1  1  1 }
    step:   89      cs: B   {|0| 1  0  1  1  1  1  1  1  1  1 }
    step:   90      cs: A   {|0| 1  1  0  1  1  1  1  1  1  1  1 }
    step:   91      cs: B   { 1 |1| 1  0  1  1  1  1  1  1  1  1 }
    step:   92      cs: C   {|1| 0  1  0  1  1  1  1  1  1  1  1 }
    step:   93      cs: D   {|0| 1  0  1  0  1  1  1  1  1  1  1  1 }
    step:   94      cs: D   { 1 |1| 0  1  0  1  1  1  1  1  1  1  1 }
    step:   95      cs: A   { 1  0 |0| 1  0  1  1  1  1  1  1  1  1 }
    step:   96      cs: B   { 1  0  1 |1| 0  1  1  1  1  1  1  1  1 }
    step:   97      cs: C   { 1  0 |1| 0  0  1  1  1  1  1  1  1  1 }
    step:   98      cs: D   { 1 |0| 1  0  0  1  1  1  1  1  1  1  1 }
    step:   99      cs: D   { 1  1 |1| 0  0  1  1  1  1  1  1  1  1 }
    step:   100     cs: A   { 1  1  0 |0| 0  1  1  1  1  1  1  1  1 }
    step:   101     cs: B   { 1  1  0  1 |0| 1  1  1  1  1  1  1  1 }
    step:   102     cs: A   { 1  1  0 |1| 1  1  1  1  1  1  1  1  1 }
    step:   103     cs: B   { 1  1 |0| 1  1  1  1  1  1  1  1  1  1 }
    step:   104     cs: A   { 1 |1| 1  1  1  1  1  1  1  1  1  1  1 }
    step:   105     cs: B   {|1| 1  1  1  1  1  1  1  1  1  1  1  1 }
    step:   106     cs: C   {|0| 0  1  1  1  1  1  1  1  1  1  1  1  1 }
    step:   107     cs: Halt        { 1 |0| 1  1  1  1  1  1  1  1  1  1  1  1 }
