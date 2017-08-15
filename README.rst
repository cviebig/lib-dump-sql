Data structure dumper for SQL parse trees
=========================================

The data structure dumper defined in `include/dump/sql/dumper.hpp
<include/dump/sql/dumper.hpp>`_ for SQL parse trees of ``lib-sql`` [1] can be
instantiated in conjunction with CRTP templates that are compatible with those
defined in ``lib-dump`` [2].

[1] https://github.com/cviebig/lib-sql

[2] https://github.com/cviebig/lib-dump
