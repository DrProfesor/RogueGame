// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __IRR_MATH_H_INCLUDED__
#define __IRR_MATH_H_INCLUDED__

#include <math.h>
#include <float.h>
#include <stdlib.h> // for abs() etc.
#include <limits.h> // For INT_MAX / UINT_MAX

#if defined(_IRR_SOLARIS_PLATFORM_) || defined(__BORLANDC__) || defined (__BCPLUSPLUS__) || defined (_WIN32_WCE)
#define sqrtf(X) (f32)sqrt((f64)(X))
	#define sinf(X) (f32)sin((f64)(X))
	#define cosf(X) (f32)cos((f64)(X))
	#define asinf(X) (f32)asin((f64)(X))
	#define acosf(X) (f32)acos((f64)(X))
	#define atan2f(X,Y) (f32)atan2((f64)(X),(f64)(Y))
	#define ceilf(X) (f32)ceil((f64)(X))
	#define floorf(X) (f32)floor((f64)(X))
	#define powf(X,Y) (f32)pow((f64)(X),(f64)(Y))
	#define fmodf(X,Y) (f32)fmod((f64)(X),(f64)(Y))
	#define fabsf(X) (f32)fabs((f64)(X))
	#define logf(X) (f32)log((f64)(X))
#endif

#ifndef FLT_MAX
#define FLT_MAX 3.402823466E+38F
#endif

#ifndef FLT_MIN
#define FLT_MIN 1.17549435e-38F
#endif

namespace Math {

//! Rounding error constant often used when comparing float values.

    const int ROUNDING_ERROR_S32 = 0;

#ifdef __IRR_HAS_S64
    const s64 ROUNDING_ERROR_S64 = 0;
#endif
    const float ROUNDING_ERROR_float = 0.000001f;

#ifdef PI // make sure we don't collide with a define
#undef PI
#endif
//! Constant for PI.
    const float PI = 3.14159265359f;

//! Constant for reciprocal of PI.
    const float RECIPROCAL_PI = 1.0f / PI;

//! Constant for half of PI.
    const float HALF_PI = PI / 2.0f;

#ifdef PI64 // make sure we don't collide with a define
#undef PI64
#endif
//! Constant for 64bit PI.
    const float PI64 = 3.1415926535897932384626433832795028841971693993751;

//! Constant for 64bit reciprocal of PI.
    const float RECIPROCAL_PI64 = 1.0 / PI64;

//! 32bit Constant for converting from degrees to radians
    const float DEGTORAD = PI / 180.0f;

//! 32bit constant for converting from radians to degrees (formally known as GRAD_PI)
    const float RADTODEG = 180.0f / PI;

//! 64bit constant for converting from degrees to radians (formally known as GRAD_PI2)
    const float DEGTORAD64 = PI64 / 180.0;

//! 64bit constant for converting from radians to degrees
    const float RADTODEG64 = 180.0 / PI64;

//! Utility function to convert a radian value to degrees
/** Provided as it can be clearer to write radToDeg(X) than RADTODEG * X
\param radians The radians value to convert to degrees.
*/
    inline float radToDeg(float radians) {
        return RADTODEG * radians;
    }


//! Utility function to convert a degrees value to radians
/** Provided as it can be clearer to write degToRad(X) than DEGTORAD * X
\param degrees The degrees value to convert to radians.
*/
    inline float degToRad(float degrees) {
        return DEGTORAD * degrees;
    }


//! returns minimum of two values. Own implementation to get rid of the STL (VS6 problems)
    template<class T>
    inline const T &min_(const T &a, const T &b) {
        return a < b ? a : b;
    }

//! returns minimum of three values. Own implementation to get rid of the STL (VS6 problems)
    template<class T>
    inline const T &min_(const T &a, const T &b, const T &c) {
        return a < b ? min_(a, c) : min_(b, c);
    }

//! returns maximum of two values. Own implementation to get rid of the STL (VS6 problems)
    template<class T>
    inline const T &max_(const T &a, const T &b) {
        return a < b ? b : a;
    }

//! returns maximum of three values. Own implementation to get rid of the STL (VS6 problems)
    template<class T>
    inline const T &max_(const T &a, const T &b, const T &c) {
        return a < b ? max_(b, c) : max_(a, c);
    }

//! returns abs of two values. Own implementation to get rid of STL (VS6 problems)
    template<class T>
    inline T abs_(const T &a) {
        return a < (T) 0 ? -a : a;
    }

//! returns linear interpolation of a and b with ratio t
//! \return: a if t==0, b if t==1, and the linear interpolation else
    template<class T>
    inline T lerp(const T &a, const T &b, const float t) {
        return (T) (a * (1.f - t)) + (b * t);
    }

//! clamps a value between low and high
    template<class T>
    inline const T clamp(const T &value, const T &low, const T &high) {
        return min_(max_(value, low), high);
    }

//! swaps the content of the passed parameters
// Note: We use the same trick as boost and use two template arguments to
// avoid ambiguity when swapping objects of an Irrlicht type that has not
// it's own swap overload. Otherwise we get conflicts with some compilers
// in combination with stl.
    template<class T1, class T2>
    inline void swap(T1 &a, T2 &b) {
        T1 c(a);
        a = b;
        b = c;
    }

