#pragma once
#include <math.h>
#include <complex>

// Id of collaborators 208825539 207950577

using namespace std;

namespace solver {


    class RealVariable {
		double a;
        double b;
        double c;
    
       
    
    public:
		RealVariable(): a(0), b(1), c(0) {}
		RealVariable(double a, double b, double c) {
            this->a = a;
            this->b = b;
            this->c = c;
        }
		const double & get_a() const { return a; }
        const double & get_b() const { return b; }
        const double & get_c() const { return c; }
      
        friend RealVariable operator* (const RealVariable& x, const double n);
        friend RealVariable operator* (const double n ,const RealVariable& x);
       // friend RealVariable operator* (const RealVariable& left,const RealVariable& right);

        friend RealVariable operator+ (const RealVariable& x, const double n);
        friend RealVariable operator+ (const double n ,const RealVariable& x);
        friend RealVariable operator+ (const RealVariable& x1,const RealVariable& x2);

        friend RealVariable operator- (const RealVariable& x, const double n);
        friend RealVariable operator- (const double n ,const RealVariable& x);
        friend RealVariable operator- (const RealVariable& x1,const RealVariable& x2);
       // RealVariable operator- () const;

        friend RealVariable operator^ (const RealVariable& x, const int n);

        friend RealVariable operator/ (const RealVariable& x, const double n);
        friend RealVariable operator/ (const RealVariable& x1, const RealVariable& x2);


        friend RealVariable operator== (const RealVariable& x1,const RealVariable& x2);
        friend RealVariable operator== (const double n,const RealVariable& x);
        friend RealVariable operator== (const RealVariable& x, const double n);

        /*bool operator! () const;
        friend string operator+ (const RealVariable& x, const string str);
        friend string operator+ (const string str ,const RealVariable& x);*/
    };


   
     class ComplexVariable{
       complex<double> a;
       complex<double> b;
       complex<double> c;

    public:
        
        ComplexVariable(): a(0), b(1,0), c(0) {}
        
        ComplexVariable(complex<double> a, complex<double> b, complex<double> c) {
            this->a = complex(a);
            this->b = complex(b);
            this->c = complex(c);
        }
		const complex<double> & get_a() const { return a; }
        const complex<double> & get_b() const { return b; }
        const complex<double> & get_c() const { return c; }
    
        friend ComplexVariable operator* (const ComplexVariable& x, const complex<double> n);
        friend ComplexVariable operator* (const complex<double> n ,const ComplexVariable& x);
        

        friend ComplexVariable operator+ (const ComplexVariable& x, const complex<double> n);
        friend ComplexVariable operator+ (const complex<double> n ,const ComplexVariable& x);
        friend ComplexVariable operator+ (const ComplexVariable& left,const ComplexVariable& right);

        friend ComplexVariable operator- (const ComplexVariable& x, const complex<double> n);
        friend ComplexVariable operator- (const complex<double> n ,const ComplexVariable& x);
        friend ComplexVariable operator- (const ComplexVariable& left,const ComplexVariable& right);
      
        friend ComplexVariable operator^ (const ComplexVariable& x, const complex<double> n);

        friend ComplexVariable operator/ (const ComplexVariable& x, const complex<double> n);
        friend ComplexVariable operator== (const ComplexVariable& left,const ComplexVariable& right);
        friend ComplexVariable operator== (const complex<double> n,const ComplexVariable& right);
        friend ComplexVariable operator== (const ComplexVariable& left, const complex<double> n);

 
    };

    double solve(const RealVariable& x);
    complex<double> solve(const ComplexVariable& x);string to_string_complex (const complex<double> c);

}