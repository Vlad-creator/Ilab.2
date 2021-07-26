#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "../Matrix/Matrix.h"
#include "gtest/gtest.h"

using namespace bfr;

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

TEST (oper_matr_um , test) { 
	std::vector<int> v_1 = {1 , 2 , 3 , 4};
	std::vector<int> v_2 = {1 , 2 , 3 , 4};
	std::vector<int> v_res = {7 , 10 , 15 , 22};
	matrix<int> test_1(2 , 2 , v_1.begin() , v_1.end());
	matrix<int> test_2(2 , 2 , v_2.begin() , v_2.end());
	matrix<int> test_res_1(2 , 2 , v_res.begin() , v_res.end());
    EXPECT_EQ (1, test_res_1 == (test_1 * test_2));

    v_1 = {2 , 3 , 4 , 5};
    v_2 = {1 , 0 , 0 , 1};
    v_res = {2 , 3 , 4 , 5};
    matrix<int> test_3(2 , 2 , v_1.begin() , v_1.end());
	matrix<int> test_4(2 , 2 , v_2.begin() , v_2.end());
	matrix<int> test_res_2(2 , 2 , v_res.begin() , v_res.end());
	EXPECT_EQ (1, test_res_2 == (test_3 * test_4));

	v_1 = {156 , 3456 , 409 , -68};
    v_2 = {0 , 0 , 0 , 0};
    v_res = {0 , 0 , 0 , 0};
    matrix<int> test_5(2 , 2 , v_1.begin() , v_1.end());
	matrix<int> test_6(2 , 2 , v_2.begin() , v_2.end());
	matrix<int> test_res_3(2 , 2 , v_res.begin() , v_res.end());
	EXPECT_EQ (1, test_res_3 == (test_5 * test_6));

	v_1 = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10};
    v_2 = {11 , 12 , 13 , 14 , 15 , 16 , 17 , 18 , 19 , 20};
    v_res = {43	, 46 , 49 , 52 , 55 , 
    	     97 , 104 , 111 , 118 , 125 , 
    	     151 , 162 , 173 , 184 , 195 , 
    	     205 , 220 , 235 , 250 , 265 ,
    	     259 , 278 , 297 , 316 ,335};
    matrix<int> test_7(5 , 2 , v_1.begin() , v_1.end());
	matrix<int> test_8(2 , 5 , v_2.begin() , v_2.end());
	matrix<int> test_res_4(5 , 5 , v_res.begin() , v_res.end());
	EXPECT_EQ (1, test_res_4 == (test_7 * test_8));
};

TEST (swap_rows , test) {
	std::vector<int> v = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8};
	std::vector<int> v_res = {5 , 6 , 7 , 8 , 1 , 2 , 3 , 4};
	matrix<int> test_1(2 , 4 , v.begin() , v.end());
	matrix<int> test_res_1(2 , 4 , v_res.begin() , v_res.end());
	test_1.swap_rows(0 , 1);
	EXPECT_EQ (1, test_res_1 == test_1);

	v = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9};
	v_res = {7 , 8 , 9 , 4 , 5 , 6 , 1 , 2 , 3};
	matrix<int> test_2(3 , 3 , v.begin() , v.end());
	matrix<int> test_res_2(3 , 3 , v_res.begin() , v_res.end());
	test_2.swap_rows(0 , 2);
	EXPECT_EQ (1, test_res_2 == test_2);

	v = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 , 16};
	v_res = {1 , 2 , 3 , 4 , 13 , 14 , 15 , 16 , 9 , 10 , 11 , 12 , 5 , 6 , 7 , 8};
	matrix<int> test_3(4 , 4 , v.begin() , v.end());
	matrix<int> test_res_3(4 , 4 , v_res.begin() , v_res.end());
	test_3.swap_rows(1 , 3);
	EXPECT_EQ (1, test_res_3 == test_3);
};

