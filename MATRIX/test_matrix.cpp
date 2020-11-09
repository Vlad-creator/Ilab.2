#include "Matrix.h"
#include "gtest/gtest.h"

TEST (equal , test) {
	std::vector<int> v_1 = {1 , 2 , 3 , 4 , 456 , 33 , 20 , 34};
	std::vector<int> v_2 = {1 , 2 , 3 , 4 , 456 , 33 , 23 , 34};
	matrix<int> test_1(4 , 2 , v_1.begin() , v_1.end());
	matrix<int> test_2(4 , 2 , v_2.begin() , v_2.end());
    EXPECT_EQ (0, test_1 == test_2);

	std::vector<int> v_3 = {1 , 2 , 3 , 4};
	std::vector<int> v_4 = {1 , 2 , 3 , 4};
	matrix<int> test_3(2 , 2 , v_3.begin() , v_3.end());
	matrix<int> test_4(2 , 2 , v_4.begin() , v_4.end());
    EXPECT_EQ (1, test_3 == test_4);

    std::vector<int> v_5 = {1 , 2 , 3 , 4 , 456 , 33 , 23 , 34};
	std::vector<int> v_6 = {1 , 2 , 3 , 5 , 456 , 33 , 23 , 34};
	matrix<int> test_5(4 , 2 , v_5.begin() , v_5.end());
	matrix<int> test_6(4 , 2 , v_6.begin() , v_6.end());
    EXPECT_EQ (0, test_5 == test_6);

    std::vector<int> v_7 = {1 , 2 , 3 , 5 , 456 , 33 , 89 , 21};
	std::vector<int> v_8 = {1 , 2 , 3 , 5 , 456 , 33 , 89 , 21};
	matrix<int> test_7(2 , 4 , v_7.begin() , v_7.end());
	matrix<int> test_8(2 , 4 , v_8.begin() , v_8.end());
    EXPECT_EQ (1, test_7 == test_8);
};

TEST (no_equal , test) {
	std::vector<int> v_1 = {1 , 2 , 3 , 4 , 456 , 33 , 20 , 34};
	std::vector<int> v_2 = {1 , 2 , 3 , 4 , 456 , 33 , 23 , 34};
	matrix<int> test_1(4 , 2 , v_1.begin() , v_1.end());
	matrix<int> test_2(4 , 2 , v_2.begin() , v_2.end());
    EXPECT_EQ (1, test_1 != test_2);

	std::vector<int> v_3 = {1 , 2 , 3 , 4};
	std::vector<int> v_4 = {1 , 2 , 3 , 4};
	matrix<int> test_3(2 , 2 , v_3.begin() , v_3.end());
	matrix<int> test_4(2 , 2 , v_4.begin() , v_4.end());
    EXPECT_EQ (0, test_3 != test_4);

    std::vector<int> v_5 = {1 , 2 , 3 , 4 , 456 , 33 , 23 , 34};
	std::vector<int> v_6 = {1 , 2 , 3 , 5 , 456 , 33 , 23 , 34};
	matrix<int> test_5(4 , 2 , v_5.begin() , v_5.end());
	matrix<int> test_6(4 , 2 , v_6.begin() , v_6.end());
    EXPECT_EQ (1, test_5 != test_6);

    std::vector<int> v_7 = {1 , 2 , 3 , 5 , 456 , 33 , 89 , 21};
	std::vector<int> v_8 = {1 , 2 , 3 , 5 , 456 , 33 , 89 , 21};
	matrix<int> test_7(2 , 4 , v_7.begin() , v_7.end());
	matrix<int> test_8(2 , 4 , v_8.begin() , v_8.end());
    EXPECT_EQ (0, test_7 != test_8);
};

