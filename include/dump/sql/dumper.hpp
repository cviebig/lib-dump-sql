#ifndef DUMP_SQL_DUMPER_HPP
#define DUMP_SQL_DUMPER_HPP

#include "sql/ast/sql.hpp"

namespace dump { namespace dispatch {
    struct full;
}}

namespace dump { namespace sql {

    template <template <typename> class Base,
              typename D = ::dump::dispatch::full>
    struct dumper
        : public Base<dumper<Base, D>>
    {
        typedef dumper<Base, D> Self;
        using Base<Self>::Base;
        using Base<Self>::operator();

        //
        // common
        //
        void operator()(::sql::ast::quot const& obj);
        void operator()(::sql::ast::bop const& obj);

        //
        // create_table_stmt
        //
        void operator()(::sql::ast::type_name const& obj);
        void operator()(::sql::ast::column_def const& obj);
        void operator()(::sql::ast::column_def_list const& obj);
        void operator()(::sql::ast::create_table_stmt_columns const& obj);
        void operator()(::sql::ast::create_table_stmt_select const& obj);
        void operator()(::sql::ast::create_table_stmt const& obj);

        //
        // expr
        //
        void operator()(::sql::ast::bind_parameter const& obj);
        void operator()(::sql::ast::schema_column_identifier const& obj);
        void operator()(::sql::ast::table_column_identifier const& obj);
        void operator()(::sql::ast::simple_column_identifier const& obj);
        void operator()(::sql::ast::function_params_expr_list const& obj);
        void operator()(::sql::ast::function_params_none const& obj);
        void operator()(::sql::ast::function_params_row const& obj);
        void operator()(::sql::ast::function_call const& obj);
        void operator()(::sql::ast::binary_operation const& obj);
        void operator()(::sql::ast::expr_list const& obj);

        //
        // identifier
        //
        void operator()(::sql::ast::identifier const& obj);
        void operator()(::sql::ast::identifier_list const& obj);

        //
        // import_table_stmt
        //
        void operator()(::sql::ast::import_table_source_csv const& obj);
        void operator()(::sql::ast::import_table_stmt const& obj);

        //
        // join_clause
        //

        void operator()(::sql::ast::join_operator_type const& obj);
        void operator()(::sql::ast::join_operator const& obj);
        void operator()(::sql::ast::join_constraint_expr const& obj);
        void operator()(::sql::ast::join_constraint_columns const& obj);
        void operator()(::sql::ast::join_constraint_omitted const& obj);
        void operator()(::sql::ast::join const& obj);
        void operator()(::sql::ast::join_list const& obj);
        void operator()(::sql::ast::join_clause const& obj);

        //
        // literal_value
        //
        void operator()(::sql::ast::integer_literal const& obj);
        void operator()(::sql::ast::floating_point_literal const& obj);
        void operator()(::sql::ast::string_literal const& obj);
        void operator()(::sql::ast::null_literal const& obj);
        void operator()(::sql::ast::fun_type const& obj);
        void operator()(::sql::ast::function_literal const& obj);

        //
        // result_column
        //
        void operator()(::sql::ast::result_column_all const& obj);
        void operator()(::sql::ast::result_column_table const& obj);
        void operator()(::sql::ast::result_column_expr const& obj);
        void operator()(::sql::ast::result_column_list const& obj);

        //
        // select_core
        //
        void operator()(::sql::ast::select_type const& obj);
        void operator()(::sql::ast::groupby_clause const& obj);
        void operator()(::sql::ast::select_core_select const& obj);
        void operator()(::sql::ast::expr_list_list const& obj);
        void operator()(::sql::ast::select_core_values const& obj);

        //
        // select_stmt
        //
        void operator()(::sql::ast::explain_clause const& obj);
        void operator()(::sql::ast::select_stmt const& obj);

        //
        // sql
        //
        void operator()(::sql::ast::sql const& obj);

        //
        // sql_stmt
        //
        void operator()(::sql::ast::sql_stmt const& obj);

        //
        // table_or_subquery
        //
        void operator()(::sql::ast::simple_table_identifier const& obj);
        void operator()(::sql::ast::schema_table_identifier const& obj);
        void operator()(::sql::ast::aliased_table_identifier const& obj);
        void operator()(::sql::ast::table_or_subquery_index const& obj);
        void operator()(::sql::ast::table_or_subquery_table const& obj);
        void operator()(::sql::ast::table_or_subquery_list const& obj);
        void operator()(::sql::ast::table_or_subquery_sublist const& obj);
        void operator()(::sql::ast::table_or_subquery_join const& obj);
        void operator()(::sql::ast::table_or_subquery_select const& obj);

    };

}}

#endif //DUMP_SQL_DUMPER_HPP
