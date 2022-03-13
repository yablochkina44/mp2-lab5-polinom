#include "../mp2-lab5-polinom/THeadList.h"
//#include "THeadList.h"


#include "gtest.h"

TEST(THeadList, can_create_headlist)
{
	ASSERT_NO_THROW(THeadList<int> list);
}


	// нет ошибки ASSERT_NO_THROW(TMatrix<int> m1(m));

	// не равны EXPECT_NE(a, b);

	// равны EXPECT_EQ(c, a);

	//ошибка ASSERT_ANY_THROW(a = a - b);


