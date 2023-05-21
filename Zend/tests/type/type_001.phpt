--TEST--
Type Alias: type aliases implement TypeAlias
--FILE--
<?php
type Foo = int | string;

var_dump(is_a(Foo::class, \TypeAlias::class, true));
--EXPECT--
bool(true)
