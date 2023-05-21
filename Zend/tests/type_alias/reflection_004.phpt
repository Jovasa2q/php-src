--TEST--
Type Alias: ReflectionClass::getTypeAlias() returns null
--FILE--
<?php
class Foo
{
}

$reflected = new ReflectionClass(Foo::class);
var_dump($reflected->getTypeAlias());
--EXPECT--
NULL
