#include <cmath>
#include <cassert>
#include <iostream>
using namespace std;

// The Vector class represents a vector in R^n, as a list of coordinates.  It also supports
// some basic operations such as addition, subtraction, scalar multiplication, etc.
//
// Internally, a vector just stores an array "u" of doubles encoding the coordinates:
//
//    double u[N];
//
// However, these raw values are "protected" from the user, to ensure that they are
// used and accessed in a way that is consistent with the behavior of a vector in R^n.
// This kind of "encapsulation" is a basic design principle in object-oriented programming;
// for further discussion see https://en.wikipedia.org/wiki/Object-oriented_programming
//
// The size of the vector is specified using a feature of C++ called "templating."
// In a nutshell, this means that the type is parameterized by a number N, specifying the
// number of coordinates that should be stored.  Any time a vector is declared, or a
// function using vectors is defined, this number needs to be specified.  For instance,
// to construct a vector u with three components, you would write:
//
//    Vector<3> u;
//
// The initial coordinates of this vector are unspecified.  To assign the initial coordinates,
// you can write something like
//
//    Vector<3> u{ 1.2, 7.3, -2.0 };
// 
// where 1.2, 7.3, and -2.0 give the "x", "y", and "z" coordinates of u, respectively.
// Operations on vectors look mostly how you might expect.  For instance, to add two vectors,
// you might write some code like this:
//
//    Vector<2> a{ 1.2, 3.4 };
//    Vector<2> b{ 5.6, 7.8 };
//    Vector<2> c = a + b;
//
// The resulting vector, c, will then have coordinates (6.8,11.2).  To access the individual
// components of the vector, you can use square brackets.  For instance, to extract the "z"
// component of a 3-vector, you would write code like this:
//
//    Vector<3> u{ 9.2, 4.1, 1.8 };
//    double z = u[2];
//
// Notice that we wrote "u[2]" rather than "u[3]", because the coordinates of a vector are
// 0-based rather than 1-based, i.e., the first coordinate has index 0, then 1, then 2, etc.
// Finally, to print out the value of a vector you can use the so-called "stream insertion
// operator" << commonly used in C++.  For example,
//
//    Vector <4> w{ 4.0, 3.0, 2.0, 1.0 };
//    cout << "My vector: " << w << endl;
//
// This code will print the output:
//
//    My vector [ 4 3 2 1 ]
//
// followed by a newline.
//
// Documentation of other functions can be found inline, below.
//
// Also provided is a function test() that will check the implementation against reference values;
// this function can be used to help debug the implementation (and is currently called from main()).
//

// The template parameter N determines the dimension of the vector (for example, N=2 for vectors in the plane)
template<int N>
class Vector
{
   public:
      // Default constructor --- creates a new vector, with undefined initial coordinates
      // EXAMPLE:
      //
      //    Vector<3> u; // creates a new 3-vector called "u"
      //
      Vector() {}

      // Construct from initializer list --- creates a new vector, with specified coordinates
      // EXAMPLE:
      //
      //    Vector<3> u{ 1., 2., 3. }; // creates a new 3-vector called "u", with coordinates (1,2,3)
      //    
      Vector( initializer_list<double> coords )
      {
         int i = 0;
         for( const auto& c : coords )
         {
            u[i] = c;
            i++;
         }
      }

      // Bracket operator --- accesses the ith coordinate of the vector
      // Note: uses 0-based indexing (i.e., coordinates start from 0, not 1)
      // EXAMPLE:
      //
      //    Vector<3> u{ 7., 5., 3. };
      //    u[1] = 9; // vector will now have entries (7,9,3)
      //
      double& operator[]( int i )
      {
         // make sure index is in valid range
         assert( i >= 0 && i < N );

         return u[i];
      }

      // const Bracket operator --- same as above, but can be used for
      // vectors that are "constant," i.e., those that cannot be modified.
      // EXAMPLE:
      //
      //    const Vector<3> u{ 7., 5., 3. };
      //    double y = u[1]; // result should be 5
      //
      const double& operator[]( int i ) const
      {
         // make sure index is in valid range
         assert( i >= 0 && i < N );

         return u[i];
      }

      // Dimension accessor --- returns the number of coordinates in this vector
      int dimension()
      {
         return N;
      }

