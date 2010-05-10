#ifndef D_SymbolTable_H
#define D_SymbolTable_H

///////////////////////////////////////////////////////////////////////////////
//
//  SymbolTable is responsible for ...
//
///////////////////////////////////////////////////////////////////////////////

typedef struct SymbolTable SymbolTable;

SymbolTable* SymbolTable_Create(void);
void SymbolTable_Destroy(SymbolTable*);
const char * SymbolTable_FindSymbol(SymbolTable* self, const char * name, int length);
void SymbolTable_SetSymbol(SymbolTable* self, const char* symbol, const char* value);
int SymbolTable_GetSymbolLength(SymbolTable* self, const char* symbol, int length);
#endif  // D_SymbolTable_H