TEST (oper_plus_eq , test) { 
	std::vector<int> v_1 = {1 , 2 , 3 , 4};
	std::vector<int> v_2 = {1 , 2 , 3 , 4};
	std::vector<int> v_res = {2 , 4 , 6 , 8};
	matrix<int> test_1(2 , 2 , v_1.begin() , v_1.end());
	matrix<int> test_2(2 , 2 , v_2.begin() , v_2.end());
	matrix<int> test_res_1(2 , 2 , v_res.begin() , v_res.end());
    EXPECT_EQ (1, test_res_1 == (test_1 += test_2));

    v_1 = {2 , 3 , 4 , 5};
    v_2 = {0 , 0 , 0 , 0};
    v_res = {2 , 3 , 4 , 5};
    matrix<int> test_3(2 , 2 , v_1.begin() , v_1.end());
	matrix<int> test_4(2 , 2 , v_2.begin() , v_2.end());
	matrix<int> test_res_2(2 , 2 , v_res.begin() , v_res.end());
	EXPECT_EQ (1, test_res_2 == (test_3 += test_4));

	v_1 = {156 , 3456 , 409 , -68};
    v_2 = {-36 , -456 , -9 , 8};
    v_res = {120 , 3000 , 400 , -60};
    matrix<int> test_5(2 , 2 , v_1.begin() , v_1.end());
	matrix<int> test_6(2 , 2 , v_2.begin() , v_2.end());
	matrix<int> test_res_3(2 , 2 , v_res.begin() , v_res.end());
	EXPECT_EQ (1, test_res_3 == (test_5 += test_6));

	v_1 = {156 , 3456 , 409 , -68 , 3345 , 213 , 34 , 345 , 1223 , 4564};
    v_2 = {-36 , -456 , -9 , 8 , -45 , 7 , 6 , 15 , -1223 , -1564};
    v_res = {120 , 3000 , 400 , -60 , 3300 , 220 , 40 , 360 , 0 , 3000};
    matrix<int> test_7(5 , 2 , v_1.begin() , v_1.end());
	matrix<int> test_8(5 , 2 , v_2.begin() , v_2.end());
	matrix<int> test_res_4(5 , 2 , v_res.begin() , v_res.end());
	EXPECT_EQ (1, test_res_4 == (test_7 += test_8));
};

TEST (oper_minus_eq , test) { 
	std::vector<int> v_1 = {1 , 2 , 3 , 4};
	std::vector<int> v_2 = {1 , 2 , 3 , 4};
	std::vector<int> v_res = {0 , 0 , 0 , 0};
	matrix<int> test_1(2 , 2 , v_1.begin() , v_1.end());
	matrix<int> test_2(2 , 2 , v_2.begin() , v_2.end());
	matrix<int> test_res_1(2 , 2 , v_res.begin() , v_res.end());
    EXPECT_EQ (1, test_res_1 == (test_1 -= test_2));

    v_1 = {2 , 3 , 4 , 5};
    v_2 = {0 , 0 , 0 , 0};
    v_res = {2 , 3 , 4 , 5};
    matrix<int> test_3(2 , 2 , v_1.begin() , v_1.end());
	matrix<int> test_4(2 , 2 , v_2.begin() , v_2.end());
	matrix<int> test_res_2(2 , 2 , v_res.begin() , v_res.end());
	EXPECT_EQ (1, test_res_2 == (test_3 -= test_4));

	v_1 = {156 , 3456 , 409 , -68};
    v_2 = {36 , 456 , 9 , -8};
    v_res = {120 , 3000 , 400 , -60};
    matrix<int> test_5(2 , 2 , v_1.begin() , v_1.end());
	matrix<int> test_6(2 , 2 , v_2.begin() , v_2.end());
	matrix<int> test_res_3(2 , 2 , v_res.begin() , v_res.end());
	EXPECT_EQ (1, test_res_3 == (test_5 -= test_6));

	v_1 = {156 , 3456 , 409 , -68 , 3345 , 213 , 34 , 345 , 1223 , 4564};
    v_2 = {36 , 456 , 9 , -8 , 45 , -7 , -6 , -15 , 1223 , 1564};
    v_res = {120 , 3000 , 400 , -60 , 3300 , 220 , 40 , 360 , 0 , 3000};
    matrix<int> test_7(5 , 2 , v_1.begin() , v_1.end());
	matrix<int> test_8(5 , 2 , v_2.begin() , v_2.end());
	matrix<int> test_res_4(5 , 2 , v_res.begin() , v_res.end());
	EXPECT_EQ (1, test_res_4 == (test_7 -= test_8));
};

