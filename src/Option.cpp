//!
//! @file 			Option.hpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2013/04/02
//! @last-modified 	2014/04/03
//! @brief 		 	The option class enables used of 'optional' parameters in the command-line interface.
//! @details
//!					See README.rst in repo root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//========================================= INCLUDES ============================================//
//===============================================================================================//

// System includes
#include <stdio.h>		// snprintf()
#include <stdlib.h>		// realloc(), malloc(), free()
#include <cctype>		// isalnum()
#include <string.h>		// strlen()

// User includes
#include "../include/Config.hpp"
#include "../include/Print.hpp"
#include "../include/Option.hpp"
#include "../include/Param.hpp"
#include "../include/Cmd.hpp"

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace Clide
{

	//===============================================================================================//
	//===================================== MEMBER FUNCTIONS ========================================//
	//===============================================================================================//

	Option::Option(
		const char shortName,
		std::string longName,
		bool (*callBackFunc)(char *optionVal),
		std::string description,
		bool associatedValue)
	{
		// Base constructor
		
		#if(clide_ENABLE_DEBUG_CODE == 1)	
			Print::PrintDebugInfo("CLIDE: Base option constructor called.\r\n",
					Print::DebugPrintingLevel::VERBOSE);
		#endif

		Init(
				shortName,
				longName,
				callBackFunc,
				description,
				associatedValue);
	}
	
	Option::Option(
		std::string longName,
		bool (*callBackFunc)(char *optionVal),
		std::string description)
	{	
		// Simplified constructor. No short name.
		
		#if(clide_ENABLE_DEBUG_CODE == 1)	
			Print::PrintDebugInfo("CLIDE: Simplified option constructor called (no short name).\r\n",
					Print::DebugPrintingLevel::VERBOSE);
		#endif
		Init(
			'\0',
			longName,
			callBackFunc,
			description,
			false);
	}
	
	Option::Option(
		const char shortName,
		bool (*callBackFunc)(char *optionVal),
		std::string description)
	{	
		// Simplified constructor. No long name.
		
		#if(clide_ENABLE_DEBUG_CODE == 1)	
			Print::PrintDebugInfo("CLIDE: Simplified option constructor called (no long name).\r\n",
					Print::DebugPrintingLevel::VERBOSE);
		#endif
		Init(
			shortName,
			std::string(""),
			callBackFunc,
			description,
			false);
	}
	
	Option::~Option()
	{
		// Destructor
		#if(clide_ENABLE_DEBUG_CODE == 1)	
			Print::PrintDebugInfo("CLIDE: Option destructor called.\r\n",
					Print::DebugPrintingLevel::VERBOSE);
		#endif
		
		// Free memory
		//free(this->longName);
		//free(this->description);
	}
	
	//===============================================================================================//
	//==================================== PRIVATE FUNCTIONS ========================================//
	//===============================================================================================//

	void Option::Init(
		const char shortName,
		std::string longName,
		bool (*callBackFunc)(char *optionVal),
		std::string description,
		bool associatedValue)
	{
		#if(clide_ENABLE_DEBUG_CODE == 1)	
			Print::PrintDebugInfo("CLIDE: Option constructor called.\r\n",
					Print::DebugPrintingLevel::VERBOSE);
		#endif
		
		if(longName.length() > clide_MAX_NAME_LENGTH)
		{
			#if(clide_ENABLE_DEBUG_CODE == 1)
				// Description too long, do not save it
				Print::PrintError("CLIDE: ERROR: 'Long' option name was too long.\r\n");
			#endif

			return;
		}
		
		// Check too-long description
		if(description.length())
		{
			if(description.length() > clide_MAX_DESCRIPTION_LENGTH)
			{
				#if(clide_ENABLE_DEBUG_CODE == 1)	
					// Description too long, do not save it
					Print::PrintError("CLIDE: ERROR: Option description was too long.\r\n");
				#endif
				
				return;
			}
		}
	
		// NAME

		#if(clide_ENABLE_DEBUG_CODE == 1)
			Print::PrintDebugInfo("CLIDE: Saving short name.\r\n",
					Print::DebugPrintingLevel::VERBOSE);
		#endif

		// Store short name directly (only one char, no memory alloc needed)
		this->shortName = shortName;
		
		#if(clide_ENABLE_DEBUG_CODE == 1)
			Print::PrintDebugInfo("CLIDE: Saving long name.\r\n",
					Print::DebugPrintingLevel::VERBOSE);
		#endif

		// Copy long name
		this->longName = longName;
		
		// DECRIPTION

		#if(clide_ENABLE_DEBUG_CODE == 1)
			Print::PrintDebugInfo("CLIDE: Saving description.\r\n",
					Print::DebugPrintingLevel::VERBOSE);
		#endif

		// Copy description
		this->description = description;
		
		// CALLBACK
		this->callBackFunc = callBackFunc;
		
		// DETECTED?
		this->isDetected = false;
		
		// ASSOCIATED VALUE?
		this->associatedValue = associatedValue;
		
		#if(clide_ENABLE_DEBUG_CODE == 1)	
			Print::PrintDebugInfo("CLIDE: Option constructor finished.\r\n",
					Print::DebugPrintingLevel::VERBOSE);
		#endif

	}

} // namespace Clide

// EOF
