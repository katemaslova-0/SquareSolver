#ifndef SQUARE_SOLVER_DATA_H
#define SQUARE_SOLVER_DATA_H

enum Roots {
    kNoRoots,
    kOneRoot,
    kTwoRoots,
    kInfinity,
    kStart
};

enum Input {
    kStdin,
    kFileInput,
    kDefaultInput
};

struct Flags
{
	bool show_flags;
	bool test_flag;
	bool cf_flag;
};

#endif // SQUARE_SOLVER_DATA_H
