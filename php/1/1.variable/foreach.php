<?php
function a() {
    return function($arr) {
        foreach ($arr as $item) {
            echo $item . "\n";
        }
    };
}

$f = a();
$f([1,2,3,4,5]);