TEST (negate , test){
	std::vector<int> v = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8};
	std::vector<int> v_res = {-1 , -2 , -3 , -4 , -5 , -6 , -7 , -8};
	matrix<int> test_1(2 , 4 , v.begin() , v.end());
	matrix<int> test_res_1(2 , 4 , v_res.begin() , v_res.end());
	test_1.negate();
	EXPECT_EQ (1, test_res_1 == test_1);

	v = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9};
	v_res = {-1 , -2 , -3 , -4 , -5 , -6 , -7 , -8 , -9};
	matrix<int> test_2(3 , 3 , v.begin() , v.end());
	matrix<int> test_res_2(3 , 3 , v_res.begin() , v_res.end());
	test_2.negate();
	EXPECT_EQ (1, test_res_2 == test_2);

	v = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 , 16};
	v_res = {-1 , -2 , -3 , -4 , -5 , -6 , -7 , -8 , -9 , -10 , -11 , -12 , -13 , -14 , -15 , -16};
	matrix<int> test_3(4 , 4 , v.begin() , v.end());
	matrix<int> test_res_3(4 , 4 , v_res.begin() , v_res.end());
	test_3.negate();
	EXPECT_EQ (1, test_res_3 == test_3);
};

TEST (transpose , test){
	std::vector<int> v = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8};
	std::vector<int> v_res = {1 , 5 , 2 , 6 , 3 , 7 , 4 , 8};
	matrix<int> test_1(2 , 4 , v.begin() , v.end());
	matrix<int> test_res_1(4 , 2 , v_res.begin() , v_res.end());
	matrix<int>test_1_res = (test_1.transpose());
	EXPECT_EQ (1, test_res_1 == test_1_res);

	v = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9};
	v_res = {1 , 4 , 7 , 2 , 5 , 8 , 3 , 6 , 9};
	matrix<int> test_2(3 , 3 , v.begin() , v.end());
	matrix<int> test_res_2(3 , 3 , v_res.begin() , v_res.end());
	matrix<int>test_2_res = (test_2.transpose());
	EXPECT_EQ (1, test_res_2 == test_2_res);

	v = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15};
	v_res = {1 , 6 , 11 , 2 , 7 , 12 , 3 , 8 , 13 , 4 , 9 , 14 , 5 , 10 , 15};
	matrix<int> test_3(3 , 5 , v.begin() , v.end());
	matrix<int> test_res_3(5 , 3 , v_res.begin() , v_res.end());
	matrix<int>test_3_res = (test_3.transpose());
	EXPECT_EQ (1, test_res_3 == test_3_res);
};

TEST (determinant , the_main_test)
{
	std::vector<long double> v = {1 , 2 , 3 , 4};
	matrix<long double> test_1(2 , 2 , v.begin() , v.end());
	long double res = -2;
	EXPECT_FLOAT_EQ (res , test_1.determinant());

	v = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9};
	matrix<long double> test_2(3 , 3 , v.begin() , v.end());
	res = 0;
	EXPECT_FLOAT_EQ (res , test_2.determinant());

	v = {23 , -15 , 23 , 1 , 34 , -65 , -2 , 4 , 54 , 10 , -3 , -4 , 1 , 2 , 3 , 4};
	matrix<long double> test_3(4 , 4 , v.begin() , v.end());
	res = 385719;
	EXPECT_FLOAT_EQ (res , test_3.determinant());

	v = {-2 , 1 , 2 , 0 , -2 , 0 , 1 , -3 , 4 , -4 , -3 , 2 , -5 , 4 , -2 , 1 , -5 , 1 , -3 , 1 , -4 , 3 , 2 , 4 , -3};
	matrix<long double> test_4(5 , 5 , v.begin() , v.end());
	res = 907;
	EXPECT_FLOAT_EQ (res , test_4.determinant());

	v = {-2 , 1 ,  2 , 0 , -2 , 0 , 1 , -3 , 4 , -4 , -3 , 2 , -5 , 4 , -2 , 1 , -5 , 1 , -3 , 1 , -4 , 3 , 2 , 4 , -3 , -5 , -3 , -2 , 2 , 0 , 4 , -3 , -3 , 3 , 4 , 2};
	matrix<long double> test_5(6 , 6 , v.begin() , v.end());
	res = 10060;
	EXPECT_FLOAT_EQ (res , test_5.determinant());

	v = {-2 , 1 , 2 , 0 , -2 , 0 , 1 , -3 , 4 , -4 , -3 , 2 , -5 , 4 , -2 , 1 , -5 , 1 , -3 , 1 , -4 , 3 , 2 , 4 , -3 , -5 , -3 , -2 , 2 , 0 , 4 , -3 , -3 , 3 , 4 , 2 , -2 , 1 , -4 , -3 , 4 , -2 , -4 , 4 , -1 , 2 , 3 , -1 , 0};
	matrix<long double> test_6(7 , 7 , v.begin() , v.end());
	res = -123437;
	EXPECT_FLOAT_EQ (res , test_6.determinant());
};

//-lgtest -lgtest_main -lpthread