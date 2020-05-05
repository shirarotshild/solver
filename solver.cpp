#include "solver.hpp"
#include <iostream>
#include <string>



using namespace std;
namespace solver {

    RealVariable operator* (const RealVariable& x, const double n) {
            return RealVariable(x.get_a()*n, x.get_b()*n, x.get_c()*n);
    
    }

    RealVariable operator* (const double n ,const RealVariable& x) {
          return RealVariable(x.get_a()*n, x.get_b()*n, x.get_c()*n);
    
    }

  /* RealVariable operator* (const RealVariable& left, const RealVariable& right) {
       
    return left; 

    }*/

    RealVariable operator+ (const RealVariable& x, const double n) {
          return RealVariable(x.get_a(), x.get_b(), x.get_c()+n);

    }

    RealVariable operator+ (const double n ,const RealVariable& x) {
        return RealVariable(x.get_a(), x.get_b(), x.get_c()+n);

    }

    RealVariable operator+ (const RealVariable& x1, const RealVariable& x2) {
       return RealVariable(x1.get_a()+x2.get_a(), x1.get_b()+x2.get_b(), x1.get_c()+x2.get_c());

    }

    RealVariable operator- (const RealVariable& x, const double n) {
        return RealVariable(x.get_a(), x.get_b(), x.get_c()-n);

    }

    RealVariable operator- (const double n ,const RealVariable& x) {
          return RealVariable(x.get_a(), x.get_b(), x.get_c()-n);

   }

    RealVariable operator- (const RealVariable& x1, const RealVariable& x2) {
        
		return RealVariable(x1.get_a()-x2.get_a(), x1.get_b()-x2.get_b(), x1.get_c()-x2.get_c());

    }

    /*RealVariable RealVariable::operator- () const {
        return *this;
    }*/

    RealVariable operator^ (const RealVariable& x, const int n) {
        
        if(n == 2) {
        return RealVariable(1,0,0);
        }
        if (n == 1) {
            return x;
        }
        if (n == 0) {
            return RealVariable(0,0,1);
        }
        throw invalid_argument("power is too big ");

 }

    RealVariable operator/ (const RealVariable& x, const double n) {
		if(n == 0) throw invalid_argument("You cannot divide by 0");
		return RealVariable(x.a/n, x.b/n, x.c/n);
        

    }

    /*RealVariable operator/ (const RealVariable& x1, const RealVariable& x1 {
       return x2;
    }*/

    RealVariable operator == (const RealVariable& x1, const RealVariable& x2) {
        return RealVariable(x1.get_a()-x2.get_a(), x1.get_b()-x2.get_b(), x1.get_c()-x2.get_c());

    }

    RealVariable operator== (const double n, const RealVariable& x) {
		return RealVariable(x.a, x.b, x.c-n);

    }
    
    RealVariable operator== (const RealVariable& x, const double n) {
        return RealVariable(x.a, x.b, x.c-n);

    }

/////////////////////////////////////////ComplexVariable functions//////////////////////////////////////////////


    ComplexVariable operator* (const ComplexVariable& x, const complex<double> n) {
      return ComplexVariable(x.a*n, x.b*n, x.c*n);

    }

    ComplexVariable operator* (const complex<double> n , const ComplexVariable& x) {
         return ComplexVariable(x.a*n, x.b*n, x.c*n);

    }

    /*ComplexVariable operator* (const ComplexVariable& x1, const ComplexVariable& x2) {
       
        return left;
    } */  

    ComplexVariable operator+ (const ComplexVariable& x, const complex<double> n) {
       return ComplexVariable(x.a, x.b, x.c+n);


    }
    
    ComplexVariable operator+ (const complex<double> n , const ComplexVariable& x) {
         return ComplexVariable(x.a, x.b, x.c+n);
    }

    ComplexVariable operator+ (const ComplexVariable& x1, const ComplexVariable& x2) {
       return ComplexVariable(x1.a+x2.a, x1.b+x2.b, x1.c+x2.c);
    
    }

    ComplexVariable operator- (const ComplexVariable& x, const complex<double> n) {
        return ComplexVariable(x.a, x.b, x.c-n);
        
    }
    
    ComplexVariable operator- (const complex<double> n , const ComplexVariable& x) {
          return ComplexVariable(x.a, x.b, x.c-n);
        
    }

    ComplexVariable operator- (const ComplexVariable& x1, const ComplexVariable& x2) {
       return ComplexVariable(x1.a-x2.a, x1.b-x2.b, x1.c-x2.c);

    }

    ComplexVariable operator^ (const ComplexVariable& x, const complex<double> n) {
       if(n.real() == 2) {
               return ComplexVariable(complex(1.0,0.0),complex(0.0,0.0),complex(0.0,0.0));
        }
        if (n.real() == 1) {
            return x;
        }
        if (n.real() == 0) {
            return ComplexVariable(complex(0.0,0.0),complex(0.0,0.0),complex(1.0,0.0));
        }
        throw invalid_argument("power is not vaild: ");
    }

    ComplexVariable operator/ (const ComplexVariable& x, const complex<double> n) {
        if(n.real() == 0 && n.imag() ==0) throw invalid_argument("power is not vaild: ");
			  return ComplexVariable(x.a/n, x.b/n, x.c/n);
    }

    ComplexVariable operator== (const ComplexVariable& x1, const ComplexVariable& x2) {
        return x1-x2;

    }

    ComplexVariable operator== (const complex<double> n, const ComplexVariable& x) {
        return x - n;

    }
    
    ComplexVariable operator== (const ComplexVariable& x, const complex<double> n) {
        return x - n;

    }
    double solve(const RealVariable& x)	{
     double a = x.get_a(), b = x.get_b(), c = x.get_c();
	 if(a == 0 && b ==0 && c !=0) throw invalid_argument("There is no solution to the equation");
	  if (a==0) return ((-c)/b);
	   double sqrt1 = ((b*b) -4*(a*c));
	   if(sqrt1<0) throw invalid_argument("There is no solution to the equation");
	   double x1 = (-b + sqrt(sqrt1) )/ (2*a);
            return x1;
	  
    }

    
    complex<double> solve(const ComplexVariable& x) {
     complex<double> a = x.get_a(), b = x.get_b(), c = x.get_c();
	 //if(a == 0 && b == 0 && c !=0) throw invalid_argument("There is no solution to the equation");
if(a == complex(0.0,0.0)) { // The equation is linear
            if ((b == complex(0.0,0.0)) && (c != complex(0.0,0.0))) throw runtime_error("There is no solution for this equation");
            else return -c/b;
        }
	 complex<double> sqrt1 = b*b - complex(4.0,0.0)*a*c;
	 complex <double> x1 = (-b + sqrt(sqrt1)) / (complex(2.0,0.0)*a);

        return x1;
   }
    string to_string_complex (const complex<double> c){
        return to_string(c.real()) + "+" + to_string(c.imag())  + "i";
   }

   
}