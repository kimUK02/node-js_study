#변수
bool, int, float, string, arr , obj , resource, null 총 8가지의 변수형이 있습니다.

 
##변수 앞에는 $을 씀

###문자열 
#### 문자열 append 는 . 연산자
 
~~~php  
      echo "Hello, ". "World!!" ;
      $str1 = "people";
      $str2 = "hate";
      $str3 = "php";
      $temp .= $str1.$str2.$str3;
      echo $temp;
~~~

###
객체 
~~~php
    class Human{
            private $Name;
            private $Age;
    
            public function setter($Name, $Age)
            {
                $this->Name = $Name;
                $this->Age = $Age;
                echo "Name: ".$this->Name. " Age: ".$this->Age."\n";
            }
        }
    
        $KSW = new Human();
        $KSW->setter("Simon",17);
~~~