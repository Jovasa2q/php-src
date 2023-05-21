--TEST--
Type Alias: ReflectionClass::getTypeAlias() returns a ReflectionType
--FILE--
<?php
type Foo = int | string;

$reflected = new ReflectionClass(Foo::class);
$reflectionType = $reflected->getTypeAlias();

var_dump(is_a($reflectionType, ReflectionType::class));
var_dump($reflectionType::class);
var_dump((string) $reflectionType);
--EXPECT--
bool(true)
string(19) "ReflectionUnionType"
string(10) "string|int"
