#ifndef DUMP_SQL_DEF_DUMPER_HPP
#define DUMP_SQL_DEF_DUMPER_HPP

#include "dump/sql/dumper.hpp"

namespace dump { namespace sql {

    //
    // common
    //
    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(::sql::ast::quot const& obj) {
        switch(obj)
        {
            case ::sql::ast::quot::NONE:
                this->cEnum("none");
                break;
            case ::sql::ast::quot::SINGLE:
                this->cEnum("single");
                break;
            case ::sql::ast::quot::DOUBLE:
                this->cEnum("double");
                break;
            case ::sql::ast::quot::SQUARED:
                this->cEnum("squared");
                break;
            case ::sql::ast::quot::BACKTICK:
                this->cEnum("backtick");
                break;
        }
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(::sql::ast::bop const& obj) {
        this->cEnum(::sql::ast::terminal(obj));
    }

    //
    // create_table_stmt
    //
    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(::sql::ast::type_name const& obj) {
        this->cNode(obj, "Type name");
        this->cAttr(obj, "type", obj.name, false, true);
        this->cAttr(obj, "upper_bound", obj.upper_bound, false, true);
        this->cAttr(obj, "lower_bound", obj.lower_bound, true, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(::sql::ast::column_def const& obj) {
        this->cNode(obj, "Column definition");
        this->cAttr(obj, "identifier", obj.name, false);
        this->cAttr(obj, "type", obj.type, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::column_def_list const& obj) {
        this->cList(obj, "Column definition list");
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::create_table_stmt_columns const& obj) {
        this->cNode(obj, "Create table stmt columns");
        this->cAttr(obj, "rowid", obj.rowid, false, true);
        this->cAttr(obj, "columns", obj.columns, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::create_table_stmt_select const& obj) {
        this->cNode(obj, "Create table stmt select");
        this->cAttr(obj, "statement", obj.statement, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::create_table_stmt const& obj) {
        this->cNode(obj, "Create table stmt");
        this->cAttr(obj, "temporary", obj.temporary, false, true);
        this->cAttr(obj, "if not exists", obj.if_not_exists, false, true);
        this->cAttr(obj, "identifier", obj.name, false);
        this->cAttr(obj, "definition", obj.definition, true);
    }

    //
    // expr
    //
    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::bind_parameter const& obj) {
        this->cNode(obj, "Bind Parameter");
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::schema_column_identifier const& obj) {
        this->cNode(obj, "Schema column identifier");
        this->cAttr(obj, "schema", obj.schema, false);
        this->cAttr(obj, "table", obj.table, false);
        this->cAttr(obj, "column", obj.column, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::table_column_identifier const& obj) {
        this->cNode(obj, "Table column identifier");
        this->cAttr(obj, "table", obj.table, false);
        this->cAttr(obj, "column", obj.column, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::simple_column_identifier const& obj) {
        this->cNode(obj, "Simple column identifier");
        this->cAttr(obj, "column", obj.column, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::function_params_expr_list const& obj) {
        this->cNode(obj, "Function params expr list");
        this->cAttr(obj, "distinct", obj.distinct, false, true);
        this->cAttr(obj, "parameters", obj.expressions, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::function_params_none const& obj) {
        this->cNode(obj, "Function params none");
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::function_params_row const& obj) {
        this->cNode(obj, "Function params row");
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::function_call const& obj) {
        this->cNode(obj, "Function call");
        this->cAttr(obj, "name", obj.name, false);
        this->cAttr(obj, "parameters", obj.parameters, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::binary_operation const& obj) {
        this->cNode(obj, "Binary operation");
        this->cAttr(obj, "operator", obj.op, false, true);
        this->cAttr(obj, "first", obj.first, false);
        this->cAttr(obj, "second", obj.second, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(::sql::ast::expr_list const& obj) {
        this->cList(obj, "Expression list");
    }

    //
    // identifier
    //
    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(::sql::ast::identifier const& obj) {
        this->cNode(obj, "Identifier");
        this->cAttr(obj, "quotation", obj.quotation, false, true);
        this->cAttr(obj, "identifier", obj.identifier, true, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::identifier_list const& obj) {
        this->cList(obj, "Identifier list");
    }

    //
    // import_table_stmt
    //
    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::import_table_source_csv const& obj) {
        this->cNode(obj, "Import table statement source csv");
        this->cAttr(obj, "filename", obj.filename, false);
        this->cAttr(obj, "identifier", obj.delimiter, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::import_table_stmt const& obj) {
        this->cNode(obj, "Import table statement");
        this->cAttr(obj, "table", obj.table, false);
        this->cAttr(obj, "source", obj.source, true);
    }

    //
    // join_clause
    //

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::join_operator_type const& obj) {
        switch(obj)
        {
            case ::sql::ast::join_operator_type::plain:
                this->cEnum("none");
                break;
            case ::sql::ast::join_operator_type::left:
                this->cEnum("left");
                break;
            case ::sql::ast::join_operator_type::left_outer:
                this->cEnum("left outer");
                break;
            case ::sql::ast::join_operator_type::inner:
                this->cEnum("inner");
                break;
            case ::sql::ast::join_operator_type::cross:
                this->cEnum("cross");
                break;
        }
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::join_operator const& obj) {
        this->cNode(obj, "Join operator");
        this->cAttr(obj, "natural", obj.natural, false, true);
        this->cAttr(obj, "type", obj.type, true, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::join_constraint_expr const& obj) {
        this->cNode(obj, "Join constraint expression");
        this->cAttr(obj, "expression", obj.expression, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::join_constraint_columns const& obj) {
        this->cNode(obj, "Join constraint columns");
        this->cAttr(obj, "columns", obj.columns, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::join_constraint_omitted const& obj) {
        this->cNode(obj, "Join constraint omitted");
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(::sql::ast::join const& obj) {
        this->cNode(obj, "Join");
        this->cAttr(obj, "op", obj.op, false);
        this->cAttr(obj, "table", obj.table, false);
        this->cAttr(obj, "constraint", obj.constraint, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(::sql::ast::join_list const& obj) {
        this->cList(obj, "Join list");
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(::sql::ast::join_clause const& obj) {
        this->cNode(obj, "Join clause");
        // TODO: rename table to base
        this->cAttr(obj, "table", obj.table, false);
        this->cAttr(obj, "joins", obj.joins, true);
    }

    //
    // literal_value
    //
    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::integer_literal const& obj) {
        this->cNode(obj, "Integer literal");
        this->cAttr(obj, "literal", obj.literal, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::floating_point_literal const& obj) {
        this->cNode(obj, "Floating point literal");
        this->cAttr(obj, "literal", obj.literal, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::string_literal const& obj) {
        this->cNode(obj, "String literal");
        this->cAttr(obj, "quotation", obj.quotation, false);
        this->cAttr(obj, "literal", obj.literal, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::null_literal const& obj) {
        this->cNode(obj, "Null literal");
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(::sql::ast::fun_type const& obj) {
        switch(obj)
        {
            case ::sql::ast::fun_type::current_date:
                this->cEnum("CURRENT_DATE");
                break;
            case ::sql::ast::fun_type::current_time:
                this->cEnum("CURRENT_TIME");
                break;
            case ::sql::ast::fun_type::current_timestamp:
                this->cEnum("CURRENT_TIMESTAMP");
                break;
        }
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::function_literal const& obj) {
        this->cNode(obj, "Function literal");
        this->cAttr(obj, "literal", obj.literal, true);
    }

    //
    // result_column
    //
    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::result_column_all const& obj) {
        this->cNode(obj, "Result column all");
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::result_column_table const& obj) {
        this->cNode(obj, "Result column table");
        this->cAttr(obj, "table name", obj.identifier, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::result_column_expr const& obj) {
        this->cNode(obj, "Result column expression");
        this->cAttr(obj, "expression", obj.expression, false);
        this->cAttr(obj, "alias", obj.alias, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::result_column_list const& obj) {
        this->cList(obj, "Result column list");
    }

    //
    // select_core
    //
    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(::sql::ast::select_type const& obj) {
        switch (obj) {
            case ::sql::ast::select_type::distinct:
                this->cEnum("distinct");
                break;
            case ::sql::ast::select_type::all:
                this->cEnum("all");
                break;
            case ::sql::ast::select_type::none:
                this->cEnum("not specified");
                break;
        }
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::groupby_clause const& obj) {
        this->cNode(obj, "Group by clause");
        this->cAttr(obj, "by", obj.by, false);
        this->cAttr(obj, "having", obj.having, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::select_core_select const& obj) {
        this->cNode(obj, "Select core select");
        this->cAttr(obj, "type", obj.type, false);
        this->cAttr(obj, "columns", obj.columns, false);
        this->cAttr(obj, "from", obj.from, false);
        this->cAttr(obj, "where", obj.where, false);
        this->cAttr(obj, "grouping", obj.grouping, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::expr_list_list const& obj) {
        this->cList(obj, "Expression list list");
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::select_core_values const& obj) {
        this->cNode(obj, "Select core values");
        this->cAttr(obj, "expressions", obj.expressions, true);
    }

    //
    // select_stmt
    //
    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::explain_clause const& obj) {
        this->cNode(obj, "Explain clause");
        this->cAttr(obj, "explain", obj.explain, false);
        this->cAttr(obj, "query plan", obj.query_plan, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(::sql::ast::select_stmt const& obj) {
        this->cNode(obj, "Select statement");
        this->cAttr(obj, "core", obj.core, true);
    }

    //
    // sql
    //
    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(::sql::ast::sql const& obj) {
        this->cList(obj, "SQL");
    }

    //
    // sql_stmt
    //
    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(::sql::ast::sql_stmt const& obj) {
        this->cNode(obj, "SQL statement");
        this->cAttr(obj, "explain", obj.explain, false);
        this->cAttr(obj, "stmt", obj.stmt, true);
    }

    //
    // table_or_subquery
    //
    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::simple_table_identifier const& obj) {
        this->cNode(obj, "Simple table identifier");
        this->cAttr(obj, "table", obj.table, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::schema_table_identifier const& obj) {
        this->cNode(obj, "Schema table identifier");
        this->cAttr(obj, "schema", obj.schema, false);
        this->cAttr(obj, "table", obj.table, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::aliased_table_identifier const& obj) {
        this->cNode(obj, "Aliased table identifier");
        this->cAttr(obj, "table", obj.table, false);
        this->cAttr(obj, "alias", obj.alias, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::table_or_subquery_index const& obj) {
        switch (obj.index_usage)
        {
            case ::sql::ast::index_usage_type::yes:
                this->cEnum("yes");
                this->cAttr(obj, "index", obj.index, true);
                break;
            case ::sql::ast::index_usage_type::no:
                this->cEnum("no");
                break;
            case ::sql::ast::index_usage_type::not_specified:
                this->cEnum("not specified");
                break;
        }
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::table_or_subquery_table const& obj) {
        this->cNode(obj, "Table or subquery table");
        this->cAttr(obj, "table", obj.table, false);
        this->cAttr(obj, "index", obj.index, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::table_or_subquery_list const& obj) {
        this->cList(obj, "Table or subquery list");
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::table_or_subquery_sublist const& obj) {
        this->cNode(obj, "Table or subquery sublist");
        this->cAttr(obj, "list", obj.list, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::table_or_subquery_join const& obj) {
        this->cNode(obj, "Table or subquery join");
        this->cAttr(obj, "join", obj.join, true);
    }

    template <template <typename> class Base, typename D>
    inline void dumper<Base, D>::operator()(
            ::sql::ast::table_or_subquery_select const& obj) {
        this->cNode(obj, "Table or subquery select");
        this->cAttr(obj, "stmt", obj.stmt, false);
        this->cAttr(obj, "alias", obj.alias, true);
    }

}}

#endif //DUMP_SQL_DEF_DUMPER_HPP
