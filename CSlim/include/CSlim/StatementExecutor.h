#ifndef D_StatementExecutor_H
#define D_StatementExecutor_H

///////////////////////////////////////////////////////////////////////////////
//
//  StatementExecutor is responsible for ...
//
///////////////////////////////////////////////////////////////////////////////
#include "SlimList.h"

typedef struct StatementExecutor StatementExecutor;
typedef void(*Fixture)(StatementExecutor*);
typedef void*(*Constructor)(StatementExecutor*, SlimList*);
typedef void(*Destructor)(void *);
typedef char*(*Method)(void *, SlimList*);

StatementExecutor* StatementExecutor_Create(void);
void StatementExecutor_Destroy(StatementExecutor*);

void StatementExecutor_AddFixture(StatementExecutor* executor, Fixture);
void StatementExecutor_RegisterFixture(StatementExecutor*, const char * className, Constructor, Destructor);
void StatementExecutor_RegisterMethod(StatementExecutor*, const char * className, const char * methodName, Method);

char* StatementExecutor_Make(StatementExecutor*, const char* instanceName, const char* className, SlimList* args);
char* StatementExecutor_Call(StatementExecutor*, const char* instanceName, const char* methodName, SlimList*);
void* StatementExecutor_Instance(StatementExecutor*, const char* instanceName);
void StatementExecutor_SetSymbol(StatementExecutor*, const char* symbol, const char* value);

void StatementExecutor_ConstructorError(StatementExecutor* executor, const char* message);
char* StatementExecutor_FixtureError(const char* message);

#endif  // D_StatementExecutor_H