    template<class T>
    inline T roundingError();

    template<>
    inline float roundingError() {
        return ROUNDING_ERROR_float;
    }


    template<>
    inline int roundingError() {
        return ROUNDING_ERROR_S32;
    }


#ifdef __IRR_HAS_S64
    template <>
    inline s64 roundingError()
    {
    return ROUNDING_ERROR_S64;
    }

    template <>
    inline u64 roundingError()
    {
    return ROUNDING_ERROR_S64;
    }
#endif

    template<class T>
    inline T relativeErrorFactor() {
        return 1;
    }

    template<>
    inline float relativeErrorFactor() {
        return 8;
    }

//! returns if a equals b, taking possible rounding errors into account
    template<class T>
    inline bool equals(const T a, const T b, const T tolerance = roundingError<T>()) {
        return (a + tolerance >= b) && (a - tolerance <= b);
    }


//! returns if a equals b, taking relative error in form of factor
//! this particular function does not involve any division.
    template<class T>
    inline bool equalsRelative(const T a, const T b, const T factor = relativeErrorFactor<T>()) {
        //https://eagergames.wordpress.com/2017/04/01/fast-parallel-lines-and-vectors-test/

        const T maxi = max_(a, b);
        const T mini = min_(a, b);
        const T maxMagnitude = max_(maxi, -mini);

        return (maxMagnitude * factor + maxi) == (maxMagnitude * factor + mini); // MAD Wise
    }

    union FloatIntUnion32 {
        FloatIntUnion32(float f1 = 0.0f) : f(f1) {}

        // Portable sign-extraction
        bool sign() const { return (i >> 31) != 0; }

        int i;
        float f;
    };

//! We compare the difference in ULP's (spacing between floating-point numbers, aka ULP=1 means there exists no float between).
//\result true when numbers have a ULP <= maxUlpDiff AND have the same sign.
    inline bool equalsByUlp(float a, float b, int maxUlpDiff) {
        // Based on the ideas and code from Bruce Dawson on
        // http://www.altdevblogaday.com/2012/02/22/comparing-floating-point-numbers-2012-edition/
        // When floats are interpreted as integers the two nearest possible float numbers differ just
        // by one integer number. Also works the other way round, an integer of 1 interpreted as float
        // is for example the smallest possible float number.

        FloatIntUnion32 fa(a);
        FloatIntUnion32 fb(b);

        // Different signs, we could maybe get difference to 0, but so close to 0 using epsilons is better.
        if (fa.sign() != fb.sign()) {
            // Check for equality to make sure +0==-0
            if (fa.i == fb.i)
                return true;
            return false;
        }

        // Find the difference in ULPs.
        int ulpsDiff = abs_(fa.i - fb.i);
        if (ulpsDiff <= maxUlpDiff)
            return true;

        return false;
    }

//! returns if a equals zero, taking rounding errors into account
    inline bool iszero(const float a, const float tolerance = ROUNDING_ERROR_float) {
        return fabs(a) <= tolerance;
    }

//! returns if a equals not zero, taking rounding errors into account
    inline bool isnotzero(const float a, const float tolerance = ROUNDING_ERROR_float) {
        return fabsf(a) > tolerance;
    }

//! returns if a equals zero, taking rounding errors into account
    inline bool iszero(const int a, const int tolerance = 0) {
        return (a & 0x7ffffff) <= tolerance;
    }

//! returns if a equals zero, taking rounding errors into account
    inline bool iszero(const unsigned int a, const unsigned int tolerance = 0) {
        return a <= tolerance;
    }

#ifdef __IRR_HAS_S64
    //! returns if a equals zero, taking rounding errors into account
    inline bool iszero(const s64 a, const s64 tolerance = 0)
    {
    return abs_(a) <= tolerance;
    }
#endif

