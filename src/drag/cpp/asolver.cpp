#include <iostream>

#include "asolver.h"
///#include "alglib.h"
#include "asdlib.h"


Asolver * make_solver(AsolFun * fn, const Params & p, const void * data)
{
    return new Asdlib(fn, p, data);
    //return new Alglib(fn, p);
}


//============================================
// TEST ALGLIB

struct Tfun: AsolFun
{
    double f(const Params & pms, const void *);
};

double Tfun::f(const Params & x, const void *)
{
    double y = x.v[0] * x.v[0];
    std::cout << "# " << x.v[0] << " -> " << y << '\n';
    return y;
}

void testAsolver(Asolver * a)
{
    //void tmain(); return tmain();

    Tfun tf;
    a->setFun(&tf);
    double x[] = {1, 2, 3};
    Params p(3, x);
    a->setParams(p);
    p = a->solve(100000);

    std::cout << p.v.size() << ": {";
    for ( auto y : p.v )
        std::cout << ' ' << y;
    std::cout << " }\n";
}


