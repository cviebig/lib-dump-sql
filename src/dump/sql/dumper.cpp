#include "dump/sql_def/dumper.hpp"

#include "dump/console.hpp"
#include "dump/forest.hpp"
#include "dump/plaintext.hpp"
#include "dump/tikz.hpp"

namespace dump { namespace sql {

    template struct dumper<::dump::console_dumper>;
    template struct dumper<::dump::forest_dumper>;
    template struct dumper<::dump::plaintext_dumper>;
    template struct dumper<::dump::tikz_dumper>;

}}