    inline int int_min(int a, int b) {
        const int mask = (a - b) >> 31;
        return (a & mask) | (b & ~mask);
    }

    inline int int_max(int a, int b) {
        const int mask = (a - b) >> 31;
        return (b & mask) | (a & ~mask);
    }

    inline int int_clamp(int value, int low, int high) {
        return int_min(int_max(value, low), high);
    }

/*
    float IEEE-754 bit representation

    0      0x00000000
    1.0    0x3f800000
    0.5    0x3f000000
    3      0x40400000
    +inf   0x7f800000
    -inf   0xff800000
    +NaN   0x7fc00000 or 0x7ff00000
    in general: number = (sign ? -1:1) * 2^(exponent) * 1.(mantissa bits)
*/

    typedef union {
        unsigned int u;
        int s;
        float f;
    } inttofloat;

#define F32_AS_S32(f)        (*((int *) &(f)))
#define F32_AS_U32(f)        (*((unsigned int *) &(f)))
#define F32_AS_U32_POINTER(f)    ( ((unsigned int *) &(f)))

#define F32_VALUE_0        0x00000000
#define F32_VALUE_1        0x3f800000
#define F32_SIGN_BIT        0x80000000U
#define F32_EXPON_MANTISSA    0x7FFFFFFFU

//! code is taken from IceFPU
//! Integer representation of a floating-point value.
#ifdef IRRLICHT_FAST_MATH
#define IR(x)			((unsigned int&)(x))
#else

    inline unsigned int IR(float x) {
        inttofloat tmp;
        tmp.f = x;
        return tmp.u;
    }

#endif

//! Absolute integer representation of a floating-point value
#define AIR(x)            (IR(x)&0x7fffffff)

//! Floating-point representation of an integer value.
#ifdef IRRLICHT_FAST_MATH
#define FR(x)			((f32&)(x))
#else

    inline float FR(unsigned int x) {
        inttofloat tmp;
        tmp.u = x;
        return tmp.f;
    }

    inline float FR(int x) {
        inttofloat tmp;
        tmp.s = x;
        return tmp.f;
    }

#endif

//! integer representation of 1.0
#define IEEE_1_0        0x3f800000
//! integer representation of 255.0
#define IEEE_255_0        0x437f0000

#ifdef IRRLICHT_FAST_MATH
#define	F32_LOWER_0(f)		(F32_AS_U32(f) >  F32_SIGN_BIT)
#define	F32_LOWER_EQUAL_0(f)	(F32_AS_S32(f) <= F32_VALUE_0)
#define	F32_GREATER_0(f)	(F32_AS_S32(f) >  F32_VALUE_0)
#define	F32_GREATER_EQUAL_0(f)	(F32_AS_U32(f) <= F32_SIGN_BIT)
#define	F32_EQUAL_1(f)		(F32_AS_U32(f) == F32_VALUE_1)
#define	F32_EQUAL_0(f)		( (F32_AS_U32(f) & F32_EXPON_MANTISSA ) == F32_VALUE_0)

    // only same sign
#define	F32_A_GREATER_B(a,b)	(F32_AS_S32((a)) > F32_AS_S32((b)))

#else

#define    F32_LOWER_0(n)        ((n) <  0.0f)
#define    F32_LOWER_EQUAL_0(n)    ((n) <= 0.0f)
#define    F32_GREATER_0(n)    ((n) >  0.0f)
#define    F32_GREATER_EQUAL_0(n)    ((n) >= 0.0f)
#define    F32_EQUAL_1(n)        ((n) == 1.0f)
#define    F32_EQUAL_0(n)        ((n) == 0.0f)
#define    F32_A_GREATER_B(a, b)    ((a) > (b))
#endif


#ifndef REALINLINE
#ifdef _MSC_VER
#define REALINLINE __forceinline
#else
#define REALINLINE inline
#endif
#endif

#if defined(__BORLANDC__) || defined (__BCPLUSPLUS__)

    // 8-bit bools in Borland builder

