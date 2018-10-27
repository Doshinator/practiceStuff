#include <iostream>
#include <string>
using namespace std;
/**
 * Build an calculator using AST
 * EXPR consist of string ("*, +, -, /")
 * Numbers consist of (int)
 * Evaluate the final result as like a calculator would
 **/


class EXPR{
    public:
    virtual string toString() = 0;
    // virtual int evaluate() = 0;

};

class MEXPR : public EXPR{
    public:
    EXPR *l, *r;
 
    string toString() {return "(" + l->toString() + " * " + r->toString() + ")";}
    MEXPR(EXPR *l, EXPR *r) : l(l), r(r) { }
};

class AEXPR : public EXPR{
    public:
    EXPR *l, *r; 
    string toString() {return "(" + l->toString() + " + " + r->toString() + ")";}
    AEXPR(EXPR *l, EXPR *r) : l(l), r(r) { }
};

class DEXPR : public EXPR{
    public:
    EXPR *l, *r; 
    string toString() {return "(" + l->toString() + " / " + r->toString() + ")";}
    DEXPR(EXPR *l, EXPR *r) : l(l), r(r) { }
};

class SEXPR : public EXPR{
    public:
    EXPR *l, *r; 
    string toString() {return "(" + l->toString() + " - " + r->toString() + ")";}
    SEXPR(EXPR *l, EXPR *r) : l(l), r(r) { }
};


class INT : public EXPR{
    private:
    int num;
    public:
    INT(int n) : num(n) { }
    string toString() { return to_string(num); }
};

static EXPR *M(EXPR *l, EXPR *r) {return new MEXPR(l, r);}
static EXPR *D(EXPR *l, EXPR *r) {return new DEXPR(l, r);}
static EXPR *A(EXPR *l, EXPR *r) {return new AEXPR(l, r);}
static EXPR *S(EXPR *l, EXPR *r) {return new SEXPR(l, r);}
static EXPR *I(int n) {return new INT(n);}
int main(void){

    
    auto example = S ( D ( A ( M ( I(4), I(5)), I(5)), I(0)), I(575));
    cout << example->toString() << endl;
    //cout << example->evaluate() << endl;
    return 0;
}