TEST (oper_um_eq , test) { 
	std::vector<int> v_1 = {1 , 2 , 3 , 4};
	std::vector<int> v_2 = {1 , 2 , 3 , 4};
	std::vector<int> v_res = {1 , 4 , 9 , 16};
	matrix<int> test_1(2 , 2 , v_1.begin() , v_1.end());
	matrix<int> test_2(2 , 2 , v_2.begin() , v_2.end());
	matrix<int> test_res_1(2 , 2 , v_res.begin() , v_res.end());
    EXPECT_EQ (1, test_res_1 == (test_1 *= test_2));

    v_1 = {2 , 3 , 4 , 5};
    v_2 = {0 , 0 , 0 , 0};
    v_res = {0 , 0 , 0 , 0};
    matrix<int> test_3(2 , 2 , v_1.begin() , v_1.end());
	matrix<int> test_4(2 , 2 , v_2.begin() , v_2.end());
	matrix<int> test_res_2(2 , 2 , v_res.begin() , v_res.end());
	EXPECT_EQ (1, test_res_2 == (test_3 *= test_4));

	v_1 = {156 , 3456 , 409 , -68};
    v_2 = {0 , 1 , 0 , 0};
    v_res = {0 , 3456 , 0 , 0};
    matrix<int> test_5(2 , 2 , v_1.begin() , v_1.end());
	matrix<int> test_6(2 , 2 , v_2.begin() , v_2.end());
	matrix<int> test_res_3(2 , 2 , v_res.begin() , v_res.end());
	EXPECT_EQ (1, test_res_3 == (test_5 *= test_6));

	v_1 = {156 , 3456 , 409 , -68 , 3345 , 213 , 34 , 345 , 1223 , 4564};
    v_2 = {0 , 1 , 0 , 1 , -1 , 0 , 0 , 0 , 1 , 1};
    v_res = {0 , 3456 , 0 , -68 , -3345 , 0 , 0 , 0 , 1223 , 4564};
    matrix<int> test_7(5 , 2 , v_1.begin() , v_1.end());
	matrix<int> test_8(5 , 2 , v_2.begin() , v_2.end());
	matrix<int> test_res_4(5 , 2 , v_res.begin() , v_res.end());
	EXPECT_EQ (1, test_res_4 == (test_7 *= test_8));
};

TEST (eq , test) {
	std::vector<int> v_1 = {1 , 2 , 3 , 4};
	matrix<int> test_1(2 , 2 , v_1.begin() , v_1.end());
	matrix<int> test1(2 , 2);
	matrix<int> test_res_1(2 , 2 , v_1.begin() , v_1.end());
    EXPECT_EQ (1, test_res_1 == (test1 = test_1));

    v_1 = {156 , 3456 , 409 , -68 , 3345 , 213 , 34 , 345 , 1223 , 4564};
    matrix<int> test_2(5 , 2 , v_1.begin() , v_1.end());
    matrix<int> test2(5 , 2);
    matrix<int> test_res_2(5 , 2 , v_1.begin() , v_1.end());
    EXPECT_EQ (1, test_res_2 == (test2 = test_2));
};

int main()
{
	matrix<int> test_1(3 , 2);
	matrix<int> test_2(2 , 5);
	test_1.fill_M();
	test_2.fill_M();
	matrix<int> res = test_1[test_2];
	res.print_M();
	return 0;
}

//-lgtest -lgtest_main -lpthread