    //! conditional set based on mask and arithmetic shift
    REALINLINE u32 if_c_a_else_b ( const c8 condition, const u32 a, const u32 b )
    {
    return ( ( -condition >> 7 ) & ( a ^ b ) ) ^ b;
    }

    //! conditional set based on mask and arithmetic shift
    REALINLINE u32 if_c_a_else_0 ( const c8 condition, const u32 a )
    {
    return ( -condition >> 31 ) & a;
    }
#else

//! conditional set based on mask and arithmetic shift
    REALINLINE unsigned int if_c_a_else_b(const int condition, const unsigned int a, const unsigned int b) {
        return ((-condition >> 31) & (a ^ b)) ^ b;
    }

//! conditional set based on mask and arithmetic shift
    REALINLINE unsigned int if_c_a_else_0(const int condition, const unsigned int a) {
        return (-condition >> 31) & a;
    }

#endif

/*
    if (condition) state |= m; else state &= ~m;
*/
    REALINLINE void setbit_cond(unsigned int &state, int condition, unsigned int mask) {
        // 0, or any positive to mask
        //int conmask = -condition >> 31;
        state ^= ((-condition >> 31) ^ state) & mask;
    }

    inline float round_(float x) {
        return floorf(x + 0.5f);
    }

    REALINLINE void clearFPUException() {
#ifdef IRRLICHT_FAST_MATH
        return;
#ifdef feclearexcept
    feclearexcept(FE_ALL_EXCEPT);
#elif defined(_MSC_VER)
    __asm fnclex;
#elif defined(__GNUC__) && defined(__x86__)
    __asm__ __volatile__ ("fclex \n\t");
#endif
#endif
    }

// calculate: sqrt ( x )
    REALINLINE float squareroot(const float f) {
        return sqrtf(f);
    }

// calculate: sqrt ( x )
    REALINLINE int squareroot(const int f) {
        return static_cast<int>(squareroot(static_cast<float>(f)));
    }

#ifdef __IRR_HAS_S64
    // calculate: sqrt ( x )
    REALINLINE s64 squareroot(const s64 f)
    {
    return static_cast<s64>(squareroot(static_cast<f64>(f)));
    }
#endif

// calculate: 1 / sqrtf ( x )
    REALINLINE float reciprocal_squareroot(const float f) {
#if defined ( IRRLICHT_FAST_MATH )
#if defined(_MSC_VER)
        // SSE reciprocal square root estimate, accurate to 12 significant
        // bits of the mantissa
        float recsqrt;
        __asm rsqrtss xmm0, f           // xmm0 = rsqrtss(f)
        __asm movss recsqrt, xmm0       // return xmm0
        return recsqrt;

        /*
        // comes from Nvidia
        unsigned int tmp = (unsigned int(IEEE_1_0 << 1) + IEEE_1_0 - *(unsigned int*)&x) >> 1;
        float y = *(f32*)&tmp;
        return y * (1.47f - 0.47f * x * y * y);
        */
#else
        return 1.f / sqrtf(f);
#endif
#else // no fast math
        return 1.f / sqrtf(f);
#endif
    }

// calculate: 1 / sqrtf( x )
    REALINLINE int reciprocal_squareroot(const int x) {
        return static_cast<int>(reciprocal_squareroot(static_cast<float>(x)));
    }

// calculate: 1 / x
    REALINLINE float reciprocal(const float f) {
#if defined (IRRLICHT_FAST_MATH)

        // SSE Newton-Raphson reciprocal estimate, accurate to 23 significant
    // bi ts of the mantissa
    // One Newton-Raphson Iteration:
    // f(i+1) = 2 * rcpss(f) - f * rcpss(f) * rcpss(f)
#if defined(_MSC_VER)
    float rec;
    __asm rcpss xmm0, f               // xmm0 = rcpss(f)
    __asm movss xmm1, f               // xmm1 = f
    __asm mulss xmm1, xmm0            // xmm1 = f * rcpss(f)
    __asm mulss xmm1, xmm0            // xmm2 = f * rcpss(f) * rcpss(f)
    __asm addss xmm0, xmm0            // xmm0 = 2 * rcpss(f)
    __asm subss xmm0, xmm1            // xmm0 = 2 * rcpss(f)
                                      //        - f * rcpss(f) * rcpss(f)
    __asm movss rec, xmm0             // return xmm0
    return rec;
#else // no support yet for other compilers
    return 1.f / f;
#endif
    //! i do not divide through 0.. (fpu expection)
    // instead set f to a high value to get a return value near zero..
    // -1000000000000.f.. is use minus to stay negative..
    // must test's here (plane.normal dot anything ) checks on <= 0.f
    //unsigned int x = (-(AIR(f) != 0 ) >> 31 ) & ( IR(f) ^ 0xd368d4a5 ) ^ 0xd368d4a5;
    //return 1.f / FR ( x );

#else // no fast math
        return 1.f / f;
#endif
    }

// calculate: 1 / x, low precision allowed
    REALINLINE float reciprocal_approxim(const float f) {
#if defined( IRRLICHT_FAST_MATH)

        // SSE Newton-Raphson reciprocal estimate, accurate to 23 significant
    // bi ts of the mantissa
    // One Newton-Raphson Iteration:
    // f(i+1) = 2 * rcpss(f) - f * rcpss(f) * rcpss(f)
#if defined(_MSC_VER)
    float rec;
    __asm rcpss xmm0, f               // xmm0 = rcpss(f)
    __asm movss xmm1, f               // xmm1 = f
    __asm mulss xmm1, xmm0            // xmm1 = f * rcpss(f)
    __asm mulss xmm1, xmm0            // xmm2 = f * rcpss(f) * rcpss(f)
    __asm addss xmm0, xmm0            // xmm0 = 2 * rcpss(f)
    __asm subss xmm0, xmm1            // xmm0 = 2 * rcpss(f)
                                      //        - f * rcpss(f) * rcpss(f)
    __asm movss rec, xmm0             // return xmm0
    return rec;
#else // no support yet for other compilers
    return 1.f / f;
#endif

    /*
    // SSE reciprocal estimate, accurate to 12 significant bits of
    float rec;
    __asm rcpss xmm0, f             // xmm0 = rcpss(f)
    __asm movss rec , xmm0          // return xmm0
    return rec;
    */
    /*
    register unsigned int x = 0x7F000000 - IR ( p );
    const float r = FR ( x );
    return r * (2.0f - p * r);
    */
#else // no fast math
        return 1.f / f;
#endif
    }