      // Addition operator --- returns the sum of this vector and v
      // EXAMPLE:
      //
      //    Vector<2> a{1.,2.};
      //    Vector<2> b{3.,4.};
      //    Vector<2> c = a + b; // result is (4,6)
      //
      Vector<N> operator+( const Vector<N>& v )
      {
         Vector<N> sum;

         for( int i = 0; i < N; i++ )
         {
            sum[i] = u[i] + v[i];
         }
         return sum;
      }
      
// *************** DO NOT PRINT OUT/ TURN IN ANYTHING --ABOVE-- THIS LINE! ******************
// *************** ALSO: PLEASE REMOVE LARGE COMMENT BLOCKS BEFORE PRINTING *****************

// ------------------ 8< --------- CUT HERE ------------- 8< --------------------------------

      // Subtraction operator --- returns this vector minus the vector v
      // EXAMPLE:
      //
      //    Vector<2> a{1.,2.};
      //    Vector<2> b{3.,4.};
      //    Vector<2> c = a - b; // result is (-2,-2)
      //
      Vector<N> operator-( const Vector<N>& v )
      {
	  Vector<N> sub;

	  for( int i = 0; i < N; i++)
	  {
	      sub[i] = u[i] - v[i];
	  }
	  return sub;
      }

      // Scalar multiplication --- returns this vector times the scalar a
      // EXAMPLE:
      //
      //    Vector<4> u{2.,3.,2.,4.};
      //    Vector<4> v = 2.*u; // result is (4,6,4,8)
      //
      Vector<N> operator*( double a )
      {
	  Vector<N> scalar;

	  for( int i = 0; i < N; i++ )
	  {
	      scalar[i] = a * u[i];
	  }

	  return scalar;
      }

   protected:
      double u[N];
};


// Norm --- returns the Euclidean norm of this vector
// EXAMPLE:
//
//    Vector<3> u{3.,4.};
//    double m = u.norm(); // result is 5
//
template<int N>
double norm( const Vector<N>& u )
{
   // TODO implement this method
   return 0.; // TODO delete this line (and return the value you computed above instead)
}

// inner product --- returns the Euclidean inner product of the vectors u and v
// EXAMPLE:
//
//    Vector<4> p{ 1., 2., 3., 4 };
//    Vector<4> q{ 4., 3., 2., 1 };
//    double c = inner( p, q ); // result is 20
//
template<int N>
double inner( const Vector<N>& u, const Vector<N>& v )
{
    double i_product;

    for( int i = 0; i < N; i++ )
    {
	i_product += u[i] * v[i];
    }
    return i_product;
}

// Cross product --- returns the cross product of the vectors u and v
// Note: notice that this function is not templated on the parameter N,
// but is defined only for vectors with 3 entries (since otherwise, the
// cross product is not defined!)  In C++, this is called "partial specialization".
// EXAMPLE:
//
//    Vector<3> u{ 2., 3., 0. };
//    Vector<3> N{ 0., 0., 1. };
//    Vector<3> v = cross( N, u ); // result is (3,-2,0)
//
Vector<3> cross( const Vector<3>& u, const Vector<3>& v )
{
    Vector<3> cross_product;

    cross_product[0] = u[1]*v[2] - u[2]*v[1];
    cross_product[1] = u[2]*v[0] - u[0]*v[2];
    cross_product[2] = u[0]*v[1] - u[1]*v[0];
    
    return cross_product;
}

// Determinant --- returns the determinant of the three vectors u, v, and w, using
// the right-hand rule.  Note: as with cross product, this function is defined only
// for 3-vectors. (How could you generalize?)
// EXAMPLE:
//
//    Vector<3> e1{ 1., 0., 0. };
//    Vector<3> e2{ 0., 1., 0. };
//    Vector<3> e3{ 0., 0., 2. };
//    cout << determinant( e1, e2, e3 ) << endl; // should print "1"
//
double det( const Vector<3>& u, const Vector<3>& v, const Vector<3> w )
{
   // TODO implement this method
   // Hint: you can implement this using just the inner product and cross product
   // that you've already implemented above!  (See the course slides for more info.)
    Vector<3> temp = cross(u, v);
    double i_temp = inner(temp, w);

    return i_temp;
}

