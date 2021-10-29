#ifndef __TESTCPP_H__
#define __TESTCPP_H__

#include <string>
using namespace std;

namespace convertion
{

	/* 分数 */
	class Fraction
	{
	public:
		/* non-explicit-one-argument ctor */
		/* 只要一個實參就夠了 */
		Fraction(int num, int den = 1)
			: m_numerator(num), m_denominator(den) {}

		operator double() const
		{
				return (double)(m_numerator) / (double)(m_denominator);
		}

		operator string() const
		{
			return (string)(m_numerator + "/" + m_denominator);
		}

		int get_num() const { return m_numerator; }
		int get_den() const { return m_denominator; }

	private:
		int m_numerator;   // 分子
		int m_denominator; // 分母
	};

}

/* non-explicit-one-argument ctor */
namespace nexp_1_arg_ctor
{

	/* 分数 */
	class Fraction
	{
	public:
		/* non-explicit-one-argument ctor */
		/* 只要一個實參就夠了 */
		Fraction(int num, int den = 1)
			: m_numerator(num), m_denominator(den) {}

		Fraction operator+(const Fraction &s)
		{
			return (Fraction)(m_numerator * s.get_den() + m_denominator * s.get_num(), s.get_den() * m_denominator);
		}
		int get_num() const { return m_numerator; }
		int get_den() const { return m_denominator; }

	private:
		int m_numerator;   // 分子
		int m_denominator; // 分母
	};

}

/* non-explicit-one-argument ctor */
namespace exp_1_arg_ctor
{

	/* 分数 */
	class Fraction
	{
	public:
		/* non-explicit-one-argument ctor */
		/* 只要一個實參就夠了 */
		explicit Fraction(int num, int den = 1)
			: m_numerator(num), m_denominator(den) {}

		Fraction operator+(const Fraction &s)
		{
			return (Fraction)(m_numerator * s.get_den() + m_denominator * s.get_num(), s.get_den() * m_denominator);
		}
		int get_num() const { return m_numerator; }
		int get_den() const { return m_denominator; }

	private:
		int m_numerator;   // 分子
		int m_denominator; // 分母
	};

}
#endif