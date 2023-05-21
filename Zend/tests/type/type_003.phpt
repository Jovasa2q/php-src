--TEST--
Type Alias: cannot instantiate instances of type aliases
--FILE--
<?php
type Foo = int | string | bool;

new Foo;
--EXPECTF--
Fatal error: Uncaught Error: Cannot instantiate type alias Foo in %s:%d
Stack trace:
#%d {main}
  thrown in %s on line %d
