--TEST--
Type Alias: ReflectionClass::isTypeAlias() returns true for type aliases
--FILE--
<?php
type Foo = int | string;

$reflected = new ReflectionClass(Foo::class);
var_dump($reflected->isTypeAlias());
--EXPECT--
bool(true)
