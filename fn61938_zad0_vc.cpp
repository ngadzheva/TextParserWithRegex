/**
 *
 * Solution to homework task
 * Data Structures Course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Nevena Mihaylova Gadzheva
 * @idnumber 61938
 * @task 0
 * @compiler VC
 *
*/

#include "stdafx.h"
#include<iostream>
#include<assert.h>

using namespace std;

#include"Queries.h"

#include"StackTest.hpp"
#include"AutomataTest.hpp"
#include"RegexToAutomataTest.hpp"
#include"StringTest.hpp"

int main(int argc, char* argv[])
{
	assert(argc < 4);

	Queries q;
	q.Read(argv[1], argv[2]);

	system("pause");
    return 0;
}

