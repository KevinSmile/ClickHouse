#pragma once

#include <DB/Storages/IStorage.h>
#include <DB/Interpreters/Context.h>

namespace DB
{
class ASTIdentifier;

/** Позволяет добавить или удалить столбец в таблице.
  */
class InterpreterAlterQuery
{
public:
	InterpreterAlterQuery(ASTPtr query_ptr_, Context & context_);

	void execute();

private:
	void dropColumnFromAST(const ASTIdentifier & drop_column, ASTs & columns);

	ASTPtr query_ptr;
	
	Context context;
};
}
