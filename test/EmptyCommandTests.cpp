//!
//! @file 			EmptyCommandTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2013/07/04
//! @last-modified 	2014/04/03
//! @brief 			Contains test functions for Clide command options with negative numbers.
//! @details
//!					See README.rst in root dir for more info.

#include "../api/Clide.hpp"

#include "UnitTest++/UnitTest++/UnitTest++.h"

namespace ClideTest
{
	SUITE(EmptyCommandTests)
	{
		using namespace Clide;

		bool Callback(Cmd *cmd)
		{	
			return true;
		}
		
		TEST(EmptyCommandTest)
		{
			Rx rxController;
			
			Cmd cmdTest("test", &Callback, "A test command.");
			Option testOption('a', "", NULL, "A test option.", true);
			
			// Register option
			cmdTest.RegisterOption(&testOption);
			
			// Register command
			rxController.RegisterCmd(&cmdTest);
			
			// Create fake input buffer
			char rxBuff1[50] = "";
			
			// Run rx controller
			rxController.Run(rxBuff1);
			
			CHECK_EQUAL(false, testOption.isDetected);
			
			// Create fake input buffer
			char rxBuff2[50] = "test";
			
			// Run rx controller
			rxController.Run(rxBuff2);
			
			CHECK_EQUAL(false, testOption.isDetected);
		}
	} // SUITE(EmptyCommandTests)
} // namespace ClideTest
