//!
//! @file 		Clide-Port.c
//! @author 	Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @date 		2012/03/19
//! @brief 		Command-line style communications protocol
//! @details
//!		<b>Last Modified:			</b> 2013/05/14					\n
//!		<b>File Version:			</b> v1.0.0.0					\n
//!		<b>Company:					</b> CladLabs					\n
//!		<b>Project:					</b> Free Code Libraries		\n
//!		<b>Language:				</b> C++						\n
//!		<b>Compiler:				</b> GCC						\n
//! 	<b>uC Model:				</b> PSoC5						\n
//!		<b>Computer Architecture:	</b> ARM						\n
//! 	<b>Operating System:		</b> FreeRTOS v7.2.0			\n
//!		<b>Documentation Format:	</b> Doxygen					\n
//!		<b>License:					</b> GPLv3						\n
//!
//! See Clide-Port.h for more information.
//!

//===============================================================================================//
//========================================= INCLUDES ============================================//
//===============================================================================================//

#ifdef __cplusplus
extern "C" {
#endif

// PSoC includes
#include <device.h>

// System includes
#include <stdio.h>		// snprintf()
#include <stdlib.h>		// realloc(), malloc(), free()
#include <cctype>		// isalnum() 

#include <getopt.h>		// getopt()	

// FreeRTOS includes
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "./FreeRTOS/FreeRTOS-Plus-CLI/FreeRTOS_CLI.h"

#ifdef __cplusplus
}
#endif

// User includes
#include "./Comms/include/UartDebug.h"
#include "./Comms/include/UartComms.h"

void* operator new(size_t size) 
{ 
	return malloc(size); 
} 

void operator delete(void* ptr) 
{ 
	free(ptr); 
} 

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace Clide
{

	//===============================================================================================//
	//==================================== PRIVATE DEFINES ==========================================//
	//===============================================================================================//

	// none

	//===============================================================================================//
	//=================================== PRIVATE TYPEDEF's =========================================//
	//===============================================================================================//

	// none

	//===============================================================================================//
	//============================= PRIVATE VARIABLES/STRUCTURES ====================================//
	//===============================================================================================//

	// none

	//===============================================================================================//
	//================================== PRIVATE FUNCTION PROTOTYPES ================================//
	//===============================================================================================//

	// none

	//===============================================================================================//
	//===================================== PUBLIC FUNCTIONS ========================================//
	//===============================================================================================//



	// Port specific
	void DebugPrint(const char* msg) 
	{
		UartDebug::PutString(msg);
	}

	// Port specific
	void CmdLinePrint(const char* msg)
	{
		UartComms::PutString(msg);
	}

	//===============================================================================================//
	//==================================== PRIVATE FUNCTIONS ========================================//
	//===============================================================================================//

	// none

} // namespace Clide