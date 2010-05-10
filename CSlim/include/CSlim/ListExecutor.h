#ifndef D_ListExecutor_H
#define D_ListExecutor_H

///////////////////////////////////////////////////////////////////////////////
//
//  ListExecutor is responsible for ...
//
///////////////////////////////////////////////////////////////////////////////
#include "SlimList.h"
#include "StatementExecutor.h"
typedef struct ListExecutor ListExecutor;

ListExecutor* ListExecutor_Create(StatementExecutor*);
void ListExecutor_Destroy(ListExecutor*);
SlimList* ListExecutor_Execute(ListExecutor*, SlimList*);

#endif  // D_ListExecutor_H
