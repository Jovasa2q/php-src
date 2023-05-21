--TEST--
Type Alias: classes cannot extend type aliases
--FILE--
<?php
type Foo = int | string;

class Bar extends Foo
{
}
--EXPECTF--
Fatal error: Class Bar cannot extend type alias Foo in %s on line %d
