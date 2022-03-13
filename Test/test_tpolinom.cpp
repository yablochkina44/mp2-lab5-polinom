#include "../mp2-lab5-polinom/TPolinom.h"

#include "gtest.h"

TEST(TPolinom, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TPolinom polinom);
}


//TEST(TVector, copied_vector_is_equal_to_source_one)
//{
//	//скопированный вектор равен исходному
//	TVector <int> a(5);
//	for (int i = 0; i < 5; i++)
//		a[i] = i;
//	TVector<int> b(a);
//	EXPECT_EQ(a, b);
//}
//
//TEST(TVector, copied_vector_has_its_own_memory)
//{
//	//скопированный вектор имеет свою собственную память
//	TVector <int> a(5);
//	for (int i = 0; i < 5; i++)
//		a[i] = i;
//	TVector<int> b(a);
//	a[0] = 5;
//	EXPECT_NE(a, b);
//}