// Scalar-vector product --- returns the vector u scaled by the factor a
// Note: we have to define the function a*u separately from u*a, since in
// general left- and right-multiplication might do different things.  Also,
// in C++, the operator* for the class Vector assumes that the vector is
// the first object, and the scalar is the second object.  So, we have to
// define the other operator outside the class.
// EXAMPLE:
//
//    Vector<3> u{ 1., 2., 3. };
//    double a = 2.;
//    cout << 2.*a << endl; // should print "[ 2 4 6 ]"
//
template<int N>
Vector<N> operator*( double a, const Vector<N>& u )
{
    Vector<N> scalar_vector;

    for (int i = 0; i < N; i++)
    {
	scalar_vector[i] = a * u[i];
    }

    return scalar_vector;
}

// ------------------ 8< --------- CUT HERE ------------- 8< ----------------------------

// *************** DO NOT PRINT OUT/ TURN IN ANYTHING --BELOW-- THIS LINE! ******************
// *************** ALSO: PLEASE REMOVE LARGE COMMENT BLOCKS BEFORE PRINTING *****************

// output operator --- puts a string representation of the vector in
// the given output stream
// EXAMPLE:
//    
//    Vector<3> u{ 1., 2., 3. };
//    Vector<2> a{ 4., 5. };
//    cout << u << " has more entries than " << a << endl;
//    // output is "[ 1 2 3 ] has more entries than [ 4 5 ]"
//
template<int N>
ostream& operator<<( ostream& os, const Vector<N>& u )
{
   os << "[ ";
   for( int i = 0; i < N; i++ )
   {
      os << u[i] << " ";
   }
   os << "]";

   return os;
}

// Diff (scalar) --- returns the difference between scalar values, used for testing
double diff( double x, double y )
{
   return fabs( x-y );
}

// Diff (vector) --- returns the difference between vector values, used for testing
template<int N>
double diff( Vector<N> u, Vector<N> v )
{
   double sum = 0.;
   for( int i = 0; i < N; i++ )
   {
      sum += diff( u[i], v[i] );
   }
   return sum;
}

// Check -- this function compares the computed value to a known reference value
// It returns 1 if the values agree, and 0 otherwise
template<typename T>
int check( T val,  // value computed by the implementation
           T ref ) // correct reference value 
{
   // Since different numerical implementations may produce slightly
   // different numerical values (e.g., due to different order of
   // operations), values are only checked against a reference within
   // some very small tolerance of the true solution.
   const double tolerance = 1e-5;

   cout << "YOUR CODE: " << val << endl;
   cout << "REFERENCE: " << ref << endl;
   cout << "  CORRECT? ";

   if( diff(val,ref) < tolerance )
   {
      cout << "YES" << endl << endl;
      return 1;
   }
   else
   {
      cout << "NO" << endl << endl;
      return 0;
   }
}

// Test --- this function checks the value of each vector method against
// known (correct) reference values.  Note that this is not a formal guarantee
// that the methods are correctly implemented; just a spot check that things
// are on the right track.
void test()
{
   // Constants used for testing
   Vector<3> u{ 1., 2., 3. };
   Vector<3> v{ 3., 1., 2. };
   Vector<3> w{ 5., 3., 7. };
   double a = 4.;

   // Print out the constants
   cout << "u: " << u << endl;
   cout << "v: " << v << endl;
   cout << "w: " << w << endl;
   cout << "a: " << a << endl;
   cout << endl;

   // Check each method, keeping track of how many passed
   int nPassed = 0;

   cout << "u+v (addition)" << endl;
   nPassed += check( u+v, Vector<3>{4,3,5} );

   cout << "u-v (subtraction)" << endl;
   nPassed += check( u-v, Vector<3>{-2,1,1} );

   cout << "u*a (right scalar multiplication)" << endl;
   nPassed += check( u*a, Vector<3>{4,8,12} );

   cout << "norm(u) (Euclidean norm)" << endl;
   nPassed += check( norm(u), 3.74166 );

   cout << "inner(u,v) (inner product)" << endl;
   nPassed += check( inner(u,v), 11. );

   cout << "cross(u,v) (cross product)" << endl;
   nPassed += check( cross(u,v), Vector<3>{1,7,-5} );

   cout << "det(u,v,w) (determinant)" << endl;
   nPassed += check( det(u,v,w), -9. );

   cout << "a*u (left scalar multiplication)" << endl;
   nPassed += check( a*u, Vector<3>{4,8,12} );

   cout << "PASSED " << nPassed << " OF 8 TESTS" << endl;
}

int main()
{
   test();
   
   return 0;
}

