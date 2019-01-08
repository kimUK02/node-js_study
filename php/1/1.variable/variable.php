<?php
/**
 * Created by PhpStorm.
 * User: xylitol
 * Date: 1/1/19
 * Time: 11:42 PM
 */
    $int = 10;
    $str = 'a';
    $str .= 'c';
    echo $int . $str ;

    $a[0] = "abc";
    $a[1] = "def";
    $b["foo"] = 13;
    echo "\n". $a[0]. $a[1]."\n";

    class Human{
        private $name;
        private $nge;

        public function setter($Name, $Age)
        {
            $this->Name = $Name;
            $this->Age = $Age;
            echo "Name: ".$this->Name. " Age: ".$this->Age."\n";
        }
    }

    $KSW = new Human();
    $KSW->setter("kimsungwook",17);

    $tmp = 1;
    function Test(){
        global $tmp;
        echo $tmp;
    }
    Test();