    REALINLINE int floor32(float x) {
#ifdef IRRLICHT_FAST_MATH
        const float h = 0.5f;

    int t;

#if defined(_MSC_VER)
    __asm
    {
        fld	x
        fsub	h
        fistp	t
    }
#elif defined(__GNUC__)
    __asm__ __volatile__ (
        "fsub %2 \n\t"
        "fistpl %0"
        : "=m" (t)
        : "t" (x), "f" (h)
        : "st"
        );
#else
    return (int) floorf ( x );
#endif
    return t;
#else // no fast math
        return (int) floorf(x);
#endif
    }


    REALINLINE int ceil32(float x) {
#ifdef IRRLICHT_FAST_MATH
        const float h = 0.5f;

    int t;

#if defined(_MSC_VER)
    __asm
    {
        fld	x
        fadd	h
        fistp	t
    }
#elif defined(__GNUC__)
    __asm__ __volatile__ (
        "fadd %2 \n\t"
        "fistpl %0 \n\t"
        : "=m"(t)
        : "t"(x), "f"(h)
        : "st"
        );
#else
    return (int) ceilf ( x );
#endif
    return t;
#else // not fast math
        return (int) ceilf(x);
#endif
    }


    REALINLINE int round32(float x) {
#if defined(IRRLICHT_FAST_MATH)
        int t;

#if defined(_MSC_VER)
    __asm
    {
        fld   x
        fistp t
    }
#elif defined(__GNUC__)
    __asm__ __volatile__ (
        "fistpl %0 \n\t"
        : "=m"(t)
        : "t"(x)
        : "st"
        );
#else
    return (int) round_(x);
#endif
    return t;
#else // no fast math
        return (int) round_(x);
#endif
    }

    inline float f32_max3(const float a, const float b, const float c) {
        return a > b ? (a > c ? a : c) : (b > c ? b : c);
    }

    inline float f32_min3(const float a, const float b, const float c) {
        return a < b ? (a < c ? a : c) : (b < c ? b : c);
    }

    inline float fract(float x) {
        return x - floorf(x);
    }
}
#endif
