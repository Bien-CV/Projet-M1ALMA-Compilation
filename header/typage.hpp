#ifndef TYPAGE_HPP
#define TYPAGE_HPP

enum AtomType {TERMINAL , NONTERMINAL};

enum Operation {CONC, UNION, STAR, UN, ATOM};

typedef struct {
	Operation classe;
} Node;

typedef struct : public Node
{
	Node* left;
	Node* right;
} Conc;

typedef struct : public Node
{
	Node* left;
	Node* right;
} Union;

typedef struct : public Node
{
	Node* stare;
	
} Star;

typedef struct : public Node
{
	Node* une;
	
} Un;

typedef struct : public Node
{
	int code;
	int action;
	AtomType type;
} Atom;

typedef struct {
	int code;
	int action;
	AtomType type;
	string chaine;
} Instance;

#endif //TYPAGE_HPP
