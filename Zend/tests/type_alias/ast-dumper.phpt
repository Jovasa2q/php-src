--TEST--
Type alias AST dumper
--FILE--
<?php

try {
    assert((function () {
        type Foo = string | int | bool;

        return false;
    })());
} catch (Error $e) {
    echo $e->getMessage();
}

?>
--EXPECT--
assert(function () {
    type Foo = string|int|bool;

    return false;
}())
