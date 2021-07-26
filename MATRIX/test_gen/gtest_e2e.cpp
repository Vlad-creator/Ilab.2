#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "../Matrix/Matrix.h"
#include "gtest/gtest.h"

using namespace bfr;

TEST (determinant , main_test_1)
{
	FILE* file = fopen("../tests_e2e/test1" , "r");
	FILE* answ = fopen("../tests_e2e/test_answer1" , "r");

	if ((file == NULL) || (answ == NULL))
	{
		FAIL();
	}

	size_t N = 0;
	int ans = 0;
	int res_per = 0;
	fscanf(file , "%zu" , &N);
	fscanf(answ , "%d" , &ans);
	bfr::matrix<int> test{N , N};
	
	for (size_t i = 0 ; i < N ; ++i)
		for (size_t j = 0 ; j < N ; ++j)
			fscanf(file , "%d" , &test[i][j]);

	try
	{
		res_per = test.determinant();
	}

	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}

	fclose(file);
	fclose(answ);

	EXPECT_EQ (1, ans == res_per);
}

TEST (determinant , main_test_2)
{
	FILE* file = fopen("../tests_e2e/test2" , "r");
	FILE* answ = fopen("../tests_e2e/test_answer2" , "r");

	if ((file == NULL) || (answ == NULL))
	{
		FAIL();
	}

	size_t N = 0;
	int ans = 0;
	int res_per = 0;
	fscanf(file , "%zu" , &N);
	fscanf(answ , "%d" , &ans);
	bfr::matrix<int> test{N , N};
	
	for (size_t i = 0 ; i < N ; ++i)
		for (size_t j = 0 ; j < N ; ++j)
			fscanf(file , "%d" , &test[i][j]);

	try
	{
		res_per = test.determinant();
	}

	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}

	fclose(file);
	fclose(answ);

	EXPECT_EQ (1, ans == res_per);
}

TEST (determinant , main_test_3)
{
	FILE* file = fopen("../tests_e2e/test3" , "r");
	FILE* answ = fopen("../tests_e2e/test_answer3" , "r");

	if ((file == NULL) || (answ == NULL))
	{
		FAIL();
	}

	size_t N = 0;
	int ans = 0;
	int res_per = 0;
	fscanf(file , "%zu" , &N);
	fscanf(answ , "%d" , &ans);
	bfr::matrix<int> test{N , N};
	
	for (size_t i = 0 ; i < N ; ++i)
		for (size_t j = 0 ; j < N ; ++j)
			fscanf(file , "%d" , &test[i][j]);

	try
	{
		res_per = test.determinant();
	}

	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}

	fclose(file);
	fclose(answ);

	EXPECT_EQ (1, ans == res_per);
}

TEST (determinant , main_test_4)
{
	FILE* file = fopen("../tests_e2e/test4" , "r");
	FILE* answ = fopen("../tests_e2e/test_answer4" , "r");

	if ((file == NULL) || (answ == NULL))
	{
		FAIL();
	}

	size_t N = 0;
	int ans = 0;
	int res_per = 0;
	fscanf(file , "%zu" , &N);
	fscanf(answ , "%d" , &ans);
	bfr::matrix<int> test{N , N};
	
	for (size_t i = 0 ; i < N ; ++i)
		for (size_t j = 0 ; j < N ; ++j)
			fscanf(file , "%d" , &test[i][j]);

	try
	{
		res_per = test.determinant();
	}

	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}

	fclose(file);
	fclose(answ);

	EXPECT_EQ (1, ans == res_per);
}

TEST (determinant , main_test_5)
{
	FILE* file = fopen("../tests_e2e/test5" , "r");
	FILE* answ = fopen("../tests_e2e/test_answer5" , "r");

	if ((file == NULL) || (answ == NULL))
	{
		FAIL();
	}

	size_t N = 0;
	int ans = 0;
	int res_per = 0;
	fscanf(file , "%zu" , &N);
	fscanf(answ , "%d" , &ans);
	bfr::matrix<int> test{N , N};
	
	for (size_t i = 0 ; i < N ; ++i)
		for (size_t j = 0 ; j < N ; ++j)
			fscanf(file , "%d" , &test[i][j]);

	try
	{
		res_per = test.determinant();
	}

	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}

	fclose(file);
	fclose(answ);

	EXPECT_EQ (1, ans == res_per);
}

