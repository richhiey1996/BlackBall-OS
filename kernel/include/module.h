/*
Skeleton of the different OS-modules
*/

#ifndef MODULE_H
#define MODULE_H

#include <common.h>

/*=======================================================
    DEFINE
=========================================================*/
#define MAX_MODULE_DEPENDENCY  8

/* Module IDs */
#define MODULE_VGA          100		//Done		-->Richhiey	
#define MODULE_CONSOLE      101		//Done		-->Richhiey
#define MODULE_GDT          102
#define MODULE_IDT          103
#define MODULE_PIC8259      104
#define MODULE_PIT8253      105
#define MODULE_PMM          106					//-->Aditya
#define MODULE_VMM          107					//-->Aditya
#define MODULE_HEAP         108					//-->Aditya
#define MODULE_PROCESS      109		//Done		//-->Maanav and bryceleen
#define MODULE_PS2          110					//Lenherd (status unknown)
#define MODULE_VFS          111		//TODO		// -->Richhiey
#define MODULE_USERMODE     112		//TODO

/*=======================================================
    STRUCT
=========================================================*/
typedef struct Module Module;

struct Module
{
    void    (*init) (void);
    bool    isLoaded;
    char*   moduleName;
    u32int  moduleID;
    u32int  dependencies[MAX_MODULE_DEPENDENCY];
    u32int  numberOfDependencies;
};

/*=======================================================
    FUNCTION
=========================================================*/

//Loads a given module
void Module_load(Module* module);

//Get the number of loaded modules
u32int Module_getNumberOfLoadedModules(void);

#endif