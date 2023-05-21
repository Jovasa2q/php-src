--TEST--
Type: Syntax
--FILE--
<?php
type Foo = int | string;

$t = new Foo;

var_dump($t);
--EXPECT--
type Foo : string|int
