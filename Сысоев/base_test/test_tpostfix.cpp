#include "postfix.cpp"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
	ASSERT_NO_THROW(TPostfix p());
}
TEST(TPostfix, get_infix_form)
{
	TPostfix p("(a+b)*c+d");
	p.ToPostfix();
	EXPECT_EQ("(a+b)*c+d", p.GetInfix());
}
TEST(TPostfix, get_postfix_form)
{
	TPostfix p("(a+b)*c+d");
	p.ToPostfix();
	EXPECT_EQ("ab+c*d+", p.GetPostfix());
}
TEST(TPostfix, transform_infix_in_postfix_if_variables_are_given)
{
	TPostfix p("(a+b)*c");	
	EXPECT_EQ("ab+c*", p.ToPostfix());
}
TEST(TPostfix, can_calculate_in_postfix_if_variables_are_given)
{
	TPostfix p("(a+b)*c");
	p.ToPostfix();
	int CntVal = p.CountVal();
	double *res= new double[CntVal];
	for (int i = 0; i < CntVal; i++)
	{
		res[i] = i ;
	}
	double tmp = p.Calculate(res);
	EXPECT_TRUE(tmp==2);
}
TEST(TPostfix, can_check_priority)
{
	TPostfix p("(a+b)*c");
	char elem1 = '+', elem2 = '*';	
	EXPECT_TRUE(p.Priority(elem1)< p.Priority(elem2));
}
TEST(TPostfix, can_count_length_infix_form)
{
	TPostfix p("(a+b)*c");
	int res = p.GetLen();
	EXPECT_EQ(7, res);
}
TEST(TPostfix, can_count_the_amount_variables)
{
	TPostfix p("(a+b)*c");
	int res=p.CountVal();
	EXPECT_EQ(3, res);
}