TEST (determinant , main_test_6)
{
	FILE* file = fopen("../tests_e2e/test6" , "r");
	FILE* answ = fopen("../tests_e2e/test_answer6" , "r");

	if ((file == NULL) || (answ == NULL))
	{
		FAIL();
	}

	size_t N = 0;
	int ans = 0;
	int res_per = 0;
	fscanf(file , "%zu" , &N);
	fscanf(answ , "%d" , &ans);
	bfr::matrix<int> test{N , N};
	
	for (size_t i = 0 ; i < N ; ++i)
		for (size_t j = 0 ; j < N ; ++j)
			fscanf(file , "%d" , &test[i][j]);

	try
	{
		res_per = test.determinant();
	}

	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}

	fclose(file);
	fclose(answ);

	EXPECT_EQ (1, ans == res_per);
}

TEST (determinant , main_test_7)
{
	FILE* file = fopen("../tests_e2e/test7" , "r");
	FILE* answ = fopen("../tests_e2e/test_answer7" , "r");

	if ((file == NULL) || (answ == NULL))
	{
		FAIL();
	}

	size_t N = 0;
	int ans = 0;
	int res_per = 0;
	fscanf(file , "%zu" , &N);
	fscanf(answ , "%d" , &ans);
	bfr::matrix<int> test{N , N};
	
	for (size_t i = 0 ; i < N ; ++i)
		for (size_t j = 0 ; j < N ; ++j)
			fscanf(file , "%d" , &test[i][j]);

	try
	{
		res_per = test.determinant();
	}

	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}

	fclose(file);
	fclose(answ);

	EXPECT_EQ (1, ans == res_per);
}

TEST (determinant , main_test_8)
{
	FILE* file = fopen("../tests_e2e/test8" , "r");
	FILE* answ = fopen("../tests_e2e/test_answer8" , "r");

	if ((file == NULL) || (answ == NULL))
	{
		FAIL();
	}

	size_t N = 0;
	int ans = 0;
	int res_per = 0;
	fscanf(file , "%zu" , &N);
	fscanf(answ , "%d" , &ans);
	bfr::matrix<int> test{N , N};
	
	for (size_t i = 0 ; i < N ; ++i)
		for (size_t j = 0 ; j < N ; ++j)
			fscanf(file , "%d" , &test[i][j]);

	try
	{
		res_per = test.determinant();
	}

	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}

	fclose(file);
	fclose(answ);

	EXPECT_EQ (1, ans == res_per);
}

TEST (determinant , main_test_9)
{
	FILE* file = fopen("../tests_e2e/test9" , "r");
	FILE* answ = fopen("../tests_e2e/test_answer9" , "r");

	if ((file == NULL) || (answ == NULL))
	{
		FAIL();
	}

	size_t N = 0;
	int ans = 0;
	int res_per = 0;
	fscanf(file , "%zu" , &N);
	fscanf(answ , "%d" , &ans);
	bfr::matrix<int> test{N , N};
	
	for (size_t i = 0 ; i < N ; ++i)
		for (size_t j = 0 ; j < N ; ++j)
			fscanf(file , "%d" , &test[i][j]);

	try
	{
		res_per = test.determinant();
	}

	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}

	fclose(file);
	fclose(answ);

	EXPECT_EQ (1, ans == res_per);
}

TEST (determinant , main_test_10)
{
	FILE* file = fopen("../tests_e2e/test10" , "r");
	FILE* answ = fopen("../tests_e2e/test_answer10" , "r");

	if ((file == NULL) || (answ == NULL))
	{
		FAIL();
	}

	size_t N = 0;
	int ans = 0;
	int res_per = 0;
	fscanf(file , "%zu" , &N);
	fscanf(answ , "%d" , &ans);
	bfr::matrix<int> test{N , N};
	
	for (size_t i = 0 ; i < N ; ++i)
		for (size_t j = 0 ; j < N ; ++j)
			fscanf(file , "%d" , &test[i][j]);

	try
	{
		res_per = test.determinant();
	}

	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}

	fclose(file);
	fclose(answ);

	EXPECT_EQ (1, ans == res_per);
}