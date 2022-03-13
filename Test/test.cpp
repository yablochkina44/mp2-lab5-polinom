#include "pch.h"
#include "../mp2-lab5-polinom/TPolinom.h"

//test headlist
TEST(THeadList, can_create_list)
{
	ASSERT_NO_THROW(true, THeadList<int> list);
}
TEST(THeadList, can_insert_first)
{
	THeadList<int> list;

	ASSERT_NO_THROW(true, list.InsFirst(1));
}
TEST(THeadList, can_del_first)
{
	THeadList<int> list;
	list.InsFirst(1);
	ASSERT_NO_THROW(true, list.DeleteFirst);
}
TEST(THeadList, can_insert_last)
{
	THeadList<int> list;

	ASSERT_NO_THROW(true, list.InsLast(1));
}
TEST(THeadList, can_del_last)
{
	THeadList<int> list;
	list.InsFirst(1);
	ASSERT_NO_THROW(true, list.DeleteLast);
}
TEST(THeadList, can_insert_current)
{
	THeadList<int> list;
	list.InsFirst(1);
	list.InsLast(2);
	list.InsLast(3);
	list.InsLast(4);

	ASSERT_NO_THROW(true, list.InsCurrent(0));
}
TEST(THeadList, can_delete_current)
{
	THeadList<int> list;
	list.InsFirst(1);
	list.InsLast(2);
	list.InsLast(3);
	list.InsLast(4);
	ASSERT_NO_THROW(true, list.DeleteCurrent());
}

TEST(THeadList, can_get_value_current)
{
	THeadList<int> list;
	list.InsFirst(1);
	list.InsLast(2);
	list.InsLast(3);
	list.InsCurrent(0);
	EXPECT_TRUE(0 == list.GetValueCurrent());
}
TEST(THeadList, can_set_value_current)
{
	THeadList<int> list;
	list.InsFirst(1);
	list.InsLast(2);
	list.InsLast(3);
	list.InsCurrent(5);
	list.SetValueCurrent(0);
	EXPECT_TRUE(0 == list.GetValueCurrent());
}
TEST(THeadList, cant_delete_first_in_empty_list)
{
	THeadList<int> list;
	ASSERT_ANY_THROW(list.DeleteFirst());
}
TEST(THeadList, cant_delete_current_in_empty_list)
{
	THeadList<int> list;
	ASSERT_ANY_THROW(list.DeleteCurrent());
}



//test polinom
TEST(TPolinom, can_create_polinom)
{
	ASSERT_NO_THROW(true, TPolinom p);
}
TEST(TPolinom, can_add_polinoms_without_abbreviations)
{
	TPolinom p1, p2, p3;
	TMonom m,m0;
	m.coef = 10;
	m.x = 1;
	m.y = 1;
	m.z = 1;

	m0.coef = 20;
	m0.x = 1;
	m0.y = 1;
	m0.z = 1;

	p1.AddMonom(m);
	p2.AddMonom(m);
	
	p3.AddMonom(m0);
	p1 += p2;
	EXPECT_TRUE(p3==p1);
	
}

TEST(TPolinom, can_add_polinoms_with_the_abbreviation)
{
	TPolinom p1, p2, p3;
	TMonom m2,m1,m, m0;
	m.coef = 10;
	m.x = 1;
	m.y = 1;
	m.z = 1;

	m1.coef = -10;
	m1.x = 1;
	m1.y = 1;
	m1.z = 1;

	m0.coef = 20;
	m0.x = 2;
	m0.y = 2;
	m0.z = 2;

	m2.coef = 40;
	m2.x = 2;
	m2.y = 2;
	m2.z = 2;

	p1.AddMonom(m);
	p1.AddMonom(m0);
	p2.AddMonom(m1);
	p2.AddMonom(m0);

	p3.AddMonom(m2);
	p1 += p2;
	EXPECT_TRUE(p3 == p1);

}
TEST(TPolinom, can_multiply_polinom_and_nu)
{
	TPolinom p1, p2;
	TMonom m, m0;
	m.coef = 10;
	m.x = 1;
	m.y = 1;
	m.z = 1;

	p1.AddMonom(m);
	p1 *= 2;

	m0.coef = 20;
	m0.x = 1;
	m0.y = 1;
	m0.z = 1;
	p2.AddMonom(m0);
	EXPECT_TRUE(p2 == p1);

}