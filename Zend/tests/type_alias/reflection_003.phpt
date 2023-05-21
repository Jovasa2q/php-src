--TEST--
Type Alias: ReflectionClass::isTypeAlias() returns false for non-type aliases
--FILE--
<?php
class Foo
{
}

$reflected = new ReflectionClass(Foo::class);
var_dump($reflected->isTypeAlias());
--EXPECT--
bool(false)
