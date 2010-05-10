#include "SymbolTable.h"
#include <stdlib.h>
#include <memory.h>
#include "SlimUtil.h"

typedef struct symbolNode {
	struct symbolNode* next;
	const char* name;
	const char* value;
} SymbolNode;

struct SymbolTable
{
	SymbolNode * head;
};

SymbolTable* SymbolTable_Create(void)
{
     SymbolTable* self = malloc(sizeof(SymbolTable));
     memset(self, 0, sizeof(SymbolTable));
     return self;
}

void SymbolTable_Destroy(SymbolTable* self)
{
	SymbolNode* node;
	for (node = self->head; node;) {
		SymbolNode* nextSymbolNode = node->next;
		free((void*)node->name);
		free((void*)node->value);
		free(node);
		node = nextSymbolNode;
	}	
	free(self);
}

const char * SymbolTable_FindSymbol(SymbolTable* self, const char * name, int length) {
	SymbolNode* node;
	for (node = self->head; node; node = node->next)
	{
		if (strlen(node->name) == length && strncmp(node->name, name, length) == 0)
			return node->value;
	}
	return NULL;
}

void SymbolTable_SetSymbol(SymbolTable* self, const char* symbol, const char* value) {
	SymbolNode * symbolNode = malloc(sizeof(SymbolNode));
	symbolNode->name = buyString(symbol);
	symbolNode->value = buyString(value);
	symbolNode->next = self->head;
	self->head = symbolNode;
}

int SymbolTable_GetSymbolLength(SymbolTable* self, const char* symbol, int length)
{
	const char * symbolValue = SymbolTable_FindSymbol(self, symbol, length);
	if (symbolValue == NULL)
		return -1;
	return strlen(symbolValue);
}


