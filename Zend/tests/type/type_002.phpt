--TEST--
Type Alias: non-type aliases cannot implement TypeAlias
--FILE--
<?php
class Foo implements \TypeAlias
{
}
--EXPECTF--
Fatal error: Non-type alias class Foo cannot implement interface TypeAlias in %s on line %d
