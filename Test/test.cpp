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

TEST(TPolinom, abbreviation_first)
{
	//сокращается m and m1
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
	p1.AddMonom(m0);

	p2.AddMonom(m1);
	p2.AddMonom(m0);
	p2.AddMonom(m0);

	p3.AddMonom(m2);
	p3.AddMonom(m2);
	p1 += p2;
	EXPECT_TRUE(p3 == p1);

}

TEST(TPolinom, abbreviation_average)
{
	//сокращается m and m1
	TPolinom p1, p2, p3;
	TMonom m2, m1, m, m0;
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

	
	p1.AddMonom(m0);
	p1.AddMonom(m);
	p1.AddMonom(m0);

	
	p2.AddMonom(m0);
	p2.AddMonom(m1);
	p2.AddMonom(m0);

	p3.AddMonom(m2);
	p3.AddMonom(m2);
	p1 += p2;
	EXPECT_TRUE(p3 == p1);

}

TEST(TPolinom, abbreviation_last)
{
	//сокращается m and m1
	TPolinom p1, p2, p3;
	TMonom m2, m1, m, m0;
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


	p1.AddMonom(m0);
	p1.AddMonom(m0);
	p1.AddMonom(m);

	p2.AddMonom(m0);
	p2.AddMonom(m0);
	p2.AddMonom(m1);

	p3.AddMonom(m2);
	p3.AddMonom(m2);
	p1 += p2;
	EXPECT_TRUE(p3 == p1);

}

TEST(TPolinom, abbreviation_first_and_last)
{
	//сокращается m and m1,  m3 and m4
	TPolinom p1, p2, p3;
	TMonom m2, m1, m, m0,m3,m4,m5;
	m.coef = 10;
	m.x = 1;
	m.y = 1;
	m.z = 1;

	m1.coef = -10;
	m1.x = 1;
	m1.y = 1;
	m1.z = 1;

	m3.coef = 20;
	m3.x = 2;
	m3.y = 2;
	m3.z = 2;

	m4.coef = -20;
	m4.x = 2;
	m4.y = 2;
	m4.z = 2;

	m5.coef = 30;
	m5.x = 3;
	m5.y = 3;
	m5.z = 3;

	m2.coef = 60;
	m2.x = 3;
	m2.y = 3;
	m2.z = 3;


	p1.AddMonom(m);
	p1.AddMonom(m5);
	p1.AddMonom(m3);

	p2.AddMonom(m1);
	p2.AddMonom(m5);
	p2.AddMonom(m4);

	p3.AddMonom(m2);
	p1 += p2;
	EXPECT_TRUE(p3 == p1);

}

TEST(TPolinom, abbreviation_first_and_average)
{
	//сокращается m and m1,  m3 and m4
	TPolinom p1, p2, p3;
	TMonom m2, m1, m, m0, m3, m4, m5;
	m.coef = 10;
	m.x = 1;
	m.y = 1;
	m.z = 1;

	m1.coef = -10;
	m1.x = 1;
	m1.y = 1;
	m1.z = 1;

	m3.coef = 20;
	m3.x = 2;
	m3.y = 2;
	m3.z = 2;

	m4.coef = -20;
	m4.x = 2;
	m4.y = 2;
	m4.z = 2;

	m5.coef = 30;
	m5.x = 3;
	m5.y = 3;
	m5.z = 3;

	m2.coef = 60;
	m2.x = 3;
	m2.y = 3;
	m2.z = 3;


	p1.AddMonom(m);
	p1.AddMonom(m3);
	p1.AddMonom(m5);
	

	p2.AddMonom(m1);
	p2.AddMonom(m4);
	p2.AddMonom(m5);
	

	p3.AddMonom(m2);
	p1 += p2;
	EXPECT_TRUE(p3 == p1);

}

TEST(TPolinom, abbreviation_last_and_average)
{
	//сокращается m and m1,  m3 and m4
	TPolinom p1, p2, p3;
	TMonom m2, m1, m, m0, m3, m4, m5;
	m.coef = 10;
	m.x = 1;
	m.y = 1;
	m.z = 1;

	m1.coef = -10;
	m1.x = 1;
	m1.y = 1;
	m1.z = 1;

	m3.coef = 20;
	m3.x = 2;
	m3.y = 2;
	m3.z = 2;

	m4.coef = -20;
	m4.x = 2;
	m4.y = 2;
	m4.z = 2;

	m5.coef = 30;
	m5.x = 3;
	m5.y = 3;
	m5.z = 3;

	m2.coef = 60;
	m2.x = 3;
	m2.y = 3;
	m2.z = 3;


	p1.AddMonom(m5);
	p1.AddMonom(m);
	p1.AddMonom(m3);
	

	p2.AddMonom(m5);
	p2.AddMonom(m1);
	p2.AddMonom(m4);
	


	p3.AddMonom(m2);
	p1 += p2;
	EXPECT_TRUE(p3 == p1);

}

TEST(TPolinom, can_multiply_polinom_and_num)
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




//test monom
TEST(TMonom, can_create_monom)
{
	ASSERT_NO_THROW(TMonom m);
}

TEST(TMonom, can_ins_monom_with_pos_coef)
{
	TMonom m;
	m.x = 0;
	m.y = 0;
	m.z = 0;
	ASSERT_NO_THROW(m.coef = 1);
}

TEST(TMonom, can_ins_monom_with_neg_coef)
{
	TMonom m;
	m.x = 0;
	m.y = 0;
	m.z = 0;
	ASSERT_NO_THROW(m.coef = -1);
}



TEST(TMonom, can_compare_the_monom)
{
	TMonom m1, m2;
	m1.coef = 5;
	m1.x = 1;
	m1.y = 1;
	m1.z = 1;
	m2.coef = 7;
	m2.x = 1;
	m2.y = 1;
	m2.z = 1;
	EXPECT_EQ(m1 == m2, 1);
}

TEST(TMonom, can_compare_the_monoms)
{
	TMonom m1, m2;
	m1.coef = 5;
	m1.x = 1;
	m1.y = 1;
	m1.z = 1;
	m2.coef = 7;
	m2.x = 1;
	m2.y = 2;
	m2.z = 3;
	EXPECT_EQ(m1 != m2, true);
}

TEST(TMonom, can_compare)
{
	TMonom m1, m2;
	m1.coef = 5;
	m1.x = 1;
	m1.y = 1;
	m1.z = 1;
	m2.coef = 7;
	m2.x = 1;
	m2.y = 2;
	m2.z = 3;
	EXPECT_EQ(m1 < m2, true);
	EXPECT_EQ(m1 > m2, false);
}